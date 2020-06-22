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

int N,K,B;
bool broken[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream cout ("maxcross.out");
    ifstream cin ("maxcross.in");

    cin>>N>>K>>B;
    for(int i=0;i<B;++i){
        int x;
        cin>>x;
        broken[x]=1;
    }
    int ans=K,cnt=0;
    //sliding window of size K to find the least amount of signals needing repair
    for(int i=1;i<=N-K+1;++i){
        if(i==1){
            for(int j=0;j<K;++j){
                if(broken[i+j])cnt++;
            }
        }
        else{
            if(broken[i-1]) cnt--;
            if(broken[i+K-1]) cnt++;
        }
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}
