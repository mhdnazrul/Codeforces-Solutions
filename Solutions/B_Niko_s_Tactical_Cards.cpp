/*
    author  : nazrulislam_7 
    problem Name: B. Niko's Tactical Cards
    problem link: https://codeforces.com/contest/2173/problem/B
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }

void solve() {
    int n;  cin >> n;
    vector<ll> a(n),b(n);
    readV(a);readV(b);
    ll mx =0,mn =0; 
    for (int i=0; i <n;++i) {
        ll red_mx =mx -a[i];
        ll red_mn =mn -a[i];
        ll blue_mx =b[i] -mn; 
        ll blue_mn =b[i] -mx; 
        ll mx_val =max(red_mx,blue_mx);
        ll mn_val =min(red_mn,blue_mn);
        mx = mx_val;
        mn = mn_val;
    }
    cout<< mx<< nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    if(!(cin>>test_cases)) return 0;
    for(int tc = 1; tc <= test_cases; tc++){
    //  cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}