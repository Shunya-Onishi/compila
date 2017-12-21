CC	= gcc
CFLAGS	= -O -Wall
LEX	= flex
YACC 	= bison -d
HDRS	= edu4.tab.h
LDFLAGS	= -lfl -ly
LIBS	=
OBJS	= edu4.tab.o lex.yy.o ast.o
PROGRAM	= mycompiler

all:		$(PROGRAM)

$(PROGRAM):	$(OBJS) $(HDRS) 
	$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)

lex.yy.c: edu4.l
	$(LEX) edu4.l
edu4.tab.c: edu4.y
	$(YACC) edu4.y

clean:;		rm -f* .o*~

###
lex.yy.o:lex.yy.c edu4.tab.h
edu4.tab.o:edu4.tab.c edu4.tab.h
ast.o:makeast.c makeast.h