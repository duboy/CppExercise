#include <iostream>
#include <vector>
#include <stack>
#include<map>
#include<string>
#include<set>
#include <functional> 
using namespace std;

int takeCard(vector<int> &cards)
{
	if (cards.empty())
		return -1;

	return 0;
}

int main()
{
	int n;
	cin >> n;
	vector<int> cards;// = { {1, 2, 3}, {0, 4}, {0, 4}, {0, 4}, {1,2,3} };
	
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		cards.push_back(temp);
	}

	cout << takeCard(cards);

}