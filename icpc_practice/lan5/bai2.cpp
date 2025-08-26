#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int solveParentheses(string s) {
    // Tìm vị trí của ký tự '*'
    int star_pos = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '*') {
            star_pos = i;
            break;
        }
    }
    
    if (star_pos == -1) {
        return 0;
    }
    
    // Đếm số cặp ngoặc tương ứng xung quanh *
    // Sử dụng stack để tìm các cặp ngoặc hợp lệ
    
    int count = 0;
    
    // Phương pháp: đếm các cặp ngoặc ( ) mà có thể "bao quanh" dấu *
    // Tức là ( ở bên trái * và ) ở bên phải *, và tạo thành cặp hợp lệ
    
    for (int i = 0; i < star_pos; i++) {
        if (s[i] == '(') {
            // Tìm ngoặc đóng tương ứng bên phải *
            int open_count = 1;
            bool found = false;
            
            for (int j = i + 1; j < s.length(); j++) {
                if (j == star_pos) continue; // Bỏ qua vị trí *
                
                if (s[j] == '(') {
                    open_count++;
                } else if (s[j] == ')') {
                    open_count--;
                    if (open_count == 0 && j > star_pos) {
                        // Tìm thấy cặp ngoặc bao quanh *
                        count++;
                        found = true;
                        break;
                    }
                }
            }
        }
    }
    
    return count;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string s;
        cin >> s;
        
        cout << solveParentheses(s) << endl;
    }
    
    return 0;
}

/*
Test cases với phân tích mới:
Input: 4
       ((**)())    → Expected: 2
       (*)         → Expected: 1  
       (()())*     → Expected: 0
       ()*()       → Expected: 0

Phân tích theo thuật toán mới:
- "((**)())": Tìm các cặp ( ) bao quanh * tại vị trí 2
- "(*)": Cặp (,) bao quanh * → 1
- "(()())*": * ở cuối, không có ) bên phải để tạo cặp → 0  
- "()*()": * tại vị trí 2, không có cặp ngoặc nào bao quanh * → 0 ✓

Thuật toán: Với mỗi ( bên trái *, tìm ) tương ứng bên phải * sao cho
chúng tạo thành cặp ngoặc hợp lệ và bao quanh *.
*/