#include <cstdio>
using namespace std;

#define MOD 1000000000

int dp[101][10][4];

int main() {

	freopen("input.txt", "r", stdin);

	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {

		if (i == 1) {
			for (int j = 1; j <= 8; j++) {
				dp[i][j][0] = 1;
			}
			dp[i][9][1 << 1] = 1;
		}
		else {

			for (int j = 0; j <= 9; j++) {

				if (j == 0) {
					for (int k = 0; k < 4; k++) {
						dp[i][0][k | (1 << 0)] += dp[i - 1][1][k];
						dp[i][0][k | (1 << 0)] %= MOD;
					}
				}
				else if (j == 9) {
					for (int k = 0; k < 4; k++) {
						dp[i][9][k | (1 << 1)] += dp[i - 1][8][k];
						dp[i][9][k | (1 << 1)] %= MOD;
					}
				}
				else {
					for (int k = 0; k < 4; k++) {
						dp[i][j][k | 0] += dp[i - 1][j + 1][k];
						dp[i][j][k | 0] += dp[i - 1][j - 1][k];
						dp[i][j][k | 0] %= MOD;
					}
				}

			}
		}
	}
	int answer = 0;
	for (int i = 0; i <= 9; i++) {
		answer = (answer + dp[N][i][3]) % MOD;
	}
	printf("%d", answer);
	return 0;
}

/*
���� ��� ��쿡�� bit�� ����.

��, 9���� ������ bit = 2, 0���� ������ bit = 1
���� ���� ������� bit = 0 -> �׷� ��� ������ ��Ʈ 3
0~9���� ��� ���ԵǷ��� ���ʴ� ��ƾ���.

�̷��� �ϸ� d[100][10][4] �����ε� �ذ��� ����.
*/