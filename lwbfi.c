#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdint.h>
#include <unistd.h>

typedef int32_t cell_t;
cell_t *array;
int fd, ip = 0, cp = 0;
char c;

char gc(int icp) {
	int n = pread(fd, &c, sizeof(char), icp * sizeof(char));
	if(!n)
		exit(EXIT_SUCCESS);
}

void run_std() {
	if(c == '+')
		array[cp] = array[cp] + 1;
	if(c == '-')
		array[cp] = array[cp] - 1;
	if(c == '>')
		cp++;
	if(c == '<')
		cp--;
	if(c == '.')
		putchar((char) array[cp]);
	if(c == ',')
		array[cp] = getchar();
}

void run() {
	while(1) {
		gc(ip);
		run_std();
		ip++;
	}
}

int main(int argc, char ** argv) {
	if(argc != 2)
		exit(EXIT_FAILURE);
	array = calloc(sizeof(cell_t), 30000);	
	fd = open(argv[1], O_RDONLY);
	if(!fd)
		exit(EXIT_FAILURE);

	run();	

	close(fd);
}
