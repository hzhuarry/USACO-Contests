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
const ll INF=1e16;
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1};

int L,N,rf,rb;
vpii stops;

bool cmp(const pii &a, const pii &b){
    return a.s>b.s;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("reststops.in");
    ofstream cout ("reststops.out");
    
    cin>>L>>N>>rf>>rb;
    for(int i=0;i<N;++i){
        int x,c;
        cin>>x>>c;
        stops.pb(mp(x,c));
    }
    ll ans=0;
    sort(ALL(stops),cmp);
    int bessie=0;
    for(int i=0;i<N;++i){
        int x=stops[i].f;
        if(x<bessie)continue;
        ll t1=(ll)(x-bessie)*rb, t2=(ll)(x-bessie)*rf;
        ll diff=t2-t1;
        ans+=diff*stops[i].s;
        bessie=x;
    }
    cout<<ans<<endl;
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
    return 0;
}

