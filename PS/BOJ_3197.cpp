#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> P;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

struct compare {
	bool operator()(P a, P b) {
		return get<2>(a) > get<2>(b);
	}
};

int R, C;
vector<vector<char>> map;
vector<vector<int>> day;	//������ ��� ��¥ ��ó��
vector<vector<int>> check;
pair<int, int> L[2];

void init() {
	scanf("%d %d", &R, &C);

	priority_queue<P, vector<P>, compare> Q;	//tuple<int, int, int> -> y��ǥ, x��ǥ, ������ ��³�
	map.resize(R, vector<char>(C));
	day.resize(R, vector<int>(C));
	check.resize(R, vector<int>(C, 0));

	int k = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %c", &map[i][j]);

			switch (map[i][j]) {
			case 'L':
				L[k++] = { i, j };	//L[0] ���� ������ġ, L[1] ���� ������ġ
			case '.':
				Q.push({ i, j, 0 });
				check[i][j] = -1;
			}
		}
	}

	while (!Q.empty()) {	//���� ��³�¥ ���

		int nowy = get<0>(Q.top());
		int nowx = get<1>(Q.top());
		int nowd = get<2>(Q.top());
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];

			if (ny >= 0 && ny < R && nx >= 0 && nx < C && check[ny][nx] == 0) {
				check[ny][nx] = -1;

				day[ny][nx] = nowd + 1;
				Q.push({ ny, nx, day[ny][nx] });
			}
		}
	}

	/*for (int i = 0; i < R; i++) {	//���� ��³�¥ ��� �׽�Ʈ
		for (int j = 0; j < C; j++) {
			printf("%d", day[i][j]);
		}
		printf("\n");
	}*/
}

bool sol(int d) {

	deque<pair<int, int>> Q;
	Q.push_front({ L[0].first, L[0].second });
	check[L[0].first][L[0].second] = d;

	/*
	������ ��³�¥�� ����س��� �ʿ��� d������ ĭ�� �̵�����
	*/
	while (!Q.empty()) {
		auto now = Q.back();
		if (L[1] == now) return true;
		Q.pop_back();

		int nowy = now.first;
		int nowx = now.second;

		for (int i = 0; i < 4; i++) {
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];

			if (ny >= 0 && ny < R && nx >= 0 && nx < C && check[ny][nx] != d && day[ny][nx] <= d) {
				check[ny][nx] = d;
				Q.push_front({ ny, nx });
			}
		}
	}

	return false;
}

int main() {

	freopen("input.txt", "r", stdin);
	
	init();

	/*
	d�Ͽ� ������ ������ ���Ѵٸ� d-1���� ������ ���Ѵ� -> �̺�Ž��
	*/

	int maxd = (R + C) / 2;
	int mind = 1;
	while (1) {
		if (mind == maxd) break;

		int mm = (mind + maxd) / 2;
		if (sol(mm))	//d���϶� ���� �� �ִ°�
			maxd = mm;
		else
			mind = mm + 1;

	}

	printf("%d", mind);
	return 0;
}