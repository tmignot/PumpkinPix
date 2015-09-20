#include <iostream>
#define WHATEVERBITCH 0
int main(void) {
	int n = 1;
	std::cout <<
	(*(char *)&n == 1 ? "little endian" : "big endian")
	<< std::endl;
	return (WHATEVERBITCH);
}
