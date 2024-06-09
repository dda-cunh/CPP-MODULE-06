#include <iostream>

#include "../inc/Serializer.hpp"
#include "../inc/Data.hpp"

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
	struct Data	*deserialized;
	uintptr_t	serialized;

	DO_TEST("STACK", 
	{
		struct Data	original = {};

		original.age = 24;
		original.name = "Ronald Macnaldo";
		std::cout << "Original:" << std::endl << '\t';
		std::cout << original << std::endl;
		std::cout << '\t' << &original << std::endl;
		serialized = Serializer::serialize(&original);
		std::cout << "Serialized:" << std::endl << '\t';
		std::cout << serialized << std::endl;
		deserialized = Serializer::deserialize(serialized);
		std::cout << "Deserialized:" << std::endl << '\t';
		if (deserialized)
			std::cout << *deserialized << std::endl;
		else
			std::cout << deserialized << std::endl;
	});
	DO_TEST("HEAP", 
	{
		struct Data	*original;

		original = new struct Data;
		original->age = 35;
		original->name = "Mcree Dagree";
		std::cout << "Original:" << std::endl << '\t';
		std::cout << *original << std::endl;
		std::cout << '\t' << original << std::endl;
		serialized = Serializer::serialize(original);
		std::cout << "Serialized:" << std::endl << '\t';
		std::cout << serialized << std::endl;
		deserialized = Serializer::deserialize(serialized);
		std::cout << "Deserialized:" << std::endl << '\t';
		if (deserialized)
			std::cout << *deserialized << std::endl;
		else
			std::cout << deserialized << std::endl;
		delete original;
	});
	DO_TEST("NULL", 
	{
		struct Data	*original;

		original = NULL;
		std::cout << "Original:" << std::endl;
		std::cout << '\t' << original << std::endl;
		serialized = Serializer::serialize(original);
		std::cout << "Serialized:" << std::endl << '\t';
		std::cout << serialized << std::endl;
		deserialized = Serializer::deserialize(serialized);
		std::cout << "Deserialized:" << std::endl << '\t';
		if (deserialized)
			std::cout << *deserialized << std::endl;
		else
			std::cout << deserialized << std::endl;
	});
}
