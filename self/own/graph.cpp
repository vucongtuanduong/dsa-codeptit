#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
int a[100][100];
int n,s;
bool vs[100];
vector<vector<int>> adj;
int par[100];
int d[100];
struct cmp
{
    bool operator()(pair<int,int> a,pair<int,int> b)
    {
        return a.second>b.second;
    }
};
void solve()
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
    q.push({s, 0});
    while(!q.empty())
    {
        int u=q.top().first;
        int v=q.top().second;
        q.pop();
        if(vs[u]) continue;
        vs[u]=true;
        for(int i=1;i<=n;i++)
        {
            if(!vs[i] && d[u]+a[u][i]<d[i])
            {
                d[i]=d[u]+a[u][i];
                par[i]=u;
                q.push({i, d[i]});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<d[i]<<endl;
    }
}
int main()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==0)
            {
                a[i][j]=1000;
            }
        }
        vs[i]=false;
    }
    fill(d, d+n+1, 1000);
    d[s]=0;
    par[s]=s;
    solve();
}