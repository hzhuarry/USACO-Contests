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
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpd;

const int MOD = 1000000007;
const ll INF=1e18;
const int dx[4]= {-1,1,0,0}, dy[4]= {0,0,-1,1};

//important! keep track every possible PCL rectangle! Each rectangles ID is its top left coordinate and bottom right coordinate
struct PCL{
    int x1,x2,y1,y2;
};

int N,ans;
char grid[21][21];
bool vis[21][21];
vector<PCL> v;

void ff(int i,int j,char ch,int row_start,int row_end,int col_start,int col_end){
    if(i<row_start||j<col_start||i>row_end||j>col_end||vis[i][j]||grid[i][j]!=ch)return;
    vis[i][j]=1;
    for(int k=0;k<4;++k){
        ff(i+dx[k],j+dy[k],ch,row_start,row_end,col_start,col_end);
    }
}

void flood(int row_start,int row_end,int col_start,int col_end){
    //cmp must be 2
    int cmp=0;
    map<char,int> m;
    memset(vis,0,sizeof(vis));
    for(int i=row_start;i<=row_end;++i){
        for(int j=col_start;j<=col_end;++j){
            if(!vis[i][j]){
                ff(i,j,grid[i][j],row_start,row_end,col_start,col_end);
                if(m.empty()||m.find(grid[i][j])==m.end()){
                    cmp++;
                }
                m[grid[i][j]]++;
            }
        }
    }
    if(cmp==2){
        bool one=0,twoMore=0;
        for(auto it=m.begin();it!=m.end();++it){
            int curr=it->s;
            if(curr==1){
                one=1;
                continue;
            }
            if(curr>=2){
                twoMore=1;
                continue;
            }
        }
        if(one&&twoMore){
            PCL a;
            a.x1=row_start;
            a.y1=col_start;
            a.x2=row_end;
            a.y2=col_end;
            v.pb(a);
        }
    }
}

bool isInPCL(int x,int y){
    return v[x].x1>=v[y].x1&&v[x].y1>=v[y].y1&&v[x].x2<=v[y].x2&&v[x].y2<=v[y].y2;
}

bool isMaxPCL(int x){
    for(int i=0;i<sz(v);++i){
        if(i!=x&&isInPCL(x,i)){
            return 0;
        }
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    ifstream cin ("where.in");
    ofstream cout ("where.out");
    
    cin>>N;
    for(int i=1;i<=N;++i)
    {
        for(int j=1;j<=N;++j){
            char ch;
            cin>>ch;
            grid[i][j]=ch;
        }
    }
    
    //brute force every rectangle
    for(int rect=1;rect<=N;++rect){
        for(int start_row=1;start_row<=N-rect+1;++start_row){
            for(int rect_sz=1;rect_sz<=N;++rect_sz){
                for(int start_col=1;start_col<=N-rect_sz+1;++start_col){
                    flood(start_row,start_row+rect-1,start_col,start_col+rect_sz-1);
                } 
            }
        }    
    }
    for(int i=0;i<sz(v);++i){
        if(isMaxPCL(i)){
            ans++;
        }
    }
    cout<<ans<<endl;
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
    return 0;
}
