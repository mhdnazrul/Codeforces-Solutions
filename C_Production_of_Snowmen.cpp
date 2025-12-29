#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    ll countAB = 0;
    for (int s = 0; s < n; s++) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] >= b[(i + s) % n]) {
                ok = false;
                break;
            }
        }
        if (ok) countAB++;
    }

    ll countBC = 0;
    for (int s = 0; s < n; s++) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (b[i] >= c[(i + s) % n]) {
                ok = false;
                break;
            }
        }
        if (ok) countBC++;
    }

    ll result = (ll)n * countAB * countBC;
    cout << result << endl;
}

int main() {
    FAST_IO
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}