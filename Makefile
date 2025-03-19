CFLAGS = -Wall -Wno-abi -I ./Lexer -I ./Parser

all: parser

flex: Lexer/lexer.l
	cd Lexer && flex lexer.l

bison: Parser/ast.c Parser/ast.h Parser/parser.y
	cd Parser && bison -d parser.y

bison_debug: Parser/ast.c Parser/ast.h Parser/parser.y
	cd Parser && bison --debug -d parser.y

parser: flex bison
	gcc -o Parser/parser.out $(CFLAGS) Parser/parser.tab.c Lexer/lex.yy.c Parser/ast.c

debug_parser: flex bison_debug
	gcc -o Parser/parser_debug.out $(CFLAGS) Parser/parser.tab.c Lexer/lex.yy.c Parser/ast.c

clean:
	rm -rf *.h.gch Parser/*.out Lexer/lex.yy.c Parser/parser.tab.*