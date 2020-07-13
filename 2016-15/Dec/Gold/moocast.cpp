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

int N;
pii coord[1000];
bool vis[1000];

int dfs(int i,double d){
    int cnt=1;
    vis[i]=1;
    for(int cow=0;cow<N;++cow){
        if(i==cow)continue;
        if(!vis[cow]){
            int x1=coord[i].f,y1=coord[i].s;
            int x2=coord[cow].f,y2=coord[cow].s;
            int a=abs(x2-x1),b=abs(y2-y1);
            int c=a*a+b*b;
            double dist=sqrt((double)c);
            if(dist<=d){
                cnt+=dfs(cow,d);
            }
        }
    }
    return cnt;
}

bool ok(int x){
    memset(vis,0,sizeof(vis));
    double d=sqrt((double)x);
    if(dfs(0,d)==N){
        return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    setIO("moocast");
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>coord[i].f>>coord[i].s;
    }
    int lo=0,hi=1e9;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(ok(mid)){
            hi=mid;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<lo<<endl;
    return 0;
}
