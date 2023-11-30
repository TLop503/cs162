/**************************************************
 * Name: ways_to_top(int n)
 * Description: sums possible ways to combine 1, 2, 3
 * in unique orders to reach n
 * Parameters: n - num to reach
 * Pre-conditions: n is reasonably (sub 37) int
 * Post-conditions: will recursively call itself and total everything up
 ***********************************************/
int ways_to_top(int n) {
	if (n == 3) {
		return 4;
	}
	if (n == 2) {
		return 2;
	}
	if (n == 1) {
		return 1;
	}
	if (n <= 0) {
		return 0;
	}
	else {
		//take out 1 block of each size and count rests
		//kinda makes a tree
		return (ways_to_top(n-1) +
				ways_to_top(n-2) +
				ways_to_top(n-3));
	}
}
