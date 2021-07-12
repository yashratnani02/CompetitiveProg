queue<int> que;
    vector<int> dis(N,-1);
    que.push(0);
    dis[0] = 0;
    while(!que.empty()){
        int t = que.front(); que.pop();
        for(int x: G[t]) if(dis[x] == -1) {
            dis[x] = dis[t] + 1;
            que.push(x);
        }
    }


//This Calculate Shortest Path of All Nodes to Source
//SSSP with DFS works only on trees
