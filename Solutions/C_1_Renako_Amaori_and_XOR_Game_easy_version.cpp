/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/problemset/problem/2171/C1
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    inV(a);
    inV(b);

    int NOT_eq = 0;
    int not_eq_idx = -1;

    for(int i = 0; i < n; ++i) {
        if(a[i] != b[i]) {
            NOT_eq++;
            not_eq_idx = i; 
        }
    }

    if (NOT_eq % 2 == 0) {
        cout << "Tie" << nl;
    } else {
        if (not_eq_idx % 2 == 0) {
            cout << "Ajisai" << nl;
        } else {
            cout << "Mai" << nl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        solve();
    }
    return 0;
}