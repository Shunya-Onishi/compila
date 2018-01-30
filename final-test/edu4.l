%{
#include "edu4.tab.h"
%}
%%
if {return IF;}
else {return ELSE;}
while {return WHILE;}
array {return array;}
define {return define;}
for {return FOR;}

"==" {return deq;}
"<"  {return lt;}
">"  {return gt;}
"<=" {return le;}
">=" {return ge;}
"++" {return incri;}
"--" {return decri;}
"+"  {return add;}
"-"  {return sub;}
"*"  {return mul;}
"/"  {return divi;}

-?(([0-9]+)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?) {yylval.dval = atof(yytext);  return NUMBER;}

[a-zA-Z_][a-zA-Z0-9_]* {return IDEN;}




[\t ] ; /*ignore whitespace*/
"$" {return 0; /*end of input*/}
\n ;
. return yytext[0];
%%
