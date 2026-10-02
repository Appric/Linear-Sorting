a.out: main.o countingSort.o
	g++ main.o countingSort.o -o a.out

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o a.out