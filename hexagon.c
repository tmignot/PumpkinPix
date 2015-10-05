#ifndef WHATEVERBITCH
# define WHATEVERBITCH -1
#endif
#ifndef	STDLIB
# include <stdlib.h>
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
	unsigned short	bmpih_size;

	if (ac == 1) {
		puts("hexagon: usage: pp --hexagon bmpfilename");
		return WHATEVERBITCH;}

	fd = open(av[1], O_RDONLY);
	if (fd == -1) {
		printf("hexagon: %s: file does not exist\n", av[1]);
		return WHATEVERBITCH;}

	read(fd, (void*)magic, 2);
	if (magic[0] != 'B' || magic[1] != 'M') {
		printf("hexagon: %s: not a bmp file\n", av[1]);
		close(fd);
		return WHATEVERBITCH;}

	printf("hexagon: %s: BMPFILEHEADER\n", av[1]);
	puts("size = always 14B including magic 2B");
	read(fd, (void*)bmpfileheader, 12);
	printf("%3d %3d %3d %3d |%10i  file size\n", bmpfileheader[0], bmpfileheader[1], bmpfileheader[2], bmpfileheader[3], ((int*)bmpfileheader)[0]);
	printf("%3d %3d %3d %3d |%10i  reserved space\n", bmpfileheader[4], bmpfileheader[5], bmpfileheader[6], bmpfileheader[7], ((int*)bmpfileheader)[1]);
	printf("%3d %3d %3d %3d |%10i  bmp header total size\n", bmpfileheader[8], bmpfileheader[9], bmpfileheader[10], bmpfileheader[11], ((int*)bmpfileheader)[2]);

	printf("hexagon: %s: BMPINFOHEADER\n", av[1]);
	bmpih_size = ((int*)bmpfileheader)[2]-14;
	printf("size = %dB\n", bmpih_size);
	bmpinfoheader = malloc(bmpih_size);
	if (!bmpinfoheader) {
		puts("bmpinfoheader: malloc error");
		close(fd);
		return WHATEVERBITCH;}
	read(fd, (void*)bmpinfoheader, bmpih_size);
	printf("%3d %3d %3d %3d |%10i  info header size\n", bmpinfoheader[0], bmpinfoheader[1], bmpinfoheader[2], bmpinfoheader[3], ((int*)bmpinfoheader)[0]);
	printf("%3d %3d %3d %3d |%10i  image width\n", bmpinfoheader[4], bmpinfoheader[5], bmpinfoheader[6], bmpinfoheader[7], ((int*)bmpinfoheader)[1]);
	printf("%3d %3d %3d %3d |%10i  image height\n", bmpinfoheader[8], bmpinfoheader[9], bmpinfoheader[10], bmpinfoheader[11], ((int*)bmpinfoheader)[2]);
	printf("%7d %7d |%10i  color planes number\n", bmpinfoheader[12], bmpinfoheader[13], bmpinfoheader[12] + bmpinfoheader[13]*10);
	printf("%7d %7d |%10i  bits per pixel\n", bmpinfoheader[14], bmpinfoheader[15], bmpinfoheader[14] + bmpinfoheader[15]*10);
	printf("%3d %3d %3d %3d |%10i  compression\n", bmpinfoheader[16], bmpinfoheader[17], bmpinfoheader[18], bmpinfoheader[19], ((int*)bmpinfoheader)[4]);
	printf("%3d %3d %3d %3d |%10i  pixel array size (bytes)\n", bmpinfoheader[20], bmpinfoheader[21], bmpinfoheader[22], bmpinfoheader[23], ((int*)bmpinfoheader)[5]);
	printf("%3d %3d %3d %3d |%10i\n", bmpinfoheader[24], bmpinfoheader[25], bmpinfoheader[26], bmpinfoheader[27], ((int*)bmpinfoheader)[6]);
	printf("%3d %3d %3d %3d |%10i\n", bmpinfoheader[28], bmpinfoheader[29], bmpinfoheader[30], bmpinfoheader[31], ((int*)bmpinfoheader)[7]);
	printf("%3d %3d %3d %3d |%10i\n", bmpinfoheader[31], bmpinfoheader[32], bmpinfoheader[33], bmpinfoheader[34], ((int*)bmpinfoheader)[8]);
	printf("%3d %3d %3d %3d |%10i\n", bmpinfoheader[35], bmpinfoheader[36], bmpinfoheader[37], bmpinfoheader[38], ((int*)bmpinfoheader)[9]);

	close(fd);
	return 0;
}
