#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
	public:
		static void	convert(std::string data);

	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter &operator=(ScalarConverter const & rhs);
		~ScalarConverter(void);
};
#endif
