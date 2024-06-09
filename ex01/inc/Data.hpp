#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

struct	Data
{
	unsigned char	age;
	std::string		name;
};

std::ostream	&operator<<(std::ostream & o, struct Data const & i);

#endif