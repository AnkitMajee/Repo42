import java.util.Scanner;

class Fibo extends Thread {
    int num;

    Fibo() {
        Scanner obj = new Scanner(System.in);
        System.out.print("Enter the number of terms of the Fibonacci series (>2) = ");
        num = obj.nextInt();
        obj.nextLine();
    }

    public void run() {
        int a = 0, b = 1;
        for (int i = 1; i <= num; ++i) {
            try {
                Thread.sleep(6000);
            } catch (InterruptedException e) {
                System.out.println(e);
            }

            int c = a + b;
            System.out.println("Fibo item " + i + " = " + (i == 1 ? 0 : i == 2 ? 1 : c) + " ");
            a = b;
            b = c;
        }
    }
}

class Prime extends Thread {
    int num;

    Prime() {
        Scanner obj = new Scanner(System.in);
        System.out.print("Enter the number up to which prime numbers should be calculated = ");
        num = obj.nextInt();
        obj.nextLine();
    }

    public void run() {
        int term = 1;
        for (int i = 2; i <= num; ++i) {
            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                System.out.println(e);
            }

            int flag = 0;
            for (int j = 2; j < i; ++j) {
                if (i % j == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                System.out.println("Prime term " + term + " = " + i + " ");
                term++;
            }
        }
    }
}

public class Threading {
    public static void main(String args[]) {
        Fibo obj1 = new Fibo();
        Prime obj2 = new Prime();
        obj1.start();
        obj2.start();
    }
}
