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

int n;
int x[200],y[200],pw[200];
bool vis[200];

bool check(int i,int j)
{
    if(i==j||vis[j])return 0;
    double dis=sqrt(pow(abs(x[i]-x[j]),2)+pow(abs(y[i]-y[j]),2));
    return dis<=(double)pw[i];
}

//dfs 
int reach(int i)
{
    vis[i]=1;
    int cnt=1;
    for(int s=0;s<n;++s){
        if(check(i,s)){
            cnt+=reach(s);
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream cout ("moocast.out");
    ifstream cin ("moocast.in");

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x[i]>>y[i]>>pw[i];
    }
    int ans=0;
    for(int i=0;i<n;++i){
        memset(vis,0,sizeof(vis));
        //for(int j=0;j<200;++j)vis[j]=0;
        ans=max(ans,reach(i));
    }
    cout<<ans<<endl;
    return 0;
}
