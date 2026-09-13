/*┌──────────────────────────────────────────────────────────────────────────┐
  │           >   Handle: nazrulislam_7  ||  Author: Nazrul Islam
  |           Problem: B. Min Matrices
  │           Problem Link: https://codeforces.com/contest/2263/problem/B
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
// ──────────────────────────────────Solution──────────────────────────────────
 
void run_case() {
    int n, k; cin >> n >> k;
    if(k<n || (k/2)>n-1) {cout << "-1\n"; return;}
    
    int mn_val = 2*n-k, val =1;
    vector<vi> m(n, vi(n, 0));
    rep(i, 0, mn_val) m[i][i] = val++;
    rep(j, mn_val, n) m[0][j] = val++;
    rep(i,mn_val, n) m[i][0] = val++;
 
    rep(i, 0, n) {
        rep(j, 0, n) {
            if(m[i][j]==0) m[i][j] = val++;
        }
    }
 
    rep(i, 0, n) {
        rep(j, 0, n) cout << m[i][j] << " \n"[j==n-1];
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) run_case();
    return 0;
}