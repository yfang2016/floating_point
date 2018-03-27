CC 	= gcc
main: main.c add.c sub.c mul.c
	$(CC) -o $@ $^
