CC		:= g++
OBJS	:= main.o sort.o

.PHONY: clean

a.out: $(OBJS)
	$(CC) $(OBJS) -o a.out

clean:
	rm $(OBJS) a.out