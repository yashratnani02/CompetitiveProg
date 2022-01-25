int color[n] = {0};

void dfs(int node, int col){
    vis[node] = 1;
    color[node] = col;
    for(auto child : adj[node]){
        if(!vis[child]){
            dfs(child,1^col);
        }
    }
}

    dfs(src,0);
