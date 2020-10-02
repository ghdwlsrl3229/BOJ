#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
#define ll long long
#define fr first
#define sc second
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()

int main() {
	int t; cin >> t;
	while (t--) {
		double m, n; scanf("%lf%lf", &m, &n);

		double ans = n / 2;
		ans += (m*m - 1) / (3 * m);
		printf("%.1lf\n", ans);
	}
	return 0;
}
