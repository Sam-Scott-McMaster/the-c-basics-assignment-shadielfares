convert: convert.c parser.c convert.h parser.h
	gcc -o convert convert.c parser.c 
#The testdigits.c is like my main.c in this case

ctest: convert.c convert.h parser.c parser.h
	gcc -o ctest --coverage convert.c parser.c
clean:
	rm -f convert
