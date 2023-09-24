#include <bits/stdc++.h>
using namespace std;
#define vt vector
#define PB push_back
#define f first
#define s second
#define EACH(x, a) for (auto& x: a)

void solve() {
	int n, m;
	cin >> n;
	vt<pair<string, string>> like(n);
	for (int i = 0; i < n; i++) {
		string x, y;
		cin >> x >> y;
		like[i] = {x, y};
		// cout << like[i].f << endl;
	}

	vt<pair<string, string>> seen;

	cin >> m;
	vt<pair<string, string>> hate(m);
	for (int i = 0; i < m; i++) {
		string x, y;
		cin >> x >> y;
		hate[i] = {x, y};
		// cout << hate[i].f << " " << hate[i].s << endl;
	}
	int g;
	int ans = 0;
	cin >> g;
	vt<vt<string>> temp(g, vt<string>(3));
	for (int i = 0; i < g; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> temp[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		int check = 0;
		for (int j = 0; j < g; j++) {
			for (int k = 0; k < 3; k++) {
				if (temp[j][k] == like[i].f) check++;
				if (temp[j][k] == like[i].s) check++;
			}
			if (check != 2 && check != 0) {
				seen.PB(like[i]);
				ans++;
				break;
			}
		}
		// cout << ans << endl;
	}

	for (int i = 0; i < m; i++) {

		int check = 0;
		pair<string, string> z = hate[i];
		EACH(x, seen) {
			if ((z.f == x.f && z.s == x.s) || (z.s == x.f && z.f == x.s)) {
				ans++;
				continue;
			}
			// cout << "same" << endl;
		}


		for (int j = 0; j < g; j++) {
			check = 0;
			for (int k = 0; k < 3; k++) {
				if (temp[j][k] == hate[i].f) check++;
				if (temp[j][k] == hate[i].s) check++;
			}
			// cout << check << endl;
			if (check == 2) {
				ans++;
				break;
			}
		}
		// cout << ans << endl;
	}

	cout << ans << endl;


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	solve();

	return 0;
}