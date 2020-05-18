/**
 *    Author:  "Robin Singh" !!!
 *    BrainyIsTheNewSexy     (CodeForces)
 *    rob_in_1               (Other OJs)
**/
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define IO  freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
#define ff first
#define ss second
#define mp make_pair
#define szz(v) ((int)(v).size())  
#define fr(i, j, k) for(int i = j; i < k; i++)     
#define bk(i, j, k) for(int i = j-1; i >= k; i--)
#define mem(ptr)  memset(ptr, 0, sizeof ptr)
#define sbit(n)  __builtin_popcount(n)
#define nl "\n"
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <long long> vll;
typedef vector < pair<int,int> > vpii;
typedef vector < pair<ll, ll> > vpll;
const long long mod = 1e9+7;
const long double eps = 1e-9;
const long long INF = (1LL<<61);
const int inf = (1<<30);
const int nn = 1e6+5;
//---------------------------------------------*DEBUGGING*--------------------------------------------------------->]
#define dbg( args...) { vector<string> _v = split( #args, ','); err( _v.begin(), args); cerr << '\n'; }
vector<string> split( const string& s, char c) { vector<string> v; stringstream ss( s); string x; 
while ( getline( ss, x, c)) v.emplace_back(x); return move(v); }
void err( vector<string>::iterator it) { } 
template<typename T, typename... Args>
void err( vector<string>::iterator it, T a, Args... args) {
    cerr << it -> substr( ( *it)[0] == ' ', it -> length()) << " = " << a << '\t'; err( ++it, args...); }
//----------------------------------------------------------------------------------------------------------------->]
//*****************************************!Template Ends Here!*****************************************************]

int a[100], n;
int dp[100][100];

int fun(int i, int s){
    if(s == 0) return 1;
    if(i >= n || s < 0) return 0;
    if(dp[i][s] != -1) return dp[i][s];

    return fun(i+1, s) + fun(i, s-a[i]);
}

int main()
{
    IO;
    IOS;
    int s;
    cin >> n >> s;
    fr(i, 0, n) cin >> a[i];
    memset(dp, -1, sizeof dp);

    cout << fun(0, s) << nl;

    // Bottom UP
    
    int DP[s+1][n+1];
    memset(DP, 0, sizeof DP);

    DP[0][0] = 1;

    for(int i=0; i<=s; i++){
        for(int j=1; j<=n; j++){
            if(i==0){
                DP[0][j] = 1;
            }
            else{
                DP[i][j] = DP[i][j-1];
                if(a[j-1] <= i){
                    DP[i][j] += DP[i-a[j-1]][j];
                }
            }
        }
    }
    cout << DP[s][n] << nl;

    // O(s) Memory

    int cache[s+1];
    memset(cache, 0, sizeof cache);
    cache[0] = 1;

    for(int i=0; i<n; i++){
        for(int j = a[i]; j<=s; j++)
            cache[j] += cache[j-a[i]];
    }
    cout << cache[s];
    return 0;
}
