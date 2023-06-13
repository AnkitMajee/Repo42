class Complex {
    double real;
    double imaginary;
  
    Complex(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    Complex add(Complex other) {
        double sumReal = this.real + other.real;
        double sumImaginary = this.imaginary + other.imaginary;
        return new Complex(sumReal, sumImaginary);
    }

    Complex multiply(Complex other) {
        double productReal = this.real * other.real - this.imaginary * other.imaginary;
        double productImaginary = this.real * other.imaginary + this.imaginary * other.real;
        return new Complex(productReal, productImaginary);
    }
}

public class ComplexOperations {
    public static void main(String[] args) {
        Complex num1 = new Complex(2.5, 3.7);
        Complex num2 = new Complex(1.8, -2.2);

        Complex sum = num1.add(num2);
        Complex product = num1.multiply(num2);

        System.out.println("Sum: " + sum.real + " + " + sum.imaginary + "i");
        System.out.println("Product: " + product.real + " + " + product.imaginary + "i");
    }
}
