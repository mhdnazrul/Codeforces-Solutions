/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/contest/2191/problem/C
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
    int n;       cin >> n;
    string s;    cin >> s;
    bool ok = 1;
    int one = -1,zero = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            zero++;
            if (one != -1) ok = 0;
        } else {
            if (one == -1) one = i;
        }
    }
    if (ok) {
        cout << "Bob\n";
        return;
    }
    vi idx;
    for (int i = 0; i < n; i++) {
        if (i < zero && s[i] == '1') {
            idx.push_back(i + 1);
        } else if (i >= zero && s[i] == '0') {
            idx.push_back(i + 1);
        }
    }

    cout << "Alice\n" << idx.size() << "\n";
    for (int idx : idx) {
        cout << " " << idx;
    }
    cout << nl;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);          int T=1;
    if(!(cin >> T))     return 0;
    while(T--)        run_case();
    return 0;
}

