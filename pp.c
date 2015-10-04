#ifndef WHATEVERBITCH
# define WHATEVERBITCH -1
#endif
#ifndef	STDIO
# include <stdio.h>
#endif
#ifndef STRING
# include <string.h>
#endif

int	ppparquetry(int, char**);
int	pphexagon(int, char**);

int	main(int ac, char** av) {

	if (ac == 1) {
		puts("pp: Pumpkin Pix (2015)");
		return WHATEVERBITCH;}

	if (!strcmp(av[1], "-p") || !strcmp(av[1], "--parquetry")) {
		puts("pp: Parquetry mode");
		return(ppparquetry(ac-1, &(av[1])));}
	else if (!strcmp(av[1], "-h") || !strcmp(av[1], "--hexagon")) {
		puts("pp: Hexagon mode");
		//return(pphexagon(ac-1, &(av[1])));}
	}

	return 0;
}
