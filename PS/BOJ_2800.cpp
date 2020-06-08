#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string str;
vector<vector<char>> strcheck;

void sol(vector<char> stack, vector<int> check, int cnt);
void Print(vector<char>);

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	
	vector<char> v;
	vector<int> ch;
	cin >> str;
	sol(v, ch, 0);

	sort(strcheck.begin(), strcheck.end());
	vector<vector<char>>::iterator itor = strcheck.begin();
	vector<char>::iterator itor2;
	for (itor = strcheck.begin(); itor != strcheck.end(); itor++) {
		for (itor2 = itor->begin(); itor2 != itor->end(); itor2++) {
			cout << *itor2;
		}
		cout << "\n";
	}
	return 0;
}

void sol(vector<char> stack, vector<int> check, int idx) {

	if (idx == str.size()) {
		Print(stack);
		return;
	}
	char t = str[idx];

	if (t == '(') {
		//���ž��� ���
		stack.push_back(t);
		check.push_back(1);		// 1 => �������� ���� ��ȣ
		sol(stack, check, idx + 1);

		//������ ���
		stack.pop_back();
		check.pop_back();
		check.push_back(-1);	// -1 => ���ŵ� ��ȣ
		sol(stack, check, idx + 1);
	}
	else if (t == ')') {
		if (check.back() == 1) {		//��ȣ ���� �����ִ°��
			check.pop_back();
			stack.push_back(t);
			sol(stack, check, idx + 1);
		}
		else if (check.back() == -1) {	//��ȣ ���� ���ŵȰ��
			check.pop_back();
			sol(stack, check, idx + 1);
		}
	}
	else {
		stack.push_back(t);
		sol(stack, check, idx + 1);
	}
}

void Print(vector<char> stack) {
	if (stack.size() == str.size()) return;	//�Ѱ��� ���žȵȰ�� ��¾���

	vector<vector<char>>::iterator iit;	//�ߺ��˻�
	for (iit = strcheck.begin(); iit != strcheck.end(); iit++) {
		if (stack == *iit) {
			return;
		}
	}
	strcheck.push_back(stack);
/*	���⼭ �ٷ�������� �ʰ� strcheck�� �� ��� ���� �������� �����ؼ� ���
	vector<char>::iterator it;	//���
	for (it = stack.begin(); it != stack.end(); it++) {
		printf("%c", *it);
	}
	printf("\n");
	*/
}