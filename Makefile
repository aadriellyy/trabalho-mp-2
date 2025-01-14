testa_conta_palavras: testa_conta_palavras.cpp conta_palavra.o
	g++ -std=c++11 -Wall -ftest-coverage -fprofile-arcs conta_palavra.o testa_conta_palavras.cpp -o testa_conta_palavras
	./testa_conta_palavras

conta_palavras.o: conta_palavra.cpp conta_palavras.hpp
	g++ -std=c++11 -Wall -ftest-coverage -fprofile-arcs -c conta_palavra.cpp -o conta_palavra.o

compile: testa_conta_palavras.cpp conta_palavra.o
	g++ -std=c++11 -Wall conta_palavra.o testa_conta_palavras.cpp -o testa_conta_palavras
	
test: testa_conta_palavras
	./testa_conta_palavras