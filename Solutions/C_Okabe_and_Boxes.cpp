/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/contest/821/problem/C
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
    int n;    in(n);
    stack<int> st;
    int need = 1;
    int ans = 0;
    for(int i = 0; i < 2 * n; i++){
        string s;        cin >> s;
        if(s == "add"){
            int x;            in(x);
            st.push(x);
        } 
        else { 
            if(!st.empty() && st.top() == need){
                st.pop();
            }
            else if(!st.empty()){
                ans++;
                while(!st.empty()) st.pop();
            }
            need++;
        }
    }

    out(ans);
}

int32_t main(){
    fastio();
    run_case();
    return 0;
}