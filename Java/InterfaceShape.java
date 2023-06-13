import java.util.Scanner;

interface Shape {
    double calculatePerimeter();
}

class Square implements Shape {
    private double side;        // instance variable jo method ka bahar implement hota hai

    public Square(double side) {
        this.side = side;         // this variable instance variable aur local variable koi idfi. krne mai help karta hai
    }

    public double calculatePerimeter() {
        return 4 * side;
    }
}

class Circle implements Shape {
    private double radius;      // instance variable

    public Circle(double radius) {
        this.radius = radius;
    }

    public double calculatePerimeter() {
        return 2 * Math.PI * radius;
    }
}

public class InterfaceShape {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Side of Square: ");
        int s = sc.nextInt();
        Square obj1 = new Square(s);  // obj of Square class created as constructor its get parameter

        System.out.print("Enter radius of Circle: ");
        int radius = sc.nextInt();
        Circle obj2 = new Circle(radius);  // obj of Circle class created

        double squarePerimeter = obj1.calculatePerimeter();   // obj called from parent class method
        double circlePerimeter = obj2.calculatePerimeter();

        System.out.println("Square Perimeter: " + squarePerimeter);
        System.out.println("Circle Perimeter: " + circlePerimeter);
    }
}
