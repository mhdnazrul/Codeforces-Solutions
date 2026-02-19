// problem link:https://codeforces.com/contest/2166/problem/C
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
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max_idx = max_element(a.begin(), a.end()) - a.begin();
    rotate(a.begin(), a.begin() + max_idx, a.end());
    a.push_back(a[0]);
    vector<long long> left_val(n + 1), right_val(n + 1);
    vector<int> st;
    st.push_back(0);
    for (int i = 1; i < n; i++) {
        while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
        if (st.empty()) {
            left_val[i] = a[0];
        } else {
            left_val[i] = a[st.back()];
        }
        st.push_back(i);
    }
    st.clear();
    st.push_back(n);
    for (int i = n - 1; i >= 1; i--) {
        while (!st.empty() && a[st.back()] < a[i]) st.pop_back();
        right_val[i] = a[st.back()];
        st.push_back(i);
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        ans += min(left_val[i], right_val[i]);
    }
    cout << ans << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    if(!(cin>>test_cases)) return 0;
    for(int tc = 1; tc <= test_cases; tc++){
    // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}
