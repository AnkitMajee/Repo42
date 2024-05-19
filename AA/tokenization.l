%{
	int i, f, id, key, sep, op, inc;
%}

%%

("if"|"else"|"do"|"while") {++key;printf("%s = keyword\n", yytext);}
[{}() ;\t\n]	         {++sep;printf("%s = separator\n", yytext);}
[<>=+-]	                 {++op;printf("%s = operator\n", yytext);}
[_a-zA-z][a-zA-Z0-9]*	 {++id;printf("%s = identifiers\n", yytext);}
[+][+]                   {++inc;printf("%s = Increment\n", yytext);}
[0-9]+                   {++i;printf("%s = int\n", yytext);}
[0-9]*[.][0-9]+		 {++f;printf("%s = float\n", yytext);}

%%
int main(){
	printf("Enter your string - ");
	yylex();
	printf("Count of int - %d \n", i);
	printf("Count of float - %d \n", f);
	printf("Count of identifiers - %d \n", id);
	printf("Count of keywords - %d \n", key);
	printf("Count of separators - %d \n", sep);
	printf("Count of operators - %d \n", op);
	printf("Count of increments - %d \n", inc);
	return 0;
}
int yywrap(){
	return 1;
}
