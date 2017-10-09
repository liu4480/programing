all: search

search: clean
	g++ -o search search.c binary_search.c jump_search.c interpolation_search.c exponential_search.c ternary_search.c \
		search.h

clean:
	rm -rf *.o search

