#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int unf[10001];

struct Edge {
	int s, e, val;
	Edge(int a, int b, int c) {
		s = a;
		e = b;
		val = c;
	}
	bool operator<(const Edge& p)const {
		return val < p.val;
	}
};

int Find(int v) {
	if (v == unf[v]) return v;
	else return unf[v] = Find(unf[v]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, res = 0, a, b, c;
	vector<Edge> Ed;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		Ed.push_back(Edge(a, b, c));
	}
	for (int i = 1; i <= v; i++) {
		unf[i] = i;
	}
	sort(Ed.begin(), Ed.end());
	for (int i = 0; i < e; i++) {
		int fa = Find(Ed[i].e);
		int fb = Find(Ed[i].s);
		if (fa != fb) {
			res += Ed[i].val;
			Union(Ed[i].s, Ed[i].e);
		}
	}
	cout << res << endl;
	return 0;
}
