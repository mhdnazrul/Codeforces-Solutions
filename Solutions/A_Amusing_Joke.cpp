// problem link:https://codeforces.com/problemset/problem/141/A         
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
    string a, b, c;
    cin >> a >> b >> c;
    vector<int> f(26, 0);
    for (char ch : a) f[ch - 'A']++;
    for (char ch : b) f[ch - 'A']++;
    for (char ch : c) f[ch - 'A']--;

    for (int x : f) {
        if (x != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    //if(!(cin>>test_cases)) return 0;
    for(int tc = 1; tc <= test_cases; tc++){
    //  cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}