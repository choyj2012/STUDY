#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

bool CheckVps(vector<char>&, char);	//��ȣ�� ¦�� �´��� �˻�

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector<int> vi;		//'(' => -1 , '[' => -2�� ����
	vector<char> vc;	//��ȣ�� ¦�� �´��� �˻��
	char str[33];
	int len;
	int i;
	
	scanf("%s", str);
	len = strlen(str);

	for (i = 0; i < len; i++) {
		if (str[i] == '(') {
			vi.push_back(-1);
			vc.push_back(str[i]);
		}

		else if (str[i] == '[') {
			vi.push_back(-2);
			vc.push_back(str[i]);
		}

		else if (str[i] == ')') {
			if (!CheckVps(vc, str[i])) {
				printf("0");
				return 0;
			}

			if (vi.back() == -1) {
				vi.pop_back();
				vi.push_back(2);
			}
			else {
				int t = 0;
				while (vi.back() != -1) {
					t += vi.back();
					vi.pop_back();
				}
				vi.pop_back();
				vi.push_back(t * 2);
			}
		}

		else if (str[i] == ']') {
			if (!CheckVps(vc, str[i])) {
				printf("0");
				return 0;
			}

			if (vi.back() == -2) {
				vi.pop_back();
				vi.push_back(3);
			}
			else {
				int t = 0;
				while (vi.back() != -2) {
					t += vi.back();
					vi.pop_back();
				}
				vi.pop_back();
				vi.push_back(t*3);
			}
		}
	}
	int answer = 0;
	while (!vi.empty()) {
		if (vi.back() < 0) {	//���°�ȣ�� �ְ�, �ݴ°�ȣ�� ���� ���
			printf("0");
			return 0;
		}
		answer += vi.back();
		vi.pop_back();
	}

	printf("%d", answer);
	return 0;
}

bool CheckVps(vector<char>& vc, char c) {
	if (c == ')') {
		if (!vc.empty() && vc.back() == '(') {
			vc.pop_back();
			return true;
		}
		else return false;
	}

	if (c == ']') {
		if (!vc.empty() && vc.back() == '[') {
			vc.pop_back();
			return true;
		}
		else return false;
	}
}