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

const int dx[4]= {-1,1,0,0},dy[4]= {0,0,-1,1}; //flood

int n,k;
char board[100][10];
bool vis[100][10];
queue<pair<int,int> > wipe;

int ff(int i,int j,char color)
{
    if(i<0||j<0||i>=n||j>=10||vis[i][j]||board[i][j]!=color)return 0;
    int c=1;
    vis[i][j]=1;
    for(int next=0; next<4; ++next) c+=ff(i+dx[next],j+dy[next],color);
    return c;
}

void clean(int i,int j,char color)
{
    if(i<0||j<0||i>=n||j>=10||board[i][j]!=color)return;
    board[i][j]='0';
    for(int next=0; next<4; ++next) clean(i+dx[next],j+dy[next],color);
}

void gravity()
{
    for(int j=0; j<10; ++j)
    {
        for(int i=n-1; i>=0; --i)
        {
            if(board[i][j]=='0')
            {
                int nexti=i-1;
                while(nexti>=0)
                {
                    bool ok=0;
                    if(board[nexti][j]!='0')
                    {
                        board[i][j]=board[nexti][j];
                        board[nexti][j]='0';
                        ok=1;
                    }
                    if(ok)break;
                    nexti--;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream cout ("mooyomooyo.out");
    ifstream cin ("mooyomooyo.in");

    cin>>n>>k;
    str s;
    for(int i=0; i<n; ++i)
    {
        cin>>s;
        for(int j=0; j<10; ++j)
        {
            board[i][j]=s[j];
        }
    }
    
    while(1)
    {
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<10; ++j)
            {
                if(board[i][j]!='0'&&!vis[i][j])
                {
                    if(ff(i,j,board[i][j])>=k)
                    {
                        wipe.push(mp(i,j));
                    }
                }
            }
        }
        //nothing to queue==done
        if(wipe.empty())break;
        
        while(!wipe.empty())
        {
            auto num=wipe.front();
            int x=num.f,y=num.s;
            char color=board[x][y];
            clean(x,y,color);
            wipe.pop();
        }
        gravity();
    }
    //print board;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<10; ++j)
        {
            cout<<board[i][j];
        }
        cout<<endl;
    }
    return 0;
}
