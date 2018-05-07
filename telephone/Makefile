GCC = gcc
CFLAGS = -g 
TARGET = phone
OBJS = phone_fmt.o phone.o
HDRS = phone_fmt.h 
.SUFFIXES: .c .o

$(TARGET) : $(OBJS) $(HDRS)
	        $(GCC) $(CFLAGS) $(OBJS) -o $@
.c.o:
	        $(GCC) $(CFLAGS) -c $<
clean:
	        rm -f *.o *~ $(TARGET) $(OBJS)

