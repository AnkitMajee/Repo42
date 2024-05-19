%{
int yylex();
#include<stdio.h>
void yyerror(char *msg);
%}
%token NUM
%left '+' '-'
%left '*' '/'
%%
S : S E '\n'{printf("\n");}
    | {}
    ;
E:  E '+' E {printf("+");}
    |   E '*' E {printf("*");}
    |   E '-' E {printf("-");}
    |   E '/' E {printf("/");}
    |   NUM     {printf("%d", yylval);}
    ;
%%

int main(){
    yyparse();
}

void yyerror(char *msg){
	printf("\n Error in arithmatic \n");
}
