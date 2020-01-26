int a[100], n, sum;
int dp[100][1000];

// recursive with memo
int fun(int ind, int s){
    if(ind >= n){
        int t = sum-s;
        return abs(s-t);
    }
    if(dp[ind][s] != -1) return dp[ind][s];

    return min(fun(ind+1, s+a[ind]), fun(ind+1, s));
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    IOS;
    cin >> n;
    
    fr(i, 0, n) {
        cin >> a[i];
        sum += a[i];
    }
    memset(dp, -1, sizeof dp);
    cout << fun(0, 0) << nl;

    // Bottom UP
    bool DP[n+1][sum+1];
    memset(DP, 0, sizeof DP);
    DP[0][0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j==0) dp[i][j] = 1;
            else{
                if(j >= a[i]) dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
    }
    int res;
    for(int i=sum/2; i>=0; i--){
        if(dp[n][i]){
            res = abs(i - (sum-i));
            break;
        }
    }
    cout << res << nl;
    
    // Brute
    int ans = INT_MAX;
    for(int i=0; i < (1 << n); i++){
        int s = 0, t = 0;
        for(int j=0; j<n; j++){
            if(i & (1<<j)) s += a[j];
            else t += a[j];
        }
        ans = min(ans, abs(s-t));
    }
    cout << ans;

    return 0;
}
