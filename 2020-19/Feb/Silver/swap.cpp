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

int N,M,K;
vpii interval;

void swap(vi& v){
    for(auto p:interval){
        reverse(v.begin()+p.f,v.begin()+p.s+1);
    }
}

void mapTo(vi& a, vi b){
    for(int i=0;i<N;++i){
        a[i]=b[a[i]];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("swap.in");
    ofstream cout ("swap.out");
    
    cin>>N>>M>>K;
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b, a--,b--;
        interval.pb(mp(a,b));
    }
    vi applyTo(N);
    vi ans(N);
    for(int i=0;i<N;++i){
        applyTo[i]=i;
        ans[i]=i;
    }
    swap(applyTo);
    while(K>0){
        if(K&1){
            mapTo(ans,applyTo);
        }
        K>>=1;
        mapTo(applyTo,applyTo);
    }
    for(int i=0;i<N;++i){
        cout<<ans[i]+1<<endl;
    }
    return 0;
}
