let allProblems = [];
const REPO_URL = 'https://github.com/mhdnazrul/Codeforces-Solutions';
let allSolutions = [];
let currentFilteredSolutions = [];
let ratingChart = null;
let currentSort = { key: null, dir: 'asc' };

document.addEventListener('DOMContentLoaded', () => {
    const loadingMsg = document.createElement('div');
    loadingMsg.textContent = 'Loading...';
    loadingMsg.style.textAlign = 'center';
    loadingMsg.style.padding = '20px';
    const tableContainer = document.querySelector('.table-container');
    if (tableContainer) tableContainer.appendChild(loadingMsg);

    fetch('solutions.json')
        .then(resp => {
            if (!resp.ok) throw new Error(`HTTP ${resp.status}`);
            return resp.json();
        })
        .then(data => {
            allSolutions = (Array.isArray(data) ? data : []).map(normalizeEntry);
            currentFilteredSolutions = [...allSolutions];
            renderStatistics(allSolutions);
            renderTable(currentFilteredSolutions);
            if (loadingMsg.parentNode) loadingMsg.parentNode.removeChild(loadingMsg);
        })
        .catch(error => {
            console.error('Error loading solutions.json:', error);
            const nr = document.getElementById('no-results');
            if (nr) {
                nr.textContent = 'Error loading data. Check console.';
                nr.style.display = 'block';
            }
            if (loadingMsg.parentNode) loadingMsg.parentNode.removeChild(loadingMsg);
        });

    const searchBox = document.getElementById('searchInput');
    if (searchBox) {
        let debounceTimer;
        searchBox.addEventListener('input', () => {
            clearTimeout(debounceTimer);
            debounceTimer = setTimeout(applyFilters, 300);
        });
    }
    const difficultyFilter = document.getElementById('difficultyFilter');
    if (difficultyFilter) difficultyFilter.addEventListener('change', applyFilters);
});

function normalizeEntry(p) {
    const relPath = p.sol_path || p.solPath || p.solutionUrl || '';
    const solutionUrl = p.solutionUrl || (relPath ? `${REPO_URL}/blob/main/${encodeURI(relPath)}` : '#');
    const questionUrl = p.questionUrl || p.q_link || p.qLink || '#';
    const id = p.problemId || p.id || p.filename || (relPath ? relPath.split('/').pop() : 'N/A');
    const name = p.problemName || p.name || id;
    const rating = Number(p.rating) || 0;
    const tags = Array.isArray(p.tags) ? p.tags : [];
    return {
        problemId: String(id),
        problemName: String(name),
        rating,
        tags,
        questionUrl,
        solutionUrl,
        raw: p
    };
}

function renderStatistics(solutions) {
    try {
        const totalElem = document.getElementById('total-solved');
        const avgElem = document.getElementById('avg-rating');
        const maxElem = document.getElementById('max-rating');
        if (totalElem) totalElem.textContent = solutions.length;
        const ratings = solutions.map(s => s.rating).filter(r => r > 0);
        const avg = ratings.length ? Math.round(ratings.reduce((a,b)=>a+b,0)/ratings.length) : '-';
        const max = ratings.length ? Math.max(...ratings) : '-';
        if (avgElem) avgElem.textContent = avg;
        if (maxElem) maxElem.textContent = max;

        const ratingCounts = {};
        ratings.forEach(r => ratingCounts[r] = (ratingCounts[r] || 0) + 1);
        const categories = Object.keys(ratingCounts).map(Number).sort((a,b)=>a-b);

        const canvas = document.getElementById('ratingChart');
        if (canvas) {
            canvas.height = 160;
            const ctx = canvas.getContext('2d');
            if (ratingChart) ratingChart.destroy();
            ratingChart = new Chart(ctx, {
                type: 'bar',
                data: {
                    labels: categories,
                    datasets: [{ label: 'Solved', data: categories.map(c => ratingCounts[c] || 0), backgroundColor: '#3498db' }]
                },
                options: { responsive: true, maintainAspectRatio: false, plugins: { legend: { display: false } }, scales: { y: { beginAtZero: true, ticks: { stepSize: 1 } } } }
            });
        }
    } catch (error) {
        console.error('Error rendering statistics:', error);
    }
}

