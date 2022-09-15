#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

#define DBG(x) cout << "[" << #x << "]: " << x << '\n'
#define mset(a, b) memset(a, b, sizeof(a))

using ll = long long;
using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;
const int MXN = 1e5 + 5;
const int B_SIZE = 8;
const int HAS_QUEEN = -1;
const int UNVISITED = 0;

int cont = 0;
int max_points = 0;

vector<int> b_weight[B_SIZE];
vector<int> b_visited[B_SIZE];

void update_square(int x, int y, int sum)
{
	if (x >= 0 && x < B_SIZE && y >= 0 && y < B_SIZE)
		if (b_visited[y][x] != HAS_QUEEN) b_visited[y][x] += sum;
}

void update_range(int x, int y, bool add)
{
	int sum = add ? 1 : -1;
	
	for (int i = 0; i < B_SIZE; i++) {
		// VERTICAL AND HORIZONTAL
		update_square(i, y, sum);
		update_square(x, i, sum);
		
		// DIAGONALS
		
		// bottom right
		update_square(x+i, y+i, sum);
		
		// bottom left
		update_square(x-i, y+i, sum);
		
		// top right
		update_square(x+i, y-i, sum);
		
		// top left
		update_square(x-i, y-i, sum);
	}
}


void add_queen(int x, int y, int sum)
{
	// means that a queen has been added to each of the 8 previous rows;
	// this means that 8 queens have been placed (which is the goal)
	if (y >= B_SIZE) {
		if (sum > max_points) max_points = sum;
		return;
	}
	
	// place (x, y) is safe from other queens
	if (b_visited[y][x] == UNVISITED) {
		b_visited[y][x] = HAS_QUEEN;
		update_range(x, y, true);
		for (int i = 0; i < B_SIZE; i++) {
			add_queen(i, y+1, sum + b_weight[y][x]);
		}
		update_range(x, y, false);
		b_visited[y][x] = UNVISITED;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	for (int c = 0; c < n; c++) {
		// clearing global vectors and variables
		max_points = 0;
		for (int i = 0; i < B_SIZE; i++) {
			b_visited[i].clear();
			b_weight[i].clear();
		}
		
		// reading from input weights for each square on the board
		// setting each square on the board as 'not visited' (zero)
		for (int i = 0; i < B_SIZE; i++) {
			for (int j = 0; j < B_SIZE; j++) {
				int x; cin >> x;
				b_weight[i].pb(x);
				b_visited[i].pb(UNVISITED);
			}
		}
		
		// starts by adding a queen to a square in the first row
		// and recursively adding new queens to the other rows
		for (int i = 0; i < B_SIZE; i++) {
			add_queen(i, 0, 0);
		}
		
		cout << right << setw(5) << max_points << endl;
	}
	
	return 0;
}
