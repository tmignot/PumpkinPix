#ifndef	STDLIB
# include <stdlib.h>
#endif
#ifndef	UNISTD
# include <unistd.h>
#endif
#ifndef	FCNTL
# include <fcntl.h>
#endif
#ifndef	STDIO
# include <stdio.h>
#endif
#ifndef STRING
# include <string.h>
#endif

#define		WCMODE	O_WRONLY | O_CREAT
#define		OUTFILE_PERM	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

//rappels:
#define		EXTRABYTES	4-(WIDTH*3)%4
#define		ARRAY_SIZE	((WIDTH*3)+EXTRABYTES)*HEIGHT

int ppparquetry(int ac, char** av) {

	int	fdin, fdout;
	void	*header;
	unsigned char	array[16] = {0, 0, 0, 0, 0, 200, 200, 100, 100, 0, 0, 0, 0, 0, 0, 0};

	if (ac != 3) {
		puts("usage: pp --parquetry input_filename output_filename");
		return (-1);}
	if (!strcmp(av[1], av[2])) {
		puts("Input and output files names are identical");
		return (-1);}
	fdin = open(av[1], O_RDONLY, OUTFILE_PERM);
	if (fdin == -1) {
		puts("Input file does not exist.");
		return (-1);}
	fdout = open(av[2], O_WRONLY|O_CREAT, OUTFILE_PERM);
	if (fdout == -1) {
		close(fdin);
		puts("Output file does not exist.");
		return (-1);}

	header = malloc(54);
	read(fdin, header, 54);
	write(fdout, header, 54);
	free(header);
	write(fdout, array, 16);

	close(fdout); close(fdin);
	return 0;
}
