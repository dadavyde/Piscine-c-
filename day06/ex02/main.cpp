#include <iostream>
#include <ctime>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>


Base * generate(void)
{
	Base *base;

	int i = rand() % 3;
	if(i == 0)
		base = new A();
	else if (i == 1)
		base = new B();
	else
		base = new C();
	return (base);
}

void  identify_from_pointer(Base * p)
{

	A *a = dynamic_cast<A *>(p);
	if (a)
		std::cout << "It's A class." << std::endl;
	else
	{
		B *b = dynamic_cast<B *>(p);
		if (b)
			std::cout << "It's B class." << std::endl;
		else
		{
			C *c = dynamic_cast<C *>(p);
			if (c)
				std::cout << "It's C class." << std::endl;
		}
	}
}

void identify_from_reference( Base & p )
{

	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "It's reference to A class." << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			B b = dynamic_cast<B&>(p);
			std::cout << "It's reference to B class." << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				C c = dynamic_cast<C&>(p);
				std::cout << "It's reference to C class." << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}

		}

	}
}


int main()
{

	srand(time(0));
	Base  *p;

	p = generate();
	identify_from_pointer(p);
	identify_from_reference(*p);
	delete p;
}
