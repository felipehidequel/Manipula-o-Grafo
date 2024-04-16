all: app

app: terceira_unidade.cpp
	g++ -o app terceira_unidade.cpp -Wall -g

clean:
	rm -f app *.o

debug: terceira_unidade.cpp
	g++ -o app terceira_unidade.cpp -Wall -g -DDEBUG

