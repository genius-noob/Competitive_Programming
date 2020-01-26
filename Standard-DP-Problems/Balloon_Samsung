Problem : https://www.geeksforgeeks.org/samsung-semiconductor-institute-of-researchssir-software-intern-fte-set-2/

// Approach 1 : Generate All permutation and optimise

// DP solution

Solution : 

/**
 *    Author: "Robin Singh" !!
 *    BrainyIsTheNewSexy    (CodeForces, CodeJam)
 *    rob_in_1              (All Other OJs)
**/

#include <bits/stdc++.h>
using namespace std;

#define dbg( args...) { vector<string> _v = split( #args, ','); err( _v.begin(), args); cerr << '\n'; }
vector<string> split( const string& s, char c) { vector<string> v; stringstream ss( s); string x; 
while ( getline( ss, x, c)) v.emplace_back(x); return move(v); }
void err( vector<string>::iterator it) { } 
template<typename T, typename... Args>
void err( vector<string>::iterator it, T a, Args... args) {
cerr << it -> substr( ( *it)[0] == ' ', it -> length()) << " = " << a << '\t'; err( ++it, args...); }

#define int long long
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
#define ff first
#define ss second
#define MP make_pair
#define szz(v) ((int)(v).size())  
#define fr(i, j, k) for(int i = j; i < k; i++)     
#define bk(i, j, k) for(int i = j-1; i >= k; i--)
#define mem(ptr, val)  memset(ptr, val, sizeof ptr)
#define sbit(n)  __builtin_popcount(n)
#define nl "\n"

typedef long double ld;
typedef pair<int, int> pii;
typedef vector <int> vi;
typedef vector < pair<int,int> > vpii;
const long double eps = 1e-9;
const int mod = 1e9+7;

pii dir[8] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, -1} , {-1, 1}, {1, -1} };

//*****************************************!Template Ends Here!******************************************//

const int nn = 50;
int a[nn], n;
int dp[nn][nn];

int fun(int l, int r){

	if(dp[l][r] != -1) {
		return dp[l][r];
	}

	int mx = 0;
	
	for(int i = l+1; i < r; i++){
		int here = fun(l, i) + fun(i, r);           // ith ballon will be exploded at last
		if(l == 0 && r == n+1){
			here += a[i];                           // if single element
		}
		else here += a[l] * a[r];                  // a[0] = a[n+1] = 1 will handle case of 2 elements       
		mx = max(mx, here);                        // calculate max for each subsets
	}
	
	return dp[l][r] = mx;                          // if(l+1 == r => 2 elements) return 0, as we are considering three elements
}

void robin(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	a[0] = a[n+1] = 1;                    // in case of 2 elements, 1 * a[r] or a[l] * 1

	memset(dp, -1, sizeof dp);
	cout << fun(0, n+1);
}

int32_t main(){
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    for(int tc = 1; tc <= T; tc++){
    	// cout << "Case #" << tc << ": ";
    	robin();
    }
    return 0;
}
