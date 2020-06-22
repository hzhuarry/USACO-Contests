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
typedef vector<ll> vl;

int N,M;
vi adj[3005];
bool close[3005];
bool vis[3005];
int num,cnt;

//find an open farm and dfs
int open()
{
    int x=distance(close,find(ALLA(close+1,N+1),0));
    return x;
}

void dfs(int n)
{
    vis[n]=1;
    for(auto u:adj[n]){
        if(!vis[u]&&!close[u]){
            dfs(u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream cout ("closing.out");
    ifstream cin ("closing.in");

    cin>>N>>M;
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    num=N;
    for(int i=0;i<N;++i){
        int c;
        cin>>c;
        if(i==N-1){
            cout<<"YES"<<endl;
            break;
        }
        for(int j=0;j<3006;++j)vis[j]=0;
        dfs(open());
        int x=count(ALLA(vis,3005),1);
        if(x==num)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        num--;
        close[c]=1;
    }
    return 0;
}
