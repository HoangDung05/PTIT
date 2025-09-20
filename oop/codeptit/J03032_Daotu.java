package codeptit;

import java.util.Scanner;

public class J03032_Daotu {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            String s = sc.nextLine();
            String[] arr = s.trim().split("\\s");
            for (String word : arr) {
                for (int i = word.length() - 1; i >= 0; i--)
                    System.out.print(word.charAt(i));
                System.out.print(" ");
            }
            System.out.println();
        }
    }
}


