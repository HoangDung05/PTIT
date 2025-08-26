package codeptit;

import java.util.Scanner;

public class J02013_Sap_xep_noi_bot {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        int temp;
        for (int i = 0; i < n; i++) {
            boolean swapped = true;
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    temp = a[j + 1];
                    a[j + 1] = a[j];
                    a[j] = temp;
                    swapped = false;
                }
            }
            if (swapped)
                break;
            System.out.printf("Buoc %d: ", i + 1);
            for (int k = 0; k < n; k++)
                System.out.print(a[k] + " ");
            System.out.println();

        }
    }
}
