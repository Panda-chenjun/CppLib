libexstdc++.a : stdio.o
	ar -rcs libexstdc++.a stdio.o
stdio.o : stdio.h
	g++ -c stdio.tcc -o stdio.o