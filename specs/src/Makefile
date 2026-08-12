CPPFLAGS=-Wall

specs: parser.tar.o lex.yy.o query.o main.o rdf.o
	g++ $(CPPFLAGS) -o $@ $^
main.o: main.cpp query.hpp
	g++ $(CPPFLAGS) -c -o $@ $<
parser.tar.o: parser.tab.cpp
	g++ $(CPPFLAGS) -c -o $@ $<
lex.yy.o: lex.yy.c parser.tab.hpp query.hpp
	g++ $(CPPFLAGS) -c -o $@ $<
# The generated parser and lexer are committed for reproducible package builds.
# These recipes run only when a generated file is absent, so normal builds need
# make and g++ but not flex or bison.
parser.tab.cpp parser.tab.hpp:
	test -f parser.tab.cpp -a -f parser.tab.hpp || bison -vd parser.ypp
lex.yy.c:
	test -f lex.yy.c || flex -i lexer.lex
query.o: query.cpp query.hpp
	g++ $(CPPFLAGS) -c -o $@ $<
rdf.o: rdf.cpp rdf.hpp
	g++ $(CPPFLAGS) -c -o $@ $<

.PHONY: clean clean-build

clean:
	rm -f specs *.tab* *.o lex.yy.c *.output *~

# Preserve committed generated parser/lexer sources during portable package builds.
clean-build:
	rm -f specs *.o
