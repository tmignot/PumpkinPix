#include	<iostream>
//#define		H[2] {200,300}
int	main(void) {

	std::cout << "Hello!" << std::endl;
	std::cout << "Preprocessor Constants Arrays test" << std::endl;
	/*
	std::cout << "define H {200,300}" << std::endl;
	std::cout << "H[0] = " << H[0] << std::endl;
	std::cout << "H[1] = " << H[1] << std::endl;
	*/

	std::cout << "It doesn't work. It's too much for preprocessor. Just use multiple consts." << std::endl;
	return (0);
}
