#include<iostream>
#include<forward_list>
#include<string>

using namespace std;

void test_insert(forward_list<string> &fstr, const string &str1, const string &str2) {
	auto prev = fstr.cbefore_begin();
	auto curr = fstr.cbegin();
	bool inserted = false;
	while (curr != fstr.cend()) {
		if (*curr == str1) {
			curr = fstr.insert_after(curr, str2);
			inserted = true;
		}
		prev = curr;
		++curr;
	}
	if (!inserted) 
		fstr.insert_after(prev, str2);
}

int main()
{
	forward_list<string> fstr = { "Hello","!","world","!" };
	test_insert(fstr, "Hello", "ÄãºÃ");
	for (auto c : fstr)
		cout << c << " ";
	cout << endl;

	test_insert(fstr, "!", "?");
	for (auto c : fstr)
		cout << c << " ";
	cout << endl;

	test_insert(fstr, "Bye", "ÔÙ¼û");
	for (auto c : fstr)
		cout << c << " ";
	cout << endl;

	system("pause"); return 0;
}