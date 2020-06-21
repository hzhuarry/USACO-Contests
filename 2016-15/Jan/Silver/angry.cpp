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
typedef vector<pll> vpl;
typedef vector<pld> vpd;

const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1}; //flood

int n,k;
vi barrels;

int numShots(int r)
{
    int cnt=0, start=0;
    while(start<n)
    {
        cnt++;
        int last=start;
        //2*r distance from the leftmost barrel
        while(last<n&&barrels[last]-barrels[start]<=2*r){
            last++;
        }
        start=last;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin ("angry.in");
    ofstream cout ("angry.out");
    
    cin>>n>>k;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        barrels.pb(a);
    }
    SORT(barrels);
    //bast radius
    int l=0,r=1000000000;
    int ans;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(numShots(mid)<=k){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<l<<endl;
    return 0;
}
