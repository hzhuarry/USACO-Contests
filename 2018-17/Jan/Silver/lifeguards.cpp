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

int N;
vpii guard;
set<pii> times;

bool cmp(const pii& a,const pii &b){
    if(a.f==b.f) return a.s>b.s;
    return a.f<b.f;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("lifeguards.in");
    ofstream cout ("lifeguards.out");
    
    cin>>N;
    for(int i=0;i<N;++i)
    {
        int a,b;
        cin>>a>>b;
        times.insert({a,i});
        times.insert({b,i});
        guard.pb(mp(a,b));
    }
    vi seen(N,0),points(N,0);
    set<int> curr_work;
    int last=-1;
    for(auto& u:times){
        if(sz(curr_work)==1){
            points[*curr_work.begin()]+= u.f-last;
        }
        if(seen[u.s]){
            curr_work.erase(u.s);
        }
        else{
            curr_work.insert(u.s);
            seen[u.s]=1;
        }
        last=u.f;
    }
    int index=distance(points.begin(),min_element(ALL(points)));
    guard.erase(guard.begin()+index);
    sort(ALL(guard),cmp);
    ll ans=0;
    int lastPos=-1;
    for(int i=0;i<sz(guard);++i){
        if(i==0){
            ans+=(ll)(guard[i].s-guard[i].f);
            lastPos=guard[i].s;
        }
        else{
            //this means that theres an interval thats within the last interval and we do not need to consider this in our ans
            if(guard[i].s<=lastPos)continue;
            
            if(guard[i].f<lastPos){
                ans+=(ll)guard[i].s-lastPos;
                lastPos=guard[i].s;
            }
            else{
                ans+=(ll)guard[i].s-guard[i].f;
                lastPos=guard[i].s;
            }
        }
    }
    cout<<ans<<endl;
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
    return 0;
}
