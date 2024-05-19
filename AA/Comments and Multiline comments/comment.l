%{
 int i;
%}

%%
"//"[^\n]* ;
"/*"[^*/]*"*/" ; 
[ \t]* {fprintf(yyout," ");}
[\n]*   {fprintf(yyout,"\n");}
. {fprintf(yyout,"%s",yytext);}
%%

int main(){
	extern FILE *yyin, *yyout;
	yyin = fopen("fileIn", "r");
	yyout = fopen("fileout", "w");
	yylex();
	return 0;
}
int yywrap(){
	return 1;
}
