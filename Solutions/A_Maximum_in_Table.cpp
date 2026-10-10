/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/contest/509/problem/A
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
  
  void run_case(){
      int n;      in(n);
      vector<vector<ll>> v(n, vector<ll>(n, 1));
  
      for(int i = 1; i < n; i++){
          for(int j = 1; j < n; j++){
              v[i][j] = v[i-1][j] + v[i][j-1];
          }
      }
      out(v[n-1][n-1]);
  }
  
  int32_t main(){
      fastio();
      int T = 1;
      //in(T);
      while(T--) run_case();
      return 0;
  }
  
