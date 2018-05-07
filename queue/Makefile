CC      = gcc
CFLAGS  = -g
TARGET1 = generator
OBJS1   = generator.o
TARGET2 = grocery_sim
OBJS2   = grocery_sim.o functions.o queue.o
TARGET3 = bakery_sim
OBJS3   = bakery_sim.o functions.o queue.o

all: $(TARGET1) $(TARGET2) $(TARGET3)

$(TARGET1): $(OBJS1)
	        $(CC) -o $(TARGET1) $(OBJS1)

generate.o: generate.c 
	        $(CC) $(CFLAGS) -c generate.c

$(TARGET2): $(OBJS2)
	        $(CC) -o $(TARGET2) $(OBJS2)

grocery_sim.o: grocery_sim.c queue.c functions.c  queue.h 
	        $(CC) $(CFLAGS) -c grocery_sim.c

$(TARGET3): $(OBJS3)
	        $(CC) -o $(TARGET3) $(OBJS3)

bakery_sim.o: bakery_sim.c queue.c functions.c queue.h 
	$(CC) $(CFLAGS) -c bakery_sim.c

queue.o: queue.c queue.h 
	        $(CC) $(CFLAGS) -c queue.c

clean:
	        /bin/rm -f *.o *~ $(TARGET1) $(TARGET2) $(TARGET3)