function renderTable(solutions) {
    try {
        const tableBody = document.getElementById('table-body');
        const noResults = document.getElementById('no-results');
        if (!tableBody) return;
        tableBody.innerHTML = '';
        if (!solutions.length) {
            if (noResults) noResults.style.display = 'block';
            return;
        }
        if (noResults) noResults.style.display = 'none';

        solutions.forEach(sol => {
            const tr = document.createElement('tr');
            const tdId = document.createElement('td'); tdId.textContent = sol.problemId; tr.appendChild(tdId);
            const tdName = document.createElement('td'); tdName.textContent = sol.problemName; tr.appendChild(tdName);
            const tdRating = document.createElement('td'); 
            const ratingBadge = document.createElement('span');
            ratingBadge.className = `rating-badge lvl-${getLevelClass(sol.rating)}`;
            ratingBadge.textContent = sol.rating || 'N/A';
            tdRating.appendChild(ratingBadge);
            tr.appendChild(tdRating);
            const tdTags = document.createElement('td');
            sol.tags.forEach(tag => { 
                const span = document.createElement('span'); 
                span.className = 'tag'; 
                span.textContent = tag; 
                tdTags.appendChild(span); 
            });
            tr.appendChild(tdTags);
            const tdLinks = document.createElement('td'); tdLinks.className = 'center-align';
            const qLink = document.createElement('a'); 
            qLink.href = sol.questionUrl || '#'; 
            qLink.target = '_blank'; 
            qLink.rel = 'noopener noreferrer'; 
            qLink.className = 'action-btn btn-problem'; 
            qLink.textContent = 'Question';
            const sLink = document.createElement('a'); 
            sLink.href = sol.solutionUrl || '#'; 
            sLink.target = '_blank'; 
            sLink.rel = 'noopener noreferrer'; 
            sLink.className = 'action-btn btn-sol'; 
            sLink.textContent = 'Code';
            tdLinks.appendChild(qLink); 
            tdLinks.appendChild(document.createTextNode(' ')); 
            tdLinks.appendChild(sLink);
            tr.appendChild(tdLinks);
            tableBody.appendChild(tr);
        });
    } catch (error) {
        console.error('Error rendering table:', error);
    }
}

function getLevelClass(rating) {
    if (rating < 1000) return 'newbie';
    if (rating < 1200) return 'green';
    if (rating < 1400) return 'cyan';
    if (rating < 1600) return 'blue';
    return 'violet';
}

function applyFilters() {
    const searchInput = document.getElementById('searchInput');
    const difficultyFilter = document.getElementById('difficultyFilter');
    if (!searchInput || !difficultyFilter) return;
    const q = searchInput.value.trim().toLowerCase();
    const diffVal = difficultyFilter.value;
    currentFilteredSolutions = allSolutions.filter(s => {
        const matchesQuery = !q || (`${s.problemId} ${s.problemName}`).toLowerCase().includes(q);
        const matchesDiff = diffVal === 'all' || (s.rating && s.rating >= Number(diffVal));
        return matchesQuery && matchesDiff;
    });
    if (currentSort.key) sortTable(currentSort.key, false);
    renderTable(currentFilteredSolutions);
}

function sortTable(key, toggle = true) {
    try {
        if (toggle) {
            if (currentSort.key === key) currentSort.dir = currentSort.dir === 'asc' ? 'desc' : 'asc';
            else { currentSort.key = key; currentSort.dir = 'asc'; }
        }
        const dir = currentSort.dir === 'asc' ? 1 : -1;
        currentFilteredSolutions.sort((a,b) => {
            let va = (a[key] !== undefined) ? a[key] : (a.raw && a.raw[key]) || '';
            let vb = (b[key] !== undefined) ? b[key] : (b.raw && b.raw[key]) || '';
            if (key === 'rating') {
                va = Number(va) || 0;
                vb = Number(vb) || 0;
                return (va - vb) * dir;
            }
            return String(va).localeCompare(String(vb)) * dir;
        });
        // Update sort icons
        document.querySelectorAll('.fa-sort').forEach(icon => icon.style.opacity = '0.5');
        const activeTh = document.querySelector(`th[onclick="sortTable('${key}')"] .fa-sort`);
        if (activeTh) {
            activeTh.style.opacity = '1';
            activeTh.className = currentSort.dir === 'asc' ? 'fas fa-sort-up' : 'fas fa-sort-down';
        }
        renderTable(currentFilteredSolutions);
    } catch (error) {
        console.error('Error sorting table:', error);
    }
}