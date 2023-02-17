#include<iostream>
#include<climits>
#include<queue>
#include<algorithm>

using namespace std;
//prim
int ch[10001];
struct Edge {
	int e;
	int val;
	Edge(int a, int b) {
		e = a;
		val = b;
	}
	bool operator<(const Edge& p)const {
		return val > p.val;
	}
};
int main() {
	int a, b, c, res = 0, V, E;
	cin >> V >> E;
	priority_queue<Edge> pQ;
	vector<pair<int, int> > map[10001];

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));
	}
	pQ.push(Edge(1, 0));

	while (!pQ.empty()) {
		Edge temp = pQ.top();
		pQ.pop();
		int v = temp.e;
		int cost = temp.val;
		if (ch[v] == 0) {
			ch[v] = 1;
			res += cost;
			for (int i = 0; i < map[v].size(); i++) {
				pQ.push(Edge(map[v][i].first, map[v][i].second));
			}
		}
	}

	cout << res << endl;


	return 0;
}