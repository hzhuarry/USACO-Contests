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

int X, Y, K, M,ans=101;
int vis[101][101];
set<int> s;

void dfs(int x,int y,int k){
    if((vis[x][y]>0&&k>=vis[x][y])||k>K) return;
    vis[x][y]=k;
    //add sums
    s.insert(x+y);
    //right to left
    if(x<=Y-y){
        dfs(0,x+y,k+1);
    }
    else{
        dfs(x-Y+y,Y,k+1);
    }
    
    //left to right
    if(y<=X-x){
        dfs(x+y,0,k+1);
    }
    else{
        dfs(X,y-X+x,k+1);
    }
    //fill left
    dfs(X,y,k+1);
    
    //fill right
    dfs(x,Y,k+1);
    
    //empty left
    dfs(0,y,k+1);
    
    //empty right
    dfs(x,0,k+1);
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("pails.in");
    ofstream cout ("pails.out");
    
    cin>>X>>Y>>K>>M;
    dfs(0,0,0);
    for(auto u=s.begin();u!=s.end();++u){
        ans=min(ans,abs(M-*u));
    }
    cout<<ans<<endl;
    return 0;
}
