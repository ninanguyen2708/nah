/* Des: tree distances (use to calc tree diameter)
 * Accuracy: high
 */
void dfs1(ll u, ll par = -1) {
	fir[u] = sec[u] = 0; vis[u] = 1;
	for (ll v : adj[u]) {
		if (v == par || vis[v]) continue; dfs1(v, u);
		if (fir[u] < fir[v] + 1) {
			sec[u] = fir[u]; pre[u] = v;
			fir[u] = fir[v] + 1; 
		} else maximize(sec[u], fir[v] + 1);
	}
}

void dfs2(ll u, ll par = -1) {
	for (ll v : adj[u]) {
		if (v == par) continue; 
		if (pre[u] == v) {
			if (fir[v] < sec[u] + 1) {
				sec[v] = fir[v]; pre[v] = u;
				fir[v] = sec[u] + 1;
			} else maximize(sec[v], sec[u] + 1);
		} else {
			sec[v] = sec[u]; pre[v] = u;
			fir[v] = fir[u] + 1; 
		}
		dfs2(v, u);
	}
}
// with nodes; if a node, just dfs from 1
mem(vis, 0); res = 0;
FOR(i, 1, n + 1) if (!vis[i]) dfs1(i), dfs2(i);
FOR(i, 1, n + 1) maximize(res, fir[i]);
