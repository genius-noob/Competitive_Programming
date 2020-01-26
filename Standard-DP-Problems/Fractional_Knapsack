
    vector < pair <double, pair<int, int> > > v;
    int n, W;
    cin >> n >> W;
    int w[n], p[n];
    for(int i=0; i<n; i++){
        cin >> w[i];
    }
    for(int i=0; i<n; i++){
        cin >> p[i];
        double t = 1.0 * p[i] / w[i];
        v.push_back(make_pair(t, make_pair(w[i], p[i])));
    }
    sort(v.rbegin(), v.rend());

    int cur = 0;
    double ans = 0;
    
    for(int i=0; i<n; i++){
        int wt = v[i].second.first;
        int pr = v[i].second.second;
        if(cur + wt <= W) {
            cur += wt;
            ans += pr;
        }
        else{
            int rem = W - cur;
            ans += 1.0 * pr * rem/wt;
            break;
        }
    }
    cout << ans;
