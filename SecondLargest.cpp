// Find out the second largest number in an array
// use 2 numbers to record
int secondLargest(vector<int> arr) {
	int res;
	if (arr.empty()) return res;
	int first = arr[0];
	int second = arr[0];
	for (int i=0; i<arr.size(); i++) {
		if (first<arr[i]) {
			second = first;
			first = arr[i];
		}
		else if (second<arr[i]) second = arr[i];
	}
	res = second;
	return res;
}