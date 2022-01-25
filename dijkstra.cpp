
vector<pii> adj[n];
    for (int i = 0; i < m; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        adj[x].eb(y,z);
        adj[y].eb(x,z);
    }
    for (int i = 0; i < n; i++)
    {
        distance[i] = me;
    }
      distance[0] = 0;
      int p[n] = {0};
      set<pii> q;
      q.insert({0,0});
      while (!q.empty())
      {
          int v = q.begin()->second;
          q.erase(q.begin());
          for(auto child : adj[v])
          {
                int to = child.first;
                int len = child.second;
                if(distance[v] + len < distance[to]){
                    q.erase({distance[to],to});
                    distance[to] = distance[v] + len;
                    p[to] = v;
                    q.insert({distance[to],to});
                }

          }
      }
    
      vector<int> path;
      for (int v = n-1 ; v != 0; v = p[v])
      {
         path.push_back(v);
      }
      path.push_back(0);
      reverse(path.begin(),path.end());
      if(distance[n-1]==me){
          cout<<-1<<endl;
          return;
      }
      for (int i = 0; i < path.size(); i++)
      {
          cout<<path[i] + 1<<" ";
      }
  
