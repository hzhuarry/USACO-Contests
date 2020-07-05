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

//if a cow is visited, then its component will not be 0
int N,M,needToChange,cow[100001],components[100001];

//which of the cows are already in the correct ordered spot
bool ordered[100001];

//first->neighbor , second->width
vector<pair<int,int> > adj[100001];


void dfs(int node,int w,int cmp){
    components[node]=cmp;
    for(auto u:adj[node]){
        if(components[u.first]==0&&w<=u.second){
            dfs(u.first,w,cmp);
        }
    }
}

bool ok(int width){
    memset(components,0,sizeof(components));
    
    //we want the cows out of order to be in the same component
    int cmp=1;
    for(int i=1;i<=N;++i){
        if(!ordered[i]&&components[i]==0){
            dfs(i,width,cmp++);
        }
    }
    
    //check if the unordered pairs are the grouped into the same components
    // if two cows are in the same component, that means they are able to use wrmholes to swap positions
    //if they are then this width is able to sort the cows
    //the ordered cows automatically have the same component as itself so we do not need to check them
    for(int i=1;i<=N;++i){
        if(!ordered[i]&&(components[i]!=components[cow[i]])){
            return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("wormsort.in");
    ofstream cout ("wormsort.out");
    
    cin>>N>>M;
    for(int i=1;i<=N;++i){
        cin>>cow[i];
        if(cow[i]!=i){
            needToChange++;
        }
        else
        {
            ordered[i]=1;
        }
        
    }
    for(int i=0;i<M;++i){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].pb(mp(b,w));
        adj[b].pb(mp(a,w));
    }
    if(needToChange==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    //bsearch the max width
    int lo=1,hi=1e9;
    while(lo<hi){
        int mid=(lo+hi+1)/2;
        if(ok(mid)){
            lo=mid;
        }
        else{
            hi=mid-1;
        }
    }
    cout<<lo<<endl;
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
    return 0;
}
