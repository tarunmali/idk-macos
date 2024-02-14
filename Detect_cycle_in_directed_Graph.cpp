#include <iostream>
using namespace std;
#define ll long long
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include 

ll n;
stack<ll> st;

ll sum(ll i,ll j, vector<ll> &ps){
    ll ans=ps[j];
    if(i!=0) ans-=ps[i-1];
    return ans;
}


void f(){
    for(ll x: v){
        cout<<x<<" ";
    } 
    // ll n=v.size();
    // vector<ll> ps(n);
    // ps[0]=v[0];
    // for(ll i=1;i<n;i++){
    //     ps[i]=ps[i-1]+v[i];
    // }
    // ll min_sum=LONG_MAX;
    // ll i_ans,j_ans;
    // for(ll i=0;i<n;i++){
    //     for(ll j=i+2;j<n;j++){
    //         if(v[i]==v[j] and sum(i,j-1,ps)<min_sum){
    //             i_ans=i;
    //             j_ans=j-1;
    //         }
    //     }
    // }
    // sort(v.begin()+i_ans,v.begin()+j_ans+1);
    // for(ll i=i_ans;i<=j_ans;i++){
    //     cout<<v[i]+1<<" ";
    // }
    // cout<<'\n';
}

bool dfs(ll node, ll par,vector<ll> al[],vector<bool> &vis){
    vis[node]=1;
    v.push_back(node);

    for(ll nei:al[node]){
        if(!vis[nei]){
            if(dfs(nei,node,al,vis)){
                return 1;
            } 
        } 
        else if(par!=nei){
            v.push_back(nei);
            return 1;
        }
    }
    
    v.pop_back();
    return 0;
}

void solve(){
    ll e;
    cin>>n>>e;
    vector<ll> al[n];
    vector<bool> vis(n,0);
    while(e--){
        ll u,v;
        cin>>u>>v;
        u--,v--;
        al[u].push_back(v);
        // al[v].push_back(u);
    }
    for(ll i=0;i<n;i++){
        if(!vis[i]) if(dfs(i,-1,al,vis)){
            f();
            return;
        };
    }
    cout<<""<<'\n';
}


int main(){
    ll ttt;
    ttt=1;
    // cin>>ttt;
    while(ttt--){
        solve();
    }
}