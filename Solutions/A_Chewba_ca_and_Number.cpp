// problem link:https://codeforces.com/problemset/problem/514/A
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x; cout << '\n'; }

void solve() {
    string n;    cin >> n;
    ll ln = n.size();
    vector<char> arr(ln);
    for (int i = 0; i < ln; i++) {
        if (i == 0 && n[i] == '9') {
            arr[i] = n[i];
        }
        else if (n[i] >= '5') {
            arr[i] = '9' - n[i] + '0';
        }
        else
            arr[i] = n[i];
    }
    printV(arr);
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