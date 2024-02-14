#include <iostream>
using namespace std;
#define ll long long
#include <cstring>

ll ma[50][50],vis[50][50];
ll rr,cc,ri,ci,l;

struct Node{
    ll x,y,l;
};
Node q[1000001];
ll front,back;
void init(){
    front=0,back=0;
}
void push(Node temp){
    q[back++]=temp;
}
Node pop(){
    return q[front++];
}
bool empty(){
    return front == back;
}
bool valid(ll x,ll y){
    return (x>=0 && x<rr && y>=0 && y<cc);
}


bool left(ll x,ll y){
    return (ma[x][y]==1 || ma[x][y]==3 || ma[x][y]==6 || ma[x][y]==7);
}
bool right(ll x,ll y){
    return (ma[x][y]==1 || ma[x][y]==3 || ma[x][y]==4 || ma[x][y]==5);
}
bool up(ll x,ll y){
    return (ma[x][y]==1 || ma[x][y]==2 || ma[x][y]==4 || ma[x][y]==7);
}
bool down(ll x,ll y){
    return (ma[x][y]==1 || ma[x][y]==2 || ma[x][y]==6 || ma[x][y]==5);
}


ll f(){
    ll ans=0;
    push({ri,ci,l});
    vis[ri][ci]=1;
    while(!empty()){
        Node n=pop();
        ll tx=n.x,ty=n.y,tl=n.l;
        ll x=n.x,y=n.y,l=n.l;
        if(tl==0) continue;
        ans++;
        if(valid(tx,ty-1) and !vis[tx][ty-1] and right(tx,ty-1) and left(tx,ty)){
            push({tx,ty-1,tl-1});
            vis[tx][ty-1]=1;
        }

        if(valid(x,y+1) && right(x,y) && left(x,y+1) && vis[x][y+1]==0){
            push({x,y+1,l-1});
            vis[x][y+1]=1;
        }
        if(valid(x-1,y) && up(x,y) && down(x-1,y) && vis[x-1][y]==0){
            push({x-1,y,l-1});
            vis[x-1][y]=1;
        }
        if(valid(x+1,y) && down(x,y) && up(x+1,y) && vis[x+1][y]==0){
            push({x+1,y,l-1});
            vis[x+1][y]=1;
        }

    }
    return ans;
}

void solve(){
    memset(vis, 0, sizeof vis);
    cin>>rr>>cc>>ri>>ci>>l;
    for(ll i=0;i<rr;i++){
        for(ll j=0;j<cc;j++){
            cin>>ma[i][j];
        }
    }
    if(ma[ri][ci]>0){
        init();
        cout<<f()<<'\n';
        return;
    }
    cout<<0<<'\n';
    

}


int main(){
    ll ttt;
    ttt=1;
    cin>>ttt;
    while(ttt--){
        solve();
    }
}