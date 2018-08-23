#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

struct Recv
{
	int difference;
	set<int>::iterator first;
	set<int>::iterator last;
};

bool shun(vector<int> &Varr, int *arr, int len)
{
	set<int>  myset(arr, arr + len);
	Recv recv = { 0,myset.begin(),myset.begin() };
	set<int>::iterator lt = myset.begin();
	set<int>::iterator st = myset.begin();
	if (st != myset.end() && (++st != myset.end()))
	{
		;
	}
	int i = 1;
	for (; st != myset.end(); )
	{
		if ((*st - i) == *lt)
		{
			st++;
			i++;
		}
		else if (recv.difference < i)
		{
			recv.first = lt;
			recv.last = st;
			recv.difference = i;
			i = 1;
			lt = st;
			st++;
		}
		else
		{
			i = 1;
			lt = st;
			st++;
		}
	}
	if (recv.difference >= 5)
	{
		for (set<int>::iterator mt = recv.first; mt != recv.last; ++mt)
		{
			for (auto beg = Varr.begin(); beg != Varr.end(); ++beg)
			{
				if (*beg == *mt)
				{
					Varr.erase(beg);
					break;
				}
			}
		}

		return true;
	}
	return false;
}

int main()
{
	string str;
	cin >> str;
	int *arr = new int[str.length()];
	
	int i = 0;
	for (auto sbeg = str.begin(); sbeg != str.end(); ++sbeg, ++i)
	{
		if (*sbeg == 'A')
			arr[i] = 1;
		else if (*sbeg == 'J')
			arr[i] = 11;
		else if (*sbeg == 'Q')
			arr[i] = 12;
		else if (*sbeg == 'K')
			arr[i] = 13;
		else if (*sbeg == 'T')
			arr[i] = 10;
		else
			arr[i] = *sbeg - '0';
	}
	vector<int> Varr(str.length());
	for (int i = 0; i < str.length(); i++)
		Varr[i] = arr[i];

	int step = 0;
	while (shun(Varr, arr, str.length()))
		++step;

}