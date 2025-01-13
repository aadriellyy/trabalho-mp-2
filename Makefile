testa_conta_palavras: testa_conta_palavras.cpp conta_palavras.o
	g++ -std=c++11 -Wall -ftest-coverage -fprofile-arcs conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	./testa_conta_palavras

conta_palavras.o: conta_palavras.cpp conta_palavras.hpp
	g++ -std=c++11 -Wall -ftest-coverage -fprofile-arcs -c conta_palavras.cpp -o conta_palavras.o

compile: testa_conta_palavras.cpp conta_palavras.o
	g++ -std=c++11 -Wall conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	
test: testa_conta_palavras
	./testa_conta_palavras