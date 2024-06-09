#include <cstddef>
#include <iostream>

#include "../inc/Classes.hpp"

#define CLI_GREEN		"\033[32m"
#define CLI_RESET		"\033[0m"
#define CLI_CYAN		"\033[36m"

#define TEST_LINE_LEN	100

#define DO_TEST(name, test_scope)					\
	do												\
	{												\
		testHeader(std::cout, name);				\
		test_scope									\
		testFooter(std::cout);						\
	} while(0)

void	testFooter(std::ostream &o)
{
	o << std::endl << CLI_GREEN;
	o << std::string(TEST_LINE_LEN, '-');
	o << CLI_RESET << std::endl;
}

void	testHeader(std::ostream &o, std::string name)
{
	size_t		len;

	testFooter(std::cout);
	if (name.length() > TEST_LINE_LEN / 2)
		name = "  " + name.substr(TEST_LINE_LEN / 2) + " test  ";
	else
		name = "  " + name + " test  ";
	o << std::endl << CLI_GREEN;
	len = (TEST_LINE_LEN / 2) - (name.length() / 2);
	o << std::string(len, '-') << name;
	if (name.length() & 1)
		len--;
	o << std::string(len, '-') << std::endl << std::endl << CLI_CYAN;
}

int main(void)
{
	// Base	*base_heap;

	DO_TEST("Identify A",
	{
		A	a;

		std::cout << "reference: " << std::endl << '\t';
		identify(a);
		std::cout << "pointer: " << std::endl << '\t';
		identify(&a);
	});
	DO_TEST("Identify B",
	{
		B	b;

		std::cout << "reference: " << std::endl << '\t';
		identify(b);
		std::cout << "pointer: " << std::endl << '\t';
		identify(&b);
	});
	DO_TEST("Identify C",
	{
		C	c;

		std::cout << "reference: " << std::endl << '\t';
		identify(c);
		std::cout << "pointer: " << std::endl << '\t';
		identify(&c);
	});
	DO_TEST("Identify generate()",
	{
		Base	*obj;

		obj = generate();
		std::cout << "reference: " << std::endl << '\t';
		identify(*obj);
		std::cout << "pointer: " << std::endl << '\t';
		identify(obj);
		delete obj;
	});
	DO_TEST("Identify *(Base *)int",
	{
		Base	base;
		long	i;

		i = 0;
		base = *(Base *)i;
		std::cout << "reference: " << std::endl << '\t';
		identify(base);
		std::cout << "pointer: " << std::endl << '\t';
		identify(&base);
	});
	DO_TEST("Identify NULL",
	{
		identify(NULL);
	});
}
