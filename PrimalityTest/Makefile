Test: Test.o PrimalityTest.o Fermat.o Trial.o
	g++ $^ -o $@

Fermat.o: Fermat.cpp
	g++ $< -c -o $@

%.o: %.cpp
	g++ $< -c -o $@

clean:
	rm -f *.o Test
