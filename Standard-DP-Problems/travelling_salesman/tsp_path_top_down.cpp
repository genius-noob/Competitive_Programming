#include<bits/stdc++.h>
using namespace std;

const int n = 4;
const int VISITED_ALL = (1<<n) -1;

int dist[4][4] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};

int dp[16][4];
int nxt[16][4];

int tsp(int mask, int pos){
    if(mask == VISITED_ALL){
        return dist[pos][0];
    }
    if(dp[mask][pos] != -1){
       return dp[mask][pos];
    }

    int ans = INT_MAX, min_city = -1;

    for(int city = 0; city < n; city++){
        if((mask & (1<<city)) == 0){
            int here = dist[pos][city] + tsp(mask | (1<<city), city);
            if(here < ans) {
                ans = here;
                min_city = city;
            }
        }

    }
    nxt[mask][pos] = min_city;
    return dp[mask][pos] = ans;
}

int main(){
    for(int i = 0; i < (1<<n); i++){
        for(int j = 0;j < n; j++){
            dp[i][j] = -1;
        }
    }
    cout << tsp(1, 0) << '\n';

    // path
    int mask = 1, pos = 0;
    cout << 0 << " -> ";
    while(mask != VISITED_ALL) {
        cout << nxt[mask][pos] << " -> ";
        pos = nxt[mask][pos];
        mask |= (1 << pos);
    }
    cout << 0 << '\n';
    return 0;
}

