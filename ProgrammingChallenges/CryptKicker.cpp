#include <iostream>
#include <istream>
#include <ostream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>

bool ReadDictionary(std::istream& in, std::unordered_set<std::string>& dictionary)
{
	std::string line;
	std::getline(in, line);
	std::stringstream ss;
	
	if(line.empty())
		return false;

	int nWordCount = 0;

	ss << line;
	ss >> nWordCount;
	if(ss.fail())
		return false;

	for(int i = 0; i < nWordCount; ++i)
	{
		std::string word;
		in >> word;
		dictionary.insert(word);
	}
}

void Decrypt(std::unordered_set<std::string>& dictionary, std::unordered_set<std::string>& encryptedWords, std::vector<std::string>& contentDecrypted)
{

}

void DecryptLines(std::istream& in, std::ostream& out, std::unordered_set<std::string>& dictionary)
{
	std::string line;
	std::stringstream ss;
	in.ignore();
	while(std::getline(in, line))
	{
		ss.clear();
		std::unordered_set<std::string> encryptedWords;
		if(line.empty())
			break;

		ss << line;
		std::string word;
		while(ss >> word)
		{
			encryptedWords.insert(word);
		}

		if(encryptedWords.size() != dictionary.size())
		{
			
		}
		else
		{
			std::vector<std::string> contentDecrypted;
			Decrypt(dictionary, encryptedWords, contentDecrypted);
		}
	}
}


int main()
{
	std::unordered_set<std::string> dictionary;
	
	ReadDictionary(std::cin, dictionary);
	DecryptLines(std::cin, dictionary);
}