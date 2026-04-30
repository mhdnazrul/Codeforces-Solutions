/*┌──────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7
  │                        >   Author:- Nazrul Islam
  │Problem Link: 
  └──────────────────────────────────────────────────────────────────────────┘*/
#include <bits/stdc++.h>
using namespace std;
using ll  = long long;using ld  = long double;using vi  = vector<int>;
using vll = vector<ll>;using pii = pair<int,int>;using pll = pair<ll,ll>;
using ull = unsigned long long; // using i128 = __int128; // only use C++ 20 or up
constexpr ll INF = 1'000'000'000'000'000'000LL;  constexpr int MOD = 1'000'000'007;
#define rep(i,a,b)  for(int i=(a);i<(b);++i)
#define per(i,a,b)  for(int i=(b)-1;i>=(a);--i)
#define all(x)      (x).begin(),(x).end()
#define rall(x)     (x).rbegin(),(x).rend()
#define sz(x)       (int)(x).size()
#define fi          first
#define se          second
inline void yes() { cout << "YES\n"; }
inline void no()  { cout << "NO\n";  }
template<class T> void Vin(vector<T>& v){ for (auto& x : v) cin >> x; }
template<class T> void Vout(const vector<T>& v) {
    rep(i, 0, sz(v)) cout << v[i] << " \n"[i == sz(v) - 1];
}
template<class T>vector<T> prefix_sum(const vector<T>& v) {
    vector<T> p(sz(v) + 1, 0);
    rep(i, 0, sz(v)) p[i + 1] = p[i] + v[i];
    return p;
}
ll modpow(ll b, ll e, ll m = MOD) {
    if (m == 1)  return 0;
    ll r = 1;    b %= m;
    if (b < 0) b += m;
    for (; e > 0; e >>= 1) {
        if (e & 1) r = (ull)r * b % m;
        b = (ull)b * b % m;         }
    return r;
}
ll modinv(ll a, ll m = MOD) { return modpow(a, m - 2, m); }
ll madd(ll a, ll b, ll m = MOD) { return (a + b) % m; }
ll msub(ll a, ll b, ll m = MOD) { return ((a - b) % m + m) % m; }
ll mmul(ll a, ll b, ll m = MOD) { return (__int128)a * b % m; }
// ── Solution ──────────────────────────────────────────────────────────────

void run_case() {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) run_case();
    return 0;
}
