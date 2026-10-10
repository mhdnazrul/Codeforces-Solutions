/*┌──────────────────────────────────────────────────────────────────────────┐
  │           >   Handle: nazrulislam_7  ||  Author: Nazrul Islam
  |           Problem: B. Predominant Frequency Division
  │           Problem Link: https://codeforces.com/contest/2242/problem/B
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
    vi a(n); Vin(a);
    int cnt1 =0, cnt2 =0, cnt3 =0, mn=1e9;
    bool ok = false;
    vi x(n,0), y(n,0), z(n,0), cnt(n,0);
    for(int i=0; i<=n-2; i++){
        if(a[i]==1) cnt1++;
        else if(a[i]==2) cnt2++;
        else if(a[i]==3) cnt3++;
 
        x[i] = cnt1;
        y[i] = cnt2;
        z[i] = cnt3;
        cnt[i] = cnt1+cnt2-cnt3;
    }
    
    for(int i=1; i<=n-2; i++){
        int j=i-1;
        if(x[j]>=y[j] +z[j]) mn = min(cnt[j],mn);
        if(mn != 1e9 && cnt[i] >=mn){ ok = true; break; }
    }
 
    ok?yes():no();
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) run_case();
    return 0;
}
 