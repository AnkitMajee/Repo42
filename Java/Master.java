import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Complex{
    private float re, im;
    Complex(){}
    Complex(float real, float imag){
        this.re = real;
        this.im = imag;
    }
    public void add(Complex obj){
        float real = this.re + obj.re;
        float imag = this.im + obj.im;
        System.out.println("Addition value = ("+real+" + "+imag+" i)");
    }
    public void mul(Complex obj){
        float real = (this.re*obj.re) - (this.im*obj.im);
        float imag = (this.re*obj.im) + (this.im*obj.re);
        System.out.println("Multiplication value = ("+real+" + "+imag+" i)");    
    }
}

class Master{
    public static void main(String args[]) throws IOException{
        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter real part of 1st complex no. = ");
        float r1 = Float.parseFloat(scan.readLine());
        System.out.print("Enter imaginary part of 1st complex no. = ");
        float f1 = Float.parseFloat(scan.readLine());
        Complex obj1 = new Complex(r1, f1);
        System.out.print("Enter real part of 2nd complex no. = ");
        float r2 = Float.parseFloat(scan.readLine());
        System.out.print("Enter imaginary part of 2nd complex no. = ");
        float f2 = Float.parseFloat (scan.readLine());
        Complex obj2 = new Complex(r2, f2);
        obj1.add(obj2);
        obj1.mul(obj2);
    }
}