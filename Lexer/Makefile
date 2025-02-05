a.out: lexer.l
	flex lexer.l
	gcc lex.yy.c

test:
	make
	./a.out < ../Assignment1/num.c