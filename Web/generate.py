import os
import json
import re
import requests
import urllib.parse 
from typing import Dict, Any, Optional, List

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
ROOT_DIR = os.path.abspath(os.path.join(SCRIPT_DIR, '..'))

FOLDERS_TO_SCAN = [
    os.path.join(ROOT_DIR, 'Solutions'),
    os.path.join(ROOT_DIR, 'Gyms'),
    os.path.join(ROOT_DIR, 'Groups')
]
OUTPUT_JSON_FILE = os.path.join(SCRIPT_DIR, 'solutions.json')
README_FILE = os.path.join(ROOT_DIR, 'README.md')
CF_API_URL = 'https://codeforces.com/api/problemset.problems'
ULTIMATE_REGEX = re.compile(
    r'(https?://codeforces\.com/(?:'
    r'(?:problemset/problem|problem|contest)/(\d+)/(?:problem/)?([A-Za-z]\d*)'
    r'|gym/(\d+)/problem/([A-Za-z]\d*)'
    r'|group/[^/]+/contest/(\d+)/problem/([A-Za-z]\d*)'
    r'))'
)

def fetch_problem_data() -> Dict[str, Dict[str, Any]]:
    print("Fetching Codeforces problem data from API...")
    problem_map = {}
    try:
        response = requests.get(CF_API_URL)
        response.raise_for_status()
        data = response.json()
        if data['status'] == 'OK':
            for problem in data['result']['problems']:
                problem_id = f"{problem['contestId']}{problem['index']}"
                problem_map[problem_id] = {
                    "name": problem.get('name', 'N/A'),
                    "rating": problem.get('rating', None),
                    "tags": problem.get('tags', [])
                }
            print(f"Successfully fetched and mapped {len(problem_map)} problems.")
        else:
            print(f"Codeforces API error: {data.get('comment', 'Unknown error')}")
    except requests.exceptions.RequestException as e:
        print(f"Error fetching API data: {e}")
    return problem_map

def parse_problem_link(file_path: str) -> Optional[Dict[str, str]]:
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            for line in f:
                match = ULTIMATE_REGEX.search(line)
                if match:
                    url = match.group(1)
                    if match.group(2) and match.group(3):
                        problem_id = f"{match.group(2)}{match.group(3)}"
                    elif match.group(4) and match.group(5):
                        problem_id = f"{match.group(4)}{match.group(5)}"
                    elif match.group(6) and match.group(7):
                        problem_id = f"{match.group(6)}{match.group(7)}"
                    else:
                        continue
                    return {"url": url, "id": problem_id}
            print(f"Warning: Could not find ANY valid Codeforces link in: {file_path}")
            return None
    except Exception as e:
        print(f"Error reading file {file_path}: {e}")
        return None

def generate_readme(Solutions: List[Dict[str, Any]]):
    print(f"Generating {README_FILE}...")
   
    rating_counts = {}
    for sol in Solutions:
        rating = sol.get('rating')
        if rating:
            if rating in rating_counts:
                rating_counts[rating] += 1
            else:
                rating_counts[rating] = 1
   
    content = f"""## Codeforces Solution Archive [link](https://mhdnazrul.github.io/Codeforces-Solutions/)
### 📢 Find me on:
- [Codeforces Solution Archive Website](https://mhdnazrul.github.io/Codeforces-Solutions/)
- [GitHub](https://github.com/mhdnazrul) | [Codeforces](https://codeforces.com/profile/nazrulislam_7) | [Facebook](https://www.facebook.com/mhdnazrulislam.me/)
## 📊 Statistics
* **Total Problems Solved:** {len(Solutions)}
* **Solved by Difficulty:**
"""
    for rating in sorted(rating_counts.keys()):
        content += f" * **{rating}:** {rating_counts[rating]} problems\n"
    content += "\n---\n\n## 📋 Solution Index\n\n"
   
    content += "| Problem ID | Problem Name | Difficulty | Tags | Question | Solution |\n"
    content += "| :---- | :---- | :----: | :---- | :----: | :----: |\n"
   
    for sol in Solutions:
        problem_id = sol.get('problemId', 'N/A')
        problem_name = sol.get('problemName', 'N/A')
        difficulty = sol.get('rating', 'N/A')
       
        tags = ", ".join(sol.get('tags', []))
        if not tags:
            tags = "N/A"
           
        question_url = sol.get('questionUrl', '#')
       
        raw_solution_url = sol.get('solutionUrl', '#')
        readme_solution_path = raw_solution_url.replace('../', './')
       
        content += f"| {problem_id} | {problem_name} | {difficulty} | {tags} | [Question]({question_url}) | [Solution]({readme_solution_path}) |\n"
    try:
        with open(README_FILE, 'w', encoding='utf-8') as f:
            f.write(content)
        print(f"Successfully generated '{README_FILE}'")
    except Exception as e:
        print(f"Error writing {README_FILE}: {e}")

def main():
    problem_data_map = fetch_problem_data()
    all_solutions = []
   
    print(f"Scanning folders: {', '.join(FOLDERS_TO_SCAN)}...")
   
    for folder in FOLDERS_TO_SCAN:
        for root, _, files in os.walk(folder):
            for file in files:
                if file.endswith('.cpp'):
                    file_path = os.path.join(root, file)
                    link_info = parse_problem_link(file_path)
                   
                    if link_info:
                        problem_id = link_info['id']
                        url = link_info['url']
                        problem_details = problem_data_map.get(problem_id, {})
                       
                        problem_name_from_api = problem_details.get('name', 'N/A')
                        if problem_name_from_api == 'N/A' or not problem_name_from_api:
                            file_name_only = os.path.splitext(file)[0]
                            problem_name = file_name_only.replace('_', ' ').replace('-', ' ')
                        else:
                            problem_name = problem_name_from_api
                        rating = problem_details.get('rating', None)
                        if rating is None:
                            rating = 800
                        tags = problem_details.get('tags', [])
                        if not tags:
                            tags = ["implementation"]
                       
                        rel_path = os.path.relpath(file_path, SCRIPT_DIR)
                       
                        web_path_raw = rel_path.replace(os.sep, '/')
                       
                        web_path_encoded = urllib.parse.quote(web_path_raw, safe='/')
                        solution_entry = {
                            "problemName": problem_name,
                            "problemId": problem_id,
                            "rating": rating,
                            "tags": tags,
                            "questionUrl": url,
                            "solutionUrl": web_path_encoded 
                        }
                        all_solutions.append(solution_entry)
    all_solutions.sort(key=lambda x: (x['rating'] if x['rating'] is not None else 0))
   
    try:
        with open(OUTPUT_JSON_FILE, 'w', encoding='utf-8') as f:
            json.dump(all_solutions, f, indent=4)
        print(f"\nSuccessfully generated '{OUTPUT_JSON_FILE}' with {len(all_solutions)} solutions.")
    except Exception as e:
        print(f"Error writing JSON file: {e}")
    generate_readme(all_solutions)

if __name__ == "__main__":
    main()