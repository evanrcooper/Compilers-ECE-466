CFLAGS = -Wall -Wno-abi -Wno-unused-function -I ./Lexer -I ./Parser -I ./SymbolTable -I ./Quads

all: parser

debug: flex bison
	gcc -DYYDEBUG=1 -o Parser/parser.out $(CFLAGS) Parser/parser.tab.c Lexer/lex.yy.c Parser/ast.c SymbolTable/sym_tab.c ./Quads/quads.c

flex: Lexer/lexer.l
	cd Lexer && flex lexer.l

bison: Parser/ast.c Parser/ast.h Parser/parser.y
	cd Parser && bison -d parser.y

parser: flex bison
	gcc -o Parser/parser.out $(CFLAGS) Parser/parser.tab.c Lexer/lex.yy.c Parser/ast.c SymbolTable/sym_tab.c ./Quads/quads.c

clean:
	rm -rf *.h.gch Parser/*.out Lexer/lex.yy.c Parser/parser.tab.* Lexer/*.out SymbolTable/*.out ./Quads/*.out