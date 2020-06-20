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

int N;
vpll mountainRange;

bool cmp(const pll &a, const pll &b){
    if(a.f==b.f) return a.s>b.s;
    return a.f<b.f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin ("mountains.in");
    ofstream cout ("mountains.out");
    
    cin>>N;
    for(int i=0;i<N;++i){
        int x,y;
        cin>>x>>y;
        ll s=x-y,e=x+y;
        mountainRange.pb(mp(s,e));
    }
    sort(ALL(mountainRange),cmp);
    int ans=0;
    ll endPoint=-1;
    for(int i=0;i<N;++i){
        if(mountainRange[i].s<=endPoint)continue;
        endPoint=mountainRange[i].s;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
