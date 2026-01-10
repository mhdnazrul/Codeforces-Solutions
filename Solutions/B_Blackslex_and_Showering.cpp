/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/contest/2179/problem/B
  └────────────────────────────────────────────────────────────────────────────────────┘*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;      using ld=long double;
using vi=vector<int>;    using vll=vector<ll>;
using pii=pair<int,int>; using pll=pair<ll,ll>;
constexpr ll INF=4e18;   constexpr int MOD=1e9+7;
const char nl='\n';
#define sz(x) (int)(x.size())
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)
template<class T> void in(T &x){cin>>x;}
template<class T> void inV(vector<T> &v){for(auto &x:v) cin>>x;}
template<class T> void out(const T &x){cout<<x<<'\n';}
template<class T> void outV(const vector<T> &v){for(int i=0;i<(int)v.size();i++) cout<<v[i]<<(i+1<(int)v.size()?' ':'\n');}
ll timeDIFF(int lf,int mid, int rt){
  ll firstSide = abs(lf -mid)+abs(mid-rt);
  ll secondSide = abs(lf-rt);
  return firstSide - secondSide;
}
void run_case(){
    int n;  in(n);
    vi a(n); inV(a);
    ll totalDiff = 0;
    for (int i = 0; i < n - 1; i++) {
      totalDiff += abs(a[i] - a[i + 1]);
    }

    ll rm=0;
    for(int i=1; i<n-1; i++){
      rm = max(rm, timeDIFF(a[i-1],a[i],a[i+1]));
    }

    rm = max(rm,(ll)abs(a[0]-a[1]));
    rm = max(rm, (ll)abs(a[n-2]-a[n-1]));
    ll ans = totalDiff-rm;
    out(ans);
}

int32_t main(){
    fastio();      int T=1; 
    if(!(cin>>T))  return 0;
    while(T--)     run_case();
    return 0;
}

