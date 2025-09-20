package codeptit;

import java.util.Arrays;
import java.util.Scanner;

public class J03038_Danhdauchucai {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n + 1];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        int x = sc.nextInt();
        a[n] = x;
        Arrays.sort(a);
        System.out.println(Arrays.toString(a));
    }
}
//5
//1 6 18 37 64
//3

