package codeptit;

import java.util.Scanner;

public class J02014_Diemcanbang {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                a[i] = sc.nextInt();
                a[i] += a[i - 1];
            }
            boolean check = true;
            for (int i = 2; i <= n; i++) {
                if (a[i - 1] == a[n] - a[i]) {
                    check = false;
                    System.out.println(i);
                    break;
                }
            }
            if (check)
                System.out.println(-1);
        }

    }
}

