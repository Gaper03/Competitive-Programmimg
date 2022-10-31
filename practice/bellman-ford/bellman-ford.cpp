#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

#define DBG(x) cout << "[" << #x << "]: " << x << '\n'
#define mset(a, b) memset(a, b, sizeof(a))

#define MXN 5005

using ll = long long;
using pii = pair<int, int>;


const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
  
  // The problem consists on finding out whether the given graph has a negative cycle or not.
  // There is an algorithm that can be used to solve this problem, called Bellman-Ford algorithm.
  // We select a root node and create an array to save the minimum distance from each node to the root.
  // Then we iterate N times updating the minimum distances, comparing each of them with an edge that connects
  // the respective node to another. An update made in the last iteration means that the graph has a negative cycle.
   
  
	int n, m;
	cin >> n >> m;
	
	ll edges[MXN][3];
	
	for (int i = 0; i < m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		
		edges[i][0] = u-1;
		edges[i][1] = v-1;
		edges[i][2] = w;
	}
	
	vector<int> minDist(n, INF);
	minDist[0] = 0;
	
	bool hasNegativeCycle = false;
	
	for (int i = 0; i < n; i++) {
		bool changed = false;
		for (int j = 0; j < m; j++) {
			ll u, v, w;
			u = edges[j][0];
			v = edges[j][1];
			w = edges[j][2];
			
			if (minDist[v] > minDist[u] + w) {
				minDist[v] = minDist[u] + w;
				changed = true;
			}
		}
		if (i + 1 == n && changed == true)
			hasNegativeCycle = true;
	}
	
	if (hasNegativeCycle)
		cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}
