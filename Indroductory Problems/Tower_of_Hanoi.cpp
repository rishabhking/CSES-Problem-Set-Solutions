#include<bits/stdc++.h>
using namespace std;
 
vector<pair<int,int>> v;
 
void tower_of_hentai(int n,int src,int dest,int helper){
    if(n==0) return ;
    tower_of_hentai(n-1,src,helper,dest);
    v.push_back({src,dest});
    tower_of_hentai(n-1,helper,dest,src);
}
 
void solve(){
    int n; cin >> n;
 
    tower_of_hentai(n,1,3,2);
    cout << v.size() << "\n";
    for(auto &it: v) cout << it.first << " " << it.second << endl;
}
 
signed main(){
 
int t=1; 
while(t--){
    solve();
}
 
    return 0;
}
