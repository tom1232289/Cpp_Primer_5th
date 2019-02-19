#include "BinStrTree.h"

int main()
{
	TreeNode tn1;
	TreeNode tn2("1");
	TreeNode tn3(tn2);
	TreeNode tn4;
	tn4 = tn3;

	BinStrTree bst1;
	BinStrTree bst2(bst1);
	BinStrTree bst3;
	bst3 = bst2;

	getchar();
	return 0;
}