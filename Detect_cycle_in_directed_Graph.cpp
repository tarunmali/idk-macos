#include <iostream>
using namespace std;
#define ll long long
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <stack>

ll n;
stack<ll> st;
ll sum;



void f(){
    //incomplete
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
}

bool dfs(ll node,vector<ll> al[],vector<bool> &vis, vector<bool> &rsFlag){
    vis[node]=1;
    st.push(node);
    rsFlag[node]=1;
    for(ll nei:al[node]){
        if(!vis[nei]){
            if(dfs(nei,al,vis,rsFlag)){
                return 1;
            } 
        } 
        if(rsFlag[node]){
            //successfully find the cycle
            st.push(node);
            //run the logic to extract the present found cycleinfo
            f();
        }
    }
    st.pop();
    rsFlag[node]=0;
    return 0;
}

void solve(){
    sum=LLONG_MAX;
    ll e;
    cin>>n>>e;
    vector<ll> al[n];
    vector<bool> vis(n,0),rsFlag(n,0);
    while(e--){
        ll u,v;
        cin>>u>>v;
        u--,v--;
        al[u].push_back(v);
    }
    for(ll i=0;i<n;i++){
        if(!vis[i]) dfs(i,al,vis,rsFlag);
    }
}


int main(){
    ll ttt;
    ttt=1;
    // cin>>ttt;
    while(ttt--){
        solve();
    }
}