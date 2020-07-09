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

int N,D;
pii cows[50000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    setIO("crowded");
    
    cin>>N>>D;
    for(int i=0;i<N;++i){
        cin>>cows[i].f>>cows[i].s;
    }
    SORTA(cows,N);
    multiset<int,greater<int> > rightWindow;
    int r=1;
    map<int,bool> crowd;
    for(int i=0;i<N-1;++i){
        if(i!=0){
            rightWindow.erase(rightWindow.find(cows[i].s));
        }
        while(r<N&&cows[r].f-cows[i].f<=D){
            rightWindow.insert(cows[r].s);
            ++r;
        }
        if(cows[i].s*2<=*rightWindow.begin()) crowd[cows[i].f]=1;
    }
    int l=N-2;
    multiset<int,greater<int> > leftWindow;
    map<int,bool> crowdL;
    for(int i=N-1;i>0;--i){
        if(i!=N-1){
           leftWindow.erase(leftWindow.find(cows[i].s)); 
        }
        while(l>=0&&abs(cows[l].f-cows[i].f)<=D){
            leftWindow.insert(cows[l].s);
            l--;
        }
        if(cows[i].s*2<=*leftWindow.begin()) crowdL[cows[i].f]=1;
    }
    int ans=0;
    for(auto it=crowdL.begin();it!=crowdL.end();++it){
        if(it->s){
            bool ok=crowd[it->f];
            if(ok) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
