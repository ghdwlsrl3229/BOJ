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

int K;
int x, y;
int arr[220][220];
bool poss;

/*
1.	01	2.	10	3.	11	4.	11
	11		11		01		10
*/

int num = 1;
void Lshape(int sx, int sy, int sz, int type) {
	if (sz == 2) {
		for (int i = sx; i < sx + sz; i++)
			for (int j = sy; j < sy + sz; j++) {
				if (i == sx && j == sy + 1 && type == 1) continue;
				if (i == sx + 1 && j == sy + 1 && type == 2) continue;
				if (i == sx && j == sy && type == 3) continue;
				if (i == sx + 1 && j == sy && type == 4) continue;
				arr[i][j] = num;
			}
		num++;
		return;
	}

	if (type == 1) {
		Lshape(sx, sy, sz / 2, 2);
		Lshape(sx + sz / 2, sy, sz / 2, 1);
		Lshape(sx + sz / 2, sy + sz / 2, sz / 2, 3);
		Lshape(sx + sz / 4, sy + sz / 4, sz / 2, 1);
	}
	else if (type == 2) {
		Lshape(sx, sy, sz / 2, 2);
		Lshape(sx, sy + sz / 2, sz / 2, 4);
		Lshape(sx + sz / 2, sy, sz / 2, 1);
		Lshape(sx + sz / 4, sy + sz / 4, sz / 2, 2);
	}
	else if (type == 3) {
		Lshape(sx + sz / 2, sy + sz / 2, sz / 2, 3);
		Lshape(sx + sz / 2, sy, sz / 2, 1);
		Lshape(sx, sy + sz / 2, sz / 2, 4);
		Lshape(sx + sz / 4, sy + sz / 4, sz / 2, 3);
	}
	else if (type == 4) {
		Lshape(sx, sy, sz / 2, 2);
		Lshape(sx, sy + sz / 2, sz / 2, 4);
		Lshape(sx + sz / 2, sy + sz / 2, sz / 2, 3);
		Lshape(sx + sz / 4, sy + sz / 4, sz / 2, 4);
	}
}

void square(int sx, int sy, int sz) {
	if (sz == 2) {
		for (int i = sx; i < sx + 2; i++)
			for (int j = sy; j < sy + 2; j++)
				if (arr[i][j] != -1) arr[i][j] = num;
		num++;
		return;
	}

	if (sx <= x && x < sx + sz / 2) {
		if (sy <= y && y < sy + sz / 2) {
			square(sx, sy, sz / 2);
			Lshape(sx, sy, sz, 3);
		}
		else {
			square(sx, sy + sz / 2, sz / 2);
			Lshape(sx, sy, sz, 1);
		}
	}
	else {
		if (sy <= y && y < sy + sz / 2) {
			square(sx + sz / 2, sy, sz / 2);
			Lshape(sx, sy, sz, 4);
		}
		else {
			square(sx + sz / 2, sy + sz / 2, sz / 2);
			Lshape(sx, sy, sz, 2);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> K >> x >> y;
	x--, y--;

	arr[x][y] = -1;
	square(0, 0, 1 << K);

	for (int i = (1 << K) - 1; i >= 0; i--) {
		for (int j = 0; j < (1 << K); j++)
			cout << arr[j][i] << ' ';
		cout << '\n';
	}
	return 0;
}
