int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> lis(n, 1);
    vector <int> prev(n, -1);

    int max_len = 0, best_end;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[i] > a[j] && lis[i] < lis[j] + 1){
                lis[i] = 1 + lis[j];
                prev[i] = j;
            }
        }
        if(lis[i] > max_len){
            max_len = lis[i];
            best_end = i;
        }
    }

    cout << max_len << '\n';

    vector <int> seq;
    int cur = best_end;
    while(cur != -1){
        seq.push_back(a[cur]);
        cur = prev[cur];
    }
    reverse(seq.begin(), seq.end());
    
    for(int x: seq) cout << x << ' ';
    return 0;
}
