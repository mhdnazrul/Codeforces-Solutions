// problem link:https://codeforces.com/group/MWSDmqGsZm/contest/326175/problem/G
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
    ll n, m, k;    cin >> n >> m >> k;
    ll ans = 0;
    ll mn = min({n, m, k});
    for (ll i = max(0LL, mn - 5); i <= mn; i++) {
        ll eyes = n - i;
        ll mouths = m - i;
        ll bodies = k - i;
        if (eyes < 0 || mouths < 0 || bodies < 0) continue;
        ll y = min({mouths, eyes / 2, bodies});
        eyes -= 2*y;
        mouths -= y;
        bodies -= y;
        ll x = min(eyes / 2, bodies);
        ans = max(ans, x + y + i);
    }
    cout << ans << nl;
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