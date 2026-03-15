/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/contest/2195/problem/C
  └────────────────────────────────────────────────────────────────────────────────────┘*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;       using ld=long double;
using vi=vector<int>;     using vll=vector<ll>;
using pii=pair<int,int>; using pll=pair<ll,ll>;
const ll INF = 2e18;   const int MOD = 1e9 + 7; 
#define per(i,a,b)  for(int i=(b)-1;i>=(a);--i)
#define rep(i,a,b)  for(int i=(a);i<(b);++i)
#define trav(a, x)     for (auto &a : x)
#define forr(i, n)       rep(i, 0, n)
#define all(x) (x).begin(),(x).end()
#define rall(x) rbegin(x),rend(x)
#define sz(x) (int)(x).size()
const char nl = '\n';
template<class T>    void inV(vector<T> &v){for(auto &x:v) cin>>x;}
template<typename T> void outV(const vector<T>& v) {if (v.empty()) return;
    for (int i = 0; i < sz(v); ++i)cout << v[i] << " \n"[i == sz(v) - 1];}

void run_case() {
    int n;       cin >> n;
    vi a(n);     inV(a);
    int dp[7];
    for(int i = 1; i <= 6; i++) dp[i] = 1;
    dp[a[0]] = 0;
    
    for (int i = 1; i < n; i++) {
        int next_dp[7];
        for (int v = 1; v <= 6; v++) {
            int pre = 2e9;
            for (int p = 1; p <= 6; p++) {
                if (p != v && p != 7 - v) {
                    if (dp[p] < pre) {
                        pre = dp[p];
                    }
                }
            }
            next_dp[v] = pre + (a[i] == v ? 0 : 1);
        }
        for (int v = 1; v <= 6; v++) {
            dp[v] = next_dp[v];
        }
    }

    int ans = 2e9;
    for (int i = 1; i <= 6; i++) {
        ans = min(ans, dp[i]);
    }
    
    cout << ans << nl;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);          int T=1;
    if(!(cin >> T))     return 0;
    while(T--)        run_case();
    return 0;
}