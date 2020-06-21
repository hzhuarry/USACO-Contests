#include <bits/stdc++.h>
#include <fstream>

using namespace std;

#define endl "\n"
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
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1}; //flood

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin ("homework.in");
    ofstream cout ("homework.out");
    
    //remember to cast long double when dividing
    int n;
    cin>>n;
    vi v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    vi lowscores(n);
    int small=10001;
    for(int i=n-1;i>=0;--i){
        small=min(small,v[i]);
        lowscores[i]=small;
    }
    ld tempAvg,maxAvg=0.0;
    int cnt=1;
    ll sum=v[n-1];
    vi ans;
    for(int i=n-2;i>0;--i){
        sum+=v[i];
        tempAvg=(ld)(sum-lowscores[i])/cnt;
        if(tempAvg>maxAvg){
            maxAvg=tempAvg;
            ans.clear();
            ans.pb(i);
        }
        else if(tempAvg==maxAvg){
            ans.pb(i);
        }
        cnt++;
    }
    SORT(ans);
    for(auto u:ans){
        cout<<u<<endl;
    }
    return 0;
}
