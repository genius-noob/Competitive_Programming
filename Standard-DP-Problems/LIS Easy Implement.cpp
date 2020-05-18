// https://cp-algorithms.com/sequences/longest_increasing_subsequence.html

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

int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF), par(n+1, -1), ind(n+1, -1);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int id = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        // this condition ensures that same element doesn't come next to each other
        if(d[id] > a[i] && d[id-1] < a[i]) {
            d[id] = a[i];
            ind[id] = i;
            par[i] = ind[id-1];
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }

    vi v;
    int p = ind[ans];
    while(p != -1) {
        v.pb(a[p]);
        p = par[p];
    }
    reverse(all(v));
    for(int x : v) cout << x << ' ';
    cout << nl;

    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    IOS;
    int n;
    cin >> n;
    vi a(n);
    fr(i, 0, n) cin >> a[i];
    cout << lis(a);
    return 0;
}


// check this also :  http://codeforces.com/blog/entry/13225
