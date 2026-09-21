/*┌──────────────────────────────────────────────────────────────────────────┐
  │           >   Handle: nazrulislam_7  ||  Author: Nazrul Islam
  |           Problem: A. Iskander and Drawings
  │           Problem Link: https://codeforces.com/contest/2244/problem/A
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
    int mx=0,i=0;
    while(i<n){
        if(s[i]=='#'){
            int j=i;
            while(j<n && s[j]=='#') j++;
            int len=j-i;
            int cnt=0;
            if(len<=2) cnt=1;
            else cnt = (len+1)/2;
            mx = max(mx,cnt);
            i=j;
        }
        else i++;
    }
    cout << mx << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) run_case();
    return 0;
}