GCC = gcc
CFLAGS = -g 
TARGET = sieve
OBJS = sieve.o
HDRS = 
.SUFFIXES: .c .o

$(TARGET) : $(OBJS) $(HDRS)
	        $(GCC) $(CFLAGS) $(OBJS) -o $@
.c.o:
	        $(GCC) $(CFLAGS) -c $<
clean:
	        rm -f *.o *~ $(TARGET) $(OBJS)

