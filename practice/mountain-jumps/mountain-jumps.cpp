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

int getHeightDiff(int mh1, int mh2) { return abs(mh1 - mh2); }

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	
	if (n < 1) {
		cout << 0 << endl;
		return 0;
	}
	
	vector<int> mountains;
	for (int i = 0; i < n; i++) {
		int mountainHeight;
		cin >> mountainHeight;
		mountains.pb(mountainHeight);
	}
	
	if (n == 1) {
		cout << 0 << endl;
	} else if (n == 2) {
		cout << getHeightDiff(mountains[0], mountains[1]) << endl;
	} else {
		vector<int> minDist(n);
		
		minDist[1] = getHeightDiff(mountains[0],mountains[1]);
		
		for (int i = 2; i < n; i++) {
			int distToPrev1M = getHeightDiff(mountains[i-1], mountains[i]);
			int distToPrev2M = getHeightDiff(mountains[i-2], mountains[i]);
			minDist[i] = min(minDist[i-1] + distToPrev1M, minDist[i-2] + distToPrev2M);
		}
		
		cout << minDist[n-1] << endl;
	}
	
	return 0;
}
