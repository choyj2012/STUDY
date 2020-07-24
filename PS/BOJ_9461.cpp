	#include <stdio.h>
	#include <vector>
	using namespace std;


	int main() {

		int n, t;

		scanf("%d", &n);
		vector<long long> v(101);
	
		v[1] = 1;
		v[2] = 1;
		v[3] = 1;

		for (int i = 4; i <= 100; i++) {
			v[i] = v[i - 2] + v[i - 3];
		}

		for (int i = 1; i <= n; i++) {
			scanf("%d", &t);
			printf("%lld\n", v[t]);
		}

		return 0;
	}