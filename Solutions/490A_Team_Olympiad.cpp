/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/problemset/problem/490/A
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
    int n;  cin>>n;
    vi v,freq(4,0);
    for (int i = 0; i < n; i++){
        int x; cin>>x;
        v.push_back(x);        
        freq[x]++;
    }
    sort(all(freq));
    if ( freq[1] == 0){
        cout<<0<<"\n";
        return;
    }
    else    cout<<freq[1]<<"\n";

    int a = 0, b = 0, c = 0;
    while(freq[1]--){
        for (int i = a; i < n; i++){
            if (v[i] == 1){
                a = i;
                cout<<++a<<" ";                
                break;
            }
        }

        for (int i = b; i < n; i++){
            if (v[i] == 2){
                b = i;
                cout<<++b<<" ";                
                break;
            }
        }

        for (int i = c; i < n; i++){
            if (v[i] == 3){
                c = i;
                cout<<++c<<" ";                
                break;
            }
        }
        cout<<"\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);          int T=1;
    //if(!(cin >> T))     return 0;
    while(T--)        run_case();
    return 0;
}
