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

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream cout ("div7.out");
    ifstream cin ("div7.in");

    cin>>N;
    vl c;
    ll sum=0;
    for(int i=0;i<N;++i){
        int x;
        cin>>x;
        sum+=x;
        c.pb(sum%7);
    }
    int ans=0;
    unordered_map<int,int> um;
    for(int i=0;i<N;++i){
        if(c[i]==0){
            ans=i+1;
        }
        else if(um.find(c[i])==um.end()){
            um[c[i]]=i;
        }
        else{
            ans=max(ans,i-um[c[i]]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
