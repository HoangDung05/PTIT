package codeptit;

import java.util.Arrays;
import java.util.Scanner;

public class J02016_Bobasopytago {
    static boolean check(long[] a) {
        Arrays.sort(a);
        for (int i = a.length - 1; i >= 0; i--) {
            int j = 0, k = i - 1;
            while (j < k) {
                if (a[j] + a[k] == a[i])
                    return true;
                if (a[j] + a[k] < a[i])
                    j++;
                else
                    k--;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextLong();
                a[i] = a[i] * a[i];
            }
            if (check(a))
                System.out.println("YES");
            else
                System.out.println("NO");

        }
    }
}
