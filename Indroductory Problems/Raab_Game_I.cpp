#include<bits/stdc++.h>
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
 
void pri(deque<int> &p, deque<int> &q){
    for(auto &it: p) cout << it << " ";
    cout << endl;
    for(auto &it: q) cout << it << " ";
    cout << endl;
    return;
}
 
void solve(){
    int n,a,b; cin >> n >> a >> b;
 
    if(a==b && b==0){
        yes;
        for(int i=1;i<=n;i++) cout << i << " ";
        cout << endl;
 
        for(int i=1;i<=n;i++) cout << i << " ";
        cout << endl;
        return;
    }
 
    if(a==0 || b==0 || (a+b>n)){
        no;return;
    }
 
    deque<int> p(n),q(n);
    for(int i=0;i<n;i++){
        p[i] = q[i] = i+1;
    }
 
    int l = a+b-1;
    int aa = 1 , bb = l;
 
    deque<int> v(l+1);
    for(int i=0;i<l+1;i++){
        v[i] = i+1;
    }   
 
    v.pop_front();
    v.push_back(1);    
 
    // pri(p,v);
 
    while(bb!=b){
        int x = v.front();
        v.pop_front();
        v.push_back(x);
        aa++;
        bb--;
    }
 
    int sz = v.size();
    for(int m = sz; v.size()<n; m++){
        v.push_back(m+1);
    }
 
    // pri(p,v);
 
    aa = 0 , bb = 0;
    for(int i=0;i<n;i++){
        if(p[i] > v[i]) aa++;
        else if(p[i] < v[i]) bb++;
    }   
 
    if(aa!=a || bb!=b){
        no;return;
    }
    else{
        yes;
        for(int i=0;i<n;i++){
            cout << p[i] << " ";
        }
        cout << endl;
 
        for(int i=0;i<n;i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}
 
signed main(){
fastio();
 
int t=1; cin >> t;
while(t--){
    solve();
}
 
    return 0;
}