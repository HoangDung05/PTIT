package codeptit;

import java.util.Scanner;

public class J02036_Uocsochunglonnhat {
    static int gcd(int a, int b) {
        while (b > 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    static int lcm(int a, int b) {
        if (gcd(a, b) == 0)
            return 0;
        return (a * b) / gcd(a, b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n], b = new int[n + 1];
            for (int i = 0; i < n; i++)
                a[i] = sc.nextInt();
            b[0] = a[0];
            b[n] = a[n - 1];
            for (int i = 1; i < n; i++) {
                b[i] = lcm(a[i - 1], a[i]);
            }
            for (int i = 0; i <= n; i++)
                System.out.print(b[i] + " ");
            System.out.println();
        }
    }
}
