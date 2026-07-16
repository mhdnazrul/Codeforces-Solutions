/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/contest/816/problem/B
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
    int n, k, q;    in(n); in(k); in(q);
    const int MAX = 200000;
    vi diff(MAX + 2, 0);
    for(int i = 0; i < n; i++){
        int l, r;
        in(l); in(r);
        diff[l]++;
        diff[r + 1]--;
    }
    vi cnt(MAX + 1, 0);
    for(int i = 1; i <= MAX; i++){
        cnt[i] = cnt[i - 1] + diff[i];
    }

    vi ans(MAX + 1, 0);
    for(int i = 1; i <= MAX; i++){
        if(cnt[i] >= k) ans[i] = 1;
    }

    for(int i = 1; i <= MAX; i++){
        ans[i] += ans[i - 1];
    }

    while(q--){
        int a, b;
        in(a); in(b);
        out(ans[b] - ans[a - 1]);
    }
}

int32_t main(){
    fastio();
    run_case();
    return 0;
}