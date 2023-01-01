#include<iostream>
#include<queue>
#include<vector>
#include<array>
#include<map>
#include<unordered_map>
#include<stack>
using namespace std;


string arrayGame(int arr[], int n) {
	int max_value = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max_value) {
			max_value = arr[i];
		}
	}

	int diff_val=0;
	for (int i = 0; i < n; i++) {
		diff_val += (max_value - arr[i]);
	}

	if (diff_val == 0) {
		return "Draw";
	}

	// if diff_val value is odd then First one is going to win
	if (diff_val & 1 ) {
		return "First";
	}
	else {
		return "Second";
	}

	

}



int main() {
	int arr[] = {10,8,2,5,10,7};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << arrayGame(arr, n);

	return 0;
}
