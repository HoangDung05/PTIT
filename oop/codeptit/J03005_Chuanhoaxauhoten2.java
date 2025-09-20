package codeptit;

import java.util.Scanner;

public class J03005_Chuanhoaxauhoten2 {
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
            int length = arr.length;
            for (int i = 1; i < length; i++) {
                if (i != length - 1)
                    result.append(capitalizeWord(arr[i])).append(" ");
                else
                    result.append(capitalizeWord(arr[i])).append(", ");
            }
            result.append(arr[0].toUpperCase());
            System.out.println(result.toString().trim());
        }
    }
}

