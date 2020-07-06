#include <stdio.h>
#include <list>
using namespace std;

struct Node {
	int rank;
	bool target = false;
};

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i, T;
	scanf("%d", &T);

	for (i = 1; i <= T; i++) {

		list<Node> l;
		int Rankcnt[10] = { 0, };
		int n, m, j;
		scanf("%d %d", &n, &m);

		for (j = 0; j < n; j++) {
			Node temp;
			scanf("%d", &temp.rank);
			Rankcnt[temp.rank]++;
			if (j == m) temp.target = true;
			l.push_back(temp);
		}

		list<Node>::iterator now = l.begin();

		int k;
		int cnt = 0;
		while (1) {
			if (now == l.end()) now = l.begin();
			bool isErased = true;
			for (k = now->rank + 1; k <= 9; k++) {
				if (Rankcnt[k] > 0) {	//���繮������ �߿䵵 ����������
					Node temp = *now;
					list<Node>::iterator del = now;
					now++;
					l.erase(del);
					l.push_back(temp);
					isErased = false;
					break;
				}
			}

			if (isErased == true) {		//���繮�� ���
				cnt++;
				Rankcnt[now->rank]--;
				if (now->target == true) break;		//���繮���� ���ϴ¹����ϰ��
				list<Node>::iterator del = now;
				now++;
				l.erase(del);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}