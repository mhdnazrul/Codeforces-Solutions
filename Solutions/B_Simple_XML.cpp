/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/contest/125/problem/B
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
    string str;     in(str);
    int ln = str.length(), space=0;

    for(int i=0; i<ln;){
        int j=i;
        while(str[j]!='>')j++;
        string txt = str.substr(i,j-i+1);
        if(txt[1]=='/'){
            space--;
            for(int m=0; m<2*space;m++){
                cout<<" ";
            }
            out(txt);
        }
        else{
            for(int k=0; k<2*space; k++){
                cout<<" ";
            }
            out(txt);
            space++;
        }
        i=j+1;
    }
}

int32_t main(){
    fastio();      int T=1; 
    //if(!(cin>>T))  return 0;
    while(T--)     run_case();
    return 0;
}