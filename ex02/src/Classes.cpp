#include "../inc/Classes.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base::~Base()
{

}

Base	*generate(void)
{
	std::srand(std::time(NULL));
	char	to_gen = rand() % 3;

	if (to_gen == 0)
		return (new A);
	if (to_gen == 1)
		return (new B);
	if (to_gen == 2)
		return (new C);
	return (NULL);
}

void	identify(Base *p)
{
	if (p)
		identify(*p);
}

void	identify(Base &p)
{
	std::string	type;

	type = "unknown";
	try
	{
		(void) dynamic_cast<A&>(p);
		type = 'A';
	}
	catch (std::exception const &ex)
	{
		try
		{
			(void) dynamic_cast<B&>(p);
			type = 'B';
		}
		catch (std::exception const &ex)
		{
			try
			{
				(void) dynamic_cast<C&>(p);
				type = 'C';
			}
			catch (std::exception const &ex)
			{
				
			}
		}
	}
	std::cout << "The type is " << type << std::endl;
}
