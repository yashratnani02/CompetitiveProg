struct sieve
{
    vector<int> spf;
    
    sieve(int M)
    {
        spf.resize(M);
        for (int i = 0; i < M; i++)
        {
            spf[i] = i;
        }

        for (int i = 2; i < M; i += 2)
        {
            spf[i] = 2;
        }
        for (int i = 3; i * i < M; i++)
        {
            if (spf[i] == i)
            {
                for (int j = i * i; j < M; j++)
                {
                    if (spf[j] == j)
                    {
                        spf[j] = i;
                    }
                }
            }
        }
       
    }
     
};
