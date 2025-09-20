package codeptit;

import java.util.Scanner;

public class J02106_Matrannhiphan {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int cnt = 0, cnt_1, cnt_0;
        for (int i = 0; i < n; i++) {
            cnt_1 = 0;
            cnt_0 = 0;
            for (int j = 0; j < 3; j++) {
                int k = sc.nextInt();
                if (k == 0)
                    cnt_0++;
                else
                    cnt_1++;
            }
            if (cnt_1 > cnt_0)
                cnt++;
        }
        System.out.println(cnt);
    }
}
