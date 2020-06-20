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

typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<ld> vd;
typedef vector<str> vs;

typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<pld> vpd;

const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1}; //flood

int N,M;
vpll farm;

bool ok(ll d)
{
    ll curr=-d,cnt=0;
    for(auto u:farm)
    {
        while(max(curr+d,u.f)<=u.s){
            cnt++;
            curr=max(curr+d,u.f);
            if(cnt>=N)break;
        }
        if(cnt>=N)break;
    }
    return cnt>=N;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin ("socdist.in");
    ofstream cout ("socdist.out");
    
    cin>>N>>M;
    for(int i=0;i<M;++i){
        pll p;
        cin>>p.f>>p.s;
        farm.pb(p);
    }
    SORT(farm);
    ll l=1,h=farm.back().s-farm.front().f;
    while(l<h){
        ll mid=(l+h+1)/2;
        if(ok(mid)){
            l=mid;
        }
        else{
            h=mid-1;
        }
    }
    cout<<l<<endl;
    return 0;
}
