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
	unsigned char	magic[2];
	unsigned char	bmpfileheader[12];
	unsigned char*	bmpinfoheader;

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
		printf("hexagon: %s: BMPFILEHEADER\n", av[1]);
		read(fd, (void*)bmpfileheader, 12);
		printf("%3d %3d %3d %3d |%10i  file size\n", bmpfileheader[0], bmpfileheader[1], bmpfileheader[2], bmpfileheader[3], ((int*)bmpfileheader)[0]);
		printf("%3d %3d %3d %3d |%10i  reserved space\n", bmpfileheader[4], bmpfileheader[5], bmpfileheader[6], bmpfileheader[7], ((int*)bmpfileheader)[1]);
		printf("%3d %3d %3d %3d |%10i  bmp header total size\n", bmpfileheader[8], bmpfileheader[9], bmpfileheader[10], bmpfileheader[11], ((int*)bmpfileheader)[2]);
	}

	close(fd);
	return 0;
}
