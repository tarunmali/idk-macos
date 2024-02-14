#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
#define ll long long

ll ma[12][12];
ll n;
ll visited_all;
ll mem[4096][12];

ll f(ll mask, ll pos){
    if(mem[mask][pos]!=-1) return mem[mask][pos];
    if(mask==visited_all) return ma[pos][0];
    ll ans=LLONG_MAX;
    for(ll city=0;city<n;city++){
        if((mask & (1<<city))==0){
            ll newAns=ma[pos][city]+f((mask | (1<<city)),city);
            ans=min(ans,newAns);
        }
    }
    return mem[mask][pos]=ans;
}

void solve(){
    memset(mem, -1,sizeof mem);
    cin>>n;
    visited_all=(1<<n)-1;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>ma[i][j];
        }
    }
    cout<<f(1,0)<<'\n';
}


int main(){
    ll ttt;
    ttt=1;


    cin>>ttt;
    while(ttt--){
        solve();
    }
}