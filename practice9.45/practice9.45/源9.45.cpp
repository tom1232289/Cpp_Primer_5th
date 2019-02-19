#include<iostream>
#include<string>

using namespace std;

void name_string(string &name, const string &prefix, const string &suffix) {
	name.insert(name.begin(), 1, ' ');
	name.insert(name.begin(), prefix.begin(), prefix.end());
	name.append(" ");
	name.append(suffix.begin(), suffix.end());
}

int main()
{
	string s = "James Bond";
	name_string(s, "Mr.", "¢ò");
	cout << s << endl;

	s = "M";
	name_string(s, "Mrs.", "¢ó");
	cout << s << endl;

	system("pause"); return 0;
}