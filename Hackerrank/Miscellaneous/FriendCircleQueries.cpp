#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <unordered_set>
#include <fstream>


//https://www.hackerrank.com/challenges/friend-circle-queries/copy-from/99825568?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous

namespace miscellaneous {

	using namespace std;

	class DisjoinSet {
	public:
		DisjoinSet() : maxSize_(0) {}
		std::vector<int> SolveProblem(std::vector<std::vector<int>>&);
		void Union(const int x, const int y);
		std::unordered_map<int, int> parents_;
		std::unordered_map<int, int> connected_components_;
		int maxSize_;
	};

	std::vector<int> DisjoinSet::SolveProblem(std::vector<std::vector<int>>& queries)
	{
		std::vector<int> result;
		for (auto& query : queries) {
			int x = query[0];
			int y = query[1];

			Union(x, y);
			result.emplace_back(maxSize_);
		}

		return result;
	}

	void DisjoinSet::Union(const int x, const int y)
	{
		if (parents_[x] == 0 && x != 0 && parents_[y] == 0 && y != 0) {
			parents_[x] = y;
			parents_[y] = y;
			connected_components_[y] = 2;
			if (maxSize_ < connected_components_[y])
				maxSize_ = connected_components_[y];
		}
		else if (parents_[x] == 0 && x != 0) {
			int aux = y;
			while (aux != parents_[aux])
				aux = parents_[aux];

			parents_[x] = aux;
			++connected_components_[aux];
			if (maxSize_ < connected_components_[aux])
				maxSize_ = connected_components_[aux];
		}
		else if (parents_[y] == 0 && y != 0) {
			int aux = x;
			while (aux != parents_[aux])
				aux = parents_[aux];

			parents_[y] = aux;
			++connected_components_[aux];
			if (maxSize_ < connected_components_[aux])
				maxSize_ = connected_components_[aux];
		}
		else {
			int aux_x = x;
			int aux_y = y;

			while (aux_x != parents_[aux_x])
				aux_x = parents_[aux_x];

			while (aux_y != parents_[aux_y])
				aux_y = parents_[aux_y];

			if (aux_x != aux_y) {
				// merge the smaller in the bigger component
				if (connected_components_[aux_y] >= connected_components_[aux_x]) {
					parents_[aux_x] = aux_y;
					connected_components_[aux_y] += connected_components_[aux_x];
					connected_components_[aux_x] = 0;
					if (maxSize_ < connected_components_[aux_y])
						maxSize_ = connected_components_[aux_y];
				}
				if (connected_components_[aux_x] > connected_components_[aux_y]) {
					parents_[aux_y] = aux_x;
					connected_components_[aux_x] += connected_components_[aux_y];
					connected_components_[aux_y] = 0;
					if (maxSize_ < connected_components_[aux_x])
						maxSize_ = connected_components_[aux_x];
				}
			}
		}
	}


	// Complete the maxCircle function below.
	vector<int> maxCircle(vector<vector<int>> queries) {

		DisjoinSet disjointSet;
		auto&& results = disjointSet.SolveProblem(queries);
		return results;
	}
}


//int main() {
//	std::ifstream fin("FriendCircleQueries.in.txt");
//	int count;
//	fin >> count;
//
//
//	std::vector<std::vector<int>> input(count, std::vector<int>());
//	for (int i = 0; i < count; ++i) {
//		int x, y;
//		fin >> x >> y;
//		input[i].emplace_back(x);
//		input[i].emplace_back(y);
//	}
//
//	DisjoinSet disjointSet;
//	disjointSet.SolveProblem(input);
//
//	//auto&& result = maxCircle(input);
//
//	//for (auto& entry : result)
//	//	std::cout << entry << "\n";
//}