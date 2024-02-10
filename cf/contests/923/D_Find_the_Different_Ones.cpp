#include <bits/stdc++.h>
using namespace std;
#define it(v) v.begin(),v.end()
#define ll long long
#define vl vector<long long> 
#define vvl vector<vector<long long>> 
#define nl '\n'
#define lld long double
#define ull unsigned long long  
#define iinp(n) long long n; cin>>n;
#define sinp(s) string s; cin >> s ;cin.ignore();
#define vinp(name,size) vector<ll>name (size); for(int i=0;i<size;i++) {cin>>name[i];}
template<typename... T> void pri(T&&... args){((cout << args <<" "), ...);cout<<'\n';}
template<typename... T> void inp(T&... args){((cin >> args and cin.ignore()), ...);}
void priv(vector<ll> &v){for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<'\n';}
void _pri(ll t) {cerr << t<<" ";}
void _pri(string t) {cerr << t;}
void _pri(char t) {cerr << t;}
void _pri(lld t) {cerr << t;}
void _pri(double t) {cerr << t;}
void _pri(ull t) {cerr << t;}  
 
template <class T, class V> void _pri(pair <T, V> p);
template <class T> void _pri(vector <T> v);
template <class T> void _pri(set <T> v);
template <class T, class V> void _pri(map <T, V> v);
template <class T> void _pri(multiset <T> v);
template <class T, class V> void _pri(pair <T, V> p) {_pri(p.first); cerr << " "; _pri(p.second); cerr << '\n';}
template <class T> void _pri(vector <T> v) {for (T i : v){_pri(i);}cerr <<'\n';}    
template <class T> void _pri(set <T> v) {for (T i : v) {_pri(i); } cerr << '\n';}
template <class T> void _pri(multiset <T> v) {for (T i : v) {_pri(i);} cerr << '\n';}
template <class T, class V> void _pri(map <T, V> v) {for (auto i : v) {_pri(i);} cerr <<'\n';}
#define mod 1000000007  
ll moda(ll a, ll b, ll cm=mod) {a = a % cm; b = b % cm; return (((a + b) % cm) + cm) % cm;}
ll modm(ll a, ll b, ll cm=mod) {a = a % cm; b = b % cm; return (((a * b) % cm) + cm) % cm;}
ll mods(ll a, ll b, ll cm=mod) {a = a % cm; b = b % cm; return (((a - b) % cm) + cm) % cm;}
int mpow(int base, int exp, long long cmod=mod){base %= cmod;long long result = 1;while (exp > 0) {if (exp & 1) result = ((long long)result * base) % cmod;base = ((long long)base * base) % cmod;exp >>= 1;}return result;}    
ll mminvprime(ll a, ll b) {return mpow(a, b - 2, b);}
ll modd(ll a, ll b, ll cm=mod) {a = a % cm; b = b % cm; return (modm(a, mminvprime(b, cm), cm) + cm) % cm;}


vl nextdiff(vl &v){
    ll n=v.size();
    stack<ll> st;
    st.push(0);
    vector<ll> nge(n,n);
    for(ll i=1;i<n;i++){
    while(!st.empty() and v[i]!=v[st.top()]){
    //the current element which came is greater then the top element, as long as it is greater then the top element of stack, it will be nge of that element
        nge[st.top()]=i;
        st.pop();
    }
    st.push(i);
    }
    return nge;
}

vl prevdiff(vl &v){
    ll n=v.size();
    stack<ll> st;
    st.push(n-1);
    vector<ll> nge(n,-1);
    for(ll i=n-2;i>=0;i--){
    while(!st.empty() and v[i]!=v[st.top()]){
    //the current element which came is greater then the top element, as long as it is greater then the top element of stack, it will be nge of that element
        nge[st.top()]=i;
        st.pop();
    }
    st.push(i);
    }
    return nge;
}

void solve(){
    iinp(n);
    vinp(v,n);   
    vl next=nextdiff(v);
    vl prev=prevdiff(v);
    iinp(q);
    while(q--){
       ll l,r;
       inp(l,r);
       l--,r--;         
        if(next[l]>r and prev[l]<l){
            pri(-1,-1);
        }
        else if(next[l]<=r){
            pri(l+1,next[l]+1);
        }
        else{
            pri(prev[r]+1,r+1);            
        }    
    }
    pri(); 
}



int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("/Users/idk/Developer/input.txt", "r", stdin);
    freopen("/Users/idk/Developer/output.txt", "w", stdout);
    freopen("/Users/idk/Developer/error.txt", "w", stderr);
    #endif

    int ttt;
    ttt=1;
    cin>>ttt;
    int ccc=ttt;
    while(ttt--){
        // cout<<"Case "<<(ccc-ttt)<<":"<<" ";
        solve();
    } 
    cerr<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;

}
