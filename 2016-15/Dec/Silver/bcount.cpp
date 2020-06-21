#include <bits/stdc++.h>
#include <fstream>

using namespace std;

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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int N,Q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream cout ("bcount.out");
    ifstream cin ("bcount.in");

    cin>>N>>Q;
    vi h(N+1),g(N+1),j(N+1);
    for(int i=1;i<=N;++i){
        int x;
        cin>>x;
        h[i]=h[i-1]+(x==1);
        g[i]=g[i-1]+(x==2);
        j[i]=j[i-1]+(x==3);
    }
    for(int i=0;i<Q;++i){
        int a,b;
        cin>>a>>b;
        cout<<h[b]-h[a-1]<<" "<<g[b]-g[a-1]<<" "<<j[b]-j[a-1]<<endl;
    }
    return 0;
}
