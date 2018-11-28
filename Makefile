
CC = gcc
OBJS = main.o string_utils.o
EXEC = prog
COMP_FLAG = -std=c99 -Wall -Werror

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

main.o: main.c string_utils.o
	$(CC) -c $(COMP_FLAG) $*.c

string_utils.o: string_utils.c

clean:
	rm -f $(OBJS) $(EXEC)