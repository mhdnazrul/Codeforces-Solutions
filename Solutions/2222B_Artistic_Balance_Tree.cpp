/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7
  │                        >   Author:- Nazrul Islam
  │Problem Link: https://codeforces.com/contest/2222/problem/B
  └────────────────────────────────────────────────────────────────────────────────────┘*/
#include <bits/stdc++.h>
using namespace std;
// ── Aliases ───────────────────────────────────────────────────────────────────────────
using ll  = long long;using ld  = long double;using vi  = vector<int>;
using vll = vector<ll>;using pii = pair<int,int>;using pll = pair<ll,ll>;
// ── Constants ─────────────────────────────────────────────────────────────────────────
constexpr ll INF = 1'000'000'000'000'000'000LL;  constexpr int MOD = 1'000'000'007;
// ── Macros ────────────────────────────────────────────────────────────────────────────
#define rep(i,a,b)  for(int i=(a);i<(b);++i)
#define per(i,a,b)  for(int i=(b)-1;i>=(a);--i)
#define all(x)      (x).begin(),(x).end()
#define rall(x)     (x).rbegin(),(x).rend()
#define sz(x)       (int)(x).size()
#define fi          first
#define se          second
// ── Output ────────────────────────────────────────────────────────────────────────────
inline void yes() { cout << "YES\n"; }
inline void no()  { cout << "NO\n";  }
// ── modpow ────────────────────────────────────────────────────────────────────────────
ll modpow(ll b, ll e, ll m = MOD) {
    if (m == 1) return 0;
    ll r = 1;    b %= m;
    if (b < 0) b += m;
    for (; e > 0; e >>= 1) {
        if (e & 1) r = (unsigned long long)r * b % m;
        b = (unsigned long long)b * b % m; }
    return r;
}
// ── Solution ──────────────────────────────────────────────────────────────────────────
 
void run_case() {
    int n, m;   cin>>n>>m;
    vll odd, even;
    ll total = 0;
    rep(i,1,n+1){
        ll x;        cin >> x;
        total += x;
        if (i % 2 == 1) odd.push_back(x);
        else even.push_back(x);
    }
    int odd_cnt = 0, even_cnt = 0;
    rep(i,0,m){
        int x;        cin >> x;
        if (x % 2 == 1) odd_cnt++;
        else even_cnt++;
    }
    sort(rall(odd)); 
    sort(rall(even));
    ll sum_0 = 0;
 
    if (odd_cnt > 0 && !odd.empty()) {
        sum_0 += odd[0];
        for (int i = 1; i < min((int)odd.size(), odd_cnt); ++i) {
            if (odd[i] > 0) {
                sum_0 += odd[i];
            } else break; 
        }
    }
 
    if (even_cnt > 0 && !even.empty()) {
        sum_0 += even[0];
        for (int i = 1; i < min((int)even.size(), even_cnt); ++i) {
            if (even[i] > 0) {
                sum_0 += even[i];
            } else {
                break;
            }
        }
    }
    cout << total - sum_0 << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) run_case();
    return 0;
}