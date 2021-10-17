//BridgeCutVertex
void visit(int u, int par) {
	int child = 0; low[u] = num[u] = ++tin;
	for (auto v : adj[u]) if (v != par) {
		if (num[v]) low[u] = min(low[u], num[v]);
		else {
			visit(v, u); child++;
			low[u] = min(low[u], low[v]);
			if (low[v] >= num[v]) b.push_back({u ,v});
			if (u == par) { if (child >= 2) node[u] = true; }        
			else { if (low[v] >= num[u]) node[u] = true; }
		}
	}
}
//Bridge
void visit(int u){
    low[u] = vis[u] = ++cnt;
    for (int i = 0, v; v = a[u][i]; i++)
    if (v != par[u]){
        if (vis[v]) minimize(low[u], vis[v]);
        else {
            par[v] = u; visit(v); minimize(low[u], low[v]);
            if (low[v] >= vis[v]) Bridge.push_back(mp(u,v));
        }
    }
}
