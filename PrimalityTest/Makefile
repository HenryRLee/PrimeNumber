Test: Test.o PrimalityTest.o Fermat.o Trial.o
	g++ $^ -lgmpxx -lgmp -o $@

Fermat.o: Fermat.cpp
	g++ -lgmpxx -lgmp $< -c -o $@

%.o: %.cpp
	g++ $< -c -o $@

clean:
	rm -f *.o Test
