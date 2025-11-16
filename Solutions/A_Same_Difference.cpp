#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int ans = 1e9;

        for (char c = 'a'; c <= 'z'; c++) {

            vector<int> pos;
            for (int i = 0; i < n; i++)
                if (s[i] == c)
                    pos.push_back(i);

            if (pos.empty()) continue;

            int cost = 0;
            bool ok = true;

            for (int i = 0; i < n; i++) {
                if (s[i] == c) continue;

                int j = lower_bound(pos.begin(), pos.end(), i) - pos.begin();

                if (j == (int)pos.size()) {
                    ok = false;
                    break;
                }

                cost += pos[j] - i;
            }

            if (ok) ans = min(ans, cost);
        }

        cout << ans << "\n";
    }
}
