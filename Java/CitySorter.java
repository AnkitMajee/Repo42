import java.io.IOException;

public class CitySorter {
    public static void main(String[] args) throws IOException {
        String[] cities = new String[5];
        cities[0] = args[0];
        cities[1] = args[1];
        cities[2] = args[2];
        cities[3] = args[3];
        cities[4] = args[4];
        
        bubbleSort(cities);
        
        System.out.println("Sorted cities:");
        for (String city : cities) {
            System.out.println(city);
        }
    }

    private static void bubbleSort(String[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j].compareTo(arr[j + 1]) > 0) {
                    String temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}
