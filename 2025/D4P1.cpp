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

    vector<string> v;
    string s;
    int m;
    while(getline(cin,s)){
        v.pb(s);
        m = s.size();
    }

    int n = v.size();

    int dx[8] = {0,0,1,1,1,-1,-1,-1};
    int dy[8] = {1,-1,0,1,-1,0,1,-1};

    int ans = 0;
    
    for(int x=0; x<n; ++x){
        for(int y=0; y<m; ++y){
            int cnt = 0;
            if(v[x][y] == '.') continue;
            for(int k=0; k<8; ++k){
                int X = x + dx[k];
                int Y = y + dy[k];
                if(X >= 0 && X < n && Y >= 0 && Y < m){
                    if(v[X][Y] == '@') cnt++;
                }
            }
            if(cnt <= 3) ans++; 
        }        
    }

    cout<<ans;

}
