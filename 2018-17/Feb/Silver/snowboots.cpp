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

int N,B,snow[250],si[250],di[250],ans=251;
//first param:the location, second param: the boot
bool vis[250][250]; //did we visit(try) this location using this boot?

void dfs(int loc,int boot){
    vis[loc][boot]=1;
    if(loc==N-1){
        //since it is 0 index, the boots disgarded would equal the current boot's index
        ans=min(ans,boot);
        return;
    }
    //try all steps forward
    for(int step=loc+1;step<N&&step-loc<=di[boot];++step){
        if(!vis[step][boot]&&snow[step]<=si[boot]){
            dfs(step,boot);
        }
    }
    //try all boots after the current boot
    for(int nxt=boot+1;nxt<B;++nxt){
        if(snow[loc]<=si[nxt]&&!vis[loc][nxt]){
            dfs(loc,nxt);
        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("snowboots.in");
    ofstream cout ("snowboots.out");
    
    cin>>N>>B;
    for(int i=0;i<N;++i){
        cin>>snow[i];
    }
    for(int i=0;i<B;++i){
        cin>>si[i]>>di[i];
    }
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}
