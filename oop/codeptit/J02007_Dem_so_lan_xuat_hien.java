package codeptit;

import java.util.Scanner;

public class J02007_Dem_so_lan_xuat_hien {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.println("Test " + i + ":");
            int n = sc.nextInt();
            int[] a = new int[n];
            int[] cnt = new int[100005];
            for (int j = 0; j < n; j++) {
                a[j] = sc.nextInt();
                cnt[a[j]]++;
                if (cnt[a[j]] > 1)
                    a[j] = -1;
            }
            for (int j = 0; j < n; j++) {
                if (a[j] > 0)
                    System.out.println(a[j] + " xuat hien " + cnt[a[j]] + " lan");
            }
        }
    }
}
