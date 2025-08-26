package codeptit;

import java.util.Scanner;

public class J02034_Bosungdayso {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        boolean check = true;
        if (a[0] != 1) {
            check = false;
            for (int i = 1; i < a[0]; i++)
                System.out.println(i);
        }
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] != 1) {
                int j = a[i - 1] + 1;
                while (j < a[i]) {
                    System.out.println(j);
                    j++;
                }
                check = false;
            }
        }
        if (check)
            System.out.println("Excellent!");
    }
}
