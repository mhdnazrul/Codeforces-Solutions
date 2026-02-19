/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/contest/363/problem/B
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

void run_case(){
  ll n, k, x; cin >> n >> k;
  ll sum[n]={0};
  for(ll i=0; i<n; i++){
      cin >> x;
      if(i) sum[i] = sum[i-1] + x;
      else sum[i] = x;
  }
  map<ll, ll>mp;
  mp[sum[k-1]]=1;
  ll mn= sum[k-1];
  for(ll i=1; i<n-k+1; i++){
      mp[sum[i+k-1]-sum[i-1]]=i+1;
      mn = min(mn, sum[i+k-1]-sum[i-1]);
  }
  cout << mp[mn] << endl;
}

int32_t main(){
    fastio();      int T=1; 
    //if(!(cin>>T))  return 0;
    while(T--)     run_case();
    return 0;
}

