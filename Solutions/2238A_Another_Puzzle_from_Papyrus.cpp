/*┌──────────────────────────────────────────────────────────────────────────┐
  │           >   Handle: nazrulislam_7  ||  Author: Nazrul Islam
  |           Problem: A. Another Puzzle from Papyrus
  │           Problem Link: https://codeforces.com/contest/2238/problem/A
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
 
ll find_COST(int n, vi a, vi b){
    ll cost = 0;
    rep(i,0,n){
        if(a[i] < b[i]) return INF;
        cost += a[i] - b[i];
    }
    return cost;
}
void run_case() {
    int n,c;    cin>>n>>c;
    vi a(n), b(n); 
    Vin(a); Vin(b);
    ll unoder_COST = find_COST(n,a,b);
 
    sort(all(a));
    sort(all(b));
 
    ll order_COST = find_COST(n,a,b);
 
    if(order_COST != INF)
        order_COST += c;
 
    ll ans = min(unoder_COST, order_COST);
 
    if(ans == INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) run_case();
    return 0;
}