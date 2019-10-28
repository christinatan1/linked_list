all: functions.o main.o
	gcc -o test_list functions.o main.o

main.o: main.c header.h
	gcc -c main.c

functions.o: functions.c header.h
	gcc -c functions.c

run:
	./test_list

clean:
	rm *.o
	rm *~
