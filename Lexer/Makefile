a.out: lexer.l
	flex lexer.l
	gcc lex.yy.c

test_nums:
	make
	./a.out < ../Assignment1/num.c

test_ops:
	make
	./a.out < ../Assignment1/op.c

test_kws:
	make
	./a.out < ../Assignment1/kw.c

test_chars:
	make
	./a.out < ../Assignment1/chars.c