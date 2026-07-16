// problem link:https://codeforces.com/contest/2158/problem/B
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
    int n;        cin >> n;
    vector<int> a(2*n);     readV(a);
    unordered_map<int,int> freq;
    for (int x : a) freq[x]++;

    int oddCnt = 0, evenCnt = 0;
    for (auto &x : freq) {
        if (x.second % 2) oddCnt++;
        else evenCnt++;
    }

    int ln = freq.size();
    int ans = 0;
    for (int k = 0; k <= evenCnt; k++) {
        int total = oddCnt + 2*k;
        int L = max({k, oddCnt + 2*k - n, 0});
        int U = min({k + oddCnt, n, ln});
        if (L > U) continue;
        int st = L;
        if (st % 2 != n % 2) st++;
        if (st <= U) {ans = max(ans, total);}
    }
    cout << ans << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    if(!(cin>>test_cases)) return 0;
    for(int tc = 1; tc <= test_cases; tc++){
    //  cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}
