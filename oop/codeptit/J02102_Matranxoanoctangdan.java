package codeptit;

import java.util.Arrays;
import java.util.Scanner;

public class J02102_Matranxoanoctangdan {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] a = new int[n][n];
        int[] save = new int[n * n];
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
                save[index++] = a[i][j];
            }
        }
        Arrays.sort(save);
        index = 0;
        int[][] result = new int[n][n];
        int l = 0, r = n - 1, u = 0, d = n - 1;
        while (true) {
            for (int i = l; i <= r; i++)
                result[u][i] = save[index++];
            u++;
            if (index == n * n)
                break;
            for (int i = u; i <= d; i++)
                result[i][r] = save[index++];
            r--;
            if (index == n * n)
                break;
            for (int i = r; i >= l; i--)
                result[d][i] = save[index++];
            d--;
            if (index == n * n)
                break;
            for (int i = d; i >= u; i--)
                result[i][l] = save[index++];
            l++;
            if (index == n * n)
                break;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                System.out.print(result[i][j] + " ");
            System.out.println();
        }
    }
}

