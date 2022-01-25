int n = A.size();
    int dp[n+1] = {0};
    for(int i=0;i<n+1;i++){
        dp[i] = 1e9;
    }
    dp[0] = (-1e9);
    for(int i = 0; i < n; i++){
        int x = A[i];
        int l = upper_bound(dp,dp+n+1,x) - dp;
<<<<<<< HEAD
        if(dp[l]>x and x>dp[l-1]){
=======
        if(dp[l]>x && x>dp[l-1]){
>>>>>>> 1a5f9849a385909151eec245e91459a4078b2b00
            dp[l] = x;
        }
       
    }
    int cnt = 0;
    for(int i= 1;i<=n;i++){
        if(dp[i]==1e9){
            break;
        }
        cnt = i;
    }
    if(n==1){
        return 1;
    }
    return cnt;
//This Also Returns the sequence
