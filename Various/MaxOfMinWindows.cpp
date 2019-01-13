#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <fstream>

template <typename T>
void printVector(const std::vector<T>& arr) {
	for (auto&& entry : arr)
		std::cout << entry << " ";
	std::cout << "\n";
}

template <typename T>
std::vector<int> nextSmallerElemR(const std::vector<T>& arr) {
	// init vector with arr.size values ( in case no smaller element is found to the right)
	std::vector<int> result(arr.size(), arr.size());
	std::stack<T> elems;

	elems.push(0);

	for (int i = 1; i < arr.size(); ++i) {
		while (!elems.empty() && arr[i] < arr[elems.top()]) {
			result[elems.top()] = i;
			elems.pop();
		}
		elems.push(i);
	}

	return result;
}

template <typename T>
std::vector<int> nextSmallerElemL(const std::vector<T>& arr) {
	std::vector<int> result(arr.size(), -1);
	std::stack<T> elems;

	elems.push(arr.size() - 1);
	for (int i = arr.size() - 2; i >= 0; --i) {
		while (!elems.empty() && arr[i] < arr[elems.top()]) {
			result[elems.top()] = i;
			elems.pop();
		}
		elems.push(i);
	}

	return result;
}

std::vector<long> riddle(std::vector<long> arr) {
	// compute biggest windows for each element in which that element is the smallest
	std::vector<int> windowsSizes(arr.size(), 0);

	std::vector<long> result(arr.size(), 0);
	std::vector<int> smallItemsLeft = nextSmallerElemL(arr);
	std::vector<int> smallItemsRight = nextSmallerElemR(arr);

	for (int i = 0; i < smallItemsLeft.size(); ++i)
		windowsSizes[i] = smallItemsRight[i] - smallItemsLeft[i] - 1;

	for (int i = 0; i < windowsSizes.size(); ++i) {
		int windowSize = windowsSizes[i] - 1;
		result[windowSize] = std::max(result[windowSize], arr[i]);
	}

	for (int i = result.size() - 2; i >= 0; --i)
		result[i] = std::max(result[i], result[i + 1]);
	return result;

}
 
int main() {

	std::ifstream fin("C:\\Users\\homeadmin\\Documents\\input.txt");
	int size;
	std::vector < long > arr;
	if (fin) {
		fin >> size;
		for (int i = 0; i < size; ++i) {
			long elem;
			fin >> elem;
			arr.push_back(elem);
		}
	}
	printVector(riddle(arr));
}