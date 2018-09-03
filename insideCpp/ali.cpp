#include <iostream>
#include <vector>
#include <map>
using namespace std; 

void calcPath(vector<int> &sysTime, multimap<int, int> &Map, int MaxTime)
{

}

int main()
{
	int numSystem, munRely;
	cin >> numSystem >> munRely;

	vector<int> sysTime;
	while (numSystem--)
	{
		int time;
		cin >> time;
		sysTime.push_back(time);
	}
	multimap<int, int> Map;
	while (munRely--)
	{
		int father, son;
		cin >> father >> son;
		Map.insert(make_pair(father, son));
	}

	return 0;
}