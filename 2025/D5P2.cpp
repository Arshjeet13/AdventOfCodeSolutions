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

    sort(all(v));
    vector<pair<int,int>> unionv;

    int i = 0;
    while(i < v.size()){
        int j = i + 1;
        int l = v[i].first;
        int r = v[i].second;

        while(j < v.size() && v[j].first <= r){
            r = max(r, v[j].second);
            j++;
        }

        unionv.pb({l,r});
        i = j;
    }

    int ans = 0;

    for(auto pr : unionv){
        ans += pr.second - pr.first + 1;  
    }  

    cout<<ans;    

}
