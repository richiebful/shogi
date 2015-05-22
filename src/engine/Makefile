objects = check.o clock.o init.o legal.o move.o
files = check.c clock.c init.c legal.c move.c

engine.so: $(objects)
	clang -shared $(objects) -o engine.so

$(objects): $(files)
	clang -c $(files) -I../include/

clean:
	rm *.so
	rm *~
	rm \#*\#
