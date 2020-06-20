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

int N, c[1003][1003], p[100000], a[1000000];
char grid[1003][1003];
bool vis[1003][1003];

void ff(int i,int j,int cmp){
    if(vis[i][j]||i<1||j<1||i>N||j>N||grid[i][j]!='#') return;
    vis[i][j]=1;
    c[i][j]=cmp;
    a[cmp]++;
    for(int k=0;k<4;++k){
        ff(i+dx[k],j+dy[k],cmp);
    }
}

void findPerimeter()
{
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            int cmp=c[i][j];
            if(cmp==0)continue;
            for(int k=0;k<4;++k){
                if(c[i+dx[k]][j+dy[k]]==0){
                    p[cmp]++;
                }
            }
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin ("perimeter.in");
    ofstream cout ("perimeter.out");
    
    cin>>N;
    for(int i=1;i<=N;++i){
        str s;
        cin>>s;
        for(int j=1;j<=N;++j){
            grid[i][j]=s[j-1];
        }
    }
    
    int cmp=1;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            if(!vis[i][j]&&grid[i][j]=='#'){
                ff(i,j,cmp++);
            }
        }
    }
    
    //for each cmp the adjacent(N,S,E,W) 0s add to the perimeter
    findPerimeter();
    
    int bigA=0,smallP=1e9;
    for(int i=1;i<=cmp;++i){
        if(a[i]>bigA||(a[i]==bigA&&p[i]<smallP)){
            bigA=a[i];
            smallP=p[i];
        }
    }
    cout<<bigA<<" "<<smallP<<endl;
    return 0;
}
