CFLAGS = -O3

all:
	$(CC) $(CFLAGS) lwbfi.c -o lwbfi

clean:
	rm lwbfi
