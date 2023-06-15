import java.awt.*;
import java.awt.event.*;

class CFConverter implements ActionListener
{
	Frame f=new Frame("Ankit's CFConverter");
	
	Label l1=new Label("Enter Degree");
	Label l2=new Label("Result");
	TextField t1=new TextField();
	TextField t2=new TextField();
	//TextField t3=new TextField();
	
	Button b1=new Button("F2C");
	Button b2=new Button("C2F");
	Button b3=new Button("EXIT");
	
	CFConverter(){
		l1.setBounds(50,100,100,20);
		l2.setBounds(50,140,100,20);
		t1.setBounds(200,100,100,20);
		t2.setBounds(200,140,100,20);
		//t3.setBounds(200,180,100,20);
		
		b1.setBounds(50,250,50,20);
		b2.setBounds(110,250,50,20);
		b3.setBounds(170,250,50,20);
		
		f.add(l1);
		f.add(l2);
		
		f.add(t1);
		f.add(t2);
		//f.add(t3);
		f.add(b1);
		f.add(b2);
		f.add(b3);
		
		b1.addActionListener(this);
		b2.addActionListener(this);
		b3.addActionListener(this);
		
f.setLayout(null);
f.setVisible(true);
f.setSize(400,350);
	}
 public void actionPerformed(ActionEvent e)
      {
       int n1=Integer.parseInt(t1.getText());
	   int n2=Integer.parseInt(t2.getText());
	 /* ctemp = (5.0 / 9.0) * (ftemp - 32);*/
	 if(e.getSource()==b1)
{
t2.setText(String.valueOf(n1=(5/9)*(n2-32)));  //C2F n1=C and n2=F
}
if(e.getSource()==b2)
{
t1.setText(String.valueOf(n2=(9/5)*(n1+32)));  //F2C n1=C and n2=F
}
if(e.getSource()==b3)
{
System.exit(0);
	  }
	  }

public static void main(String []args)
{
new CFConverter();
}
	  }


 //fahrenheit = Math.round((9 /(float)5)) * (celsius + 32);
 //celsius1 = Math.round((5 / (float)9)) * (fahrenheit1 - 32);

