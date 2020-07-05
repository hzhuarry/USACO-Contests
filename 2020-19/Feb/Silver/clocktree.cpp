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
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpd;

const int MOD = 1000000007;
const ll INF=1e18;
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1};

//array a keeps the original clock orientation and clocks will be changed and reset for each dfs
int N,a[2501],clocks[2501],ans;
bool vis[2501];
vi adj[2501];

// helper function to reset the clocks to their original positions when dfs each starting node
void resetClocks(){
    for(int i=1;i<=N;++i){
        clocks[i]=a[i];
    }
}

//graph is 1 index so node with parent 0 is the starting node
void dfs(int node, int parent=0){
    vis[node]=1;
    //going down the dfs, we must increment the nodes we see not including the starting node
    if(parent>0){
        clocks[node]++;
        if(clocks[node]>12){
            clocks[node]=clocks[node]-12;
        }
    }
    //dfs the node's children
    for(int n:adj[node]){
        if(!vis[n]){
            dfs(n,node);
        }
    }
    //after reaching the leaves, we simulate the process and work our way up the nodes
    //if parent is greater than 0, this means that it is not the starting node
    if(parent>0){
        //we assume the child becomes 12 and we change the parent accordingly
        //we have to add one to "go back to the parent"
        clocks[parent]+=12-clocks[node]+1;
        if(clocks[parent]>12){
            clocks[parent]=clocks[parent]-12;
        }
    }
}

bool ok(int node){
    resetClocks();
    memset(vis,0,sizeof(vis));
    dfs(node);
    return (clocks[node]==12||clocks[node]==1);
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("clocktree.in");
    ofstream cout ("clocktree.out");
    
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>a[i];
    }
    for(int i=1;i<N;++i){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(int i=1;i<=N;++i){
        //try each node
        if(ok(i)){
            ans++;
        }
    }
    cout<<ans<<endl;
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
    return 0;
}
