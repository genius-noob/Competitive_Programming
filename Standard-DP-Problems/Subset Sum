vector< vector<int> > ans;
bool is[100][300];
int a[100];

void fun(int n, int sum, vector<int> &v){
    if(sum == 0){
        ans.push_back(v);
        return;
    }
    if(n==0) return;
    if(is[n-1][sum]){
        vector<int> tmp = v;             // new path
        fun(n-1, sum, tmp);
    }
    if(sum >= a[n]){
        if(is[n-1][sum-a[n]]){
            v.push_back(a[n]);          // elements are pushed right to left, reverse to get in order
            fun(n-1, sum-a[n], v);
        }
    }

}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    IOS;
    int n, sum;
    cin >> n >> sum;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }

        memset(is, false, sizeof is);
        is[0][0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(j == 0) is[i][0] = 1;
                else if(j >= a[i]){
                    is[i][j] = (is[i-1][j] || is[i-1][j-a[i]]);
                }
                else is[i][j] = is[i-1][j];
            }
        }
        if(is[n][sum]) cout << "Yes" << nl;

        // print any subset
        int i = n, j = sum;
        while(i > 0 && j > 0){
            if(j >= a[i]) {
                if(is[i][j] && is[i-1][j-a[i]]){ 
                    cout << a[i] << ' ';
                    j -= a[i];
                    i--;
                }
                else i--;
            }
            else i--;
        }
        cout << nl;
        
        // print all subset
        vector<int> v;
        fun(n, sum, v);
        for(auto vec : ans){
            for(int x : vec) cout << x << ' ';
            cout << '\n';
        }
   
    return 0;
}

//->INTUITIONS are not to be ignored. They represent data processed too fast for the conscious mind to comprehend !!
