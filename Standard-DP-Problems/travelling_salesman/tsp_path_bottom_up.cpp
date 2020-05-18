#include <bits/stdc++.h>
using namespace std;

const int n = 4, inf = 1e9;
const int all_taken = (1 << n) -1;

int dist[4][4] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};


int dp[16];
int par[16][4];

int main(){
    for(int i = 0; i < (1 << n); i++){
        dp[i] = inf;
    }

    // starting from 0
    dp[1] = 0;
    for(int to = 1; to < n; to++) {
        dp[1 | (1 << to)] = dist[0][to];
        par[1 | (1 << to)][to] = 0;
    }
    int last = -1;

    for(int mask = 3; mask < (1 << n); mask += 2) {      // odd numbers containing first bit i.e. node 0
        for(int to = 1; to < n; to++) {
            if(mask & (1 << to)) continue;
            int minn = dp[mask | (1 << to)], min_city = -1;

            for(int from = 1; from < n; from++) {
                if(mask & (1 << from)) {
                    if((mask | (1 << to)) == all_taken) {
                        if(dp[mask] + dist[from][to] + dist[to][0] < minn) {
                            minn = dp[mask] + dist[from][to] + dist[to][0];
                            min_city = from;
                        }
                    }
                    else {
                        if(dp[mask] + dist[from][to] < minn) {
                            minn = dp[mask] + dist[from][to];
                            min_city = from;
                        }
                    }
                }
            }
            dp[mask | (1 << to)] = minn;
            par[mask | (1 << to)][to] = min_city;
            if((mask | (1 << to)) == all_taken && min_city != -1) last = to;
        }
    }

    int ans = dp[(1 << n)-1];
    cout << ans << '\n';

    // path
    vector<int> path;
    int mask = all_taken;
    while(mask) {
        path.push_back(last);
        int prev = par[mask][last];
        mask = mask & ~ (1 << last);
        last = prev;
    }
    reverse(path.begin(), path.end());
    for(int x : path) cout << x << " -> ";
    cout << 0 << '\n';
    return 0;
}

