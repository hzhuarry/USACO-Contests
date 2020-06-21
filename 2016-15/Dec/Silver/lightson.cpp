#include <bits/stdc++.h>
#include <fstream>

using namespace std;

#define endl "\n"
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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
int dx[4]= {-1,1,0,0},dy[4]= {0,0,-1,1}; //ff

int n,m;
bool on[100][100],vis[100][100];
vector<pair<int,int> > switches[100][100];

bool isVisited(int x,int y)
{
    return x >= 0 && x < 100 && y >= 0 && y < 100 && vis[x][y];
}

bool isOn(int x,int y)
{
    return x>=0&&x<100&&y>=0&&y<100&&on[x][y];
}

bool hasVisitedNeighbor(int x,int y)
{
    for(int k=0;k<4;++k)
    {
        if(isOn(x+dx[k],y+dy[k])&&isVisited(x+dx[k],y+dy[k])){
            return true;
        }
    }
    return false;
}

void searchDfs(int x,int y)
{
    if(isVisited(x,y))return;
    vis[x][y]=true;
    for(int i=0;i<switches[x][y].size();++i)
    {
        pair<int,int> next=switches[x][y][i];
        if(!on[next.first][next.s])
        {
            on[next.f][next.s]=true;
            if(hasVisitedNeighbor(next.f,next.s))
            {
                searchDfs(next.f,next.s);
            }
        }
    }
    for(int k=0;k<4;++k){
        int nx=x+dx[k],ny=y+dy[k];
        if(isOn(nx,ny))
        {
            searchDfs(nx,ny);
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream cout ("lightson.out");
    ifstream cin ("lightson.in");

    cin>>n>>m;
    for(int i=0;i<m;++i){
        int a,b,x,y;
        cin>>a>>b>>x>>y;
        a-=1;
        b-=1;
        x-=1;
        y-=1;
        switches[a][b].pb(mp(x,y));
    }
    on[0][0]=true;
    searchDfs(0,0);
    int ans=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(on[i][j]) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
