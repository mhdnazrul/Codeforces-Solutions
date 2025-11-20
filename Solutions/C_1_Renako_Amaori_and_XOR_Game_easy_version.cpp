// problem link: C1. Renako Amaori and XOR Game (easy version)
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    readV(a);
    readV(b);

    int NOT_eq = 0;
    int not_eq_idx = -1;

    for(int i = 0; i < n; ++i) {
        if(a[i] != b[i]) {
            NOT_eq++;
            not_eq_idx = i; 
        }
    }

    if (NOT_eq % 2 == 0) {
        cout << "Tie" << nl;
    } else {
        if (not_eq_idx % 2 == 0) {
            cout << "Ajisai" << nl;
        } else {
            cout << "Mai" << nl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        solve();
    }
    return 0;
}