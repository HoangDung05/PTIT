package codeptit;

import java.util.Arrays;
import java.util.Scanner;

public class J02024_Dayconcotongle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = sc.nextInt();
            Arrays.sort(a);
            for (int i = n - 1; i >= 0; i--) {
                for (int j = i - 1; j >= 0; j--) {
                    int sum = 0;
                    for (int k = j; k >= j; k--) {
                        sum += a[k];
                    }
                    if (sum % 2 == 1) {
                        for (int k = j; k >= j; k--)
                            System.out.print(a[k] + " ");
                        System.out.println();
                    }
                }
            }

        }
    }
}
