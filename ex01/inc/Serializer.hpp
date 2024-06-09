#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

struct	Data;

typedef unsigned long	uintptr_t;

class Serializer
{
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);

	private:
		Serializer(void);
		Serializer(Serializer const & src);
		Serializer &operator=(Serializer const & rhs);
		~Serializer(void);
};

#endif
