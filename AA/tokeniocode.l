%{
	int i, f, id, key, sep, op, inc;
%}

%%

("if"|"else"|"do"|"while")	{	++key;		fprintf(yyout,"%s = keyword\n", yytext);		}
[{}() ;\t\n]				{	++sep;		fprintf(yyout,"%s = separator\n", yytext);		}
[<>=+-]						{	++op;		fprintf(yyout,"%s = operator\n", yytext);		}
[_a-zA-z][a-zA-Z0-9]*		{	++id;		fprintf(yyout,"%s = identifiers\n", yytext);	}
[+][+] {	++inc;	fprintf(yyout,"%s = increment\n", yytext);	}
[0-9]+						{	++i;		fprintf(yyout,"%s = int\n", yytext);			}
[0-9]*[.][0-9]+				{	++f;		fprintf(yyout,"%s = float\n", yytext);			}

%%
int main(){
	extern FILE *yyin, *yyout;
	yyin = fopen("tokeniocode", "r");
	yyout = fopen("tokenioout", "w");
	yylex();
	return 0;
}
int yywrap(){
	return 1;
}
