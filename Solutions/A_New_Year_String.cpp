/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/contest/2182/problem/A
  └────────────────────────────────────────────────────────────────────────────────────┘*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;      using ld=long double;
using vi=vector<int>;    using vll=vector<ll>;
using pii=pair<int,int>; using pll=pair<ll,ll>;
constexpr ll INF=1e9;   constexpr int MOD=1e9+7;
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
    int n;      in(n);
    string s;   in(s);
    int cost1 = 4; 
    for (int i = 0; i <= n - 4; i++) {
        int diff = 0;
        if (s[i] != '2') diff++;
        if (s[i+1] != '0') diff++;
        if (s[i+2] != '2') diff++;
        if (s[i+3] != '6') diff++;        
        if (diff < cost1) {
            cost1 = diff;
        }
    }
    int cost2 = 0;
    for (int i = 0; i <= n - 4; i++) {
        if (s[i] == '2' && s[i+1] == '0' && s[i+2] == '2' && s[i+3] == '5') {
            cost2++;
            i += 3;
        }
    }
    cost1 < cost2?out(cost1):out(cost2);
}



int32_t main(){
    fastio();      int T=1; 
    if(!(cin>>T))  return 0;
    while(T--)     run_case();
    return 0;
}