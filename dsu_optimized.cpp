struct DSU
{
  vector<int> parent;
  vector<int> sze;
  DSU(int n,bool init){
    parent.resize(n,-1);
    sze.resize(n,0);
    len.resize(n,0);
    if(init){
      for (int i = 0; i < n; i++)
      {
        parent[i] = i;
        sze[i] = 1;
      }
    }
  }
  void make_set(int v)
  {
    parent[v] = v;
    sze[v] = 1;
  }
  int find_set(int v)
  {
    if (v == parent[v])
      return v;
    return parent[v] = find_set(parent[v]);
  }
  void union_sets(int a, int b)
  {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
      if (sze[a] < sze[b])
        swap(a, b);
      parent[b] = a;
      sze[a] += sze[b];
    }
  }
};
