#include	<unistd.h>
#include	<fcntl.h>

#define		WHATEVERBITCH	0
#define		WCTMODE	O_WRONLY | O_CREAT
#define		OUTFILE_PERM	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

//rappels:
#define		EXTRABYTES	4-(WIDTH*3)%4
#define		ARRAY_SIZE	((WIDTH*3)+EXTRABYTES)*HEIGHT

int main(void) {

	unsigned char	array[16] = {0, 0, 0, 0, 0, 200, 200, 100, 100, 0, 0, 0, 0, 0, 0, 0};

	int	fd = open("test_bmpmodif.bmp", WCTMODE, OUTFILE_PERM);
	lseek(fd, 55, SEEK_SET);
	write(fd, array, 16);
	// the image used to be a black 2x2 pixels square.
	close(fd);
	return (WHATEVERBITCH);
}
