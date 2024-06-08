#include "../inc/ScalarConverter.hpp"
#include <cstdlib>

//--------------------------  CANONICAL  --------------------------//
ScalarConverter::ScalarConverter(void)
{
	// std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
	// std::cout << "Copy Assignement operator called" << std::endl;
	(void) rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	// std::cout << "Destructor called" << std::endl;
}
//-----------------------------------------------------------------//


//-----------------------------  STATIC MEMBERS  ----------------------------//
void	ScalarConverter::convert(std::string data)
{
	double				d_rep;
	float				f_rep;
	char				c_rep;
	int					i_rep;

	d_rep = std::atof(data.c_str());
	f_rep = d_rep;
	i_rep = f_rep;
	c_rep = i_rep;
	std::cout << "char: " << c_rep << std::endl;
	std::cout << "int: " << i_rep << std::endl;
	std::cout << "float: " << f_rep << std::endl;
	std::cout << "double: " << d_rep << std::endl;
}
//---------------------------------------------------------------------------//