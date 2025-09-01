CC = gcc
CFLAGS  = -g -Wall

all: function.o funcExer1.o funcExer2.o funcExer3.o funcExer4.o funcExer5.o funcExer6.o funcExer7.o

function.o: function.c function.h 
	$(CC) $(CFLAGS) -c function.c	

funcExer1.o: funcExer1.c function.h
	$(CC) $(CFLAGS) -c funcExer1.c

funcExer2.o: funcExer2.c function.h
	$(CC) $(CFLAGS) -c funcExer2.c

funcExer3.o: funcExer3.c function.h
	$(CC) $(CFLAGS) -c funcExer3.c

funcExer4.o: funcExer4.c function.h
	$(CC) $(CFLAGS) -c funcExer4.c

funcExer5.o: funcExer5.c function.h
	$(CC) $(CFLAGS) -c funcExer5.c

funcExer6.o: funcExer6.c function.h
	$(CC) $(CFLAGS) -c funcExer6.c

funcExer7.o: funcExer7.c function.h
	$(CC) $(CFLAGS) -c funcExer7.c

clean:
	$(RM) *.o *~
