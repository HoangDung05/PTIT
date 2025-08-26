package codeptit;

import java.util.Scanner;
import java.util.Stack;

public class J02017_Thugondayso {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            if (!st.empty() && (st.lastElement() + x) % 2 == 0)
                st.pop();
            else
                st.push(x);
        }
        System.out.println(st.size());
    }
}
