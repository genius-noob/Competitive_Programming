
const int nn = 1e5+5;
int par[nn], sz[nn];

void init(){
    for(int i=0; i<nn; i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int root(int x){
    while(par[x] != x){
        x = par[x];
        par[x] = par[par[x]];
    }
    return x;
}
 
void unite(int x, int y){
        int u = root(x), v = root(y);
        if(u == v) return;
        
        if(sz[u] < sz[v]){
            swap(u, v);
        }
        par[v] = u;
        sz[u] += sz[v];
}
