#include <bits/stdc++.h>
#include <fstream>

using namespace std;

#define endl "\n"
#define sz(x) (int)x.size()
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
typedef vector<char> vch;
typedef vector<str> vs;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;

const int MOD = 1000000007;
const ll INF=1e18;
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1};

void setIO(string filename) {
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
}

int N,M;
vi adj[200001];
int closing[200001],parent[200001],size[200001];
bool vis[200001],works[200001];

void init(int N){
    for(int i=0;i<N;++i){
        parent[i]=i;
        size[i]=1;
    }
}

int find(int x){
    if(x==parent[x]){
        return x;
    }
    else{
        return parent[x]=find(parent[x]);
    }
}

void merge(int a,int b){
    int c=find(a);
    int d=find(b);
    if(c!=d){
        parent[d]=c;
        size[c]+=size[d];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    setIO("closing");

    cin>>N>>M;
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=0;i<N;++i){
        cin>>closing[i];
    }
    init(N);
    //start merging from the last farm to be closed
    for(int i=N-1;i>=0;--i){
        int currBarn=closing[i];
        vis[currBarn]=1;
        for(int connectedBarn:adj[currBarn]){
            if(vis[connectedBarn])
                merge(currBarn,connectedBarn);
        }
        if(size[find(currBarn)]==N-i){
            works[i]=1;
        }
        else{
            works[i]=0;
        }
    }
    for(int i=0;i<N;++i){
        if(works[i])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
