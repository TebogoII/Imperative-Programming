output: main.o trolley.o
	g++ -std=c++98 main.o trolley.o -o output

main.o: main.cpp train.h train.cpp manager.h manager.cpp
	g++ -std=c++98 -c main.cpp

trolley.o: trolley.cpp
	g++ -std=c++98 -c trolley.cpp

clean:
	rm *.o

run: output
	./output