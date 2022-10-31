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
	
	int n, m, q;
	cin >> n >> m >> q;
	
	// n = cities;
	// m = roads;
	// q = queries;
	
	int** distMatrix = (int**)malloc((n+1) * sizeof(int*));
	
	for (int i = 1; i <= n; i++) {
		distMatrix[i] = (int*)malloc((n+1) * sizeof(int));
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
         		 		// for each value k, from 1 to n, we fix the k-row, k-line and the main diagonal
          				// then we update the other values in the matrix by checking if the distance from
          				// node i to node j is bigger than the distance from i to k + from k to j
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
