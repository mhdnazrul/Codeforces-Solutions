// problem link:https://codeforces.com/contest/2172/problem/E
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }
string CHECK_all_Permutation(string s, int idx) {
    sort(s.begin(), s.end());
    idx--;         
    while(idx--) 
        next_permutation(s.begin(), s.end());
    return s;
}
void solve() {
    string n;
    int j, k;
    cin >> n >> j >> k;
    string a = CHECK_all_Permutation(n, j);
    string b = CHECK_all_Permutation(n, k);

    int A = 0, ln = a.size();
    for (int i = 0; i < ln; i++)
        if (a[i] == b[i]) A++;

    int B = ln - A;
    cout << A << "A" << B << "B\n";
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
