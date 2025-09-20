package codeptit;

import java.util.Scanner;

public class J03004_Chuanhoaxauhoten1 {
    public static String capitalizeWord(String word) {
        if (word == null || word.isEmpty())
            return word;
        return word.substring(0, 1).toUpperCase() + word.substring(1).toLowerCase();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            String s = sc.nextLine();
            String[] arr = s.trim().split("\\s+");
            StringBuilder result = new StringBuilder();
            for (String word : arr) {
                result.append(capitalizeWord(word) + " ");
            }
            System.out.println(result.toString().trim());
        }

    }
}
