#include<iostream>
#include<queue>
#include<vector>
#include<array>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
using namespace std;

int getAns(int l, int r, vector<int>& a, vector<vector<int>>& dp) {
	if (l > r || l<=0 || r>a.size()) {
		return 0;
	}
	if (dp[l][r] != -1) {
		return dp[l][r];
	}
	int lans = a[l - 1] + min(getAns(l + 2, r, a, dp), getAns(l + 1, r - 1, a, dp));
	int rans = a[r - 1] + min(getAns(l , r - 2, a, dp), getAns(l+1, r - 1, a, dp));

	return dp[l][r]=max(lans, rans);
}

int maxcoin(vector<int>& v, int n) {
	vector<vector<int>> dp(501, vector<int>(501, -1));
	return getAns(1, n, v, dp);
}

int main() {
	vector<int> v = { 8, 15, 3, 7 };
	int n = v.size();

	cout << maxcoin(v, n);

	return 0;
}
