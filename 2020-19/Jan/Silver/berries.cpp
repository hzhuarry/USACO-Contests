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

int N,K,ans,bTrees[1000];

int solve(int capacity){
    vi baskets;
    for(int i=0;i<N;++i){
        if(bTrees[i]<=capacity){
            baskets.pb(bTrees[i]);
        }
        else{
            int times=bTrees[i]/capacity;
            int remain=bTrees[i]%capacity;
            for(int j=0;j<times;++j){
                baskets.pb(capacity);
            }
            if(remain!=0){
                baskets.pb(remain);
            }
        }
    }
    sort(baskets.rbegin(),baskets.rend());
    int bessiesShare=0;
    //in-case baskets has less than K values
    while(sz(baskets)<K){
        baskets.pb(0);
    }
    for(int i=K/2;i<K;++i){
        bessiesShare+=baskets[i];
    }
    return bessiesShare;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("berries.in");
    ofstream cout ("berries.out");
    
    cin>>N>>K;
    for(int i=0;i<N;++i) cin>>bTrees[i];
    int maxCapacity=*max_element(bTrees,bTrees+N);
    for(int i=1;i<=maxCapacity;++i){
        ans=max(ans,solve(i));
    }
    cout<<ans<<endl;
    return 0;
}
