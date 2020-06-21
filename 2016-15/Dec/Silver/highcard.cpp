#include <bits/stdc++.h>
#include <fstream>

using namespace std;

#define endl "\n"
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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int N,ans;
bool C[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream cout ("highcard.out");
    ifstream cin ("highcard.in");


    cin>>N;
    for(int i=0;i<N;++i){
        int x;
        cin>>x;
        C[x]=1;
    }
    vi Bess,Elsie;
    for(int i=1;i<=2*N;++i){
        if(C[i])Elsie.pb(i);
        else Bess.pb(i);
    }
    int l=0,r=0;
    while(l<N&&r<N)
    {
        if(Bess[r]>Elsie[l]){
            ans++;
            l++;
            r++;
        }
        else r++;
    }
    cout<<ans<<endl;
    return 0;
}
