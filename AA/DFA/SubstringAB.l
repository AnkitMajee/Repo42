%s A B
%%

<INITIAL>b BEGIN INITIAL;  //<state> input BEGIN state
<INITIAL>a BEGIN A;
<INITIAL>\n BEGIN INITIAL; printf("\n Not Accepted\n");
<A>a BEGIN A;
<A>b BEGIN B;
<A>\n BEGIN INITIAL; printf("\n Not Accepted \n");
<B>a BEGIN B;
<B>b BEGIN B;
<B>\n BEGIN INITIAL; printf("\n Accepted \n");
%%

int main(){

printf("Enter string using {a,b}- \n");
yylex();
return 0;

}
int yywrap(){
return 1;
}
