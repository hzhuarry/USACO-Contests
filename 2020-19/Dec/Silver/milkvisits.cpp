#include <bits/stdc++.h>
#include <fstream>

using namespace std;

#define endl "\n"
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
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int N,M,connected_component[100005],num;
char c[100005];
vi adj[100005];

void dfs(int x){
    if(connected_component[x])return;
    connected_component[x]=num;
    for(auto &u:adj[x]){
        if(c[u]==c[x]){
            dfs(u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream cout ("milkvisits.out");
    ifstream cin ("milkvisits.in");
    string s;
    cin>>N>>M>>s;
    for(int i=1;i<=N;++i){
        c[i]=s[i-1];
    }
    for(int i=0;i<N-1;++i){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=1;i<N+1;++i){
        if(!connected_component[i]){
            num++;
            dfs(i);
        }
    }
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;
        char ch;
        cin>>ch;
        if(c[a]==ch||connected_component[a]!=connected_component[b])
            cout<<1;
        else cout<<0;
    }
    cout<<endl;
    return 0;
}
