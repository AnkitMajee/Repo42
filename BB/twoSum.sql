-- Start of the program
declare
a int;
b int;
begin
a:=&a;
b:=&b;
if(a>b) then
dbms_output.put_line('a is greater'||a);
else
dbms_output.put_line('b is greater'||b);
end if;
end; 
/						 
-- Program End
