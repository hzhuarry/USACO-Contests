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

int n,barns[1000];
queue<int> start;

int sim(int b){
    bool filled[1000]={0};
    int t=0,total=0;
    while(t<n){
        for(int i=0;i<barns[b];++i){
            int cnt=0,curr=b;
            while(filled[curr]){
                curr=(curr+1)%n;
                cnt++;
            }
            filled[curr]=1;
            total+=(cnt*cnt);
        }
        ++t; b=(b+1)%n;
    }
    return total;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("cbarn.in");
    ofstream cout ("cbarn.out");
    
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>barns[i];
        if(barns[i]!=0){
            start.push(i);
        }
    }
    int ans=1e9;
    while(!start.empty()){
        int curr=start.front();
        start.pop();
        ans=min(sim(curr),ans);
    }
    cout<<ans<<endl;
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
    return 0;
}
