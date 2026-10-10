// problem link:https://codeforces.com/contest/2171/problem/B
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
    int n;  cin>>n;
    vector<int>v(n);   readV(v);
    for(int i=1; i< n -1;++i) {
        if(v[i]== -1)v[i]= 0;
    }
    if (v[0]== -1 && v[n-1]== -1){
        v[0]= 0;
        v[n-1]= 0;
    }
    else if (v[0]== -1 &&  v[n-1]!= -1) {v[0]=v[n-1];}
    else if (v[n-1]== -1) {v[n-1]= v[0];}
    cout << abs(v[n-1]- v[0])<< nl;
    printV(v);
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