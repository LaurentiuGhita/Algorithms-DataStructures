#include <iostream>
#include <unordered_map>
#include <vector>

/*
end element of the sequence points to beginning element of the sequence 
and beginning element of the sequence points to the end element. O(N) + O(N) space 
*/
void subsetSequence(std::vector<int>& array)
{

	//each element has the minimum lower bound ()
	std::unordered_map<int, int > resSequencesMap;
	int firstIndex = 0;
	int endIndex = 0;

	for(int element : array)
	{
		// element not in map
		if(resSequencesMap.find(element) == resSequencesMap.end())
		{
			int begining = element;
			int end = element;
			resSequencesMap[element] = element;

			if(resSequencesMap.find(element - 1) != resSequencesMap.end())
				begining = resSequencesMap[element-1];

			if(resSequencesMap.find(element + 1) != resSequencesMap.end())
				end = resSequencesMap[element + 1];

			int aux = resSequencesMap[begining];
			// update begining to point to end
			resSequencesMap[begining] = resSequencesMap[end];

			// update end to point to begining
			resSequencesMap[end] = aux;

			// check if interval larger than pervious one
			if(end - begining >= endIndex - firstIndex)
			{
				endIndex = end;
				firstIndex = begining;
			} 
		}
	}

	std::cout << "Longest subsequence from " << firstIndex << " to " << endIndex << "\n";

}



int main()
{
	int nSize;
	std::cin >> nSize;
	std::vector<int> array;

	for(int i = 0; i < nSize; ++i)
	{
		int aux;
		std::cin >> aux;
		array.push_back(aux);
	}

	subsetSequence(array);
}