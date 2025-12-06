/*
    author  : nazrulislam_7
    problem Name: Sleeping Through Classes
    problem link: https://codeforces.com/contest/2173/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }

void solve() {
    int n, k;    cin >> n >> k;
    string s;    cin >> s;
    int cnt = 0,awake = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') 
            awake = max(awake, i + k); 
        else {if (i > awake) cnt++;}
    }
    cout << cnt << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    if (!(cin >> test_cases)) return 0;
    while (test_cases--) solve();
    return 0;
}
