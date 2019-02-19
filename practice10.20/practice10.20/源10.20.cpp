#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

void biggies(vector<string> words, size_t sz) {
	elimDups(words);
	//	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
	auto wc = stable_partition(words.begin(), words.end(), [sz](const string &s) { return s.size() >= sz; });
	auto count = count_if(words.begin(), words.end(), [sz](const string &s) { return s.size() >= sz; });
	cout << count << endl;
}

int main()
{
	vector<string> svec = { "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	biggies(svec, 5);

	system("pause"); return 0;
}