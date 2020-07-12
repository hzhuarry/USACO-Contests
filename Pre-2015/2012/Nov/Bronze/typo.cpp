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

str s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    setIO("typo");
    cin>>s;    
    int ans=0;
    int open=0,close=0;
    int cnt=0;
    int N=sz(s);
    for(int i=0;i<N;++i){
        if(s[i]=='('){
            cnt++;
            open++;
        }
        else{
            cnt--;
            close++;
        }

        //we only count the ( that have a cnt >= 2
        if(cnt<=1)
            open=0;
        //if the cnt is ever negative we stop and change the # of ) already seen before the current one since we can only change one
        if(cnt<0){
            ans=close;
            break;
        }
    }
    
    //if the cnt is positive at the end of the string, that means we change the number of ( that have a cnt >=2 to )
    if(cnt>0){
        ans=open;
    }
    cout<<ans<<endl;
    return 0;
}
