%{
int num_lines=0,num_chars = 0,num_words = 0;
%}
%%
\n ++num_lines; ++num_chars; ++num_words;
\t ++num_words;
" " ++num_words;
. ++num_chars;
%%
int main(void){
 yylex();
 printf("# of lines =　%d,# of chars = %d,# of words = %d\n",
	num_lines, num_chars, num_words);
 return 0;
}