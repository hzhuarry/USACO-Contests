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

int skills[12];
int team_space[4];
int players_team[12];
int ans=-1;

void solve(int player){
    if(player==12){
        int team_skills[4]={0,0,0,0};
        for(int i=0;i<12;++i){
            team_skills[players_team[i]]+=skills[i];
        }
        int S=*max_element(team_skills,team_skills+4);
        int s=*min_element(team_skills,team_skills+4);
        if(ans==-1||S-s<ans){
            ans=S-s;
        }
        return;
    }
    for(int team=0;team<4;++team){
        if(team_space[team]<3){
            players_team[player]=team;
            team_space[team]++;
            solve(player+1);
            team_space[team]--;
            players_team[player]=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    setIO("bteams");
    for(int i=0;i<12;++i) cin>>skills[i];
    solve(0);
    cout<<ans<<endl;
    return 0;
}
