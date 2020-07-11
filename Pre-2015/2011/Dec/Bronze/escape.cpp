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
typedef vector<char> vch;
typedef vector<str> vs;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;

const int MOD = 1000000007;
const ll INF=1e18;
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1};

void setIO(string filename) {
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
}

int N,ans;
int weights[20];

bool carries(int cow,int sum){
    int weight=weights[cow];
    while(weight>0&&sum>0){
        int d1=weight%10;
        int d2=sum%10;
        if(d1+d2>=10) return 1;
        weight/=10; sum/=10;
    }
    return 0;
}

void solve(int cow=0,int sum=0,int cnt=0){
    if(cnt>ans)ans=cnt;
    if(cow>=N)return;
    if(!carries(cow,sum)){
        solve(cow+1,sum+weights[cow],cnt+1);
    }
    solve(cow+1,sum,cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    setIO("escape");
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>weights[i];
    }
    solve();
    cout<<ans<<endl;
    return 0;
}
