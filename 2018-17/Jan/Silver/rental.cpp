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

int N,M,R;
int cow[100000];
pii buy[100000];
int rent[100000];
ll bought[100000];

bool cmp(const pii& a, const pii& b)
{
    return a.s<b.s;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("rental.in");
    ofstream cout ("rental.out");
    
    cin>>N>>M>>R;
    for(int i=0;i<N;++i){
        cin>>cow[i];
    }
    for(int i=0;i<M;++i){
        cin>>buy[i].f>>buy[i].s;
    }
    for(int i=0;i<R;++i){
        cin>>rent[i];
    }
    sort(cow,cow+N);
    sort(buy,buy+M,cmp);
    sort(rent,rent+R,greater<int>());
    int j=M-1;
    for(int i=N-1;i>=0;--i){
        int curr=cow[i];
        ll cnt=0;
        while(curr>0&&j>=0){
            if(buy[j].f>curr){
                cnt+=curr*buy[j].s;
                buy[j].f-=curr;
                curr=0;
            }
            else{
                cnt+=buy[j].f*buy[j].s;
                curr-=buy[j].f;
                buy[j].f=0;
                --j;
            }
        }
        bought[i]=cnt;
    }
    ll ans=0;
    for(int i=0;i<N;++i)
    {
        ans+=max((ll)bought[i],(ll)rent[i]);
    }
    cout<<ans<<endl;
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
    return 0;
}
