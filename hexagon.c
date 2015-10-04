#ifndef WHATEVERBITCH
# define WHATEVERBITCH -1
#endif
#ifndef	STDIO
# include <stdio.h>
#endif
#ifndef	FCNTL
# include <fcntl.h>
#endif
#ifndef	UNISTD
# include <unistd.h>
#endif

int	pphexagon(int ac, char** av) {
	int	fd;
	char	magic[2];

	if (ac == 1) {
		puts("hexagon: usage: pp --hexagon bmpfilename");
		return WHATEVERBITCH;}

	fd = open(av[1], O_RDONLY);
	if (fd == -1) {
		printf("hexagon: %s: file does not exist\n", av[1]);
		return WHATEVERBITCH;}

	read(fd, (void*)magic, 2);
	if (magic[0] != 'B' || magic[1] != 'M') {
		printf("hexagon: %s: not a bmp file\n", av[1]);}
	else {
		printf("hexagon: %s: bmp header\n", av[1]);
	}

	close(fd);
	return 0;
}
