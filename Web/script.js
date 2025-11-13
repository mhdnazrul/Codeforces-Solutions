let allSolutions = [];
let currentFilteredSolutions = [];
let ratingChart = null;
let difficultySortDirection = 'none';

// Convert GitHub blob URLs to raw URLs
function convertGitHubBlobToRaw(url) {
    if (!url) return url;
    // Example: https://github.com/user/repo/blob/main/file.cpp
    // Converts to: https://raw.githubusercontent.com/user/repo/main/file.cpp
    return url.replace(
        /^https:\/\/github\.com\/([^\/]+)\/([^\/]+)\/blob\/(.+)$/,
        'https://raw.githubusercontent.com/$1/$2/$3'
    );
}

document.addEventListener('DOMContentLoaded', () => {
    fetch('solutions.json')
        .then(response => response.json())
        .then(data => {
            // Convert all solution and question URLs to raw URLs once
            allSolutions = data.map(sol => ({
                ...sol,
                solutionUrl: convertGitHubBlobToRaw(sol.solutionUrl),
                questionUrl: convertGitHubBlobToRaw(sol.questionUrl)
            }));

            currentFilteredSolutions = [...allSolutions];

            renderStatistics(allSolutions);
            populateFilters(allSolutions);
            renderTable(allSolutions);
        })
        .catch(error => console.error('Error loading solutions.json:', error));

    document.getElementById('search-box').addEventListener('input', applyFilters);
    document.getElementById('rating-filter').addEventListener('change', applyFilters);
    document.getElementById('difficulty-header').addEventListener('click', sortTableByDifficulty);
});

function renderStatistics(solutions) {
    document.getElementById('total-solved').textContent = solutions.length;
    const ratingCounts = {};
    const ratingCategories = [800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500, 2600, 2700, 2800, 2900, 3000];
    ratingCategories.forEach(r => ratingCounts[r] = 0);
    
    solutions.forEach(sol => {
        if (sol.rating && ratingCounts.hasOwnProperty(sol.rating)) {
            ratingCounts[sol.rating]++;
        }
    });

    const ctx = document.getElementById('rating-chart').getContext('2d');
    if (ratingChart) ratingChart.destroy();

    ratingChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: ratingCategories,
            datasets: [{ label: 'Solved Count', data: Object.values(ratingCounts), backgroundColor: '#3498db' }]
        },
        options: {
            responsive: true,
            maintainAspectRatio: false,
            scales: { y: { beginAtZero: true, ticks: { stepSize: 1 } } },
            plugins: { legend: { display: false } }
        }
    });
}

function populateFilters(solutions) {
    const ratingFilter = document.getElementById('rating-filter');
    const tagFilter = document.getElementById('tag-filter');
    const ratings = new Set();
    const tags = new Set();

    solutions.forEach(sol => {
        if (sol.rating) ratings.add(sol.rating);
        sol.tags.forEach(tag => tags.add(tag));
    });

    [...ratings].sort((a, b) => a - b).forEach(rating => {
        const option = document.createElement('option');
        option.value = rating;
        option.textContent = rating;
        ratingFilter.appendChild(option);
    });

    [...tags].sort().forEach(tag => {
        const tagItem = document.createElement('label');
        tagItem.className = 'tag-item';
        const checkbox = document.createElement('input');
        checkbox.type = 'checkbox';
        checkbox.value = tag;
        checkbox.addEventListener('change', applyFilters);
        tagItem.appendChild(checkbox);
        tagItem.appendChild(document.createTextNode(tag));
        tagFilter.appendChild(tagItem);
    });
}

function renderTable(solutions) {
    const tableBody = document.getElementById('solutions-table-body');
    tableBody.innerHTML = '';

    solutions.forEach(sol => {
        const row = document.createElement('tr');

        const idCell = document.createElement('td');
        idCell.textContent = sol.problemId;
        row.appendChild(idCell);

        const nameCell = document.createElement('td');
        nameCell.textContent = sol.problemName;
        row.appendChild(nameCell);

        const ratingCell = document.createElement('td');
        ratingCell.textContent = sol.rating || 'N/A';
        row.appendChild(ratingCell);

        const tagsCell = document.createElement('td');
        sol.tags.forEach(tag => {
            const tagSpan = document.createElement('span');
            tagSpan.className = 'tag';
            tagSpan.textContent = tag;
            tagsCell.appendChild(tagSpan);
        });
        row.appendChild(tagsCell);

        const questionCell = document.createElement('td');
        questionCell.innerHTML = `<a href="${sol.questionUrl}" target="_blank" class="link-btn">Question</a>`;
        row.appendChild(questionCell);
        
        const solutionCell = document.createElement('td');
        solutionCell.innerHTML = `<a href="${sol.solutionUrl}" target="_blank" class="link-btn solution">Solution</a>`;
        row.appendChild(solutionCell);

        tableBody.appendChild(row);
    });
}

function applyFilters() {
    const searchText = document.getElementById('search-box').value.toLowerCase();
    const selectedRating = document.getElementById('rating-filter').value;
    const selectedTags = [...document.querySelectorAll('#tag-filter input[type="checkbox"]:checked')].map(cb => cb.value);

    currentFilteredSolutions = allSolutions.filter(sol => {
        const nameMatch = sol.problemName.toLowerCase().includes(searchText);
        const ratingMatch = !selectedRating || sol.rating == selectedRating;
        const tagMatch = selectedTags.every(tag => sol.tags.includes(tag));
        return nameMatch && ratingMatch && tagMatch;
    });

    difficultySortDirection = 'none';
    document.getElementById('difficulty-header').textContent = 'Difficulty ⇅';
    
    renderTable(currentFilteredSolutions);
}

function sortTableByDifficulty() {
    const header = document.getElementById('difficulty-header');
    
    if (difficultySortDirection === 'none' || difficultySortDirection === 'desc') {
        difficultySortDirection = 'asc';
        header.textContent = 'Difficulty ↑';
    } else {
        difficultySortDirection = 'desc';
        header.textContent = 'Difficulty ↓';
    }

    currentFilteredSolutions.sort((a, b) => {
        const ratingA = a.rating || 0;
        const ratingB = b.rating || 0;
        return difficultySortDirection === 'asc' ? ratingA - ratingB : ratingB - ratingA;
    });

    renderTable(currentFilteredSolutions);
}
