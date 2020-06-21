#include <bits/stdc++.h>
#include <fstream>
using namespace std;

#define pb(s) push_back(s)
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))

typedef long long ll;

int N;
int a[17];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ofstream cout ("moobuzz.out");
    ifstream cin ("moobuzz.in");
    cin>>N;
    int j=1;
    for(int i=1;i<=30;++i){
        if(i%3&&i%5){
            a[j]=i;
            j++;
        }
    }
    int index;
    if(N%16==0){
        index=16;
    }
    else{
        index=N%16;
    }
    int mul=N/16;
    int ans=a[index]+(mul*30);
    cout<<ans<<endl;
    return 0;
}
