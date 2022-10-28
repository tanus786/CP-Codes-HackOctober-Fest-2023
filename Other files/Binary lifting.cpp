#include<bits/stdc++.h>
using namespace std;

// the total number of nodes in the tree
#define N 7

// log(N)
#define LG 5


//Find out the parent and level of each node using a depth first search
void dfs(int s, vector<int> graph[], int &depth, int parent[], int level[], int visited[]){
	
	visited[s] = 1;
	
	level[s] = depth;
	
	for(int i = 0; i < graph[s].size(); i++){
		if(!visited[graph[s][i]]){
		    
		    //going one level deeper
			depth++;
			
			dfs(graph[s][i], graph, depth, parent, level, visited);
			
		    parent[graph[s][i]]=s;
			
			//backtracking to the parent node
			depth--;
		}
	}
}

void findKth(int a, int k, int dp[][LG]){
    
    int c = a;
    
    int cur_level = k;
    
    for(int i = LG; i >= 0; i--){
        if(dp[c][i] != -1 && (1 << i) <= cur_level){
            c = dp[c][i];
            cur_level = cur_level - (1 << i);
        }
    }
    
    cout << "The " << k << "nd ancestor of " << a << " is " << c << '\n';
    
}

void lca(int a, int b, int level[], int dp[][LG], int parent[]){
	
	int lg;
	
	if(level[a]<level[b])
	    swap(a,b);
	
	//calculate the maximum value of height we might need
	for(lg =0 ; (1<<lg) <= level[a]; lg++);
	
	
	// find the ancestor of a at the same level of b
	for(int i = lg - 1; i >= 0; i--)
		if((level[a] - (1<<i)) >= level[b]){
			a = dp[a][i];
		}
		
	if(a == b){
	    cout << "The lowest common ancestor of a and b is " << a << '\n';
        return;
	}
	
	// find the lowest ancestors of a and b which are not equal
	for(int i = lg; i >= 0; i--){
		if(dp[a][i] != dp[b][i]){
			a = dp[a][i];
			b = dp[b][i];
		}
	}
	cout << "The lowest common ancestor of a and b is " << parent[a] << '\n';
}

void precalculate(int dp[N][LG], int parent[]){

    
    
    //initialize 2^0 th ancestor as parent
    for(int i = 0; i < N; i++)
        dp[i][0] = parent[i];
    
    for(int h = 1; h < LG; h++){
        for(int i = 0; i < N; i++){
            if(dp[i][h-1] != -1)
                dp[i][h] = dp[dp[i][h-1]][h-1];
        }
    }
    
}
int main(){
    
    //adjacency list to store the graph
    vector<int> graph[N];
    
    int parent[N], level[N], visited[N], dp[N][LG];
    
    //intialize all arrays with zero
    memset(parent, 0, sizeof(parent));
    memset(level, 0, sizeof(level));
    memset(visited, 0, sizeof(visited));
    
    
    //initialize dp table with -1(which denotes unreachable ancestor)
    memset(dp, -1, sizeof(dp));
    
    /* create an undirected graph of the structure:
            0
          /   \
         1     2
        / \   / \
       3   4 5   6
    */
    
    
    graph[0].push_back(1);
    graph[1].push_back(0);
    graph[0].push_back(2);
    graph[2].push_back(0);
    graph[1].push_back(3);
    graph[3].push_back(1);
    graph[1].push_back(4);
    graph[4].push_back(1);
    graph[2].push_back(5);
    graph[5].push_back(2);
    graph[2].push_back(6);
    graph[6].push_back(2);
    
    
    int depth = 0;
    dfs(0, graph, depth, parent, level, visited);
    
    precalculate(dp, parent);
    
    //find out the 2nd ancestor of node 3
    findKth(3, 2, dp);
    
    //find LCA of 5 and 6
    lca(5, 6, level, dp, parent);
    
    
}
