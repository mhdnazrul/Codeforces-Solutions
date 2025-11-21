// problem link:https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/C
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
    int even=0, odd=0, positive=0, negative=0;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        if(x%2==0) even++;
        else odd++;
        if(x>0) positive++;
        else if(x<0) negative++;
    }
    cout<<"Even: "<<even<<nl;
    cout<<"Odd: "<<odd<<nl;
    cout<<"Positive: "<<positive<<nl;
    cout<<"Negative: "<<negative<<nl; 
    
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    //if(!(cin>>test_cases)) return 0;
    for(int tc = 1; tc <= test_cases; tc++){
    //  cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}