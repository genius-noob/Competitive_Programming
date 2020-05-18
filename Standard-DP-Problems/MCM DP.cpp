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
const int nn = 1e3+5;
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


int n;
int a[nn], memo[nn][nn], dp[nn][nn];

// Recursive with memo

int mcm(int i, int j){
    if(i == j) return 0;
    //if(i == j-1) return a[i-1]*a[i]*a[j];             // covered
    if(memo[i][j] != -1) return memo[i][j];

    int minn = INT_MAX;
    for(int k = i; k < j; k++){
        minn = min(minn, a[i-1] * a[k] * a[j] + mcm(i, k) + mcm(k+1, j));
    }
    return memo[i][j] = minn;
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    IOS;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    memset(memo, -1, sizeof memo);
    cout << mcm(1, n-1) << '\n';          
    // not (0, n-1) as we are using i-1 for dimension


    // Bottom UP
    // Observation : we have to calculate smaller chain length in order to calculate for larger chain
    // dp blog quora michal danilak
    // n elements => n-1 matrix

    for(int i=0; i<n; i++){
        for(int j=0; j < n; j++){
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = INT_MAX;
        }
    }

    for(int len = 2; len <= n-1; len++){         
        for(int i=1, j = len; j < n; i++, j++){
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], a[i-1] * a[k] * a[j] + dp[i][k] + dp[k+1][j]);
            }
        }
    }
    cout << dp[1][n-1] << '\n';
    
    return 0;
}

//->INTUITIONS are not to be ignored. They represent data processed too fast for the conscious mind to comprehend !!
