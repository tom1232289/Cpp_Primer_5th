#include<iostream>
#include<map>
#include<string>

using namespace std;

void remove_author(multimap<string, string> &books, const string &author) {
	auto pos = books.equal_range(author);
	if (pos.first == pos.second)
		cout << "no find " << author << endl;
	else
		books.erase(pos.first, pos.second);
}

void print_books(const multimap<string, string> &books) {
	for (const auto b : books) 
		cout << b.first << ":¡¶" << b.second << "¡·" << endl;
}

int main()
{
	multimap<string, string> books;
	books.insert({ "zhang", "123" });
	books.insert({ "wang","456" });
	books.insert({ "zhang","789" });
	remove_author(books, "zhang");
	print_books(books);

	system("pause"); return 0;

}