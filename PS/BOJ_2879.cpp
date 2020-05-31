//https://www.acmicpc.net/problem/2879

#include <stdio.h>
#include <math.h>
#define N 1010

int be[N];	//����befor
int af[N];	//��ǥafter
int n, i;

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &be[i]);
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &af[i]);
	}
	
	int gap = 0;
	int sum = 0;
	int now = 0;
	
	for (i = 1; i <= n; i++) {	//iii)��ȣ �ٲ�� ���
		gap = af[i] - be[i];
		if (now * gap < 0) {
			sum += abs(now);
			now = gap;
			continue;
		}

		if (abs(now) < abs(gap)) {	//i)������������ �����ϴ°��
			now = gap;
		}
		else if (abs(now) > abs(gap)) {	//ii)������������ �����ϴ°��
			sum += (abs(now) - abs(gap));
			now = gap;
		}
	}
	sum += abs(now);	//vi)for�������� �׸��� ���� �����ֱ�
	printf("%d", sum);
	return 0;
}