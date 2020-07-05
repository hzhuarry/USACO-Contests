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

int N, grid[250][250];
bool vis[250][250];

int ff(int i,int j, int id){
    if(i<0||j<0||i>=N||j>=N||vis[i][j]||grid[i][j]!=id) return 0;
    vis[i][j]=1;
    int c=1;
    for(int k=0;k<4;++k) c+=ff(i+dx[k],j+dy[k],id);
    return c;
}

int ff2(int i,int j,int id1,int id2){
    if(i<0||j<0||i>=N||j>=N||vis[i][j]||(grid[i][j]!=id1&&grid[i][j]!=id2)) return 0;
    vis[i][j]=1;
    int c=1;
    for(int k=0;k<4;++k) c+=ff2(i+dx[k],j+dy[k],id1,id2);
    return c;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin ("multimoo.in");
    ofstream cout ("multimoo.out");
    
    cin>>N;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>grid[i][j];
        }
    }
    
    int ans1=0;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(!vis[i][j]){
                int x=ff(i,j,grid[i][j]);
                ans1=max(x, ans1);
            }
        }
    }
    cout<<ans1<<endl;
    
    int ans2=0;
    for(int i=0;i<N;++i){
        for(int j=1;j<N;++j){
            if(grid[i][j]!=grid[i][j-1]){
                memset(vis, 0, sizeof(vis));
                int x=ff2(i,j,grid[i][j],grid[i][j-1]);
                ans2=max(ans2,x);
                
                //cant be any bigger than the whole grid so we stop filling and looking
                if(ans2==N*N){
                    cout<<ans2<<endl;
                    return 0;
                }
                
            }
        }
    }
    cout<<ans2<<endl;
    return 0;
}
