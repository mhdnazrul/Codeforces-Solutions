/*
    author  : nazrulislam_7
    created : 
problem Name:  
problem link: https://codeforces.com/problemset/problem/1676/C
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
    int n, m;        cin >> n >> m;
    vector<string> a(n);    readV(a);

    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int cost = 0;
            for(int k = 0; k < m; k++){
                cost += abs(a[i][k] - a[j][k]);
                //cout<<"a["<<i<<"]["<<k<<"] - a["<<j<<"]["<<k<<"]: "<< a[i][k]<< " || "<< a[j][k]<<" || cost: "<<cost<<nl;
            }
            ans = min(ans, cost);
        }
    }
    cout << ans << "\n";
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
