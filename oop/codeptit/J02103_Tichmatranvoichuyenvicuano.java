package codeptit;

import java.util.Scanner;

public class J02103_Tichmatranvoichuyenvicuano {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int z = 1; z <= t; z++) {
            int n = sc.nextInt(), m = sc.nextInt();
            int[][] a = new int[n][m], b = new int[m][n];
            int[][] result = new int[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    a[i][j] = sc.nextInt();
                    b[j][i] = a[i][j];
                }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < m; k++) {
                        result[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
            System.out.printf("Test %d:%n", z);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print(result[i][j] + " ");
                }
                System.out.println();
            }

        }
    }
}
