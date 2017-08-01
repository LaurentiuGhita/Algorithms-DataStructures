#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<int> > generateOrderedPermutation(std::vector<int> v1, std::vector<int> v2)
{
	std::vector<std::vector<int> > orderedPerms;
	std::vector<bool> flags(v1.size(), 0); // fill left with 0
	for(int i = 0; i < v2.size(); ++i)
		flags.push_back(1);

	int count = 0;
	do
	{
		int nLeftIndex = 0;
		int nRightIndex = 0;

		std::vector<int> perm;
		for(int i = 0; i < flags.size(); ++i)
		{
			if(flags[i] == 0)
			{
				// left
				perm.push_back(v1[nLeftIndex]);
				nLeftIndex++;
			}
			else
			{
				perm.push_back(v2[nRightIndex]);
				nRightIndex++;
			}
		}
		orderedPerms.push_back(perm);

		std::cout << ++count << "\n";
	}while(next_permutation(flags.begin(), flags.end()));

	return orderedPerms;
}

void printVector(std::vector<int> v)
{
	for(int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";

	std::cout << "\n";
}

int main()
{
	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	std::vector<int> v2;
	v2.push_back(4);
	v2.push_back(5);

	std::vector<std::vector<int> > sol;
	sol = generateOrderedPermutation(v1,v2);

	for(int i = 0; i < sol.size(); ++i)
		printVector(sol[i]);

}