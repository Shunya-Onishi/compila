%%
[ \n\t]
is|am|are|was|were { ECHO; printf(" : is a verb\n"); }
.* { ECHO; printf(" : is not a verb\n"); }
%%
int main(void) {
yylex();
return 0;
}  