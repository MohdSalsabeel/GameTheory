string discover_atlantis(int n) {
  
  // 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
	// 1 | 1 | 0 | 1 | 1 | 0 | 1 | 1 | 0 |
  
	if (n % 3 == 0) {
		return "JACK";
	}
	return "JELLY";
	
}



int main() {
	
	int n = 5;
	cout<<discover_atlantis(n);
	return 0;
}
