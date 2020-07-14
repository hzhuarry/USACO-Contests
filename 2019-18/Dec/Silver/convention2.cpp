#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define alla(x,n) x,x+n
#define rall(x) (x).rbegin(), (x).rend()
#define Sort(x) sort(all(x))
#define Sorta(x,n) sort(alla(x,n))
#define rsz resize
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ar array

#define for_base(i, a, b, x) for (int i=(a); ((a)<(b))?i<(b):i>(b); ((a)<(b))?i+=(x):i-=(x))
#define FOR1(a) for_base(i, 0, a, 1)
#define FOR2(i, a) for_base(i, 0, a, 1)
#define FOR3(i, a, b) for_base(i, a, b, 1)
#define FOR4(i, a, b, x) for_base(i, a, b, x)
#define FIFTH(a, b, c, d, e, ...) e
#define FOR(...) FIFTH(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define trav(a,x) for (auto& a: x)
#define fitfor(i, x) for (auto i=(x).begin(); i!=(x).end(); ++i)
#define ritfor(i, x) for (auto i=(x).rbegin(); i!=(x).rend(); ++i)

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef vector<pdd> vpdd;
template<class T> using min_heap=pqueue<T, vector<T>, greater<T>>;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T> bool umin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool umax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

//Read In
template<class T> void read(T& x) {
    cin >> x;
}
template<class H, class T> void read(pair<H, T>& p) {
    cin >> p.fi >> p.se;
}
template<class T> void read(vector<T>& v) {
    trav(i, v)
        read(i);
}
template<class A, size_t S> void read(array<A, S>& x) {
    trav(a, x)
    read(a);
}
template<class T> void read(T a[], int n) {
    FOR(n)
      read(a[i]);
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}

void setIO(string filename) {
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
}

const int MOD = 1000000007;
const ll INF=1e18;
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1};

int N;
//first=time of arrival, second=seniority, third=duration
ar<ll,3> cows[100000];
//first=seniority, second=time of arrival, third=duration
min_heap<ar<ll,3> > waiting;

ll ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    setIO("convention2");
    
    read(N);
    FOR(N){
        cows[i][1]=(ll)i;
        read(cows[i][0],cows[i][2]);
    }
    Sorta(cows,N);
    ll curr_finished;
    int curr=1;
    curr_finished = cows[0][0]+cows[0][2];
    while(curr<N||!waiting.empty()){
        while(curr<N&&cows[curr][0]<=curr_finished){
            waiting.push({cows[curr][1],cows[curr][0],cows[curr][2]});
            curr++;
        }
        if(waiting.empty()&&curr<N){
            curr_finished=cows[curr][0]+cows[curr][2];
            curr++;
        }
        else if(!waiting.empty()){
            ll arrivalTime=waiting.top()[1];
            ll duration=waiting.top()[2];
            umax(ans,curr_finished-arrivalTime);
            curr_finished+=duration;
            waiting.pop();
        }
    }
    cout<<ans<<endl;
    return 0;
}
