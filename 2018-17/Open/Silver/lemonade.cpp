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

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ofstream cout ("lemonade.out");
    ifstream cin ("lemonade.in");

    cin>>n;
    vi c(n);
    for(int i=0;i<n;++i){
        cin>>c[i];
    }
    SORT(c);
    int cnt=0;
    int i=0;
    while(i<c.size()&&!c.empty()){
        if(c[i]>=cnt){
            c.pop_back();
            ++cnt;
            continue;
        }
        ++i;
    }
    cout<<cnt<<endl;
    return 0;
}
