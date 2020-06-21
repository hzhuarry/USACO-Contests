#include <bits/stdc++.h>
#include <fstream>

using namespace std;

#define endl "\n"
#define pf push_front
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define f first
#define s second
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PI 3.14159265358979323846264338327950L
#define lb lower_bound
#define ub upper_bound

typedef long long ll;
typedef long double ld;
typedef string str;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<ld> vd;
typedef vector<str> vs;

typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpd;

const int MOD = 1000000007;
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1}; //flood

int N,Q,ans;
vpii adj[5001];
bool vis[5001];

void dfs(int v,int k,int small){
    vis[v]=1;
    if(small>=k){
        ans++;
    }
    for(auto u:adj[v]){
        if(!vis[u.f]){
            dfs(u.f,k,min(small,u.s));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin ("mootube.in");
    ofstream cout ("mootube.out");
    cin>>N>>Q;
    for(int i=0;i<N-1;++i){
        int a,b,r;
        cin>>a>>b>>r;
        adj[a].pb(mp(b,r));
        adj[b].pb(mp(a, r));
    }
    for(int i=0;i<Q;++i){
        int k,v;
        cin>>k>>v;
        memset(vis, 0, sizeof(vis));
        ans=0;
        dfs(v,k,1e9);
        //decrement ans by one bec the starting node v is not counted in the final ans
        cout<<ans-1<<endl;
    }
    return 0;
}
