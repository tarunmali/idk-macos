#include <iostream>
using namespace std;
#define ll long long
ll rr,cc;
ll ma[20][5];
ll ans;

void f(ll safe_rows,ll r,ll c, bool bomb_used, ll coins){
    if(r<0 or c<0 or c>=5){
        ans=max(ans,coins);
        return;
    } 
    if(ma[r][c]==1 or ma[r][c]==0){
        if(ma[r][c]==1) coins++;
        if(bomb_used) safe_rows--;
        f(safe_rows,r-1,c-1,bomb_used,coins);
        f(safe_rows,r-1,c,bomb_used,coins);
        f(safe_rows,r-1,c+1,bomb_used,coins);
    }
    else{
        if(bomb_used and safe_rows<=0){
            ans=max(ans,coins);
            return;           
        }
        else if(bomb_used and !safe_rows<=0){
            safe_rows--;
            f(safe_rows,r-1,c-1,bomb_used,coins);
            f(safe_rows,r-1,c,bomb_used,coins);
            f(safe_rows,r-1,c+1,bomb_used,coins);
        }
        else{
            bomb_used=1;
            safe_rows=4;
            f(safe_rows,r-1,c-1,bomb_used,coins);
            f(safe_rows,r-1,c,bomb_used,coins);
            f(safe_rows,r-1,c+1,bomb_used,coins);
        }
    }
}

void solve(ll tttt){
    cc=5;
    cin>>rr;
    for(ll i=0;i<rr;i++){
        for(ll j=0;j<cc;j++){
            cin>>ma[i][j];
        }
    }
    ans=0;
    f(0,rr-1,1,0,0);
    f(0,rr-1,2,0,0);
    f(0,rr-1,3,0,0);
    cout<<'#'<<tttt<<" "<<ans<<'\n';
}


int main(){
    ll ttt;
    ttt=1;
    cin>>ttt;
    ll tttt=0;
    while(ttt--){
        solve(++tttt);
    }
}