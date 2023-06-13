import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class StringReversal {

    private static String reverseString(String str) {
        int length = str.length();
        String reversed = "";
        
        for (int i = length - 1; i >= 0; i--) {
            reversed += str.charAt(i);
        }
        
        return reversed;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter a string: ");
        String input = reader.readLine();
        
        String reversed = reverseString(input);
        
        System.out.println("Reversed string: " + reversed);
    }

}
