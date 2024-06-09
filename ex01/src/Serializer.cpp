#include "../inc/Serializer.hpp"

//-------------------------------  CANONICAL  -------------------------------//
Serializer::Serializer(void)
{
	// std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(Serializer const & src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Serializer & Serializer::operator=(Serializer const & rhs)
{
	// std::cout << "Copy Assignement operator called" << std::endl;
	(void) rhs;
	return (*this);
}

Serializer::~Serializer(void)
{
	// std::cout << "Destructor called" << std::endl;
}
//---------------------------------------------------------------------------//

//-----------------------------  STATIC MEMBERS  ----------------------------//
uintptr_t	Serializer::serialize(Data *ptr)
{
	return ((uintptr_t) ptr);
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	return ((struct Data*) raw);
}
//---------------------------------------------------------------------------//