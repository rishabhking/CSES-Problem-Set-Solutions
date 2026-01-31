#include <bits/stdc++.h>
using namespace std;
 
#define int long long 
 
signed main(){
    int n , x ; cin >> n >> x;
    vector<int> v(n);
    for(auto &it: v) cin >> it;
 
    //step1 sort then divide in 2 parts
    //step2 use pointer on 1st array then take lowerbound to find sum
    //find feasible answer in O(n*(2^(n/2))) == 4*10^7 better than O(2^n)
 
    sort(v.begin(),v.end());
 
    vector<int> a,b;
    int l1 = (n+1)/2;
    int l2 = n - l1;
    for(int i=0;i<(1ll<<l1);i++){
        int y = i;
        int sum = 0;
        for(int j=0;j<l1;j++){
            if(y & (1ll<<j)){
                sum = (sum + v[j]);
            }
        }
        a.push_back(sum);
    }
 
    for(int i=0;i<(1ll<<l2);i++){
        int y = i;
        int sum = 0;
        for(int j=0;j<l2;j++){
            if(y & (1ll<<j)){
                sum = (sum + v[l1+j]);
            }
        }
        b.push_back(sum);
    }
    // for(auto &it: a) cout << it << " ";
    // cout << endl;
    // for(auto &it: b) cout << it << " ";
    // cout << endl;
    // sort(a.begin(),a.end());
    sort(b.begin(),b.end());
 
    int ans = 0;
    for(int i=0;i<a.size();i++){
        int y = upper_bound(b.begin(),b.end(),(x-a[i])) - lower_bound(b.begin(),b.end(),(x-a[i]));
        // cout << y << " ";
        ans += y;
    }
    cout << ans << endl;
}
