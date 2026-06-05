/*┌──────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7
  │                        >   Author:- Nazrul Islam
  │Problem Link: https://codeforces.com/problemset/problem/1890/A
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
    int n;    cin>>n;
    map<int,int> mp;
    rep(i,0,n){
        int x;  cin>>x;
        mp[x]++;
    }
    if(mp.size()>2)cout<<"No\n";
    else if(abs(mp.begin()->second - mp.rbegin()->second) <= 1)
        cout<<"Yes\n";
    else cout<<"No\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) run_case();
    return 0;
}