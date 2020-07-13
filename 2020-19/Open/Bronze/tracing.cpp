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
#define ar array

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

struct DSU{
    vi parent,size;
    void init(int N){
        parent.resize(N),size.resize(N);
        for(int i=0;i<N;++i){
            parent[i]=i;
            size[i]=1;
        }
    }
    int find_set(int x){
        if(parent[x]==x) return x;
        return parent[x]=find_set(parent[x]);
    }
    int set_size(int x){
        return size[find_set(x)];
    }
    bool same_set(int a,int b){
        return find_set(a)==find_set(b);
    }
    void merge(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int N,T;
str s;
bool infected[101];
vector<ar<int,3> > v;
set<int> possCow,possK;

bool ok(int cow,int k)
{
    //try with this cow as a patient zero
    bool tmp[101]={0};
    int num_shakes[101]={0};
    tmp[cow]=1;
    for(auto u:v){
       int cow1=u[1],cow2=u[2];
       if(tmp[cow1])num_shakes[cow1]++;
       if(tmp[cow2])num_shakes[cow2]++;
       if(num_shakes[cow1]<=k&&tmp[cow1])tmp[cow2]=1;
       if(num_shakes[cow2]<=k&&tmp[cow2])tmp[cow1]=1;
    }
    for(int i=1;i<=N;++i){
        if(infected[i]!=tmp[i]) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    setIO("tracing");
    cin>>N>>T>>s;
    for(int i=0;i<T;++i){
        int t,a,b;
        cin>>t>>a>>b;
        v.push_back({t,a,b});
    }
    SORT(v);
    for(int i=0;i<N;++i){
        char ch=s[i];
        if(ch=='1'){
            infected[i+1]=1;
        }
    }
    for(int cow=1;cow<=N;++cow){
        for(int k=0;k<=T;++k){
            if(ok(cow,k)){
                possCow.insert(cow);
                possK.insert(k);
            }
        }
    }
    int numCows=sz(possCow);
    int kmin,kmax;
    kmin=*possK.begin();
    kmax=*possK.rbegin();
    if(kmax==T){
        cout<<numCows<<" "<<kmin<<" "<<"Infinity"<<endl;
    }
    else{
        cout<<numCows<<" "<<kmin<<" "<<kmax<<endl;
    }
    return 0;
}
