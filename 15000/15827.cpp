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

struct node {
	int val;
	string child1, child2, op;
};

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
pll add(pll a, pll b) {
	pll ret = { a.fr * b.sc + b.fr * a.sc, a.sc * b.sc };
	ll g = gcd(ret.fr, ret.sc);
	return { ret.fr / g, ret.sc / g };
}
pll sub(pll a, pll b) {
	return add(a, { -b.fr, b.sc });
}
pll mul(pll a, pll b) {
	pll ret ={ a.fr * b.fr, a.sc * b.sc };
	ll g = gcd(ret.fr, ret.sc);
	return { ret.fr / g, ret.sc / g };
}
pll div(pll a, pll b) {
	return mul(a, { b.sc, b.fr });
}

map<string, int> mp;
node tree[1100];
pll w[1100]; //first / second
pll v[1100]; //노드에 저장된 값
int N;

void dfs(string s) {
	int n = mp[s];
	if (tree[n].op == "E") {
		v[n] = { tree[n].val, 1 };
	}
	else {
		dfs(tree[n].child1);
		dfs(tree[n].child2);
		int c1 = mp[tree[n].child1], c2 = mp[tree[n].child2];

		if (tree[n].op == "A") v[n] = add(v[c1], v[c2]);
		else if (tree[n].op == "S") v[n] = sub(v[c1], v[c2]);
		else if (tree[n].op == "M") v[n] = mul(v[c1], v[c2]);
		else if (tree[n].op == "D") v[n] = div(v[c1], v[c2]);
	}
}

void dfs2(string s) {
	int n = mp[s];
	if (tree[n].op == "E") return;
	else {
		int c1 = mp[tree[n].child1], c2 = mp[tree[n].child2];

		if (tree[n].op == "A") {
			w[c1] = w[c2] = w[n];
		}
		else if (tree[n].op == "S") {
			w[c1] = w[n];
			w[c2] = { -w[n].fr, w[n].sc };
		}
		else if (tree[n].op == "M") {
			w[c1] = div(w[n], v[c2]);
			w[c2] = div(w[n], v[c1]);
		}
		else if (tree[n].op == "D") {
			w[c1] = mul(w[n], v[c2]);
			w[c2] = mul({ -w[c1].fr, w[c1].sc }, div(v[c2], v[c1]));
		}

		dfs2(tree[n].child1);
		dfs2(tree[n].child2);
	}
}

void solve(int tc) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string a, op;
		cin >> a >> op;
		mp[a] = i;
		tree[i].op = op;
		if (op == "E") {
			int b; cin >> b;
			tree[i].val = b;
		}
		else {
			string b, c; cin >> b >> c;
			tree[i].child1 = b;
			tree[i].child2 = c;
		}
	}
	dfs("HAPPY");
	w[mp["HAPPY"]] = { 1, 1 };
	dfs2("HAPPY");
	
	for (int i = 0; i < N; i++) {
		ll g = gcd(w[i].fr, w[i].sc);
		w[i] = { w[i].fr / g, w[i].sc / g };
		if (w[i].fr < 0) w[i] = { w[i].fr * -1, w[i].sc * -1 };
		if (w[i].fr < 0 && w[i].sc < 0) w[i] = { w[i].fr * -1, w[i].sc * -1 };
	}

	for (auto i : mp) {
		cout << i.fr << ' ' << w[i.sc].sc << '/' << w[i.sc].fr << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	if (0) {
		int T; cin >> T;
		for (int i = 1; i <= T; i++) solve(i);
	}
	else {
		solve(0);
	}
	return 0;
}
