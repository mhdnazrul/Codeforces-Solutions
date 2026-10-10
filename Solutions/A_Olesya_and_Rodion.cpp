/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/problemset/problem/584/A
  └────────────────────────────────────────────────────────────────────────────────────┘*/
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)

void run_case(){
    int n,t;    cin>>n>>t;
    if(t==10){
        if(n>1)--n;
        else {
            cout<<"-1\n";
            return;
        }
    }
    cout<<t;
    for(int i=0; i<n-1; i++){
        cout<<"0";
    }
    cout<<'\n';
}

int32_t main(){
    fastio();      int T=1; 
    //if(!(cin>>T))  return 0;
    while(T--)     run_case();
    return 0;
}
