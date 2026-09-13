// problem link:https://codeforces.com/problemset/problem/151/A
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
    ll n, k, l, c, d, p, nll, np;
    cin >> n >> k >> l >> c >> d >> p >> nll >> np;
    ll total_drink = (k * l) / nll; 
    ll total_limes = c * d;         
    ll total_salt = p / np;         
    ll total_toasts = min({total_drink, total_limes, total_salt});
    ll ans = total_toasts / n;
    cout<<ans<<nl;
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