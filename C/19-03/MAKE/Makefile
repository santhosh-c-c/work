all: output

hello.o : hello.c
	@echo "Compiling hello.c"
	@gcc -c hello.c

main.o : main.c
	@echo "Compiling main.c"
	@gcc -c main.c

output : hello.o main.o
	@echo "Linking"
	@gcc main.o hello.o -o output

clean:
	@echo "Removing - Files"
	@rm hello.o main.o output

