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
#define MOD 1000000007
#define lb lower_bound
#define ub upper_bound


typedef long long ll;
typedef long double ld;
typedef string str;

typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<ld> vd;
typedef vector<str> vs;

typedef vector<pi> vpi;
typedef vector<pll> vpl;
typedef vector<pld> vpd;

const int dx[4]= {-1,1,0,0},dy[4]= {0,0,-1,1}; //flood

int N,M,cnt;
//vis can 0,1,2
int vis[100001];
vi sameNeighbors[100001],diffNeighbors[100001];
bool possible=1;

void dfs(int i, int num){
    vis[i]=num;
    //check connected nodes with same neighbor
    for(int n:sameNeighbors[i])
    {
        //if the neighbors are diff, its impossible
        if(vis[n]==3-num){
            possible=0;
            return;
        }
        
        if(vis[n]==0) dfs(n,num);
    }
    //do the same for the diff neighbors
    for(int n: diffNeighbors[i])
    {
        if(vis[n]==num){
            possible=0;
            return;
        }
        
        if(vis[n]==0) dfs(n,3-num);
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin ("revegetate.in");
    ofstream cout ("revegetate.out");
    
    cin>>N>>M;
    for(int i=0;i<M;++i){
        char c;
        int a,b;
        cin>>c>>a>>b;
        if(c=='S'){
            sameNeighbors[a].pb(b);
            sameNeighbors[b].pb(a);
        }
        else if(c=='D'){
            diffNeighbors[a].pb(b);
            diffNeighbors[b].pb(a);
        }
    }
    
    for(int i=1;i<=N;++i){
        if(!vis[i]){
            dfs(i,1);
            cnt++;
        }
    }
    
    if(!possible){
        cout<<0<<endl;
    }
    else{
        cout<<1;
        //2^K == 1 with K 0s following
        for(int i=0;i<cnt;++i)cout<<0;
        cout<<endl;
    }
    return 0;
}
