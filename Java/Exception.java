import java.util.Scanner;
public class Exception {
	public static int divide(int dividend, int divisor) {
        return dividend / divisor;
    }
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
        try {
            System.out.print("Enter the dividend: ");
            int dividend = sc.nextInt();

            System.out.print("Enter the divisor: ");
            int divisor = sc.nextInt();

            int quotient = divide(dividend, divisor);     
            System.out.println("Quotient: " + quotient);

        } catch (ArithmeticException e) {
            System.out.println("Exception Occurred");
        } finally {
            System.out.println("Program execution complete.");
        }
    }
    
    
}
