clean: objects
	rm game.o character.o

objects: headers
	g++ -o main main.cpp character.o game.o

headers: character.h game.h
	g++ -I ./ -c character.cpp -o character.o
	g++ -I ./ -c game.cpp -o game.o