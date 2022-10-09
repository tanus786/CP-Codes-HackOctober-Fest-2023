// #include<bits/stdc++.h>
// #define ll long long
// #define vi vector<int>
// #define vl vector<ll>
// #define pb push_back
// #define ff first
// #define ss second
// #define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
// using namespace std;

// int main()
// {
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
// int v,e;
// cin>>v>>e;
// vector<pair<int,int>> g[v+1];
// int a,b,wt;
// for(int i=0;i<e;i++)
// {
//     cin>>a>>b>>wt;
//     g[a].pb({b,wt});
//     g[b].pb({a,wt});
// }
// cout<<"Enter Source:";
// int src;
// cin>>src;
// priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;// min heap (dis,from)
// vector<int> dis(v+1,INT_MAX); // dis array
// dis[src]=0;
// pq.push(make_pair(0,src)); //(dis,from)
// while(!pq.empty())
// {
//     int dist=pq.top().first;
//     int pre=pq.top().second;
//     pq.pop();
//     for(auto it:g[pre])
//     {
//         int next=it.first;
//         int nextdis=it.second;
//         if(dis[next]>dist+nextdis)
//         {
//             dis[next]=dis[pre]+nextdis;
//             pq.push(make_pair(dis[next],next));
//         }

//     }
// }
// cout<<"THE distance from src are:"<<endl;
// for(int i=1;i<=v;i++)
// {
// cout<<i<<"------>"<<dis[i]<<endl;
// }
// return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
class Heap
{
public:
    pair<int, int> *heap;
    int size = 0;
    Heap(int n)
    {
        heap = new pair<int, int>[n];
        size = 0;
    }
    void min_heapify(int i)
    {
        int largest = i;
        int lc = (2 * i) + 1;
        int rc = (2 * i) + 2;
        if (lc < size && heap[lc].second < heap[largest].second)
            largest = lc;
        if (rc < size && heap[rc].second < heap[largest].second)
            largest = rc;
        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            min_heapify(largest);
        }
    }
    pair<int, int> top()
    {
        if (!size)
            return {0, 0};
        else
            return heap[0];
    }
    bool empty()
    {
        return size == 0;
    }
    void pop()
    {
        pair<int, int> lastElement = heap[size - 1];
        heap[0] = lastElement;
        size = size - 1;
        min_heapify(0);
    }
    void push(pair<int, int> key)
    {
        size = size + 1;
        heap[size - 1] = key;
        min_heapify(size - 1);
    }
};
vector<pair<int, int>> adj[100000];
void dijkstra(int v, int e)
{
    int src;
    cout << "Enter the source vertex : ";
    cin >> src;
    Heap pq(v + 1);
    vector<int> dist(v + 1, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        int prev = pq.top().second;
        pq.pop();
        for (auto i : adj[prev])
        {
            int next = i.first;
            int nextDist = i.second;
            if (dist[next] > dist[prev] + nextDist)
            {
                dist[next] = dist[prev] + nextDist;
                pq.push({dist[next], next});
            }
        }
    }
    cout << "The distances from source, " << src << " to all the 
        vertices in the Graph are \n ";
        cout<< endl;
    for (int i = 1; i <= v; i++)
    {
        cout << src << " ---> " << i << " distance : " << dist[i] << "\n ";
    }
    cout << endl;
}
int main()
{
    int v, e, a, b, wt;
    cout << "Enter The number of vertices in the graph : ";
    cin >> v;
    cout << "Enter The number of edges in the graph : ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }
    dijkstra(v, e);
    return 0;
}
