/**
 *    Author:  "Robin Singh" !!!
 *    BrainyIsTheNewSexy     (CodeForces)
 *    rob_in_1               (Other OJs)
**/
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
#define frit(it, a) for(__typeof((a).begin()) it = a.begin(); it != a.end(); ++it)
#define mem(ptr)  memset(ptr, 0, sizeof ptr) 
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
const int nn = 100;
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
int a[nn];
int memo[nn][2];
int dp[nn];

int fun(int i, int taken) {
    if(i >= n)
        return 0;
    if(memo[i][taken] != -1){
        return memo[i][taken];
    }

    if(taken) return fun(i+1, 0);
    else{
        return max(a[i] + fun(i+1, 1), fun(i+1, 0));
    }
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    IOS;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    memset(memo, -1, sizeof memo);
    cout << max(a[0] + fun(1, 1), fun(1, 0)) << '\n';

    // Bottom UP

    if(n==1){
        cout << a[0];
        return 0;
    }

    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);                       // Upto 2nd index, max we can obtain

    for(int i=2; i<n; i++){
        dp[i] = max(dp[i-1], a[i]+dp[i-2]);
    }
    cout << dp[n-1] << nl;

    // O(1) space
    
    int val1 = a[0], val2 = max(a[0], a[1]);
    for(int i=2; i<n; i++){
        int tmp = max(val1 + a[i], val2);
        val1 = val2;
        val2 = tmp;
    }
    cout << val2;
    return 0;
}
