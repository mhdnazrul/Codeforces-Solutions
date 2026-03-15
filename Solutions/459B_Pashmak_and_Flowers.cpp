/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7            
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/contest/459/problem/B
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

void run_case(){
    ll n,a,mx = 0,tp = 0,mn = INF,cnt = 0;
    cin>>n;
    
    for(int i = 0; i < n; i++) {
        cin>>a;
        if(a < mn) {cnt = 1;mn = a;} 
        else if(a == mn) cnt++;

        if(a > mx) {tp = 1;mx = a;} 
        else if(a == mx) tp++;
    }
    ll ans[2];
    ans[0]=mx-mn;
    if(mx == mn)ans[1] = (tp * (tp - 1)) / 2;
    else ans[1] = tp*cnt;
    cout<<ans[0]<<" "<<ans[1]<<nl;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);          int T=1;
    //if(!(cin >> T))     return 0;
    while(T--)        run_case();
    return 0;
}