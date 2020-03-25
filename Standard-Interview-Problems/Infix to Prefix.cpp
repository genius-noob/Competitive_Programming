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


bool isoperand(char c){
    if(isalpha(c) || isdigit(c)) return true;
    return false;
    /*
    if(c >= 'a' && c <= 'z') return true;
    if(c >= 'A' && c <= 'Z') return true;
    if(c >= '0' && c <= '9') return true;
    return false;
    */
}

bool isoperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

bool openbraces(char c){
    if(c == '{' || c == '(' || c == '[')
        return true;
    return false;
}


int preced(char c){
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    IOS;
    string s, ans = "";
    cin >> s;    
    reverse(all(s));

    fr(i, 0, szz(s)){
        if(s[i] == ')') s[i] = '(';
        else if(s[i] == '(') s[i] = ')';
    }
    
    stack <char> st;

    for(int i=0; i<szz(s); i++){
        if(isoperand(s[i])){
            ans += s[i];
        }

        else if(openbraces(s[i])){
            st.push(s[i]);
        }

        else if(isoperator(s[i])){
            while(! st.empty() && preced(st.top()) >= preced(s[i])){    // equality as left to right associativity
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);          // push current operator
        }

        else{                                                   // closed braces            
            while(! st.empty() && ! openbraces(st.top() ) ) {
                ans += st.top();
                st.pop();
            }
            st.pop();         // pop (
        }
    }

    while(! st.empty()){             // pop remaining operator
        ans += st.top();
        st.pop();
    }

    reverse(all(ans));
    cout << ans;
    return 0;
}
