#include <iostream>
#include "Trees/tree.h"


int main(int argc, char *argv[])
{
	using namespace Trees;
	std::vector<int> s = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Tree<int> t = construct<int>(s);
	t.print_recursively();

}