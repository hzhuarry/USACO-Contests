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


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("pairup.in");
    ofstream cout ("pairup.out");
    
    ll n;
    cin>>n;
    vpll v;
    for(ll i=0;i<n;++i){
        ll m,c;
        cin>>m>>c;
        v.pb(mp(c,m));
    }
    //its always optimal to pair the smallest with the largest to get the smallest possible time
    SORT(v);
    ll ans=0;
    int start=0,finish=n-1,cnt1=0,cnt2=0;
    //simulates every single pairing but can be optimized by speeding up the pairing process
    while(start<=finish){
        if(start==finish){
            //check once
            ll sum=2*v[start].f;
            ans=max(ans,sum);
            break;
        }
        if(cnt1>v[start].s){
            cnt1=0;
            start++;
        }
        if(cnt2>v[finish].s){
            cnt2=0;
            finish--;
        }
        ll sum=v[start].f+v[finish].f;
        cnt1++;
        cnt2++;
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
    return 0;
}
