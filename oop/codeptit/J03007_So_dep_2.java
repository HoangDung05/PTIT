package codeptit;

import java.util.Scanner;

public class J03007_So_dep_2 {
    static boolean check(String s) {
        int sum = 0;
        int len = s.length();
        if (s.charAt(0) != '8' || s.charAt(len - 1) != '8')
            return false;
        for (int i = 0; i < len; i++) {
            sum += (s.charAt(i) - '0');
            if (s.charAt(i) != s.charAt(len - 1 - i))
                return false;
        }
        if (sum % 10 != 0)
            return false;
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
