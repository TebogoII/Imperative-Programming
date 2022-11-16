output: main.o ingredient.o cauldron.o
	g++ -std=c++98 main.o ingredient.o cauldron.o -o output

main.o: main.cpp
	g++ -std=c++98 -c main.cpp

ingredient.o: ingredient.cpp
	g++ -std=c++98 -c ingredient.cpp

cauldron.o: cauldron.cpp
	g++ -std=c++98 -c cauldron.cpp

clean:
	rm *.o

run: output
	./output
