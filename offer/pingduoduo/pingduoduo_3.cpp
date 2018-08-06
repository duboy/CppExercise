#include <iostream>
#include <vector>
#include <stack>
#include<map>
#include<string>
#include<set>
#include <functional> 
using namespace std;

int recFind(vector<vector<int>> &friends, int user)
{
	int num = friends.size();
	if (num == 0)
		return -1;

	map<int, int> res;

	if (friends[user].empty())
		return -1;

	vector<int> dic(num, 0);

	dic[user] = 1;

	for (auto f : friends[user])
		dic[f] = 1;

	for (int i = 0; i < num; ++i)
	{
		if (dic[i] == 0)
			res[i] = 0;
	}

	for (auto f : friends[user])
	{
		for (auto r : friends[f])
		{
			if (res.find(r) != res.end())
				++res[r];
		}
	}

	int max = 0;
	int person = -1;

	for (auto r : res)
	{
		if (r.second > max)
		{
			max = r.second;
			person = r.first;
		}
	}

	return person;
	
}

int main()
{
	int N, user;
	cin >> N >> user;

	vector<vector<int>> friends;// = { {1, 2, 3}, {0, 4}, {0, 4}, {0, 4}, {1,2,3} };


	for (int i = 0; i < N; ++i)
	{
		vector<int> temp;
		int u;
		cin >> u;
		temp.push_back(u);
		while (cin.get() != '\n')
		{
			cin >> u;
			temp.push_back(u);
		}

		friends.push_back(temp);
	}

	cout << recFind(friends, 0);

}