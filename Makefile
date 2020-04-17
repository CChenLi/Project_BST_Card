game: main.cpp cards.cpp
	g++ main.cpp cards.cpp -o game

unittest: testcards.cpp cards.cpp
	g++ cards.cpp testcards.cpp -o unittest
