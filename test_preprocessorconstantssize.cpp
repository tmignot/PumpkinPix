#include	<iostream>
#include	<climits>
#define		INT0 0
#define		INT1 200
#define		INT2 -200
#define		INT3 INT_MAX
#define		INT4 INT_MIN
#define		CHAR1 'a'
#define		STR1 "BM"
int	main(void) {
	int		int0 = 0;
	int		int1 = 200;
	int		int2 = -200;
	int		int3 = INT_MAX;
	int		int4 = INT_MIN;
	char	char1 = 'a';
	std::string	str1 = "BM";

	std::cout << "Hello!" << std::endl;
	std::cout << "Preprocessor Constants Sizes" << std::endl;

	std::cout << "int0 = 0 -> size = " << sizeof(int0) << std::endl;
	std::cout << "INT0 0 -> size = " << sizeof(INT0) << std::endl;
	std::cout << "int1 = 200 -> size = " << sizeof(int1) << std::endl;
	std::cout << "INT1 200 -> size = " << sizeof(INT1) << std::endl;
	std::cout << "int2 = -200 -> size = " << sizeof(int2) << std::endl;
	std::cout << "INT2 -200 -> size = " << sizeof(INT2) << std::endl;
	std::cout << "int3 = INT_MAX -> size = " << sizeof(int3) << std::endl;
	std::cout << "INT3 INT_MAX -> size = " << sizeof(INT3) << std::endl;
	std::cout << "int4 = INT_MIN -> size = " << sizeof(int4) << std::endl;
	std::cout << "INT4 INT_MIN -> size = " << sizeof(INT4) << std::endl;

	std::cout << "char1 = 'a' -> size = " << sizeof(char1) << std::endl;
	std::cout << "CHAR1 'a' -> size = " << sizeof(CHAR1) << std::endl;

	std::cout << "str1 = \"BM\" -> size = " << str1.length() << std::endl;
	std::cout << "STR1 \"BM\" -> size = " << sizeof(STR1)-1 << std::endl;
	return (0);
}
