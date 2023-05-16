#include <cstdio>
#include <vector>
using namespace std;

#define MAX 101
#define MAXN 5010
int mat[MAX][MAX];
char m[MAX][MAX];
int N;

vector<int> adj[MAXN];
vector<int> left(MAXN, -1);
vector<int> right(MAXN, -1);
vector<bool> visit(MAXN, false);
int row, col;
void make_adj() {
	char pre = 'X';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (m[i][j] == '.') {
				if (pre != '.') row++;
				mat[i][j] = row;
			}
			pre = m[i][j];
		}
		pre = 'X';
	}

	pre = 'X';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (m[j][i] == '.') {
				if (pre != '.') col++;
				adj[mat[j][i]].push_back(col);
			}
			pre = m[j][i];
		}
		pre = 'X';
	}
}
bool dfs(int now) {
	visit[now] = true;
	for (int next : adj[now]) {
		//next�� ��Ī�� �ȵǾ��ְų�,
		//next�� ��Ī�� left (=right[next])�� �ٸ����� ��Ī�����ϸ�(=dfs(right[next]))
		if (right[next] == -1 || (!visit[right[next]] && dfs(right[next]))) {
			left[now] = next;
			right[next] = now;
			return true;
		}
	}
	return false;
}
int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &m[i][j]);
		}
	}

	make_adj();

	int match = 0;
	for (int i = 1; i <= row; i++) {
		fill(visit.begin(), visit.end(), false);
		if (dfs(i)) match++;
	}

	printf("%d", match);
	return 0;
}