// problem link:https://codeforces.com/contest/189/problem/B
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
    ll w,h; cin>>w>>h;
    ll ans=0;
    for(ll i=2;i<=w;i+=2){
    	for(ll j=2; j<=h;j+=2){
    		ans+=((w - i + 1) * (h - j + 1));
        }
    }
    cout<<ans<<nl;	 	 	   			  	  	   	 		 		
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