#include "../inc/Data.hpp"

std::ostream	&operator<<(std::ostream & o, struct Data const & i)\
{
	o << i.name << ", " << (unsigned short) i.age << " years old";
	return (o);
}
