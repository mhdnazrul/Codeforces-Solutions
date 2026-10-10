/*┌──────────────────────────────────────────────────────────────────────────┐
  │           >   Handle: nazrulislam_7  ||  Author: Nazrul Islam
  |           Problem: H. Complete the Word
  │           Problem Link: https://codeforces.com/gym/707857/problem/H
  └──────────────────────────────────────────────────────────────────────────┘*/
#include <bits/stdc++.h>
using namespace std;
using ll  = long long;using ld  = long double;using vi  = vector<int>;
using vll = vector<ll>;using pii = pair<int,int>;using pll = pair<ll,ll>;
using ull = unsigned long long; // using i128 = __int128; // only use C++ 20 or up
constexpr ll INF = 1'000'000'000'000'000'000LL;  constexpr int MOD = 1'000'000'007;
#define rep(i,a,b)  for(int i=(a);i<(b);++i)
#define per(i,a,b)  for(int i=(b)-1;i>=(a);--i)
#define all(x)      (x).begin(),(x).end()
#define rall(x)     (x).rbegin(),(x).rend()
#define sz(x)       (int)(x).size()
#define fi          first
#define se          second
inline void yes() { cout << "YES\n"; }
inline void no()  { cout << "NO\n";  }
template<class T> void Vin(vector<T>& v){ for (auto& x : v) cin >> x; }
template<class T> void Vout(const vector<T>& v) {
    rep(i, 0, sz(v)) cout << v[i] << " \n"[i == sz(v) - 1];
}
// ──────────────────────────────────Solution──────────────────────────────────

void run_case() {
    string s; cin>>s;
    int n = sz(s);
    if (n < 26) {
        cout <<"-1\n";
        return;
    }

    for (int i = 0; i <= n - 26; i++) {
        set<char> word;
        int cnt = 0;
        rep(j, 0, 26) {
            if (s[i + j] != '?') {
                word.insert(s[i + j]);
                cnt++;
            }
        }

        if (word.size() == cnt) {
            vector<char> missing;
            for (char ch = 'A'; ch <= 'Z'; ch++) {
                if (word.find(ch) == word.end()) {
                    missing.push_back(ch);
                }
            }

            int idx = 0;
            for (int j = 0; j < 26; j++) {
                if (s[i + j] == '?') {
                    s[i + j] = missing[idx++];
                }
            }

            for (int k = 0; k < n; k++) {
                if (s[k] == '?') {
                    s[k] = 'A';
                }
            }

            cout << s << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
   // cin >> T;
    while (T--) run_case();
    return 0;
}
