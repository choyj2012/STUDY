#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int oprank(char op) {
	if (op == '*' || op == '/') return 1;
	else if (op == '+' || op == '-') return 2; 
	else return 3;		//'('
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector<char> v;
	char str[110];

	scanf("%s", str);
	int len = strlen(str);
	int i;
	for (i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')	//���ĺ��ϰ��
			printf("%c", str[i]);
		else if (str[i] == ')') {	//�ݴ°�ȣ�ϰ��
				while (!v.empty() && v.back() != '(') {
					printf("%c", v.back());
					v.pop_back();
				}
				v.pop_back();
		}
		else if (str[i] == '(')v.push_back(str[i]);	//���°�ȣ�ϰ��
		else {	//������ (+, -, *, /)
			while (!v.empty() && oprank(v.back()) <= oprank(str[i])) {
				printf("%c", v.back());
				v.pop_back();
			}
			v.push_back(str[i]);
		}
	}
	while (!v.empty()) {
		printf("%c", v.back());
		v.pop_back();
	}
	return 0;
}