%s A B C
%%
<INITIAL>a BEGIN A;   //<state> input BEGIN state
<INITIAL>b BEGIN C;  // C here is reject state
<INITIAL>\n BEGIN INITIAL; printf("\n Not Accepted \n");  //It accepts the final state of the program and BEGIN INITIAL command is important to restart the execution from the initial state
<A>a BEGIN C;
<A>b BEGIN B;
<A>\n BEGIN INITIAL; printf("\n Not Accepted \n");  //for everystate we have to mention this
<B>a BEGIN B;
<B>b BEGIN B;
<B>\n BEGIN INITIAL; printf("\n Accepted \n");
<C>a BEGIN C;
<C>b BEGIN C;
<C>\n BEGIN INITIAL; printf("\n Not Accepted \n");
%%

int main(){

printf("Entye string using {a,b}-\n");
yylex();
return 0;

}
int yywrap(){
return 1;
}
