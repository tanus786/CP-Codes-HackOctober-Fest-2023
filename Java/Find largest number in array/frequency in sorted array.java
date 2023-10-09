
public class j17_frequency_in_sorted_array {

    static void printfreq(int arr[]) {
        int count = 1;
        if (arr.length == 1)
            System.out.println(arr[arr.length - 1] + " : " + 1);

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] == arr[i - 1]) {
                count++;
            } else {
                System.out.println(arr[i - 1] + " : " + count);
                count = 1;
            }
        }
        System.out.println(arr[arr.length - 1] + " : " + count);
    }

    public static void main(String[] args) {
        int arr[] = { 0, 1, 1, 2, 2, 2, 4, 5, 5, 6 };
        printfreq(arr);
    }
}
