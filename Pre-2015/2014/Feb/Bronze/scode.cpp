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

int solve(str curr=s){
    int cnt=1,n=sz(curr);
    
    //base case
    if(n%2==0||n<2) return 1;
    //check all four rules
    if(curr.substr(0,n/2)==curr.substr(n/2,n/2)){
        cnt+=solve(curr.substr(n/2,n/2+1));
    }
    if(curr.substr(0,n/2)==curr.substr(n/2+1,n/2)){
        cnt+=solve(curr.substr(0,n/2+1));
    }
    if(curr.substr(0,n/2)==curr.substr(n/2+1,n/2)){
        cnt+=solve(curr.substr(n/2,n/2+1));
    }
    if(curr.substr(1,n/2)==curr.substr(n/2+1,n/2)){
        cnt+=solve(curr.substr(0,n/2+1));
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    
    setIO("scode");
    cin>>s;
    cout<<solve()-1<<endl;
    return 0;
}
