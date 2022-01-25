struct segtree
{
  vector<int> t;
  int N;
  int size;
  segtree(int n) {
    N = n;
    size = 1;
    while (size<N)
    {
      size*=2;
    }
    t.resize(2 * size,0);
  };
  int operation(int a,int b){
    return min(a,b);
  }
  void build(int a[], int v, int tl, int tr)
  {
    if (tl == tr)
    {
      t[v] = a[tl];
    }
    else
    {
      int tm = (tl + tr)>>1;
      build(a, v * 2, tl, tm);
      build(a, v * 2 + 1, tm + 1, tr);
      t[v] = operation(t[v * 2] , t[v * 2 + 1]);
    }
  }
  void build(int a[]){
    build(a,1,0,N-1);
  }
  int query(int v, int tl, int tr, int l, int r)
  {
    //Change to inf in case of min , else set to 0
    if (l > r)
      return inf;
    if (l == tl && r == tr)
    {
      return t[v];
    }
    int tm = (tl + tr) >> 1;
    return operation(query(v * 2, tl, tm, l, min(r, tm)) , query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  int query(int l,int r){
    return query(1,0,N-1,l,r);
  }
  void update(int v, int tl, int tr, int pos, int new_val)
  {
    if (tl == tr)
    {
      t[v] = new_val;
    }
    else
    {
      int tm = (tl + tr) >> 1;
      if (pos <= tm)
        update(v * 2, tl, tm, pos, new_val);
      else
        update(v * 2 + 1, tm + 1, tr, pos, new_val);
      t[v] = operation(t[v * 2] , t[v * 2 + 1]);
    }
  }
  void update(int pos,int val){
    update(1,0,N-1,pos,val);
  }


};
