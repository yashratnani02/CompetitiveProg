const int M = 1e6 + 1;
    vector<int> sieve(M,0);
    for (int i = 0; i < M; i++)
    {
        sieve[i] = i;
    }
    
    for (int i = 2; i < M; i+=2)
    {
        sieve[i] = 2;
    }
    for (int i = 3; i*i < M; i++)
    {
        if(sieve[i]==i){
            for (int j = i*i; j < M; j++)
            {
                if(sieve[j]==j){
                    sieve[j] = i;
                }
            }
        }
    }
