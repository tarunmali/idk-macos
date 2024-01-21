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
void _pri(ll t) {cout << t<<" ";}
void _pri(string t) {cout << t;}
void _pri(char t) {cout << t;}
void _pri(lld t) {cout << t;}
void _pri(double t) {cout << t;}
void _pri(ull t) {cout << t;}  
 
template <class T, class V> void _pri(pair <T, V> p);
template <class T> void _pri(vector <T> v);
template <class T> void _pri(set <T> v);
template <class T, class V> void _pri(map <T, V> v);
template <class T> void _pri(multiset <T> v);
template <class T, class V> void _pri(pair <T, V> p) {_pri(p.first); cout << " "; _pri(p.second); cout << '\n';}
template <class T> void _pri(vector <T> v) {for (T i : v){_pri(i);}cout <<'\n';}    
template <class T> void _pri(set <T> v) {for (T i : v) {_pri(i); } cout << '\n';}
template <class T> void _pri(multiset <T> v) {for (T i : v) {_pri(i);} cout << '\n';}
template <class T, class V> void _pri(map <T, V> v) {for (auto i : v) {_pri(i);} cout <<'\n';}
#define mod 1000000007  
ll moda(ll a, ll b, ll cm=mod) {a = a % cm; b = b % cm; return (((a + b) % cm) + cm) % cm;}
ll modm(ll a, ll b, ll cm=mod) {a = a % cm; b = b % cm; return (((a * b) % cm) + cm) % cm;}
ll mods(ll a, ll b, ll cm=mod) {a = a % cm; b = b % cm; return (((a - b) % cm) + cm) % cm;}
int mpow(int base, int exp, long long cmod=mod){base %= cmod;long long result = 1;while (exp > 0) {if (exp & 1) result = ((long long)result * base) % cmod;base = ((long long)base * base) % cmod;exp >>= 1;}return result;}    
ll mminvprime(ll a, ll b) {return mpow(a, b - 2, b);}
ll modd(ll a, ll b, ll cm=mod) {a = a % cm; b = b % cm; return (modm(a, mminvprime(b, cm), cm) + cm) % cm;}

vvl f(vl &v){
    ll n=v.size();
    ll m1=-1,m2=-1,m3=-1;
    for(ll i=0;i<n;i++){
        if(m1==-1 or v[i]>v[m1]){
            m3=m2;
            m2=m1;
            m1=i;
        }
        else if(m2==-1 or v[i]>v[m2]){
            m3=m2;            m2=i;
        }
        else if(m3==-1 or v[i]>v[m3]){
            m3=i;
        }
    }
    return {{v[m1],m1},{v[m2],m2},{v[m3],m3}};
}

void solve(){
    iinp(n);
    vinp(a,n);
    vinp(b,n);
    vinp(c,n);
    vvl aa,bb,cc;
    aa=f(a);
    bb=f(b);
    cc=f(c);
    ll ans=LLONG_MIN;
    for(auto va: aa){
        for(auto vb: bb){
           for(auto vc: cc){
               if(va[1]==vb[1] or va[1]==vc[1] or vb[1]==vc[1]) continue;
               ans=max(ans,va[0]+vb[0]+vc[0]);
           }
            
        }
    }
    pri(ans);
}




int32_t main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
