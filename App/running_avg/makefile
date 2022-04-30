LIBOBJS=../../my_lib/build/*.o
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
DEPS=$(SRCS:.c=.d)
CFLAGS = -Wall


.PHONY: all clean

-include $(DEPS)

all: running_avg

%.o : %.c
		gcc $(CFLAGS) -c $< -MD -MF $*.d

running_avg: $(OBJS) 
		gcc $(CFLAGS) $^ -o $@ $(LIBOBJS)
		rm -f *.o

clean:
		rm -f *.d *.o running_avg