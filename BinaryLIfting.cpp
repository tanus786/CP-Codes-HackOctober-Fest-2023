ll n, m;

vector<vector<ll>> adj;

struct LCA{

	vector<vector<ll>> lca;
	
	ll maxN;
	
	vi level;
	
	void dfs(ll curr, ll par, ll lev){
		lca[curr][0] = par;
		level[curr] = lev;
		for(auto a:adj[curr]){
			if(a == par)continue;
			dfs(a, curr, lev+1);
		}
	}

	void init(ll source){//the sorce will be the root node
		maxN = log2(n);
		lca.resize(n+1, vector<ll>((maxN+1), -1));
		level.resize(n+1);
		
		dfs(source, -1, 0);
		
		for(ll j=1; j<=maxN; j++){
			for(ll i=0; i<n; i++){
				if(lca[i][j-1] != -1){
					ll par = lca[i][j-1];//one of my ancestors
					lca[i][j] = lca[par][j-1];//one of the ancestors of ansestors
				}
			}
		}
	}
	
	ll lcA(ll a, ll b){
		if(level[a] > level[b]){
			swap(a,b);
		}
		ll d = level[b] - level[a];
		while(d > 0){
			ll i = log2(d);
			b = lca[b][i];
			d -= (1ll<<i);
		}
		
		if(a == b){
			return a;
		}
		
		for(ll i =maxN; i>=0; i--){
			if(lca[a][i] != -1 && (lca[a][i] != lca[b][i])){
				a = lca[a][i];
				b = lca[b][i];
			}
		}
		
		
		return lca[a][0];
	}
	
	ll dis(ll a, ll b){
		return level[a] + level[b] - 2*level[lcA(a,b)];
	}
};


void accept_ho_ja(){
    
    cin>>n>>m;
    
    ll x, y;
    cin>>x>>y;
    
    x--;y--;
    
    
    adj.resize(n);
    
    for(ll i=0; i<m; i++){
    	ll a, b;
    	cin>>a>>b;
    	a--;
    	b--;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    
    LCA lc;
    lc.init(0);//we will pass the root node
    
    
    // bug(lc.level[lcA(x,y)]);
    
    cout<<lc.dis(x,y);//calculate the distance between the nodes
    
}
