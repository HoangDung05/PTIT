package codeptit;

import java.util.Scanner;

public class J02010_Sap_xep_doi_cho_truc_tiep {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        for (int i = 0; i < n - 1; i++) {
            int step = i + 1;
            System.out.printf("Buoc %d: ", step);
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j]) {
                    int temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
                }
            }
            for (int j = 0; j < n; j++)
                System.out.printf("%d ", a[j]);
            System.out.println();
        }
    }
}
