#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>

#include "../inc/ScalarConverter.hpp"

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
	std::streamsize	init_precision;
	double			d_rep;
	char			*end_ptr;

	d_rep = strtod(data.c_str(), &end_ptr);
	if (end_ptr == data.c_str())
		d_rep = NAN;
	if (d_rep >= std::numeric_limits<char>::min()
		&& d_rep <= std::numeric_limits<char>::max())
	{
		if (d_rep > 32 && d_rep < 127)
			std::cout << "char:\t" << (char) d_rep << std::endl;
		else
			std::cout << "char:\tNon displayable" << std::endl;
	}
	else
		std::cout << "char:\timpossible" << std::endl;
	if (d_rep >= std::numeric_limits<int>::min()
					&& d_rep <= std::numeric_limits<int>::max())
		std::cout << "int:\t" << (int) d_rep << std::endl;
	else
		std::cout << "int:\timpossible" << std::endl;
	init_precision = std::cout.precision();
	std::cout << std::fixed ;
	std::cout << std::setprecision(std::numeric_limits<float>::digits10 + 1);
	std::cout << "float:\t" << (float) d_rep << 'f' << std::endl;
	std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1);
	std::cout << "double:\t" << d_rep << std::endl;
	std::cout << std::scientific << std::setprecision(init_precision);
}
//---------------------------------------------------------------------------//