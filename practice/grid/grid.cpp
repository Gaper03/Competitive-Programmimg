#include<bits/stdc++.h>
using namespace std;

#define MAXD 1005
#define DBG(x) cout << "[" << #x << "]: " << x << '\n'

const int MOD = 1e9 + 7;
const char WALL_C = '#';

int h, w;
int nPaths = 0;
char board[MAXD][MAXD];
int paths[MAXD][MAXD];

int getPaths(int x, int y);

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> h >> w;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char c;
			cin >> c;
			
			if (c == '\n') cin >> c;
			
			board[i][j] = c;
			paths[i][j] = -1;
		}
	}
	paths[h-1][w-1] = 1;
	cout << getPaths(0, 0) << endl;
	
	return 0;
}

int getPaths(int x, int y)
{
	if (x >= h || y >= w || board[x][y] == WALL_C) return 0;
	
	if (paths[x][y] >= 0) return paths[x][y];
	
	int tot = (getPaths(x+1, y) + getPaths(x, y+1)) % MOD;
	paths[x][y] = tot;
	return tot;
}
