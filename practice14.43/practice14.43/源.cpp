#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

bool devidedByAll(vector<int> &ivec, int divident)
{
	return count_if(ivec.begin(), ivec.end(), bind(modulus<int>(), _1, divident)) == 0;
}