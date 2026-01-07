/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/contest/2183/problem/B
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
    int n, k;    cin >> n >> k;
    vi a(n);    inV(a);
    vector<int> freq(n + 2, 0);
    int crr_mx = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] <= n) freq[a[i]]++;
    }
    while (freq[crr_mx] > 0)crr_mx++;

    int mx = crr_mx;
    for (int i = k; i < n; i++) {
        int tp = a[i];
        int re = a[i - k];
        if (tp <= n) freq[tp]++;
        if (re <= n) {
            freq[re]--;
            if (freq[re] == 0 && re < crr_mx) {
                crr_mx = re;
            }
        }
        while (freq[crr_mx] > 0) {
            crr_mx++;
        }
        
        mx = max(mx, crr_mx);
    }
    if (mx >= k) out(k-1);
    else out(mx);
}

int32_t main(){
    fastio();      int T=1; 
    if(!(cin>>T))  return 0;
    while(T--)     run_case();
    return 0;
}

