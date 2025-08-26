package codeptit;

import java.util.Scanner;

public class J3006_So_dep_1 {
    static boolean check(String s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s.charAt(l) != s.charAt(r))
                return false;
            if (Integer.valueOf(s.charAt(l)) % 2 != 0 || Integer.valueOf(s.charAt(r)) % 2 != 0)
                return false;
            l++;
            r--;
        }
        return true;
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
