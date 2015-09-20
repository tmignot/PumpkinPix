#include	<unistd.h>
#include	<fcntl.h>

#define		WHATEVERBITCH	0
#define		WCTMODE	O_WRONLY | O_CREAT | O_TRUNC
#define		OUTFILE_PERM	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

//rappels:
#define		EXTRABYTES	4-(WIDTH*3)%4
#define		ARRAY_SIZE	((WIDTH*3)+EXTRABYTES)*HEIGHT

int main(void) {

	unsigned char	header[54] = {
		// BMPFILEHEADER (14 bytes)
		'B', 'M',	// magic
		70, 0, 0, 0,	// FILESIZE will be inserted here
		0, 0, 0, 0, // reserved space I don't use
		54, 0, 0, 0,	// headers' size (=offset to array)
		// BMPINFOHEADER (40 bytes)
		40, 0, 0, 0,	// iheader's size
		2, 0, 0, 0, 2, 0, 0, 0,	// WIDTH and HEIGHT will be inserted here
		1, 0,	// color planes number
		24, 0,	// bits per pixel
		0, 0, 0, 0,	// compression (none)
		16, 0, 0, 0,	// ARRAYSIZE will be inserted here
		0, 0, 0, 0,	// upload.wikimedia.org/wikipedia/commons/c/c4/BMPfileFormat.png
		0, 0, 0, 0,	// for more details
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	unsigned char	array[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	int	fd = open("test_bmpcreation.bmp", WCTMODE, OUTFILE_PERM);
	write(fd, header, 54);
	write(fd, array, 16);
	// right now it's a black 2x2 pixels square.
	close(fd);
	return (WHATEVERBITCH);
}
