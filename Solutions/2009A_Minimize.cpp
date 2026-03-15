/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/problemset/problem/2009/A
  └────────────────────────────────────────────────────────────────────────────────────┘*/
#include <bits/stdc++.h>
using namespace std;
void run_case(){
    int a,b;        cin>>a>>b;
    int ans = b-a;
    cout<<ans<<'\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);          int T=1;
    if(!(cin >> T))     return 0;
    while(T--)        run_case();
    return 0;
}

