void lift_preprocess(vector<vector<int>> &lift){
    //Take Input of Parents of Each Node in lift[i][0] w/ lift[1][0] = 0
     for (int i = 1; i <= LOG; i++)
    {
        for (int j = 2; j <= n; j++)
        {
 
            lift[j][i] = lift[lift[j][i - 1]][i - 1];
        }
    }
}
int lift_k(vector<vector<int>> &lift,int k,int x){
    for (int i = 0; i <= LOG; i++)
        {
            if (k & (1ll << i))
            {
                x = lift[x][i];
            }
        }
        if(x==0){
            return -1;
        }
      return x;
}   
