#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxx 1e9 + 7
#define inf -1e18
#define pb push_back
#define vi vector<int>
#define pii pair<int, int>
#define ff first
#define ss second
#define eb emplace_back
#define mp make_pair
const int me = 1e9 + 7;
void solve()
{
   //Splitwise Algorithm 
   int p,t;
   cin>>p>>t;
   int arr[p] = {0};
   multiset<pii> s;
   
   for (int i = 0; i < t; i++)
   {
       int p1,p2,amt;
       cin>>p1>>p2>>amt;
       arr[p1] -= amt;
       arr[p2] += amt;
   }
   for (int i = 0; i < p; i++)
   {
      s.insert(mp(arr[i],i));
   }
   int cnt = 0;
   while (!s.empty())
   {
       auto bgn = *(s.begin());
       s.erase(bgn);
       auto end = *(prev(s.end()));
        s.erase(end);
       int f_amt = bgn.first;
       int f_pr = bgn.second;
       int s_amt = end.first;
       int s_pr = end.second;
       int amt = min(abs(f_amt),abs(s_amt));
    f_amt += amt;
    s_amt -= amt;
    if(f_amt){
        s.insert(mp(f_amt,f_pr));
    }
    if(s_amt){
        s.insert(mp(s_amt,s_pr));
    }
       cnt++;
   }
   
   cout<<cnt<<endl;
   
   





   
   
}
signed main()
{
    //Fast IO

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Test Cases

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
