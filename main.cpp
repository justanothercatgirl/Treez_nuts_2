#include <iostream>
#include "Trees/tree.hpp"

int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie();
	std::vector<int> s = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 118 };
	Trees::Tree<int> t = Trees::construct<int>(s);
	t.print_recursively();
	std::cin.get();
}

// cd / d D : / Programming / Git, cmake and linking / project0