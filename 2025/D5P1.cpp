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

    vector<pair<int,int>> v;
    string s;
    while(getline(cin,s)){

        if(s.empty()) break;
        string n1 = "";
        for(auto c : s){
            if(c == '-') break;
            n1 += c;
        }

        string n2 = s.substr(n1.size()+1, s.size() - n1.size() - 1);
        int x = stoll(n1);
        int y = stoll(n2);
        v.pb({x,y});

    }

    int ans = 0;

    while(getline(cin,s)){
        int n = stoll(s);
        for(auto pr : v){
            int l = pr.first;
            int r = pr.second;
            if(l <= n && n <= r){
                ans++;
                break;
            }
        }
    }

    cout<<ans;

}
