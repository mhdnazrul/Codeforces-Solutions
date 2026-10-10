/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/contest/2188/problem/C
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




bool check(int k, int n, const vi& a, const vi& b) {
    int mn = a[0], mx = a[0];
    for (int x : a) {
        mn = min(mn, x);
        mx = max(mx, x);
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (a[i] - mn < k && mx - a[i] < k) return 0;
        }
    }
    return 1;
}


void run_case(){
    int n;    cin >> n;
    vi a(n);
    int mn = 2e9, mx = -2e9;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    vi b = a;
    sort(all(b));
    if (a == b) {
        cout << "-1\n";
        return;
    }

    int low = 1, high = mx - mn, ans = 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, n, a, b)) {
            ans = mid;
            low = mid + 1;
        } else  high = mid - 1;
    }
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);          int T=1;
    if(!(cin >> T))     return 0;
    while(T--)        run_case();
    return 0;
}