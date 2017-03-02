#define ALL(C) (C).begin(), (C).end()
#define forN(I, C) for(int I=0; I<int(C); ++I)
#define forEach(I, C) for(int I=0; I<int((C).size()); ++I)
#define forN1(I, C) for(int I=1; I<=int(C); ++I)
#define forEach1(I, C) for(int I=1; I<=int((C).size()); ++I)
#define PI 3.14159265358979323846
#define STR(s) to_string(s)
#define INT(S) stoi(S)
#define PB(V) push_back(V)

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <queue>

using namespace std;

typedef vector<string> VS;
typedef queue<int> QI;

int g[1000][1000];
int u[1000];
int a[1000];
int p[1000];

void clearAll() {
	forN(i, 1000) {
		forN(j, 1000) {
			g[i][j] = 0;
		}
	}

	forN(i, 1000) {
		u[i] = 0;
		a[i] = p[i] = -1;
	}
}

QI q;
void bfs(int node) {
	q.push(node);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (u[node]) {
			continue;
		}

		u[node] = 1;
		a[node] = p[node] != -1 ? a[p[node]] + 1 : 0;
		forN(i, 1000) {
			if (g[node][i] && !u[i]) {
				q.push(i);
				p[i] = node;
			}
		}
	}
}

void solve(int n, int m, int s) {
	bfs(s);
	int first = 1;
	forN(i, n) {
		if (i == s) {
			continue;
		}

		int value = a[i] != -1 ? a[i] * 6 : -1;

		if (first) {
			cout << value;
			first = 0;
			continue;
		}

		cout << " " << value;
	}
	cout << endl;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int qu, n, m, u1, v1, s;

	cin >> qu;
	forN(i, qu) {
		cin >> n;
		cin >> m;

		clearAll();
		forN(j, m) {
			cin >> u1;
			cin >> v1;
			g[u1 - 1][v1 - 1] = g[v1 - 1][u1 - 1] = 1;
		}

		cin >> s;

		solve(n, m, s - 1);
	}

	return 0;
}