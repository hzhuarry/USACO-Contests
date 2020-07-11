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

int N,ans;
char grid[5][5];
bool vis[5][5];

bool ok(int i,int j){
    return i>=0&&j>=0&&i<N&&j<N&&!vis[i][j];
}

void solve(int i,int j,int left,int right,bool secondPart){
    if(left==right){
        ans=max(ans,left+right);
        return;
    }
    if(secondPart&&(2*left<=ans)){
        return;
    }
    vis[i][j]=1;
    for(int k=0;k<4;++k){
        int ni=i+dx[k],nj=j+dy[k];
        if(ok(ni,nj)){
            if(grid[ni][nj]==')'){
                solve(ni,nj,left,right+1,true);
            }
            else if(!secondPart){
                solve(ni,nj,left+1,right,false);
            }
        }
    }
    vis[i][j]=0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    setIO("hshoe");
    cin>>N;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>grid[i][j];
        }
    }
    if(grid[0][0]=='('){
        solve(0,0,1,0,false);
    }
    cout<<ans<<endl;
    return 0;
}
