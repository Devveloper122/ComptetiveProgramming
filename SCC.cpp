#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frr(i,a,b) for(ll i=a;i>=b;i--)
#define endl '\n'
#define sz(x) (ll)x.size()
#define vl vector<ll>
#define pb push_back
#define rt return
#define pll pair<ll,ll>
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define print(x) for(auto it:x) {cout<<it<<" ";}cout<<endl;
#define vvprint(v) for(auto it: v){ for(auto it1: it){ cout<<it1<<" ";} cout<<endl;}
#define M1 1000000007
#define M2 998244353
const ll inf = 1e18;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef ONLINE_JUDGE
 #define cerr cout//erropen
 #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
 #define mdebug(...) cerr <<"[" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__);cerr<<"]";cerr<<endl;
#else
 #define debug(x)
 #define mdebug(...)
#endif

void _print(ll t) {cerr << t;}
void _print(bool t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename Head, typename... Tail> void _print(const Head &H, const Tail &...T) {_print(H);if (sizeof...(T))cerr << ", ";_print(T...);}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

#define msb(n) (64 - __builtin_clzll(n))
ll pwr(ll a,ll b){ ll prd=1; while(b--){ prd*=a; } return prd; }
ll __lcm(ll a,ll b){ return ((a/__gcd(a,b))*b);}
ll getRand(ll a, ll b) {return a+ (rand()%(b-a+1));}

void toposort(ll node, vector<vector<ll>> &adj, vector<ll> &ordering, vector<bool> &visited){
    visited[node] = 1;
    for(auto it: adj[node]){
        if(!visited[it]){
            toposort(it, adj, ordering, visited);
        }
    }
    ordering.pb(node);
}

void findSCC(ll node, vector<vector<ll>> &Tadj, vector<bool> &visited, vector<ll> &vec){
    visited[node] = 1;
    vec.pb(node);
    for(auto it: Tadj[node]){
        if(!visited[it]){
            findSCC(it, Tadj, visited, vec);
        }
    }
}

vector<vector<ll>> SCC(ll n, vector<vector<ll>> &adj, vector<vector<ll>> &Tadj){
    vector<bool> visited(n+1,0);
    vector<ll> ordering;

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            toposort(i, adj, ordering, visited);
        }
    }

    visited.assign(n+1,0);

    vector<vector<ll>> ans;
    for(int i=ordering.size()-1; i>=0; i--){
        if(!visited[ordering[i]]){
            vector<ll> vec;
            findSCC(ordering[i], Tadj, visited, vec);
            ans.pb(vec);
        }
    }

    return ans;
}



void solve() {
    ll n,m;
    cin>>n>>m;

    vector<vector<ll>> adj(n+1), Tadj(n+1);
    fr(i,0,m){
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        Tadj[b].pb(a);
    }

    vector<vector<ll>> fadj = SCC(n, adj, Tadj);
 
}
 
int main() {
 
#ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 freopen("o_error.txt", "w", stderr);
#endif // ONLINE_JUDGE
 
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    ll tc;
    tc=1;
    // cin>>tc;
    cout<< fixed << setprecision(6) ;
    while(tc--){
        solve();
    }
    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms"<<endl;
return 0;
}