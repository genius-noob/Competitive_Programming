Undirected : Apply DFS or DSU

Directed : 
coloring method : https://www.youtube.com/watch?v=rKQaZuoUR4M
https://cp-algorithms.com/graph/finding-cycle.html

Code : 

const int nn = 1e5 + 5;

int n, m;
vector<int> adj[nn];
vector<int> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;                                 // 1 => active set (gray set)
    for (int u : adj[v]) {
        if (color[u] == 0) {                      // 0 => original set (white set)
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;                               // 2 => explored completely (black set)
    return false;
}

void find_cycle() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (dfs(v))                           // if(color[v] == 0) then only call dfs (visit untraversed nodes only)
            break;
    }

    if (cycle_start == -1) {
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: \n";
        for (int v : cycle)
            cout << v+1 << " ";
        cout << endl;
    }
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    IOS;
    cin >> n >> m;
    for(int i=0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    find_cycle();

    return 0;
}
