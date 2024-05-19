%{
   int i,j;
%}

%%

[0-9]+		{	++i;	}
[0-9]*[.][0-9]+ {	++j;	}

%%

int main(){
   printf("Enter your Numbers - ");
   yylex();
   printf("Count of int - %d \n", i);
   printf("Count of float - %d \n", j);
   return 0;
}

int yywrap(){
   return 1;
}
