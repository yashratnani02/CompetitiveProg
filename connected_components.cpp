
int cnt = 0;
    for (int i = 0; i < n; i++)
    {

       if(!visited[i]){
           cnt++;
           dfs(i);
       }
    }
