#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;
using namespace placeholders;

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

bool check_size(const string &s, size_t sz) {
	return s.size() >= sz;
}

void biggies(vector<string> words, size_t sz) {
	elimDups(words);
	//	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
//	auto wc = stable_partition(words.begin(), words.end(), [sz](const string &s) { return s.size() >= sz; });
	auto wc = stable_partition(words.begin(), words.end(), bind(check_size, _1, sz));
	for_each(words.begin(), wc, [](const string &s) { cout << s << " "; });
	cout << endl;
}

int main()
{
	vector<string> svec = { "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	biggies(svec, 5);

	system("pause"); return 0;
}