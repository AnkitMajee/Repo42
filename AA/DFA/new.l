%{
%}

%s A B C R


%%
<INITIAL>[0-9]+ BEGIN A;
<INITIAL>[0-9]+[.][0-9]+ BEGIN B;
<INITIAL>[A-Za-z_][A-Za-z0-9_]* BEGIN C;
<INITIAL>[^\n] BEGIN R;
<INITIAL>\n BEGIN INITIAL; {printf("Not Accepted\n");}

<A>[^\n] BEGIN R;
<A>\n BEGIN INITIAL; {printf("Integer\n");}

<B>[^\n] BEGIN R;
<B>\n BEGIN INITIAL; {printf("Float\n");}

<C>[^\n] BEGIN R;
<C>\n BEGIN INITIAL; {printf("Identifier\n");}


<R>[^\n] BEGIN R;
<R>\n BEGIN INITIAL; {printf("Reject\n");} 

%%


int yywrap()
{
return 1;
}

int main()
{
printf("Enter String\n");
yylex();
return 0;
}




