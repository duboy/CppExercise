#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std; 

void main()
{
	multimap<int, int> imap;
	imap.insert(make_pair(3, 5));
	imap.insert(make_pair(3, 1));
	
	cout << (--imap.upper_bound(3))->second;
}