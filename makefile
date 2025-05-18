CC = gcc
CFLAGS = -g -Wall -std=c99
CCLINK = gcc
OBJS = main.o stack.o student.o
EXEC = prog.exe
RM = rm -f

$(EXEC): $(OBJS)
	$(CCLINK) $(OBJS) -o $(EXEC)

main.o: main.c stack.h student.h common.h
	$(CC) $(CFLAGS) -c main.c

stack.o: stack.c stack.h common.h
	$(CC) $(CFLAGS) -c stack.c

student.o: student.c student.h common.h
	$(CC) $(CFLAGS) -c student.c

clean:
	$(RM) $(OBJS) $(EXEC)