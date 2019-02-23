#include <iostream>
#include <memory>
#include <vector>


// https://www.hackerrank.com/challenges/maximum-xor/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous

namespace miscellaneous {

	struct Node {
		Node() : x(0), pLeft(nullptr), pRight(nullptr) {}
		Node(int val) : x(val), pLeft(nullptr), pRight(nullptr) {}
		int x;
		std::unique_ptr<Node> pLeft;
		std::unique_ptr<Node> pRight;
	};

	class Trie {
	public:
		Trie(int num_bits) : num_bits_(num_bits), pRoot_(std::make_unique<Node>(5)) {}
		void AddNumber(int x);
		void PrintInOrder();
		int Xor(int y);
	private:
		void PrintInOrder(Node*, int);

		int num_bits_;
		std::unique_ptr<Node> pRoot_;
	};

	void Trie::AddNumber(int x) {
		Node* pAux = pRoot_.get();
		for (int i = 0; i < num_bits_; ++i) {
			int shiftCount = num_bits_ - i - 1;
			int bitVal = (x >> shiftCount) & 1;

			if (bitVal == 1) {
				if (pAux->pRight == nullptr)
					pAux->pRight = std::make_unique<Node>(1);

				pAux = pAux->pRight.get();
				continue;
			}
			if (bitVal == 0) {
				if (pAux->pLeft == nullptr)
					pAux->pLeft = std::make_unique<Node>(0);

				pAux = pAux->pLeft.get();
				continue;
			}
		}
	}

	void Trie::PrintInOrder() {
		std::cout << "In order ";
		PrintInOrder(pRoot_.get(), 0);
		std::cout << std::endl;
	}

	int Trie::Xor(int y)
	{
		int result = 0;
		Node* aux = pRoot_.get();
		if (aux == nullptr)
			return 0;

		for (int i = 0; i < num_bits_; ++i) {
			int shiftCount = num_bits_ - i - 1;
			int bitVal = (y >> shiftCount) & 1;

			if (bitVal == 1) {
				if (aux->pLeft != nullptr) {
					// this means we have a 0 on the left
					result |= 1;
					aux = aux->pLeft.get();
				}
				else if (aux->pRight != nullptr)
					aux = aux->pRight.get();
			}
			else {
				if (aux->pRight != nullptr) {
					result |= 1;

					aux = aux->pRight.get();
				}
				else if (aux->pLeft != nullptr)
					aux = aux->pLeft.get();
			}
			if (i != num_bits_ - 1)
				result <<= 1;
		}
		return result;
	}

	void Trie::PrintInOrder(Node* pRoot, int level) {
		if (pRoot == nullptr)
			return;

		PrintInOrder(pRoot->pLeft.get(), level + 1);
		std::cout << pRoot->x << " ";// level " << level << "\n";
		PrintInOrder(pRoot->pRight.get(), level + 1);
	}

	// Complete the maxXor function below.
	std::vector<int> maxXor(std::vector<int> arr, std::vector<int> queries) {
		// solve here
		Trie tr(32);
		std::vector<int> results;
		for (auto& num : arr)
			tr.AddNumber(num);

		int max = 0;
		for (auto& q : queries) {
			results.emplace_back(tr.Xor(q));
		}
		return results;
	}

}

//int main() {
//	miscellaneous::Trie tr(3);
//	tr.AddNumber(1);
//	tr.AddNumber(2);
//	tr.AddNumber(3);
//	tr.AddNumber(4);
//
//	std::cout << tr.Xor(6);
//}



