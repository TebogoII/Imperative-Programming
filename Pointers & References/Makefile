output: main.o component.o locomotive.o cargo.o passenger.o train.o
	g++ -std=c++98 main.o component.o locomotive.o cargo.o passenger.o train.o -o output

main.o: main.cpp
	g++ -std=c++98 -c main.cpp

component.o: component.cpp
	g++ -std=c++98 -c component.cpp

locomotive.o: locomotive.cpp
	g++ -std=c++98 -c locomotive.cpp

cargo.o: cargo.cpp
	g++ -std=c++98 -c cargo.cpp

passenger.o: passenger.cpp
	g++ -std=c++98 -c passenger.cpp

train.o: train.cpp
	g++ -std=c++98 -c train.cpp

clean:
	rm *.o

run: output
	./output