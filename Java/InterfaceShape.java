import java.util.Scanner;

interface Shape {
    double calculatePerimeter();
}

class Square implements Shape {
    private double side;

    public Square(double side) {
        this.side = side;
    }

    public double calculatePerimeter() {
        return 4 * side;
    }
}

class Circle implements Shape {
    private double radius;

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
        Square obj1 = new Square(s);

        System.out.print("Enter radius of Circle: ");
        int radius = sc.nextInt();
        Circle obj2 = new Circle(radius);

        double squarePerimeter = obj1.calculatePerimeter();
        double circlePerimeter = obj2.calculatePerimeter();

        System.out.println("Square Perimeter: " + squarePerimeter);
        System.out.println("Circle Perimeter: " + circlePerimeter);
    }
}
