#include <iostream>
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

int main(){
    for(int i = 0; i < (1 << n); i++){
        dp[i] = inf;
    }

    // starting from 0
    dp[1] = 0;
    for(int to = 1; to < n; to++) {
        dp[1 | (1 << to)] = dist[0][to];
    }

    for(int mask = 3; mask < (1 << n); mask += 2) {      // odd numbers containing first bit i.e. node 0
        for(int to = 1; to < n; to++) {
            if(mask & (1 << to)) continue;
            for(int from = 1; from < n; from++) {
                if(mask & (1 << from)) {
                    if((mask | (1 << to)) == all_taken) {
                        dp[all_taken] = min(dp[all_taken], dp[mask] + dist[from][to] + dist[to][0]);
                    }
                    else {
                        dp[mask | (1 << to)] = min(dp[mask | (1 << to)], dp[mask] + dist[from][to]);
                    }
                }
            }
        }
    }

    int ans = dp[(1 << n)-1];
    cout << "Travelling Saleman Distance is " << ans << '\n';
    return 0;
}
