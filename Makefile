testbst: testbst.cpp intbst.cpp intbst.h
	g++ -g -o testbst testbst.cpp intbst.cpp

clean:
	rm -f testbst
