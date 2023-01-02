#include<iostream>
#include<queue>
#include<vector>
#include<array>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
using namespace std;

int calculateMex(unordered_set<int> set_of_possible_moves) {
	int value = 0;
	while (set_of_possible_moves.find(value) != set_of_possible_moves.end()) {
		value++;
	}
	return value;
};

// Find Grundy Number ( define a game state )
int calculateNimbers(int n) {
	unordered_set<int> set_of_possible_moves;
	set_of_possible_moves.insert(n - 1);
	set_of_possible_moves.insert(n - 2);
	set_of_possible_moves.insert(n - 3);

	return calculateMex(set_of_possible_moves);
}


int main() {
	
	cout << calculateNimbers(4);

	return 0;
}
