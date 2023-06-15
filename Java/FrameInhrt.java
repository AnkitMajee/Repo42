import java.awt.*;
class FrameInhrt extends Frame{
	FrameInhrt(){
		Button b1=new Button("Click Me");
		b1.setBounds(30,50,80,30);
		add(b1);
		setSize(300,300);
		setLayout(null);
		setVisible(true);
		}
public static void main (String args[]){
	FrameInhrt f1=new FrameInhrt();
}
}