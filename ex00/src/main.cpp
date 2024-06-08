#include "../inc/ScalarConverter.hpp"

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
	DO_TEST("string == \"0\"",
	{
		ScalarConverter::convert("0");
	});
	DO_TEST("string == \"nan\"",
	{
		ScalarConverter::convert("nan");
	});
	DO_TEST("string == \"42.0f\"",
	{
		ScalarConverter::convert("42.0f");
	});
	DO_TEST("string == \"inf\"",
	{
		ScalarConverter::convert("inf");
	});
	DO_TEST("string == \"-inf\"",
	{
		ScalarConverter::convert("-inf");
	});
	DO_TEST("string == \"42.43444546474849\"",
	{
		ScalarConverter::convert("42.43444546474849");
	});
}
