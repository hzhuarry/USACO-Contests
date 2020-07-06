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

int N;
vpii particles;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("moop.in");
    ofstream cout ("moop.out");
    
    cin>>N;
    for(int i=0;i<N;++i){
        int x,y;
        cin>>x>>y;
        particles.pb(mp(x,y));
    }
    SORT(particles);
    vi minYVal(N),maxYVal(N);
    int small=1e9,big=-1e9;
    for(int i=0;i<N;++i){
        small=min(small,particles[i].s);
        minYVal[i]=small;
    }
    for(int i=N-1;i>=0;--i){
        big=max(big,particles[i].s);
        maxYVal[i]=big;
    }
    int components=1;
    for(int i=0;i<N-1;++i){
        if(minYVal[i]>maxYVal[i+1]){
            components++;
        }
    }
    cout<<components<<endl;
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
    return 0;
}
