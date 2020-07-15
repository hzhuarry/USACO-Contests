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

//Read Input
template<class T> void read(T& x) {
    cin >> x;
}
template<class H, class T> void read(pair<H, T>& p) {
    cin >> p.f >> p.s;
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

ll N,K,M;

bool ok(ll X){
    ll days=0;
    ll G=0;
    while(days<K){
        ll Y=(N-G)/X;
        //we can fast-forward to the end since Y will always be M if Y is less than M
        if(Y<=M){
            G+=(K-days)*M;
            break;
        }
        else{
            //Y changes every multiple of X
            ll remain=(N-G)%X;
            //how many days we can give Y gallons using the extra gallons
            ll num_days=remain/Y;
            //sim
            G+=num_days*Y;
            days+=num_days;
            //we still have to give Bessie Y gallons once(excluding the remaining gallons)
            G+=Y;
            days++;
        }
    }
    return G>=N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    setIO("loan");
    read(N,K,M);
    ll lo=1,hi=INF;
    while(lo<hi){
        ll mid=(lo+hi+1)/2;
        if(ok(mid)) lo=mid;
        else hi=mid-1;
    }
    cout<<lo<<endl;
    return 0;
}
