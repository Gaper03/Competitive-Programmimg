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
const int MXN = 6;
const int MXK = 9;
const int NVIS = 0;
const int VIS = 1;

vector<char> l_m[MXN+1];
vector<int> visited[MXN+1];
char word[MXK+1];
int max_x;
int max_y;

bool check(int x, int y, int c_index, int c_left)
{
	// coordinates out of bound
	if (x < 0 || y < 0 || x > max_x || y > max_y) return false;
	
	// coordinate has been visited before
	if (visited[x][y] == VIS) return false;
	
	// coordinate does not contain the desired character
	if (l_m[x][y] != word[c_index]) return false;
	
	// all characters have been found
	if (c_left == 1) return true;
	
	
	visited[x][y] = VIS;
	if (check(x+1, y, c_index+1, c_left-1)) return true;
	if (check(x-1, y, c_index+1, c_left-1)) return true;
	if (check(x, y+1, c_index+1, c_left-1)) return true;
	if (check(x, y-1, c_index+1, c_left-1)) return true;
	visited[x][y] = NVIS;
	return false;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int x, y; cin >> x >> y;
	
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			char c; cin >> c;
			l_m[i].pb(c);
			visited[i].pb(NVIS);
		}
	}
	
	int k; cin >> k;
	for (int i = 0; i < k; i++) cin >> word[i];
	word[k] = '\0';
	
	max_x = x - 1;
	max_y = y - 1;
	bool found = false;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (check(i, j, 0, k)) {
				found = true;
				break;
			}
		}
	}
	
	if (found) cout << "Yes\n";
	else cout << "No\n";
	
	return 0;
}
