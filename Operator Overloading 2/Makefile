output: main.o tome.o
	g++ -std=c++98 main.o tome.o -o output

main.o: main.cpp
	g++ -std=c++98 -c main.cpp

tome.o: tome.cpp
	g++ -std=c++98 -c tome.cpp
clean:
	rm *.o

run: output
	./output
