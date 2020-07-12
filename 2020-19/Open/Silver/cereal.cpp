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

int N,M;
int firstChoice[100001],secondChoice[100001];
//will contain the cow index that has taken cereal i
int cereal[100001];

int ans[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    setIO("cereal");
    cin>>N>>M;
    for(int i=0;i<N;++i) cin>>firstChoice[i]>>secondChoice[i];
     
    int cnt=0;
    for(int i=N-1;i>=0;--i){
        int currCow=i;
        int choice=firstChoice[currCow];
        while(1){
            if(cereal[choice]==0){
                cnt++;
                cereal[choice]=currCow;
                break;
            }
            else if(cereal[choice]>currCow){
                int nextCow=cereal[choice];
                cereal[choice]=currCow;
                //check if the nextCow is already on its second choice cereal, if it is it will moo
                if(choice==secondChoice[nextCow]) break;
                currCow=nextCow;
                choice=secondChoice[nextCow];
            }
            else{
                break;
            }
        }
        ans[i]=cnt;
    }
    for(int i=0;i<N;++i)
        cout<<ans[i]<<endl;
    return 0;
}
