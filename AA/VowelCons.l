%{
       int v=0,c=0;
%}
%%
[aeiouAEIOU] {v++;}
[a-zA-Z] {c++;}
%%
int main(){
          printf("Enter String- ");
          yylex();
          printf("Number of vowels- %d \n",v);
          printf("Numbers of Consonants- %d \n",c);
          return 0;
}
int yywrap(){
 return 1;
}
