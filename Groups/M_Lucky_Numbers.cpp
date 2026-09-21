/*
    author  : nazrulislam_7
    created : 
problem Name:  M. Lucky Numbers
problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/M
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
int a,b;
cin>>a>>b;

vector<int> lucky_numbers;

for(int i=1; i<=100000; i++){
    string s = to_string(i);
    bool is_lucky = true;

    for(char c : s){
        if(c != '4' && c != '7'){
            is_lucky = false;
            break;
        }
    }

    if(is_lucky) lucky_numbers.push_back(i);
}

int cnt = 0;
for(int x : lucky_numbers){
    if(x >= a && x <= b){
        cout << x << ' ';
        cnt++;
    }
}

if(cnt == 0) cout << -1;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);

solve();
}
