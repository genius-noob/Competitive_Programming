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
int a[nn][nn], dp[nn][nn];

pair <int, int> p[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int fun(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];

    for(int k=0; k<4; k++){
        int ni = i + p[k].first, nj = j + p[k].second;
        if(ni >= 0 && ni < n && nj >= 0 && nj < n && a[ni][nj] == 1 + a[i][j] ){
            return dp[i][j] =  1 + fun(ni, nj);           // no max as array is unique, so only direction at a time
        }
    }
    return dp[i][j] = 1;          // last one, no further movement
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    IOS;
    int ans = 0;
    cin >> n;
    fr(i, 0, n){
        fr(j, 0, n) {
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof dp);

    fr(i, 0, n){
        fr(j, 0, n){
            ans = max(ans, fun(i, j));
        }
    }
    cout << ans;
    return 0;
}

//->INTUITIONS are not to be ignored. They represent data processed too fast for the conscious mind to comprehend !!

// https://www.geeksforgeeks.org/find-the-longest-path-in-a-matrix-with-given-constraints/
