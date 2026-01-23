/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: https://codeforces.com/contest/1342/problem/B
  └────────────────────────────────────────────────────────────────────────────────────┘*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;       using ld=long double;
using vi=vector<int>;     using vll=vector<ll>;
using pii=pair<int,int>; using pll=pair<ll,ll>;
const ll INF = 2e18;   const int MOD = 1e9 + 7; 
#define per(i,a,b)  for(int i=(b)-1;i>=(a);--i)
#define rep(i,a,b)  for(int i=(a);i<(b);++i)
#define trav(a, x)     for (auto &a : x)
#define forr(i, n)       rep(i, 0, n)
#define all(x) (x).begin(),(x).end()
#define rall(x) rbegin(x),rend(x)
#define sz(x) (int)(x).size()
const char nl = '\n';
template<class T>    void inV(vector<T> &v){for(auto &x:v) cin>>x;}
template<typename T> void outV(const vector<T>& v) {if (v.empty()) return;
    for (int i = 0; i < sz(v); ++i)cout << v[i] << " \n"[i == sz(v) - 1];}

void run_case(){
    
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);          int T=1;
    if(!(cin >> T))     return 0;
    while(T--)        run_case();
    return 0;
}




#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repd(i,a,b) for(ll i=a;i>=b;i--)
#define all(sdk) sdk.begin(),sdk.end()
#define ll long long
#define ull unsigned long long 
#define mod 1000000007
#define sz(a) (ll)a.size()
#define vc vector
#define st set
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pop pop_back
#define gcd(a,b)    __gcd((a),(b))
#define PI 3.14159265
#define r0 return 0
#define printvector(v) for(int i= 0;i<v.size();i++) {cout<<v[i]<<" ";} cout<<endl;
#define printarr(a,n) for(int i=0;i<n;++i) {cout<<a[i]<<" ";} cout<<endl;
using namespace std;
void solve()
{
    ll n,k;
    ll m;
    string s;
    cin>>s;
    n=sz(s);
    ll a=0,b=0;
    rep(i,0,sz(s))
    {
        if(s[i]=='0')
            a++;
        else
        {
            b++;
        }
    }
    if(a==sz(s) || n==b || n<=2)
    {
        cout<<s<<endl;
        return;
    }
    string a1="10";
    rep(i,0,n)
    {
        cout<<a1;
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
    {
        solve();
    }
    return 0;
}
