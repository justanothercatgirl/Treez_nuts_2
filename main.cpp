#include <iostream>
#include "Trees/tree.h"

int main(int argc, char *argv[])
{
	using namespace Trees;
	std::vector<int> s = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 118 };
	Tree<int> t = construct<int>(s);
	t.print_recursively();

}

// cd / d D : / Programming / Git, cmake and linking / project0