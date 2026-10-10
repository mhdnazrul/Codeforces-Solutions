let allProblems = [];
const REPO_URL = 'https://github.com/mhdnazrul/Codeforces-Solutions';
let allSolutions = [];
let currentFilteredSolutions = [];
let ratingChart = null;
let currentSort = { key: null, dir: 'asc' };

document.addEventListener('DOMContentLoaded', () => {
    fetch('solutions.json')
        .then(r => r.ok ? r.json() : [])
        .then(data => {
            allSolutions = (Array.isArray(data) ? data : []).map(normalizeEntry);
            currentFilteredSolutions = [...allSolutions];
            renderStatistics(allSolutions);
            renderTable(currentFilteredSolutions);
        })
        .catch(e => console.error(e));

    const searchBox = document.getElementById('searchInput');
    let debounceTimer;
    if (searchBox) {
        searchBox.addEventListener('input', () => {
            clearTimeout(debounceTimer);
            debounceTimer = setTimeout(applyFilters, 300);
        });
    }
    document.getElementById('difficultyFilter')?.addEventListener('change', applyFilters);
});

function normalizeEntry(p) {
    const relPath = p.sol_path || '';
    const solutionUrl = relPath ? `${REPO_URL}/blob/main/${relPath}` : '#';
    return {
        problemId: String(p.id || 'N/A'),
        problemName: String(p.name || p.id),
        rating: Number(p.rating) || 0,
        tags: Array.isArray(p.tags) ? p.tags : [],
        questionUrl: p.q_link || '#',
        solutionUrl: solutionUrl,
        raw: p
    };
}

function renderStatistics(data) {
    document.getElementById('total-solved').textContent = data.length;
    const ratings = data.map(s => s.rating).filter(r => r > 0);
    document.getElementById('avg-rating').textContent = ratings.length ? Math.round(ratings.reduce((a,b)=>a+b,0)/ratings.length) : '-';
    document.getElementById('max-rating').textContent = ratings.length ? Math.max(...ratings) : '-';

    const counts = {};
    ratings.forEach(r => counts[r] = (counts[r] || 0) + 1);
    const keys = Object.keys(counts).map(Number).sort((a,b)=>a-b);

    const ctx = document.getElementById('ratingChart')?.getContext('2d');
    if (ctx) {
        if (ratingChart) ratingChart.destroy();
        ratingChart = new Chart(ctx, {
            type: 'bar',
            data: {
                labels: keys,
                datasets: [{ label: 'Solved', data: keys.map(k => counts[k]), backgroundColor: '#2196f3' }]
            },
            options: { responsive: true, maintainAspectRatio: false, plugins: { legend: { display: false } }, scales: { y: { beginAtZero: true, ticks: { stepSize: 1 } } } }
        });
    }
}

function renderTable(data) {
    const tbody = document.getElementById('table-body');
    const noRes = document.getElementById('no-results');
    tbody.innerHTML = '';
    
    if (!data.length) { noRes.style.display = 'block'; return; }
    noRes.style.display = 'none';

    data.forEach(sol => {
        const tr = document.createElement('tr');
        const rClass = getLevelClass(sol.rating);
        
        let tagsHtml = '';
        sol.tags.slice(0, 2).forEach(t => tagsHtml += `<span class="tag">${t}</span>`);
        
        tr.innerHTML = `
            <td>${sol.problemId}</td>
            <td>${sol.problemName}</td>
            <td><span class="rating-badge lvl-${rClass}">${sol.rating || 'N/A'}</span></td>
            <td>${tagsHtml}</td>
            <td class="center-align">
                <a href="${sol.questionUrl}" target="_blank" class="action-btn btn-problem"><i class="fas fa-external-link-alt"></i> Prob</a>
                <a href="${sol.solutionUrl}" target="_blank" class="action-btn btn-sol"><i class="fas fa-code"></i> Code</a>
            </td>
        `;
        tbody.appendChild(tr);
    });
}

function getLevelClass(r) {
    if (r < 1000) return 'newbie';
    if (r < 1200) return 'green';
    if (r < 1400) return 'cyan';
    if (r < 1600) return 'blue';
    return 'violet';
}

function applyFilters() {
    const q = document.getElementById('searchInput').value.trim().toLowerCase();
    const diff = document.getElementById('difficultyFilter').value;
    
    currentFilteredSolutions = allSolutions.filter(s => {
        const matchQ = !q || (`${s.problemId} ${s.problemName}`).toLowerCase().includes(q);
        const matchD = diff === 'all' || (s.rating && s.rating >= Number(diff));
        return matchQ && matchD;
    });
    
    if (currentSort.key) sortTable(currentSort.key, false);
    else renderTable(currentFilteredSolutions);
}

function sortTable(key, toggle = true) {
    if (toggle) {
        if (currentSort.key === key) currentSort.dir = currentSort.dir === 'asc' ? 'desc' : 'asc';
        else { currentSort.key = key; currentSort.dir = 'asc'; }
    }
    const dir = currentSort.dir === 'asc' ? 1 : -1;
    
    currentFilteredSolutions.sort((a,b) => {
        let va = a[key], vb = b[key];
        if (key === 'rating') return (va - vb) * dir;
        if (key === 'problemId' || key === 'id') 
            return String(va).localeCompare(String(vb), undefined, { numeric: true, sensitivity: 'base' }) * dir;
        return String(va).localeCompare(String(vb)) * dir;
    });
    
    document.querySelectorAll('.fa-sort, .fa-sort-up, .fa-sort-down').forEach(i => i.className = 'fas fa-sort');
    const icon = document.querySelector(`th[onclick="sortTable('${key}')"] i`);
    if (icon) icon.className = currentSort.dir === 'asc' ? 'fas fa-sort-up' : 'fas fa-sort-down';
    
    renderTable(currentFilteredSolutions);
}