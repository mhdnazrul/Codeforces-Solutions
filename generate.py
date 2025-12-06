import os
import json
import re
import requests

DIRECTORIES = ["Solutions", "Gyms", "Groups"]
WEB_DIR = "Web"
EXTENSIONS = {".cpp", ".c", ".py", ".java", ".js", ".kt", ".cs"}
CF_API_URL = "https://codeforces.com/api/problemset.problems"
REPO_URL = "https://github.com/mhdnazrul/Codeforces-Solutions"

seen_files = set()
problems_data = []
stats = {"total": 0, "by_rating": {}, "by_tag": {}}
cf_problems_cache = {}

def get_cf_problems():
    try:
        print("Fetching Codeforces data...")
        resp = requests.get(CF_API_URL, timeout=15).json()
        if resp["status"] == "OK":
            for p in resp["result"]["problems"]:
                pid = f"{p.get('contestId')}{p.get('index')}"
                cf_problems_cache[pid] = p
                if 'id' in p:
                    num_id = f"{p.get('id')}{p.get('index')}"
                    if num_id != pid:
                        cf_problems_cache[num_id] = p
    except Exception as e:
        print(f"API Warning: {e}")

def sanitize_filename(filename):
    name, ext = os.path.splitext(filename)
    new_name = re.sub(r'[^a-zA-Z0-9]', '_', name)
    new_name = re.sub(r'_+', '_', new_name).strip('_')
    return f"{new_name}{ext}"

def get_fallback_rating(folder, index):
    if index and index.upper() >= 'I' and index.upper() <= 'Z': return 900
    if folder == "Gyms": return 900
    return 800

def detect_metadata(content, filename, folder_name):
    link = None
    contest_id = None
    index = None
    patterns = [
        r'(https?://codeforces\.com/group/[^/]+/contest/(\d+)/problem/(\w+))',
        r'(https?://codeforces\.com/gym/(\d+)/problem/(\w+))',
        r'(https?://codeforces\.com/contest/(\d+)/problem/(\w+))',
        r'(https?://codeforces\.com/problemset/problem/(\d+)/(\w+))'
    ]
    for pattern in patterns:
        match = re.search(pattern, content)
        if match:
            link = match.group(1)
            contest_id = match.group(2)
            index = match.group(3)
            break
    
    if not contest_id:
        name_match = re.match(r'^(\d+)([A-Z]+[0-9]?)_', filename, re.IGNORECASE)
        if name_match:
            contest_id = name_match.group(1)
            index = name_match.group(2).upper()
            if folder_name == "Gyms":
                link = f"https://codeforces.com/gym/{contest_id}/problem/{index}"
            else:
                link = f"https://codeforces.com/contest/{contest_id}/problem/{index}"
    return link, contest_id, index

def process_files():
    get_cf_problems()
    if not os.path.exists(WEB_DIR): os.makedirs(WEB_DIR)

    for folder in DIRECTORIES:
        if not os.path.exists(folder): continue
        for root, _, files in os.walk(folder):
            for file in files:
                if not any(file.endswith(ext) for ext in EXTENSIONS): continue
                
                original_path = os.path.join(root, file)
                new_filename = sanitize_filename(file)
                new_path = os.path.join(root, new_filename)
                
                if original_path != new_path:
                    try:
                        os.rename(original_path, new_path)
                        file = new_filename
                    except: continue
                
                file_key = os.path.relpath(new_path, os.getcwd()).lower()
                if file_key in seen_files:
                    try: os.remove(new_path); continue
                    except: pass
                seen_files.add(file_key)

                try:
                    with open(new_path, 'r', encoding='utf-8', errors='ignore') as f: content = f.read()
                except: content = ""

                q_link, cid, idx = detect_metadata(content, file, folder)
                p_name = new_filename.split('.')[0].replace('_', ' ')
                if cid and idx:
                    clean_name = p_name.replace(f"{cid}{idx} ", "").replace(f"{cid}{idx}", "")
                    if clean_name.strip(): p_name = clean_name.strip()

                p_rating = 0
                p_tags = []
                full_id = f"{cid}{idx}" if cid else "N/A"

                if full_id in cf_problems_cache:
                    data = cf_problems_cache[full_id]
                    p_name = data.get("name", p_name)
                    p_rating = data.get("rating", 0)
                    p_tags = data.get("tags", [])
                
                if p_rating == 0:
                    p_rating = get_fallback_rating(folder, idx)
                    if not p_tags: p_tags = ["implementation"]

                rel_path = os.path.join(folder, os.path.relpath(new_path, folder)).replace("\\", "/")
                
                problems_data.append({
                    "id": full_id,
                    "name": p_name,
                    "rating": p_rating,
                    "tags": p_tags,
                    "q_link": q_link if q_link else "#",
                    "sol_path": rel_path,
                    "filename": file
                })
                
                stats["total"] += 1
                if p_rating > 0: stats["by_rating"][p_rating] = stats["by_rating"].get(p_rating, 0) + 1
                for tag in p_tags: stats["by_tag"][tag] = stats["by_tag"].get(tag, 0) + 1

    with open(os.path.join(WEB_DIR, "solutions.json"), "w", encoding='utf-8') as f:
        json.dump(problems_data, f, indent=2)
    generate_readme()

