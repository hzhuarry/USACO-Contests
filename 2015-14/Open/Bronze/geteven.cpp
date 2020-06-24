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



int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("geteven.in");
    ofstream cout ("geteven.out");
    
    int n;
    cin>>n;
    unordered_map<char, vi> um;
    for(int i=0;i<n;++i){
        char c;
        int val;
        cin>>c>>val;
        um[c].pb(val);
    }
    int total=1;
    for(auto it=um.begin();it!=um.end();++it){
        char c=it->f;
        total*=it->s.size();
    }
    //find when all three words are odd
    int odd=1;
    //bessie
    int cnt=0;
    for(int b:um['B']){
        for(int i:um['I']){
            if((b+i)&1){
                cnt++;
            }
        }
    }
    odd*=cnt;
    cnt=0;
    //moo
    for(int m:um['M']){
        if(m&1){
            cnt++;
        }
    }
    odd*=cnt;
    cnt=0;
    //goes
    for(int g:um['G']){
        for(int o:um['O']){
            for(int e:um['E']){
                for(int s:um['S']){
                    if((g+o+e+s)&1){
                        cnt++;
                    }
                }
            }
        }
    }
    odd*=cnt;
    cout<<total-odd<<endl;
    return 0;
}
