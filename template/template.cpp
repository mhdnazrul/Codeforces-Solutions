/*┌────────────────────────────────────────────────────────────────────────────────────┐
  │                        >   Handle:- nazrulislam_7             
  │                        >   Author:- Nazrul Islam                   
  │Problem Link: 
  └────────────────────────────────────────────────────────────────────────────────────┘*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long; using ld=long double;
using vi=vector<int>; using vll=vector<ll>;
using pii=pair<int,int>; using pll=pair<ll,ll>;
const ll INF = 2e18; const int MOD = 1e9 + 7;
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define trav(x, v) for (auto &x : v)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
const char nl = '\n';
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll modpow(ll b, ll e, ll m = MOD) { ll r = 1; b %= m; 
while(e){ if(e&1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }
template<typename T> vector<T> prefix_sum(const vector<T>& v) 
{ vector<T> p(sz(v)+1, 0); rep(i,0,sz(v)) p[i+1] = p[i] + v[i]; return p; }
template<class T> void Vin(vector<T> &v){for(auto &x:v) cin>>x;}
template<typename T> void Vout(const vector<T>& v) {if (v.empty()) return;
    for (int i = 0; i < sz(v); ++i)cout << v[i] << " \n"[i == sz(v) - 1];}

void run_case(){
    int n;
    cin >> n;
    vi arr(n);
    Vin(arr);Vout(arr);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;    cin >> T;
    while(T--)run_case();
    return 0;
}

