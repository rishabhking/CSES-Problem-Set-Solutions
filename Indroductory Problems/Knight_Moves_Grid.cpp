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
 
bool isSafe(int i,int j,int n,vector<vector<int>> &vis){
    if(i>=n || j>=n || j<0 || i<0) return false;
    if(vis[i][j] != -1) return false;
    return true;
}
 
void solve(){
    int n; cin >> n;
    vector<vector<int>> vis(n,vector<int>(n,-1));
 
    vector<pair<int,int>> v = {{1,2},{2,1},{-1,2},{-2,1},{1,-2},{-1,-2},{2,-1},{-2,-1}};
 
    deque<pair<int,int>> q;
    q.push_back({0,0});
    vis[0][0] = 0;
 
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
 
        q.pop_front();
 
        for(auto &it: v){
            int i = x+it.first , j = y+it.second;
            if(isSafe(i,j,n,vis)){
                vis[i][j] = vis[x][y] + 1;
                q.push_back({i,j});
            }
        }
    }
 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << vis[i][j] << " ";
        }cout << endl;
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