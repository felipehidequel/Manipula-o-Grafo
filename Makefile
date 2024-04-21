all: app

app: zero.cpp
	g++ -o zero zero.cpp -std=gnu++17 -Wall -g

clean:
	rm -f app *.o


