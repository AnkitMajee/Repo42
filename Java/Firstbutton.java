import java.awt.*;
class Firstbutton{
	Firstbutton(){
		Frame f=new Frame();
		Button b=new Button("Click me");
		b.setBounds(30,50,80,30);
		f.add(b);
		f.setSize(200,200);
		f.setLayout(null);
		f.setVisible(true);
		}
public static void main (String args[]){
		Firstbutton f=new Firstbutton();
		}

}
	
	/* How to run the code
	1. open command prompt
	2. c:\Users\Ankit>cd Desktop
	3. c:\Users\Ankit\Desktop>cd java 
	4. c:\Users\Ankit\Desktop\java>javac classname.java
	5. c:\Users\Ankit\Desktop\java>java classname
	   Happy Coding! 
	6. if showing error i.e fail to load main class
	   i.c:\Users\Ankit\Desktop\java>set classpath=
	7. c:\Users\Ankit\Desktop\java>java classname 
	   Happy coding!
8. End 
9. cd..   to remove path
*/
