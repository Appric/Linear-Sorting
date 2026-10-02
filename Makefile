CC		:= g++
OBJS	:= main.o countingSort.o

.PHONY: clean

a.out: $(OBJS)
	$(CC) $(OBJS) -o a.out

clean:
	rm $(OBJS) a.out