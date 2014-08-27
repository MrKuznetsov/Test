// Test1.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>

#include <iostream>

#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

inline bool isDelim(char c)
{
	return (c < 'a' || c > 'z') && (c < 'A' || c > 'Z');
}

bool sortByValue (const pair<string, int> &a, const pair<string, int> &b) 
{ 
	return (a.second < b.second); 
}

void process(const string & test)
{
	//hash map for fast acces words in dictionary
	unordered_map<string, int> hash;
	
	string word = "";

	//parse every word and add it into hash
	for (unsigned int i = 0; i < test.size(); i++)
	{
		if (isDelim(test[i]))
		{
			if (word.size() > 0)
			{
				hash[word]++;
				word.clear();
			}
			continue;
		}
		word += tolower(test[i]);
	}
	//last word
	if (word.size() > 0)
	{
		hash[word]++;
	}

	//make dictionary from hash and sort it by value
	vector<pair<string, int>> dictionary(hash.begin(), hash.end());
	sort(dictionary.begin(), dictionary.end(), sortByValue);

	//cout all words 
	for (auto it = dictionary.begin(); it !=  dictionary.end(); it++)
		cout << it->first << " " << it->second << endl;

}

int _tmain(int argc, _TCHAR* argv[])
{
	string text = string("Tyger Tyger, burning bright, \n") + 
			"In the forests of the night;\n" + 
			"What immortal hand or eye,\n" +
			"Could frame thy fearful symmetry?\n" +
			"In what distant deeps or skies.\n" +
			"Burnt the fire of thine eyes?\n" +
			"On what wings dare he aspire?\n" +
			"What the hand, dare seize the fire?\n";
	process(text);

	system("pause");

	return 0;
}

