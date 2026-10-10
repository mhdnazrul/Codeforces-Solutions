/*┌──────────────────────────────────────────────────────────────────────────┐
  │           >   Handle: nazrulislam_7  ||  Author: Nazrul Islam
  |           Problem: B. Knife's Pill Farm
  │           Problem Link: https://codeforces.com/contest/2264/problem/B
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
    int n,m; cin>>n>>m;
    vll a(n); Vin(a);
 
    if(m==1){
        ll ans = -INF;
        rep(i,0,n)ans = max(ans, a[i]);
        cout<<ans<<"\n";
        return;
    }
    
    multiset<ll> s;
    ll sum =0, ans = -INF;
    rep(i,0,m-1){
        s.insert(a[i]);
        sum+=a[i];
    }
    rep(i,m-1,n){
        ll crr=1ll*m*a[i]-sum;
        ans = max(ans, crr);
        auto it = prev(s.end());
        if(a[i]<*it){
            sum-=*it;
            s.erase(it);
            s.insert(a[i]);
            sum+=a[i];
        }
    }
    cout<<ans<<"\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) run_case();
    return 0;
}