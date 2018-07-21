#include <iostream>
#include <vector>
#include <stack>
#include<queue>
#include<string>
#include<set>
#include <functional> 
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) 
	{
            if (find(str.begin(), str.end(), ' ') == str.end())
            return str;
        
		reverse(str.begin(), str.end());

		auto beginWord = str.begin();
		auto endWord = str.begin();

		while (1)
		{
			endWord = find(beginWord, str.end(), ' ');
			if (endWord == str.end())
				break;
			reverse(beginWord, endWord);
			beginWord = ++endWord;
		}
        reverse(beginWord, str.end());
		return str;
    }
};

int main()
{
	string str = "I am a student.";
	//reverse(str.begin(), str.end());

	Solution sol;
	cout << sol.ReverseSentence(str);
}