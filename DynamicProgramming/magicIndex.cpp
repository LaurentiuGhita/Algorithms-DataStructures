#include <iostream>
#include <vector>


// no duplicates
void GetMaxicIndex(std::vector<int> values, int nStart, int nEnd)
{
	int middleIndex = (nStart + nEnd) / 2;
	if(nStart <= nEnd)
	{
		if(middleIndex == values[middleIndex])
		{
			std::cout << "Found magic index at index " << middleIndex << "\n"; 
		}
		else
		{
			if(middleIndex > values[middleIndex]) // if condition not respected no need to search right
			{
				GetMaxicIndex(values, middleIndex +1, nEnd);
			}

			GetMaxicIndex(values, nStart, middleIndex -1);
		}	
	}
}

bool GetMaxicIndexUniqElems(std::vector<int> values, int nStart, int nEnd)
{
	if(nStart <= nEnd)
	{
		bool bRes = false;
		int middleIndex = (nStart + nEnd) / 2;
		int middleValue = values[middleIndex];

		if(middleIndex == middleValue)
		{
			std::cout << "found magic index at index " << middleValue << "\n";
		}
		else
		{
			if(middleValue < middleIndex)
			{
				bRes = GetMaxicIndexUniqElems(values, nStart, middleValue);
			}
		}

		if(bRes == false)
		{
			GetMaxicIndexUniqElems(values, middleIndex + 1, nEnd);
		}
	}
}

int main()
{
	std::vector<int> values;
	values.push_back(-100);
	values.push_back(1);
	values.push_back(1);
	values.push_back(1);
	values.push_back(1);
	values.push_back(1);

	GetMaxicIndex(values,0, values.size()-1);

}