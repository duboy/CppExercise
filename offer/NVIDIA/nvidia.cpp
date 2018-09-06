#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

//两个vector求交集
vector<int> vectors_intersection(vector<int> &sort_v1,vector<int> &sort_v2)
{
	vector<int> v;
	set_intersection(sort_v1.begin(), sort_v1.end(), sort_v2.begin(), sort_v2.end(),back_inserter(v));//求交集 
	return v;
}
 
//两个vector求并集
vector<int> vectors_union(vector<int> &sort_v1,vector<int> &sort_v2)
{
	vector<int> v;
	set_union(sort_v1.begin(), sort_v1.end(), sort_v2.begin(), sort_v2.end(),back_inserter(v));//求交集 
	return v;
}

//打印vector
void printV(vector<int> &ivec)
{
	for (const auto i : ivec)
		cout << i << " ";
	cout << endl;
}
int main()
{
	vector<int> v1 = {3, 4, 6, 7, 2};
	vector<int> v2 = {1, 2, 3, 4, 5};
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	vector<int> vec_intersection = vectors_intersection(v1, v2);
	vector<int> vec_union = vectors_union(v1, v2);
	
	printV(v1);
	printV(v2);
	
	//输出并集和交集， 题目并没有要求输出
	printV(vec_intersection);
	printV(vec_union);

}