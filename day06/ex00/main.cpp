#include "Cast.hpp"

int main(int argc, char **argv)
{
	std::string  literal;
	Cast cast;

	if (argc != 2)
	{
		std::cout << "Wrong argument" << std::endl;
		return (0);
	}
	literal = argv[1];
	cast.cast_literal(literal);
}
