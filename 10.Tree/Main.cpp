#include "Container/Node.h"
#include "Container/Tree.h"

int main()
{
	Tree<int> tree(10);

	tree.AddChild(10, 9);
	tree.AddChild(10, 8);
	tree.AddChild(9, 7);
	tree.AddChild(9, 6);



	Node<int>* outNode = nullptr;
	//if (tree.Find(6, outNode))
	//{
	//}

	//tree.Remove(9);

	tree.PreorderTraversal();

	return 0;
}         