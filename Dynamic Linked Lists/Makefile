output: main.o
	g++ -std=c++98 main.o -o output

main.o: main.cpp Node.h Node.cpp DynamicList.h DynamicList.cpp
	g++ -std=c++98 -c main.cpp

clean:
	rm *.o

run: output
	./output