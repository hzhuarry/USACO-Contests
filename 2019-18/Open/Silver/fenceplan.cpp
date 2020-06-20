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

const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1}; //flood

struct box{
    int x1,x2;
    int y1,y2;
};

int N,M;
vpi C;
vi nbrs[100000];
bool vis[100000];

void ff(int i, int cmp, box &b)
{
    vis[i]=cmp;
    b.x1=min(b.x1,C[i].f);
    b.x2=max(b.x2,C[i].f);
    b.y1=min(b.y1,C[i].s);
    b.y2=max(b.y2,C[i].s);
    for(auto u:nbrs[i]){
        if(vis[u]==0){
            ff(u,cmp,b);
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin ("fenceplan.in");
    ofstream cout ("fenceplan.out");
    
    cin>>N>>M;
    for(int i=0;i<N;++i){
        int x,y;
        cin>>x>>y;
        C.pb(mp(x,y));
    }
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;
        nbrs[a-1].pb(b-1);
        nbrs[b-1].pb(a-1);
    }
    
    int cmp=1,ans=1e9;
    for(int i=0;i<N;++i){
        if(vis[i]==0){
            box b={99999999,0,99999999,0};
            ff(i,cmp,b);
            ans=min(ans,2*(b.x2-b.x1+b.y2-b.y1));
        }
    }
    cout<<ans<<endl;
    return 0;
}
