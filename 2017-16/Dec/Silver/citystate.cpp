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
#define MOD 1000000007
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

const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1}; //flood

int n;
map<pair<str,str>,int> m;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin ("citystate.in");
    ofstream cout ("citystate.out");
    
    cin>>n;
    for(int i=0;i<n;++i)
    {
        str a,b;
        cin>>a>>b;
        a=a.substr(0,2);
        if(a!=b){
            m[{a,b}]++;
        }
    }
    ll ans=0;
    for(auto u:m)
    {
        ans+= u.s * m[{u.f.s,u.f.f}];
    }
	  //ans is double count
    cout<<ans/2<<endl;
    return 0;
}
