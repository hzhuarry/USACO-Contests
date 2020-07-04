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

int N,ans;
int pos[100001];
int vis[100001];

void dfs(int i){
    set<int> s;
    while(vis[i]==0){
        s.insert(i);
        vis[i]=1;
        i=pos[i];
    }
    //check for cycle
    if(s.find(i)!=s.end()){
        int curr=i;
        do{
            //mark every position within the cycle;
            vis[i]=2;
            i=pos[i];
        }while(i!=curr);
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("shuffle.in");
    ofstream cout ("shuffle.out");
    
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>pos[i];
    }
    for(int i=1;i<=N;++i){
        if(vis[i]==0){
            dfs(i);
        }
    }
    for(int i=1;i<=N;++i){
        //we can only be sure of a position if its in a cycle
        if(vis[i]==2){
            ans++;
        }
    }
    cout<<ans<<endl;
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
    return 0;
}
