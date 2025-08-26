package codeptit;

import java.util.Scanner;

public class J02028_Dayconlientieptongbangk {
    static boolean check(int n, long k, int[] a) {
        if (k == 0)
            return false;
        int mark = 0;
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum > k) {
                while (sum > k) {
                    sum -= a[mark];
                    mark++;
                }
            }
            if (sum == k)
                return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            long k = sc.nextLong();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            if (check(n, k, a))
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
