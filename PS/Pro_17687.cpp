#include <iostream>
#include <string>
#include <vector>

using namespace std;

string num = "0123456789ABCDEF";

vector<int> next_num(vector<int> now, int n) {

	now[0]++;
	for (int i = 0; i < now.size(); i++) {
		if (now[i] == n) {
			now[i] = 0;
			if (i < now.size() - 1)
				now[i + 1]++;
			else
				now.push_back(1);
		}
		else break;
	}
	return now;
}
string solution(int n, int t, int m, int p) {
	string answer = "";
	vector<int> now;
	now.push_back(0);

	int cnt = 0;
	int pcnt = 0;
	while (1) {

		for (int i = now.size() - 1; i >= 0; i--) {
			cnt++;

			if ((cnt - p) % m == 0) {
				answer += num[now[i]];
				pcnt++;
				if (pcnt == t) return answer;
			}
		}
		now = next_num(now, n);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	
	int n, t, m, p;
	cin >> n >> t >> m >> p;
	cout << solution(n, t, m, p);
	return 0;
}