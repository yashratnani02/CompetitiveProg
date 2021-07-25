#include <bits/stdc++.h>
using namespace std;

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
vector<int> adj[105];
int findNumberofDescend(int child,vector<int> dirChild[],int freq[])
{
    if(freq[child]==0)return 0;
    int cnt = 0;
    for (auto node: dirChild[child])
    {
        cnt += (1 + findNumberofDescend(node,dirChild,freq));
    }
    return cnt;
    
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //Get Number of Direct Childs under a Node
    //Stores Childrens (Not Descendents)
    int freq[105] = {0};
    queue<int> q;
    bool visited[105];
    q.push(0);
    visited[0] = 1;
    vector<int> dirChild[105];
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for(auto child : adj[par])
        {
            if(!visited[child]){
                q.push(child);
                freq[par]++;
                visited[child] = 1;
            
                dirChild[par].push_back(child);
            }
        }
    }
    int ans = 0;
    q.push(0);

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for(auto child : dirChild[par])
        {
            q.push(child);
            //O(N) per Child
            int a = findNumberofDescend(child,dirChild,freq);
            if(a%2){
                ans++;
            }
        
        }
    }
    cout<<ans;
    return;
    
}
signed main()
{
    //Fast IO

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Test Cases

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
