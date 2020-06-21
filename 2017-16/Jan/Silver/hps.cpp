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

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream cout ("hps.out");
    ifstream cin ("hps.in");

    cin>>N;
    int cnt1=0,cnt2=0,cnt3=0;
    vector<char> v;
    vi f;
    for(int i=0;i<N;++i){
        char ch;
        cin>>ch;
        if(ch=='H'){
            cnt1++;
        }
        else if(ch=='P'){
            cnt2++;
        }
        else{
            cnt3++;
        }
        v.pb(ch);
        f.pb(max(cnt1,max(cnt2,cnt3)));
    }
    vi b;
    cnt1=0,cnt2=0,cnt3=0;
    for(int i=N-1;i>=0;--i){
        if(v[i]=='H'){
            cnt1++;
        }
        else if(v[i]=='P'){
            cnt2++;
        }
        else{
            cnt3++;
        }
        b.pb(max(cnt1,max(cnt2,cnt3)));
    }
    REVERSE(b);
    int ans=f.back();
    for(int i=0;i<N-1;++i){
        ans=max(ans,f[i]+b[i+1]);
    }
    cout<<ans<<endl;
    return 0;
}
