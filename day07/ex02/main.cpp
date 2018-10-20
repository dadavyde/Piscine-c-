#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int>  a;
	Array<int>  b(5);

	std::cout << "Initialize b(5)" << std::endl;
	try
	{
		std::cout << "array b: "<< b[0] << " " << b[1] << " " << b[2] << " " << b[3] << " " << b[4] << " " << b[5] << " " << b[6] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Equate to the array a array b." << std::endl;
	a = b;
	std::cout << "Copy to array c array a." << std::endl;
	Array<int>  c(a);
	std::cout << "size of array c: " << c.size() << std::endl;
	std::cout << "Initialize array a with new values." << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;
	std::cout << "array a: " << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << std::endl;
	std::cout << "array b: " << b[0] << " " << b[1] << " " << b[2] << " " << b[3] << " " << b[4] << std::endl;
}
