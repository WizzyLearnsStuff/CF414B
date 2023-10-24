#include<iostream>

using namespace std;

#define MOD 1000000007

unsigned int dp[2001][2001] = {0};

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			for (int p = j; p <= n; p += j) {
				dp[i][p] = (dp[i][p] + dp[i-1][j]) % MOD;
			}
		}
	}

	unsigned int s = 0;
	for (int i = 1; i <= n; i++) {
		s = (s + dp[k][i]) % MOD;
	}

	cout << s;
	
}
