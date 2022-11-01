#include<bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

#define db(x) cout << "db " << x << endl
#define mset(a, b) memset(a, b, sizeof(a))

#define MXN 505

using ll = long long;
using pll = pair<ll, ll>;

const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
  
  // This problem consists on finding the minimum distance between N pairs of nodes in a given graph.
  // There is a good algorithm that can solve it in cubic complexity, called Floyd-Warshall algorithm.
  // We basically create a matrix of minimum distances between pairs of nodes.
  
	int n, m, q;
	cin >> n >> m >> q;
	
	// n = cities;
	// m = roads;
	// q = queries;
	
	ll** distMatrix = (ll**)malloc((n+1) * sizeof(ll*));
	
	for (int i = 1; i <= n; i++) {
		distMatrix[i] = (ll*)malloc((n+1) * sizeof(ll));
		for (int j = 1; j <= n; j++) {
			distMatrix[i][j] = INF;
		}
	}
	
	for (int i = 0; i < m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		
		distMatrix[u][v] = w;
		distMatrix[v][u] = w;
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != k && j != k && i != j) {
					ll dij = distMatrix[i][j];
					ll dik = distMatrix[i][k];
					ll dkj = distMatrix[k][j];
					if (dij > dik + dkj) {
						distMatrix[i][j] = dik + dkj;
					}
				}
			}
		}
	}
	
	
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		ll dist = distMatrix[a][b] != INF ? distMatrix[a][b] : -1;
		cout << dist << endl;	
	}
	
	for (int i = 1; i <= n; i++) {
		free(distMatrix[i]);
	}
	free(distMatrix);
	return 0;
}
