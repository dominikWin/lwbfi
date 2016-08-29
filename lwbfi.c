#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdint.h>
#include <unistd.h>

typedef int32_t cell_t;
cell_t *array;

int main(int argc, char ** argv) {
	if(argc != 2)
		exit(EXIT_FAILURE);
	array = calloc(sizeof(cell_t), 30000);	
	int fd = open(argv[1], O_RDONLY);
	if(!fd)
		exit(EXIT_FAILURE);


	close(fd);
}
