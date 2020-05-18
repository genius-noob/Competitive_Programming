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

    const int nn = 2e5+5;

    int cnt[26];

    void robin(){
        string s;
        cin >> s;

        int n = s.length();
        int l = 0, r = 0, ans = n, mx = 0, cur = 0;

        for(int i=0; i<n; i++){
            cnt[s[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(cnt[i]) mx++;
        }
        memset(cnt, 0, sizeof cnt);

        while(r < n){
            cnt[s[r]-'a']++;
            if(cnt[s[r]-'a'] == 1) cur++;

            if(cur == mx){
                while(cnt[s[l]-'a'] >= 2){
                    cnt[s[l]-'a']--;
                    l++;
                }
                ans = min(ans, r-l+1);
            }
            r++;
        }
        cout << ans;
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
    
    // https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
    // https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
