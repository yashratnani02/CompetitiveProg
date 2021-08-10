 //Maximum Median
    int low = arr[n/2];
    int high = arr[n/2] + k;
    int mid = (high + low)/2;
    int ans = low;
    while (high>=low)
    {
        mid = (high + low)/2;
        if(check(arr,n,k,mid)){
            low = mid + 1;
            ans = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout<<ans<<endl;
