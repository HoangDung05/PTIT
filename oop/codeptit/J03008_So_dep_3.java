package codeptit;

import java.util.Scanner;

public class J03008_So_dep_3 {
    static boolean check(String s) {
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (s.charAt(i) != '2' && s.charAt(i) != '3' && s.charAt(i) != '5' && s.charAt(i) != '7')
                return false;
            if (s.charAt(i) != s.charAt(len - 1 - i))
                return false;
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
