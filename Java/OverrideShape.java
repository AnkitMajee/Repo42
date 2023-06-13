import java.util.Scanner;

abstract class shape {
    abstract double calculateArea();
}

class Square extends shape {
    double side;

     Square(double side){
    this.side = side;
 }
 @Override
 double calculateArea(){
    return side * side;
 }
}

class Circle extends shape{
    double radius;

    Circle(double radius){
        this.radius=radius;
    }

    @Override
    double calculateArea(){
        return Math.PI * radius * radius;
    }
}

public class OverrideShape{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Side of Square = ");
        int s = sc.nextInt();
        Square obj1 = new Square(s);

        System.out.print("Enter radius of Circle: ");
        int radius = sc.nextInt();
        Circle obj2 = new Circle(radius);  // obj of Circle class created

        double squareArea = obj1.calculateArea();
        double circleArea = obj2.calculateArea();

        System.out.println("Area of a Square = "+squareArea);
        System.out.println("Area of a Circle = "+circleArea);
    }
}