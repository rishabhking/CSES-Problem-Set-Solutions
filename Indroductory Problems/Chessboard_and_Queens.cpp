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
vector<string> v;
vector<vector<int>> queen(8,vector<int>(8,0));
 
bool isSafe(int x,int y){
    if(x>=8 || x<0 || y<0 || y>=8 ){
        return false;
    }
    if(v[x][y]=='*' || queen[x][y]==1) return false;
    for(int i=0;i<8;i++){
        if(queen[x][i]==1) return false;
        if(queen[i][y]==1) return false;
    }
 
    int n = x , m = y;
    while(n>=0 && m>=0){
        if(queen[n][m]==1) return false;
        n--;m--;
    }
 
     n = x , m = y;
    while(n>=0 && m<8){
        if(queen[n][m]==1) return false;
        n--;m++;
    }
 
    n = x , m = y;
    while(n<8 && m>=0){
        if(queen[n][m]==1) return false;
        n++;m--;
    }
 
    n = x , m = y;
    while(n<8 && m<8){
        if(queen[n][m]==1) return false;
        n++;m++;
    }
 
    return true;
}
 
int func(int i,int count){
    if(count==8) return 1;
    if(i>=8) return 0;
    int ct = 0;
    for(int j=0;j<8;j++){
        if(isSafe(i,j)){
            queen[i][j] = 1;
            ct+=func(i+1,count+1);
            queen[i][j] = 0;
        }
    }
    return ct;
}
 
void solve(){
    for(int i=0;i<8;i++){
        string s; cin >> s; v.push_back(s);
    }
    cout << func(0,0) << endl;
}
 
signed main(){
fastio();
 
int t=1; 
while(t--){
    solve();
}
 
    return 0;
}