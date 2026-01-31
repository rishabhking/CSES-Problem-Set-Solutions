#include <algorithm>
#include <bitset>
#include <complex>
#include <climits>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
 
typedef long long ll;
typedef unsigned int ull;
typedef long double lld;
 
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#endif
 
#define int long long
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
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
    int n,k; cin >> n >> k;
    vector<string> v(n);
    for(auto &it: v) cin >> it;
 
    vector<bool> ans(k,false);
    vector<vector<int>> row(k,vector<int>(n,0));
    // color row_numebr
 
    vector<int> color(k,1);
    for(int i=0;i<n;i++){
        vector<int> temp(k,0);
        for(int j=0;j<n;j++){
            temp[v[i][j]-'A']++;
        }
 
        for(int j=0;j<k;j++){
            if(temp[j]>0){
                row[j][i] = color[j]++;
            }
        }
    }
    vector<vector<deque<int>>> column(k,vector<deque<int>>(n));
    // color column_number row_number
    for(int j=0;j<n;j++){
        vector<vector<int>> temp(k);
        for(int i=0;i<n;i++){
            int val = (v[i][j]-'A');
            temp[val].push_back(i);
        }
        
        for(int i=0;i<k;i++){
            for(int l=0;l<((int)temp[i].size());l++){
                column[i][j].push_back(temp[i][l]);
            }
        }
    }
    
    // debug(column)
    
    for(int i=0;i<n;i++){
        vector<vector<int>> temp(k);
        for(int j=0;j<n;j++){
            int val = (v[i][j]-'A');
            temp[val].push_back(j);
        }
        
        for(int j=0;j<k;j++){
            if(ans[j]) continue;
            for(auto &l : temp[j]){
                int cc = row[j][i];
                int sz = column[j][l].size();
                if(sz > 0) column[j][l].pop_front();
                for(auto &m: column[j][l]){
                    if(row[j][m]<0){
                        ans[j] = true;
                        break;
                    }
                    row[j][m] = (-1)*abs(row[j][m]);
                }
                if(ans[j]) break;
            }
 
            if(ans[j] == false){
                for(auto &l : temp[j]){
                    int cc = row[j][i];
                    int sz = column[j][l].size();
                    for(auto &m: column[j][l]){
                        row[j][m] = abs(row[j][m]);
                    }
                    if(ans[j]) break;
                }
            }
        }
    }
    
    for(int i=0;i<k;i++){
        if(ans[i]) yes;
        else no;
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
