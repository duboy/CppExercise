#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

int main()
{
	int T;
	cin >> T;
	vector<int> N(T);
	vector<vector<string>> searchNum(T);
	vector<vector<pair<regex, string>>> num2Loc(T);
	
	for (int i = 0; i < T; ++i)
	{
		cin >> N[i];

		for (int line = 0; line < N[i]; ++line)
		{
			string phoneNum, loc;
			cin >> phoneNum >> loc;
			for (auto beg = phoneNum.begin(); beg != phoneNum.end(); ++beg)
			{
				if (*beg == 'x')
					*beg = '.';
			}
			regex e(phoneNum);
			num2Loc[i].push_back(make_pair(e, loc));
			//num2Loc[e] = loc;
		}
		//待查询的号码数目
		int M;
		cin >> M;

		for (int index_search = 0; index_search < M; ++index_search)
		{
			string searchNo;
			cin >> searchNo;
			searchNum[i].push_back(searchNo);

		}
	}

	for (int i = 0; i < T; ++i)
	{
		for (auto begVec = searchNum[i].begin(); begVec != searchNum[i].end(); ++begVec)
		{
			for (auto begMap = num2Loc[i].begin(); begMap != num2Loc[i].end(); ++begMap)
			{
				if (regex_match(*begVec, begMap->first))
					cout << begMap->second << endl;
			}
			cout << "unknown" << endl;
		}
	}

}