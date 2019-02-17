#include <iostream>
#include <unordered_map>


//https://www.hackerrank.com/challenges/ctci-recursive-staircase/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=recursion-backtracking


// A(n) = A(n-1) + A(n-2) + A(n-3)
// suppose we are on step n - 1, we need to to 1 more step --> count is A(n - 1) ways + current step
// step n - 2 --> count is A(n - 2) ways + current 2 steps
// step n - 3 --> count is A(n - 3) ways + current 3 steps;
// Complete the stepPerms function below.
int stepPerms(int n) {
	static std::unordered_map<int, int> partial_results;

	if (partial_results.find(n) != partial_results.end())
		return partial_results[n];


	partial_results[1] = 1;
	partial_results[2] = 2;
	partial_results[3] = 4;

	if (partial_results.find(n) != partial_results.end())
		return partial_results[n];

	int count = 0;
	if (partial_results.find(n - 1) == partial_results.end()) {
		int aux = stepPerms(n - 1);
		partial_results[n - 1] = aux;
	}
	if (partial_results.find(n - 2) == partial_results.end()) {
		int aux = stepPerms(n - 2);
		partial_results[n - 2] = aux;
	}
	if (partial_results.find(n - 3) == partial_results.end()) {
		int aux = stepPerms(n - 3);
		partial_results[n - 3] = aux;
	}
	partial_results[n] = partial_results[n - 1] + partial_results[n - 2] + partial_results[n - 3];

	return partial_results[n];
}


int main() {
	std::cout << stepPerms(4) << "\n";
	std::cout << stepPerms(7) << "\n";
}

