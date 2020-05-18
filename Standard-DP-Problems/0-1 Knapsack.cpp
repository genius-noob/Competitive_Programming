    int n, W;
    cin >> n >> W;
    int wt[n+1], pr[n+1];
    for(int i=1; i<=n; i++)
        cin >> wt[i];
    for(int i=1; i<=n; i++)
        cin >> pr[i];

    int dp[n+1][W+1];
    memset(dp, 0, sizeof dp);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(j >= wt[i]){
                dp[i][j] = max(dp[i-1][j], pr[i] + dp[i-1][j-wt[i]]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][W] << '\n';

    // min wt corresponding to profit
    
    int minn;
    for(int j=1; j<=W; j++){
        if(dp[n][j] == dp[n][W]){
            minn = j;
            break;
        }
    }
    cout << minn << '\n';

    // print subset
    
    int i = n, j = W;
    while(i > 0 && j > 0){
        if(dp[i][j] == dp[i-1][j]) i--;
        else{
            cout << wt[i] << ' ';
            j -= wt[i];
        }
    }
