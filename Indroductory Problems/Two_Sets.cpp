#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned int ull;
typedef long double lld;
 
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
#ifdef ONLINE_JUDGE
#define debug(x)
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#else
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#endif
 
#define int long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define setbits(x)  __builtin_popcountll(x)
 
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
 
const int MAXN = 2e6;
const int MOD = 1e9 + 7;
int fac[MAXN + 1];
int inv[MAXN + 1];
int exp(int x,int n,int m){x%=m;int res = 1; while(n>0){if(n%2==1){res=res*x%m;}x=x*x%m;n/=2;}return res;}
void factorial(){fac[0]=1;for(int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }}
void inverses() {inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % MOD; }}
int choose(int n, int r) { if(r>n)return 0ll;return (fac[n] * inv[r] % MOD * inv[n - r] % MOD)%MOD;}
 
// int div(int a,int b,int m){
//     return ((a%m)*(bin(b,m-2,m)%m))%m ;
// }
 
void solve(){
    int n; cin >> n;
    if(((n+1)/2)%2!=0) no;
    else{
        if(n%2==0){
            yes;
            cout << n/2 << endl;
            for(int i=1;i<=n/2;i+=2){
                cout << i << " " << n - i + 1 << " ";
            }
            cout << endl;
            cout << n/2 << endl;
            for(int i=2;i<=n/2;i+=2){
                cout << i << " " << n - i + 1 << " ";
            }
        }
        else{
            yes;
            vector<int> a,b;
            int p = 1 , q = 3;
            a.push_back(p);
            a.push_back(++p);
            b.push_back(q);
 
            p=4,q=5;
            while(p<=n && q<=n){
                a.push_back(p);
                b.push_back(q);
                p+=2;
                q+=2;
                // cout << p << " " <<  q << endl;
                swap(p,q);
            }
            // debug(a);
            // debug(b);
 
            cout << a.size() << endl;
            for(auto &it: a) cout << it << " ";
            cout << endl;
            cout << b.size() << endl;
            for(auto &it: b) cout << it << " ";
        
        
        }
    }
}
 
signed main(){
fastio();
 
int t=1; 
while(t--){
    solve();
}
 
    return 0;
}