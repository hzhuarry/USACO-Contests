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

int N,M;
vi adj[500001];
int cmp[500001];
//color[0] is useless
int color[3];
bool poss=1;

void dfs(int node,int c){
    cmp[node]=c;
    color[c]++;
    //visit all neighbors
    for(int neighbors:adj[node]){
        if(cmp[neighbors]==c){
            poss=0;
            return;
        }
        if(cmp[neighbors]==0){
            dfs(neighbors,3-c);
        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("decorate.in");
    ofstream cout ("decorate.out");
    
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int c=1;
    int ans=0;
    for(int i=1;i<=N;++i){
        //cmp will be either 1 or 2 if dfs has reached it
        if(cmp[i]==0){
            memset(color,0,sizeof(color));
            dfs(i,c);
            ans+=max(color[1],color[2]);
        }
    }
    if(!poss) cout<<-1<<endl;
    else{
        cout<<ans<<endl;
    }
    return 0;
}
