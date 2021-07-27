bool dfs(int node,vector<int> adj[],bool visited[],bool stack[]){
    stack[node] = true;
    visited[node] = true;
    for(auto child : adj[node])
    {
        if(stack[child]){
            return true;
        }
        if(!visited[child]){
            bool isCycle = dfs(child,adj,visited,stack);
            if(isCycle){
                return true;
            }
        }
    }
    stack[node] = false; 
    return false;

}
