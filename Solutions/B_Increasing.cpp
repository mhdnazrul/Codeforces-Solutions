/*
    author  : nazrulislam_7
    created : 
problem Name:  
problem link: https://codeforces.com/problemset/problem/1742/B
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
    int n;      cin>>n;
    vector<int> v(n);
    set<int> st;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        v[i] = x;
        st.insert(x);
    }
    if(st.size()!=n){cout<<"NO\n"; return;}

    sort(all(v));
    for(int i=1; i<n; i++){
        if(v[i]<=v[i-1]){
            cout<<"NO\n";
            break;
        }
    }
    cout<<"YES\n";
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
