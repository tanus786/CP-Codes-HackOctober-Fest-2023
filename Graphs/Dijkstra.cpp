#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>

const ll INF=1e18+1000;

void dijkstra()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<pll>> adj(n, vector<pll>());
    for(ll i=0; i<m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;

        u--; v--;
        adj[u].push_back({v, w});
    }

    ll src = 0;
    vector<ll> d(n, INF);
    d[src] = 0;
    set<pll> set;
    set.insert({d[src], src});

    while(!set.empty()) {
        auto it = set.begin();
        set.erase(it);

        ll curr_n = (*it).second; // curr node
        ll curr_d = (*it).first; // distance from src to curr

        for(auto opt: adj[curr_n]) {

            ll next_n = opt.first; // neighbour node
            ll next_d = opt.second; // edge weight between curr and neighbour

            if(curr_d+next_d < d[next_n]) {
                auto dit = set.find({d[next_n], next_n});
                if(dit != set.end()) {
                    set.erase(dit);
                }

                d[next_n] = curr_d+next_d;
                set.insert({d[next_n], next_n});
            }
        }
    }

    for(ll i=0; i<n; i++) cout << d[i] << " ";

    cout << '\n';

    return;
}

int main()
{
    dijkstra();

    return 0;
}
