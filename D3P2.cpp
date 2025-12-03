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

int p(int n){
    int ans = 1;
    while(n--) ans *= 10;
    return ans;
}

signed main(){
    fast();

    vector<vector<int>> v;

    int m; 
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

    int n = v.size();

    int ans = 0;

    for(int i=0; i<n; ++i){
        
        int dp[m+10][15];

        for(int j=0; j<m; ++j){
            for(int x=0; x<=12; ++x) dp[j][x] = 0;
        }
        for(int j=0; j<m; ++j){
            dp[j][0] = 0;
            dp[j][1] = v[i][j];
        }

        //dp[j][x] means the longest number of length x starting at j

        for(int j=m-1; j>=0; --j){
            for(int k=j+1; k<m; ++k){
                for(int x=2; x<=12; ++x){
                    if(k + x - 2 >= m || j + x - 1 >= m) continue;
                    dp[j][x] = max(dp[j][x], dp[k][x-1] + v[i][j]*p(x-1));
                }               
            }
        }

        int mx = 0;

        for(int j=0; j<m; ++j){
            mx = max(mx, dp[j][12]);
        }

        ans += mx;

    }

    cout<<ans;


}
