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

void Sort(int *arr, int len)
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
    for (set<int>::iterator mt = recv.first; mt != recv.last; ++mt)
    {
        cout << *mt << " ";
    }
    cout << "size=" << recv.difference << endl;
    cout << endl;
}


void main()
{
    int arr[] = { 9,3,2,1,8,2,2,4,1,11};
    int len = sizeof(arr) / sizeof(arr[0]);
    Sort(arr, len);
}