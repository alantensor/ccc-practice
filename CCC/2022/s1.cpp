#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int count = 0;

	for (int a = n / 4; a >= 0; a--) {
		if ((n - 4 * a) % 5 == 0) count++;
	}
	cout << count << endl;

	return 0;
}