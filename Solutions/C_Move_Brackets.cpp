/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/problemset/problem/1374/C
  └────────────────────────────────────────────────────────────────────────────────────┘*/
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)
using ll=long long;      using ld=long double;
using vi=vector<int>;    using vll=vector<ll>;
using pii=pair<int,int>; using pll=pair<ll,ll>;
constexpr ll INF=4e18;   constexpr int MOD=1e9+7;
const char nl='\n';
#define sz(x) (int)(x.size())
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
template<class T> void in(T &x){cin>>x;}
template<class T> void inV(vector<T> &v){for(auto &x:v) cin>>x;}
template<class T> void out(const T &x){cout<<x<<'\n';}
template<class T> void outV(const vector<T> &v){for(int i=0;i<(int)v.size();i++) cout<<v[i]<<(i+1<(int)v.size()?' ':'\n');}

void run_case(){
    int n; string s; cin >> n >> s;
	int ans = 0, cur = 0;
	for (auto c: s) {
		cur += c == '(' ? +1 : -1;
		if (cur < 0) ans = max(ans, -cur);
	}
    out(ans);
}

int32_t main(){
    fastio();      int T=1; 
    if(!(cin>>T))  return 0;
    while(T--)     run_case();
    return 0;
}


/*
Example:
s = ")()("
c = ')'
cur = 0 - 1 = -1        // extra closing bracket
ans = max(0, 1) = 1    // need 1 '(' to fix

c = '('
cur = -1 + 1 = 0       // balanced again
ans = 1

c = ')'
cur = 0 - 1 = -1       // again extra ')'
ans = max(1, 1) = 1   // still need only 1 '('

c = '('
cur = -1 + 1 = 0       // balanced
ans = 1

Final answer:
ans = 1  // minimum '(' needed to make string valid
*/