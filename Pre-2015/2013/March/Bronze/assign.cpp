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

int N,K;
int relation[16][16];
int cows[16];

//recursive search and backtracking
int solve(int id)
{
    int ans=0;
    if(id>N) return 1;

    for(int i=1;i<=3;++i){
        bool ok=1;
        //we check if this assingment is allowed
        for(int prev=1;prev<id;++prev){
            if(relation[prev][id]==1&&cows[prev]!=i||relation[prev][id]==2&&cows[prev]==i){
                //if its not allowed we break out of the loop
                ok=0;
                break;
            }
        }
        if(ok){
            cows[id]=i;
            ans+=solve(id+1);
            cows[id]=0;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    setIO("assign");
    cin>>N>>K;
    for(int i=0;i<K;++i){
        char ch;
        int a,b;
        cin>>ch>>a>>b;
        if(ch=='S'){
            relation[a][b]=1;
            relation[b][a]=1;
        }
        else{
            relation[a][b]=2;
            relation[b][a]=2;
        }
    }
    cout<<solve(1)<<endl;
    return 0;
}
