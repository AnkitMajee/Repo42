import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class OverloadArea {
    public static double calculateArea(double radius) {
        return Math.PI * radius * radius;
    }

    public static double calculateArea(double sideLength, String shape) {
        if (shape.equalsIgnoreCase("square")) {
            return sideLength * sideLength;
        } else {
            throw new IllegalArgumentException("Invalid shape: " + shape);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter the radius of the circle:");
        double radius = Double.parseDouble(reader.readLine());
        double circleArea = calculateArea(radius);
        System.out.println("Area of the circle: " + circleArea);

        System.out.println("Enter the side length of the square:");
        double sideLength = Double.parseDouble(reader.readLine());
        double squareArea = calculateArea(sideLength, "square");
        System.out.println("Area of the square: " + squareArea);

        reader.close();
    }
}
