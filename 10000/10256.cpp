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

struct TrieNode {
	int terminal;
	int output;
	TrieNode* fail;
	TrieNode* children[4];
	TrieNode() : terminal(0), output(0) {
		memset(children, 0, sizeof(children));
	}
	~TrieNode() {
		for (int i = 0; i < 4; i++)
			if (children[i]) delete children[i];
	}
};

int tonum(char ch) {
	if (ch == 'A') return 0;
	else if (ch == 'C') return 1;
	else if (ch == 'G') return 2;
	else return 3;
}

void insert(TrieNode* root, const string& key) {
	TrieNode* pos = root;
	for (int i = 0; i < key.size(); i++) {
		if (pos->children[tonum(key[i])] == NULL)
			pos->children[tonum(key[i])] = new TrieNode();
		pos = pos->children[tonum(key[i])];
	}
	pos->terminal = 1;
	pos->output++;
}

void computeFailFunc(TrieNode * root) {
	queue<TrieNode*> q;
	root->fail = root;
	q.push(root);
	while (q.size()) {
		TrieNode* here = q.front();
		q.pop();

		for (int edge = 0; edge < 4; edge++) {
			TrieNode* child = here->children[edge];
			if (!child) continue;
			if (here == root) child->fail = root;
			else {
				TrieNode* t = here->fail;
				while (t != root && t->children[edge] == NULL)
					t = t->fail;
				if (t->children[edge]) t = t->children[edge];
				child->fail = t;
			}
			child->output = child->fail->output;
			if (child->terminal) child->output++;
			q.push(child);
		}
	}
}

ll ahoCorasick(const string& s, TrieNode* root) {
	ll ret = 0;
	TrieNode* state = root;
	for (int i = 0; i < s.size(); i++) {
		int chr = tonum(s[i]);
		while (state != root && state->children[chr] == NULL) state = state->fail;
		if (state->children[chr]) state = state->children[chr];
		ret += state->output;
	}
	return ret;
}

TrieNode* root;

void solve() {
	int n, m; cin >> n >> m;
	string dna, marker;
	cin >> dna >> marker;
	root = new TrieNode();

	for (int i = 0; i < m; i++)
		for (int j = i; j < m; j++) {
			string s = "";
			for (int k = 0; k < i; k++) s += marker[k];
			for (int k = j; k >= i; k--) s += marker[k];
			for (int k = j + 1; k < m; k++) s += marker[k];
			insert(root, s);
		//	cout << s << '\n';
		}
	computeFailFunc(root);

	cout << ahoCorasick(dna, root) << '\n';
	delete root;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while (T--) solve();
	return 0;
}
