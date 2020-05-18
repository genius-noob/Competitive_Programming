int p[nn], n;
int memo[nn], dp[nn];

int fun(int i){
    if(i == 0) return 0;
    if(memo[i] != -1) return memo[i];

    int maxx = 0;
    for(int j=1; j<=i; j++){
        maxx = max(maxx, p[j] + fun(i-j));
    }
    return memo[i] = maxx;
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    IOS;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> p[i];
    memset(memo, -1, sizeof memo);
    cout << fun(n) << '\n';

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i], p[j] + dp[i-j]);
        }
    }
    cout << dp[n];

    return 0;
}
