/* Des: khớp cầu
 * Accuracy: high
 */
struct Edge {
	int u, v;
	bool used; // đánh dấu cạnh đã thăm
	bool isBridge; // đánh dấu cạnh là cầu

	Edge(int _u = 0, int _v = 0) {
		u = _u; v = _v;
		used = false;
		isBridge = false;
	}
};

#define MAX   250250
int numNode, numEdge, cnt;
Edge edges[MAX];
vector<int> adj[MAX]; // lưu theo chỉ số cạnh, không phải là đỉnh kề
bool isCut[MAX]; // isCut[u] = true khi và chỉ khi u là khớp
int numChild[MAX]; // numChild[u] = số con của đỉnh u trên cây DFS

cin >> numNode >> numEdge;
for (int i = 1; i <= numEdge; i++) {
	int u, v; cin >> u >> v;
	edges[i] = Edge(u, v);
	adj[u].push_back(i);
	adj[v].push_back(i);
}

void dfs(int u) {
	low[u] = numNode + 1; // dương vô cùng
	num[u] = ++cnt;

	for (int index : adj[u]) if (!edges[index].used) { nếu cạnh chưa được sử dụng
		edges[index].used = true;
		int v = edges[index].u ^ edges[index].v ^ u;
		if (num[v] == 0) {
			numChild[u]++;
			dfs(v);
			minimize(low[u], low[v]);
			edges[index].isBridge = low[v] > num[u];
			isCut[u] |= low[v] >= num[u];
		} else minimize(low[u], num[v]);
	}
}

for (int i = 1; i <= numNode; i++) if (num[i] == 0) {
	dfs(i);
	// nếu i là gốc cây DFS và i có < 2 con thì i không phải là khớp
	if (numChild[i] < 2) isCut[i] = false; 
}
