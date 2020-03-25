void dijkstra(int src){
    dist[src] = 0;
    set < pii > s;
    s.insert({0, src});

    while(! s.empty()){
        auto it = s.begin();
        s.erase(it);
        int v = it->second;
        
        for(auto p : g[v]){
            int x = p.first;
            int c = p.second;
            
            if(dist[x] > dist[v] + c){
                s.erase({dist[x], x});
                dist[x] = dist[v] + c;
                s.insert({dist[x], x});
            }
        }
    }
}
