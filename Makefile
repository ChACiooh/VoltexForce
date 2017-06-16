volforce: volforce.o
	g++ -o volforce volforce.o

volforce.o: volforce.cc
	g++ -c volforce.cc

clean: 
	rm *.o volforce

