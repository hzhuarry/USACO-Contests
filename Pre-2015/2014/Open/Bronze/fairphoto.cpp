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

int N,ans;
pair<int,char> cows[100000];
map<int,int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("fairphoto.in");
    ofstream cout ("fairphoto.out");
    
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>cows[i].f>>cows[i].s;
    }
    SORTA(cows,N);
    //first find all same cows using 2pointer
    int start=0;
    for(int end=0;end<N;++end){
        if(cows[end].s!=cows[start].s){
            ans=max(ans,cows[end-1].f-cows[start].f);
            start=end;
        }
    }
    int sum=0;
    m[0]=0;
    for(int i=0;i<N;++i){
        int pos=cows[i].f;
        char breed=cows[i].s;
        if(breed=='G')sum++;
        else sum--;

        if(m.find(sum)==m.end()){
            m[sum]=i+1;
        }
        else{
            ans=max(ans,pos-cows[m[sum]].f);
        }
    }
    cout<<ans<<endl;
    return 0;
}
