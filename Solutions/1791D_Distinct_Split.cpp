/*┌──────────────────────────────────────────────────────────────────────────┐
  │           >   Handle: nazrulislam_7  ||  Author: Nazrul Islam
  |           Problem: D. Distinct Split
  │           Problem Link: https://codeforces.com/contest/1791/problem/D
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
    int n; cin >> n;
    string s; cin >> s;
    vi lf(26, 0), rg(26, 0);
    int lf_cnt = 0, rg_cnt = 0;
    for (char c : s) {
        if(rg[c - 'a'] == 0) rg_cnt++;
        rg[c - 'a']++;
    }
    int mx_ln=0;
    rep(i,0,n-1){
        char c = s[i];
        rg[c - 'a']--;
        if(rg[c - 'a'] == 0) rg_cnt--;
        if(lf[c - 'a'] == 0) lf_cnt++;
        lf[c - 'a']++;
        mx_ln = max(mx_ln, lf_cnt + rg_cnt);
    }
    cout << mx_ln << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) run_case();
    return 0;
}
 