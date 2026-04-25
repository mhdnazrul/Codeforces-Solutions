// problem link:https://codeforces.com/contest/2171/problem/C2
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }

void solve() {
    int n, x = 0, bit, idx;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        x ^= a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
        x ^= b[i];
    }
    if(!x){
        cout << "Tie" << '\n';
        return;
    }
    for(int i=0; i<20; i++)
        if(x&1<<i)
            bit = i;
    for(int i=0; i<n; i++)
        if((a[i]^b[i])&1<<bit)
            idx = i;
    cout << (idx & 1 ? "Mai" : "Ajisai") << '\n';
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