def generate_readme():
    sorted_probs = sorted(problems_data, key=lambda x: (x['rating'], x['id']), reverse=True)
    repo_owner = os.getenv('GITHUB_REPOSITORY_OWNER', 'mhdnazrul')
    repo_name = os.getenv('GITHUB_REPOSITORY', 'Codeforces-Solutions').split('/')[-1]
    
    md = f"""<h1 align="center">Codeforces Solution Archive</h1>
<p align="center">
    <a href="https://{repo_owner}.github.io/{repo_name}/">
        <img src="https://img.shields.io/badge/View_Website-Click_Here-2ecc71?style=for-the-badge&logo=google-chrome&logoColor=white" alt="Website">
    </a>
</p>
<p align="center">
    <img src="https://img.shields.io/badge/Language-C++%20%7C%20Python-blue?style=for-the-badge&logo=c%2B%2B" alt="Language">
    <img src="https://img.shields.io/badge/Total%20Solved-{stats['total']}-00b894?style=for-the-badge&logo=codeforces" alt="Total">
</p>
<p align="center">
    <b>🚀 Find me on: </b>
    <a href="https://github.com/mhdnazrul">GitHub</a> | <a href="https://codeforces.com/profile/nazrulislam_7">Codeforces</a> | <a href="https://www.codechef.com/users/nazrulislam_7">CodeChef</a> | <a href="https://www.linkedin.com/in/nazrulislam7/">Linkedin</a>
</p>

---

## 📊 Statistics
**Total Problems Solved:** {stats['total']}

<details><summary><b>Breakdown by Difficulty</b></summary>

| Difficulty | Count |
| :--- | :--- |
"""
    for r in sorted(stats['by_rating'].keys()): md += f"| {r} | {stats['by_rating'][r]} |\n"
    
    md += """</details>

<details><summary><b>Breakdown by Tags</b></summary>

| Tag | Count |
| :--- | :--- |
"""
    for t in sorted(stats['by_tag'].keys()): md += f"| {t} | {stats['by_tag'][t]} |\n"

    md += "</details>\n\n<h2 align=\"center\">📋 Solution Index</h2>\n\n| Problem ID | Problem Name | Difficulty ⇅ | Tags | Question | Solution |\n| :---: | :--- | :---: | :--- | :---: | :---: |\n"

    for p in sorted_probs:
        tags_display = ", ".join([f"`{t}`" for t in p['tags'][:2]]) + (", ..." if len(p['tags']) > 2 else "")
        rating_display = p['rating'] if p['rating'] > 0 else "-"
        sol_full_link = f"{REPO_URL}/blob/main/{p['sol_path']}".replace(" ", "%20")
        md += f"| {p['id']} | {p['name']} | {rating_display} | {tags_display} | [View]({p['q_link']}) | [Code]({sol_full_link}) |\n"

    md += f"\n<br>\n<p align=\"center\"><i>Auto-generated by <a href=\"Web/generate.py\">generate.py</a></i></p>"
    with open("README.md", "w", encoding="utf-8") as f: f.write(md)

if __name__ == "__main__": process_files()