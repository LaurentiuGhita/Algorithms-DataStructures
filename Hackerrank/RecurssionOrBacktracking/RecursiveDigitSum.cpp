#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>

//https://www.hackerrank.com/challenges/recursive-digit-sum/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=recursion-backtracking

using namespace std;

int superDigit(string n, int k) {
	static unordered_map<std::string, int> results;
	std::string s = n;

	if (results.find(n) != results.end())
		return results[n];

	try {
		if (n.size() == 1) {
			results[n] = stoi(n);
			return results[n];
		}

		long long total = 0;
		for (auto&& letter : s) {
			int num = letter - '0';
			total += num;
		}
		if (k != 0)
			total *= k;

		if (results.find(to_string(total)) != results.end())
			return results[to_string(total)];

		results[n] = superDigit(to_string(total), 0);

	}
	catch (const invalid_argument& e) {

	}


	return  results[n];
}
int main() {
	std::ifstream fin("recursiveDigitInput.txt");
	int count;
	std::string s;
	fin >> s;
	fin >> count;

	int x = superDigit(s, count);
}