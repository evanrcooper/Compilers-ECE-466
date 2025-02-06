enum tokens {
	TOKEOF=0, // end of file
	IDENT=257, // identifier (i.e. variable name, typedef name)
	NEWLINE, // \n
	CHARLIT, // char literal (i.e. 'x')
	STRINGLIT, // string literal (i.e. "string")
	NUMBERLIT, // number literal(i.e. 0x059859 or 5000)
	FLOATLIT, // float literal
	INDSEL, // ->
	PLUSPLUS, // ++
	MINUSMINUS, // --
	SHL, // <<
	SHR, // >>
	LTEQ, // <=
	GTEQ, // >=
	EQEQ, // ==
	NOTEQ, // !=
	LOGAND, // &&
	LOGOR, // ||
	ELLIPSIS, // ...
	TIMESEQ, // *=
	DIVEQ, // /=
	MODEQ, // %=
	PLUSEQ, // +=
	MINUSEQ, // -=
	SHLEQ, // <<=
	SHREQ, // >>=
	ANDEQ, // &=
	OREQ, // |=
	XOREQ, // ^=
	AUTO, // auto
	BREAK, // break
	CASE, // case
	CHAR, // char
	CONST, // const
	CONTINUE, // continue
	DEFAULT, // default
	DO, // do
	DOUBLE, // double
	ELSE, // else
	ENUM, // enum
	EXTERN, // extern
	FLOAT, // float
	FOR, // for
	GOTO, // goto
	IF, // if
	INLINE, // inline
	INT, // int
	LONG, // long
	REGISTER, // register
	RESTRICT, // restrict
	RETURN, // return
	SHORT, // short
	SIGNED, // signed
	SIZEOF, // sizeof
	STATIC, // static
	STRUCT, // struct
	SWITCH, // switch
	TYPEDEF, // typedef
	UNION, // union
	UNSIGNED, // unsigned
	VOID, // void
	VOLATILE, // volatile
	WHILE, // while
	_BOOL, // _bool
	_COMPLEX, // _complex
	_IMAGINARY, // _imaginary
	SEMICOLON, // ;
	SKIP, // skip this token
};
