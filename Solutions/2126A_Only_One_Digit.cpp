/*┌──────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7
  │                        >   Author:- Nazrul Islam
  │Problem Link: https://codeforces.com/problemset/problem/2126/A
  └──────────────────────────────────────────────────────────────────────────┘*/
#include <bits/stdc++.h>
using namespace std;
 
void run_case() {
    int n; cin >> n;
    int mn=INT_MAX;
    while(n>0){
        int x = n%10;
        mn = min(mn, x);
        n /= 10;
    }
    cout << mn << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) run_case();
    return 0;
}