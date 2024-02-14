#include <iostream>
using namespace std;
#define ll long long
#include <climits>

ll x[12],y[12];
ll cost[12][12];
ll now;
ll xi,yi,xf,yf;
ll n;




void solve(){
    cin>>now;
    n=2*now+2;
    cin>>xi>>yi>>xf>>yf;
    x[0]=xi,y[0]=yi,x[1]=xf,y[1]=yf;
    for(ll i=2;i<n;i=i+2){
        cin>>x[i]>>y[i]>>x[i+1]>>y[i+1];
        ll tmp;
        cin>>tmp;
        cost[i][i+1]=cost[i+1][i]=tmp;
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if((i>=2 and j>=2) and ((i%2==0 and j%2) or (i%2 and j%2==0))) cost[i][j]=LLONG_MAX;
            ll  tmp=abs(x[i]-x[j])+abs(y[i]-y[j]);
            cost[i][j]=cost[j][i]=tmp;
        }
    }


}


int main(){
    ll ttt;
    ttt=1;
    cin>>ttt;
    while(ttt--){
        solve();
    }
}