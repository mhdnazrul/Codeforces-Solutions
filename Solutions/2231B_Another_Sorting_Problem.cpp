/*┌──────────────────────────────────────────────────────────────────────────┐
  │           >   Handle: nazrulislam_7  ||  Author: Nazrul Islam
  |           Problem: B. Another Sorting Problem
  │           Problem Link: https://codeforces.com/problemset/problem/2231/B
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
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long L = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            L = max(L, a[i] - a[i + 1]);
        }
    }
    
    if (L == 0) {
        cout << "YES\n";
        return;
    }
    
    bool can_0 = true;
    bool can_1 = true;
    
    for (int i = 0; i < n - 1; i++) {
        bool next_can_0 = false;
        bool next_can_1 = false;
        
        if (can_0 && a[i] <= a[i + 1]) next_can_0 = true;
        if (can_1 && a[i] + L <= a[i + 1]) next_can_0 = true;
        
        if (can_0 && a[i] <= a[i + 1] + L) next_can_1 = true;
        if (can_1 && a[i] <= a[i + 1]) next_can_1 = true;
        
        can_0 = next_can_0;
        can_1 = next_can_1;
    }
    
    if (can_0 || can_1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
 