/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/problemset/problem/1878/C
  └────────────────────────────────────────────────────────────────────────────────────┘*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;   
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)
ll sum(ll z){
    return z*(z+1)/2;
}
void run_case(){
    ll n,k,x;   cin>>n>>k>>x;
    ll sum1 = sum(k);
    ll sum2 = sum(n);
    sum2 -= sum(n-k);
    cout << (sum1 <=x && x<=sum2 ?"YES\n":"NO\n");
    // << "\n";
}

int32_t main(){
    fastio();      int T=1; 
    if(!(cin>>T))  return 0;
    while(T--)     run_case();
    return 0;
}

