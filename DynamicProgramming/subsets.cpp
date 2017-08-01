#include <iostream>
#include <set>
#include <vector>

void getSubSets(std::vector<int> elements, std::vector<std::set<int>>& vectorOfSets)
{

	for(int j = 0; j < elements.size(); ++j)
	{
		std::set<int> currentElementSet;
		currentElementSet.insert(elements[j]);
		

		/* create new subsets --> add current element to already existing ones*/
		std::vector<std::set<int>> newSubsets;
		for(int i = 0; i < vectorOfSets.size(); ++i)
		{
			std::set<int> auxSet = vectorOfSets[i];
			auxSet.insert(elements[j]);
			newSubsets.push_back(auxSet);
		}

		for(int i = 0; i < newSubsets.size(); ++i)
			vectorOfSets.push_back(newSubsets[i]);

		vectorOfSets.push_back(currentElementSet);
	}
}


void printSubSets(std::vector<std::set<int>>& vectorOfSets)
{
	for(int i = 0; i < vectorOfSets.size(); ++i)
	{
		std::cout << "Subset " << i << "--> ";
		for(auto it = vectorOfSets[i].begin(); it != vectorOfSets[i].end(); ++it)
		{
			std::cout << *it << " ";
		}

		std::cout << "\n";
	}
}

int main()
{
	std::vector<std::set<int>> results;
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	getSubSets(v,results);
	printSubSets(results);
}