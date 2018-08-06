#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include<cmath>
#include <string>
using namespace std;

int main()
{
	char tmp;
	vector<char> vec/* {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'} */; 
	//char ch;
	//cin >> ch;
	//vec.push_back(ch);
	while (cin >> tmp)
	{
		vec.push_back(tmp);
	} 

	int k = vec.size() / 4;
	auto p = vec.begin();
	char output[10][10];
	
	for (int i = 0; i <= k; ++i)
	{
		for (int j = 0; j <= k; ++j)
			output[i][j] = ' ';
	}
	
	for(int i = 0; i < k; ++i)
	{
		output[0][i] = *(p++);
	}
	for(int i = 0; i < k; ++i)
	{
		output[i][k] = *(p++);
	}
	for(int i = k; i > 0; --i)
	{
		output[k][i] = *(p++);
	}
	for(int i = k; i > 0; --i)
	{
		output[i][0] = *(p++);
	}

	for (int i = 0; i <= k; ++i)
	{
		for (int j = 0; j <= k; ++j)
			cout <<	output[i][j];
		cout << endl;
	}
}