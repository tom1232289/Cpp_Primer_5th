#include<iostream>
#include<utility>
#include<vector>

using namespace std;

pair<string, int> process(vector<string> &v) {
	if (!v.empty())
		return make_pair(v.back(), v.back().size());
	else
		return pair<string, int>();
}