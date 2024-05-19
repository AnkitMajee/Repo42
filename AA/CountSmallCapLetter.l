%{
//Declearation part
       int v=0,c=0;
%}
%%
[A-Z] {v++;}  // Rule Section or Regular Expression Section
[a-z] {c++;}
%%
//Auxiliarry Function
int main(){
          printf("Enter String- ");
          yylex();
          printf("Number of Capaital Letter- %d \n",v);
          printf("Numbers of Small letter- %d \n",c);
          return 0;
}
int yywrap(){
 return 1;
}
