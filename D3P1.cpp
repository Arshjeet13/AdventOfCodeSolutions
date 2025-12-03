#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define fast() ios::sync_with_stdio(false); cin.tie(NULL)
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

signed main(){
    fast();

    vector<vector<int>> v;

    int n,m; 
    string s;

    while(getline(cin,s)){
        m = s.size();
        vector<int> x;
        for(int i=0; i<m; ++i){
            int num = s[i] - '0';
            x.pb(num);
        }
        v.pb(x);
    }

    int ans = 0;
    n = v.size();

    for(int i=0; i<n; ++i){
        int mx = 0;
        for(int j=0; j<m; ++j){
            for(int k=j+1; k<m; ++k){
                int val = 10*v[i][j] + v[i][k];
                mx = max(mx, val);
            }
        }
        ans += mx;
    }

    cout<<ans;
}