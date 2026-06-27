/*
    author  : nazrulislam_7
    created : 
problem Name:  
problem link: https://codeforces.com/problemset/problem/1669/C
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }
void solve(){
    int n;     cin >> n;
    vector<int> a(n);   readV(a);
    int odd = a[0] % 2;
    int even = a[1] % 2;

    bool ok = true;
    for(int i=0; i<n; i++){
        if(i % 2 == 0){
            if(a[i] % 2 != odd){
                ok = false;
            }
        } else {
            if(a[i] % 2 != even){
                ok = false;
            }
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
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
