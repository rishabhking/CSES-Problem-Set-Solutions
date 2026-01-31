#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
 
void solve(){
    int n; cin >> n;
    while(n!=1){
        cout << n << " ";
        if(n%2){
            n = 3*n+1;
        }
        else n=n/2;
    }
    cout << "1\n";
}
 
signed main(){
fastio();
 
int t=1; 
while(t--){
    solve();
}
 
    return 0;
}