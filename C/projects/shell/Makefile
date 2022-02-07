CFLAGS=-Wall -Wextra
TARGET=output
SRCS=shell.c
OBJS=$(SRCS:.c=.o)

%.o:%.c
	$(CC) $< -c -o $@ $(CFLAGS)

all:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) -lm

debug:$(OBJS)
	$(CC) $(OBJS) -g $(TARGET) -lm

.PHONY: clean
clean:
	-$(RM) $(TARGET) $(OBJS)
