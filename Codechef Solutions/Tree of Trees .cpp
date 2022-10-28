#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mx 200000
#define mp make_pair
#define pii pair<ll,ll>
#define fs first
#define sc second
#define mx 200000
vector<int>vc[mx],cost[mx];
bool deg[mx];
int aged[mx];
void clr(int n)
{
    for(int i=1; i<=n; i++)
    {
        deg[i]=0;
        vc[i].clear();
        cost[i].clear();
    }
}
int find(int n)
{
    for(int i=1; i<=n; i++)
    {
        if(deg[i]==0)
            return i;
    }
    assert(0);
}
ll base[]= {103,10007},mod[]= {784568360, 820925358};
ll base2[]= {137,277},mod2[]= {1000000007,1000000009};
ll base3[]= {701,41},mod3[]= {998244353,1012924417};
ll day[2][2][2],age[2][120][2],brac[2][2];
set<pii>s;
pii dfs(int v,bool x)
{
    ll sum[2];
    sum[0]=0;
    sum[1]=0;
    for(int i=0; i<vc[v].size(); i++)
    {
        int w=vc[v][i];
        pii ps=dfs(w,x);
        int c=cost[v][i];
        ll val[2];
        val[0]=ps.fs;
        val[1]=ps.sc;
        for(int j=0; j<2; j++)
        {
            val[j]*=base[j];
            val[j]%=mod[j];
        }
        for(int j=0; j<2; j++)
        {
            val[j]+=(day[j][c][0]+day[j][c][1])%mod2[j];
            val[j]%=mod2[j];
            sum[j]+=val[j];
            if(sum[j]>=mod2[j])
                sum[j]%=mod2[j];
        }
    }
    for(int j=0; j<2; j++)
    {
        sum[j]*=base2[j];
        sum[j]%=mod2[j];
        sum[j]+=(brac[j][0]+brac[j][1])%mod[j];
        sum[j]%=mod[j];
        int d=aged[v];
        sum[j]+=(age[j][d][0]+age[j][d][1])%mod3[j];
        sum[j]%=mod3[j];
    }
    if(x)
        s.insert(mp(sum[0],sum[1]));
    return mp(sum[0],sum[1]);
}
#define pb push_back
int main()
{
    srand(time(NULL));
    int i,j,k,l,m,n;
    for(int i=0; i<101; i++)
    {
        for(int j=0; j<=1; j++)
        {
            age[j][i][0]=rand();
            age[j][i][1]=rand();
        }
    }
    for(int i=0; i<2; i++)
    {
        brac[i][0]=rand();
        brac[i][1]=rand();
    }
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
            {
                day[i][j][k]=rand();
            }
        }
    }
    cin>>n;
    char str[5];
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&aged[i]);
    }
    for(int i=1; i<n; i++)
    {
        scanf("%d%d%s",&l,&k,str);
        vc[l].pb(k);
        deg[k]=1;
        int c=0;
        if(str[0]=='E')
            c=1;
        cost[l].pb(c);
    }
    int root=find(n);
    dfs(root,1);
    int Q;
    cin>>Q;
    while(Q--)
    {
        scanf("%d",&n);
        clr(n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&aged[i]);
        }
        for(int i=1; i<n; i++)
        {
            scanf("%d%d%s",&l,&k,str);
            vc[l].pb(k);
            deg[k]=1;
            int c=0;
            if(str[0]=='E')
                c=1;
            cost[l].pb(c);
        }
        int root2=find(n);
       pii rs= dfs(root2,0);
       if(s.find(rs)!=s.end())printf("YES\n");
       else printf("NO\n");
    }
}
