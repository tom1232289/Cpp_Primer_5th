#include "Bulk_quote.h"

int main()
{
	Quote q("1-1", 10);
	Bulk_quote bq("1-1", 10, 10, 0.3);
	print_total(cout, bq, 10);

	system("pause");
	return 0;
}