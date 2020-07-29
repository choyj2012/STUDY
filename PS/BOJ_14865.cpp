#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1000000001
int n;
int px, py, x, y;
vector<int> xpos;
vector<pair<int, int>> opos;
vector<pair<int, int>> pos;
vector<pair<int, int>> v;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	opos.resize(n);
	pos.resize(n);
	int start;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &opos[i].first, &opos[i].second);
		if (opos[i].second < 0) start = i;
	}
	
	//�������� x�� �Ʒ��� �����ϱ����ؼ�
	for (int i = 0; i < n; i++) {
		pos[i] = opos[(i + start) % n];
	}


	for (int i = 1; i <= n; i++) {

		//x���� ����ϴ°�� �Ǻ�
		if (pos[i%n].first == pos[i - 1].first &&
			((pos[i%n].second > 0 && pos[i - 1].second < 0) ||
			(pos[i%n].second < 0 && pos[i - 1].second > 0))) {

			//x���� ������ x��ǥ ����
			xpos.push_back(pos[i - 1].first);

			//����� x��ǥ�� 2�� -> ( )�� ǥ������
			if (xpos.size() == 2) {
				//x��ǥ�� �������� (��, ū���� )�� ǥ��
				if (xpos[0] > xpos[1]) swap(xpos[0], xpos[1]);
				v.push_back({ xpos[0], 1 });
				v.push_back({ xpos[1], 0 });
				xpos.clear();
			}
		}
	}

	//x��ǥ �������� ����
	sort(v.begin(), v.end());
	//1 -> ( , 0 -> )
	//( ( ) ( ) )

	int answer1 = 0, answer2 = 0;	//1 ū�� 2������
	vector<int> stack;
	for (int i = 0; i < v.size(); i++) {

		//answer2 -> '('������ �ٷ� ')'������ ī����
		if (v[i].second == 1 && v[i + 1].second == 0) answer2++;

		//answer1 -> ������ ��� ī����
		//������ ����ٴ°��� ���ݱ��� ���� ��ȣ�� ���� �������� -> ū ��ȣ�� ����
		if (stack.empty()) answer1++;
		
		if (v[i].second == 1)
			stack.push_back(1);
		if (v[i].second == 0)
			stack.pop_back();
	}

	printf("%d %d", answer1, answer2);
	return 0;
}