#include<iostream>
#include<queue>
#include<vector>
#include<array>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
using namespace std;

int grundy[1000][1000];

int precompute() {

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {

			int mex[3] = { 0 };
			if (i - 1 >= 0) {
				mex[grundy[i - 1][j]] = 1;
			}
			if (i - 2 >= 0) {
				mex[grundy[i - 2][j]] = 1;
			}
			if (j - 1 >= 0) {
				mex[grundy[i][j-1]] = 1;
			}
			if (j - 2 >= 0) {
				mex[grundy[i][j-2]] = 1;
			}
			if (i - 1 >= 0 && j-1 >= 0) {
				mex[grundy[i - 1][j-1]] = 1;
			}
			if (i - 2 >= 0 && j-2 >= 0) {
				mex[grundy[i - 2][j-2]] = 1;
			}

			int res_mex = 0;
			while (mex[res_mex]) {
				res_mex++;
			}
			grundy[i][j] = res_mex;
		}
	}

	return 0;
}

int main() {
	precompute();
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		int ans = 0;
		for (int i = 0; i < k; i++) {
			int n, m;
			cin >> n >> m;
			ans ^= grundy[n-1][m-1];
		}
		if (ans == 0) {
			cout << "EL" << endl;
		}
		else {
			cout << "Light" << endl;
		}
	}

	return 0;
}
