hw4: hw4.o
	g++ hw4.o -o hw4
	./hw4
hw4.o: hw4.cpp
	g++ hw4.cpp -c

clean:
	rm -rf hw4.o 
	rm -rf hw4
