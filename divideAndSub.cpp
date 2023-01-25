#include<iostream>
#include<queue>
#include<vector>
#include<array>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
using namespace std;

string divAndSub(int n) {
	// 0 is losing state -> it can not move
	if (n == 1) {
		return "Arya";
	}
	// dp[n + 1];
	vector<int> dp(n + 1);
	dp[0] = 0;
	// Losing State -> 0
	// Winning State -> 1
	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		for (int move = 2; move <= 5; move++) {
			if (dp[i/move]  == 0) {
				dp[i] = 1;
			}

			if (i-move>=0 && dp[i - move] == 0) {
				dp[i] = 1;
			}
		}
	}
	if (dp[n]) {
		return "Jon";
	}
	else {
		return "Arya";
	}


}


int main() {
	int n = 6;
	cout<<divAndSub(n);

	return 0;
}
