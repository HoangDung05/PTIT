package codeptit;

import java.util.Scanner;

public class J03025_Xaudoixung {

    public static boolean check(String s) {
        int cnt = 0;
        int l = 0, r = s.length() - 1;
        while (l <= r) {
            if (s.charAt(l) != s.charAt(r)) {
                cnt++;
            }
            l++;
            r--;
        }
        return cnt == 1 || (cnt == 0 && (s.length() % 2 == 1));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            if (check(s))
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}


