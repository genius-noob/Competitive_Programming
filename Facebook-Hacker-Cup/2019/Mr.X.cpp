/**
 *    Author: "Robin Singh" !!
 *    rob_in_1
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg( args...) { vector<string> _v = split( #args, ','); err( _v.begin(), args); cerr << '\n'; }
vector<string> split( const string& s, char c) { vector<string> v; stringstream ss( s); string x; 
while ( getline( ss, x, c)) v.emplace_back(x); return move(v); }
void err( vector<string>::iterator it) { } 
template<typename T, typename... Args>
void err( vector<string>::iterator it, T a, Args... args) {
cerr << it -> substr( ( *it)[0] == ' ', it -> length()) << " = " << a << '\t'; err( ++it, args...); }
#else
#define dbg(...)
#endif

#define int long long
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
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

//===*********************************!Template Ends Here!**********************************===//

const int nn = 2e5+5;

int calc(char x, char op, char y){
    int a = x-'0', b = y-'0';
    if(op == '&') return (a and b);
    else if(op == '|') return (a or b);
    else return (a ^ b);
}

void robin(){
    string s;
    cin >> s;
    int n = s.length();
    int value[2];

    for(int i = 0; i <= 1; i++){
        char t[n];
        int ind = 0;
        for(int j = 0; j < n; j++){
            if(s[j] == 'x') t[ind++] = (i + '0');
            else if(s[j] == 'X') t[ind++] = (1-i)+'0';
            else if(s[j] == ')'){
                int val = calc(t[ind-1], t[ind-2], t[ind-3]);
                // dbg(i, j, val);
                t[ind-4] = val + '0';
                ind = ind-4+1;
            }
            else t[ind++] = s[j];
        }
        value[i] = t[0] - '0';
    }
    int ans = (value[0] == value[1]) ? 0 : 1;
    cout << ans << '\n';
}

int32_t main(){
  #ifdef LOCAL 
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T = 1;
  cin >> T;
  for(int tc = 1; tc <= T; tc++){
    cout << "Case #" << tc << ": ";
    robin();
  }
  return 0;
}
