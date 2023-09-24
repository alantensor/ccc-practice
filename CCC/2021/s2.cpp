#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define pii pair<int, int>
#define f first
#define s second
#define ll long long
#define lld long double
#define EACH(x, a) for (auto& x: a)
#define PI 3.14159265358979323846
#define vt vector
#define ONLINE_JUDGE
// #define TEST_CASE
// const int MOD = 1e9 + 7;

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	vt<bool> R(n + 1, 0), C(m + 1, 0);
	while (q--) {
		char a;
		int x;
		cin >> a >> x;
		if (a == 'R')
			R[x] = !R[x];
		else C[x] = !C[x];
	}
	vt<vt<bool>> grid(n + 1, vt<bool>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		if (R[i]) grid[i].flip();
	}

	for (int i = 1; i <= m; i++) {
		if (C[i]) {
			for (int a = 1; a <= n; a++) {
				grid[a][i] = !grid[a][i];
			}
		}
	}
	int c = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (grid[i][j]) c++;
		}
	}
	cout << c << endl;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	auto begin = chrono::high_resolution_clock::now();
#endif


#ifdef TEST_CASE
	int tc, i = 1;
	cin >> tc;
	while (tc--) {
		// cout << "Case #" << i << ": ";
		solve();
		i++;
	}

	return 0;
#endif

	solve();

#ifndef ONLINE_JUDGE
	auto end = chrono::high_resolution_clock::now();
	ofstream os;
	os.open("time.txt");
	os << setprecision(4) << fixed;
	os << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	os.close();
#endif

	return 0;
}




