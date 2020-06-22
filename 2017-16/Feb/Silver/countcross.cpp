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

int N,K,R;
int grid[101][101];
bool vis[101][101];

//can also use binary hash and another 2d array to keep track of roads in O(1), my code searches for the road in O(n) using the find function
vpi roads[101][101];
int cowx[101],cowy[101];

void ff(int i,int j,int cmp)
{
    if(i<1||j<1||i>N||j>N||vis[i][j]){
        return;
    }
    vis[i][j]=1;
    grid[i][j]=cmp;
    for(int k=0;k<4;++k){
        int x=i+dx[k],y=j+dy[k];
        if(find(ALL(roads[i][j]),mp(x,y))==roads[i][j].end()){
            ff(x,y,cmp);
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin ("countcross.in");
    ofstream cout ("countcross.out");
    
    cin>>N>>K>>R;
    for(int i=0;i<R;++i){
        int a,b,x,y;
        cin>>a>>b>>x>>y;
        roads[a][b].pb(mp(x,y));
        roads[x][y].pb(mp(a,b));
    }
    for(int i=0;i<K;++i){
        cin>>cowx[i]>>cowy[i];
    }
    int cmp=0;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            if(!vis[i][j]){
                ff(i,j,++cmp);
            }
        }
    }
    int ans=0;
	  //if cows have diff components, they must be a distant pair
    for(int i=0;i<K;++i){
        for(int j=i+1;j<K;++j){
            if(grid[cowx[i]][cowy[i]]!=grid[cowx[j]][cowy[j]])
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
