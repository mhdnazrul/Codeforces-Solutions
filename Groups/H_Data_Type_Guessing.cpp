// problem link:https://codeforces.com/group/MWSDmqGsZm/contest/326175/problem/H
// Author: nazrulislam_7
#include<bits/stdc++.h>
using namespace std;
int main()
{
	double N,K,A;	cin>>N>>K>>A;
	double result = (N*K) / A;
	long long LL_NUM = result;
	double myRes = result - LL_NUM;
	if(myRes > 0){
		cout<<"double"<<endl;
	}else if(LL_NUM <= 2147483647){
		cout<<"int"<<endl;
	} else {
		cout<<"long long"<<endl;
	}
}