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

int N,K;
int diamonds[500010];
int pre[500010],suf[500010];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("diamond.in");
    ofstream cout ("diamond.out");
    
    cin>>N>>K;
    for(int i=1;i<=N;++i){
        cin>>diamonds[i];
    }
    sort(diamonds+1,diamonds+N+1);
    int start=1;
    for(int end=1;end<=N;++end){
        while(start<end&&(diamonds[end]-diamonds[start]>K)){
            start++;
        }
        pre[end]=max(pre[end-1],end-start+1);
    }
    start=N;
    for(int end=N;end>0;--end){
        while(start>end&&abs(diamonds[start]-diamonds[end])>K){
            start--;
        }
        suf[end]=max(suf[end+1],start-end+1);
    }
    ll ans=0;
    for(int i=1;i<=N;++i){
        ans=max(ans,(ll)pre[i-1]+(ll)suf[i]);
    }
    cout<<ans<<endl;
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
    return 0;
}
