#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// Cấu trúc Node đại diện cho một đỉnh trong đồ thị
struct Node {
    int index;    // Số thứ tự của đỉnh
    int g;        // Khoảng cách thực tế từ đỉnh bắt đầu đến đỉnh hiện tại
    int f;        // Giá trị ước lượng tổng = g + h
    int h;        // Giá trị heuristic (ước lượng khoảng cách từ đỉnh hiện tại đến đích)
    int color;    // Trạng thái đỉnh: 0-chưa xét, 1-trong Open, 2-trong Close
    int parent;   // Đỉnh cha (dùng để truy vết đường đi)
};

// Biến toàn cục
int a[100][100];  // Ma trận kề lưu trọng số giữa các đỉnh
Node p[100];      // Danh sách các đỉnh
Node Open[100];   // Tập Open (các đỉnh đang xét)
Node Close[100];  // Tập Close (các đỉnh đã xét)
bool consistent = true;
int min_g = INT_MAX;
vector<int> PathBest;

// Hàm nhập dữ liệu từ bàn phím
void ReadInputFromKeyboard(int a[100][100], int &n, int &start, int &finish, int b[]) {
    cout << "Nhap so dinh cua do thi: ";
    cin >> n;
    
    cout << "Nhap ma tran trong so (khoang cach giua cac dinh):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    cout << "Nhap gia tri heuristic (h) cho tung dinh:\n";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    cout << "Nhap dinh bat dau: ";
    cin >> start;
    
    cout << "Nhap dinh ket thuc: ";
    cin >> finish;
}

// Hàm hiển thị ma trận trọng số
void ShowMatrix(int a[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }
}

// Hàm đếm số đỉnh đang có trong tập Open
int Count(int n, Node *Open) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (Open[i].color == 1) // Nếu color = 1 (đang trong Open)
            count++;
    }
    return count;
}

// Hàm tìm vị trí đầu tiên trong tập Open
int Find(int n, Node *Open) {
    for (int i = 0; i < n; i++)
        if (Open[i].color == 1)
            return i;
    return -1;
}

// Hàm tìm đỉnh có giá trị f nhỏ nhất trong tập Open
int FindMin(int n, Node *Open) {
    int minIndex = Find(n, Open);
    if (minIndex == -1) return -1;
    
    int min = Open[minIndex].f;
    for (int i = 0; i < n; i++) {
        if (Open[i].color == 1 && Open[i].f < min) {
            minIndex = i;
            min = Open[i].f;
        }
    }
    return minIndex;
}

// Hàm khởi tạo các đỉnh với giá trị ban đầu
void Init(int n, int *b) {
    for (int i = 0; i < n; i++) {
        p[i].index = i;
        p[i].color = 0;       // Ban đầu chưa xét
        p[i].g = 0;           // Khởi tạo g = 0 (sẽ được tính lại sau)
        p[i].parent = -1;     // Chưa có đỉnh cha
        p[i].h = b[i];        // Gán giá trị heuristic từ input
        p[i].f = p[i].h;      // Khởi tạo f = h (vì g = 0)
        
    }
}

// Hàm tìm vị trí của một đỉnh trong mảng
int FindPoint(int n, Node q[], int o) {
    for (int i = n-1; i >= 0; i--)
        if (q[i].index == o)
            return i;
    return -1;
}

void PrintResult(int finish)
{
    cout << "Duong di tim duoc la: ";
    // In đường đi từ start đến finish
    for (int i = PathBest.size() - 1; i >= 0; i--) {
        cout << PathBest[i] << "->";
    }
    cout << finish;
    cout << endl;
    cout << "Do dai duong di la: " << min_g;
}

// Hàm thực hiện thuật toán A*
void AStar(int a[100][100], int n, int start, int finish, int b[]) {
    int l = 0; // Chỉ số cho Open
    
    // Thêm đỉnh bắt đầu vào Open
    Open[l] = p[start];
    Open[l].color = 1;       // Đánh dấu đang trong Open
    Open[l].g = 0;                    // Sửa: g(start) phải = 0
    Open[l].f = Open[l].h;            // f = g + h = 0 + h
    Open[l].parent = -1; 
    l++;
    
    int w = 0; // Chỉ số cho Close
    
    // Lặp khi tập Open còn phần tử
    while (Count(l, Open) != 0) {
        // Tìm đỉnh có f nhỏ nhất trong Open
        int k = FindMin(l, Open);
        if (k == -1) break;

        // Chuyển đỉnh từ Open sang Close
        Open[k].color = 2;
        Close[w] = Open[k];
        w++;

        p[Open[k].index].color = 2;
        
        // Nếu đã tìm thấy đích
        if (Open[k].index == finish) {
            // Truy vết đường đi ngược từ đích về start
            int current = finish;
            vector<int> path; // Dùng để lưu đường đi
            while (current != start) {
                int pos = FindPoint(w, Close, current);
                if (pos == -1) break;
                current = Close[pos].parent;
                path.push_back(current);
            }
            if (consistent)
            {
                min_g = Close[w-1].g;
                PrintResult(finish);
                return;
            }
            else
            {
                if(Close[w-1].g < min_g)
                {
                    min_g = Close[w-1].g;
                    PathBest = path;
                    continue;
                }
            }
        }
        
        // Duyệt qua các đỉnh kề của đỉnh hiện tại
        for (int i = 0; i < n; i++) {
            if (b[Open[k].index] > a[Open[k].index][i] + b[i])
                consistent = false;
            if (a[Open[k].index][i] != 0) { // Nếu có đường đi giữa 2 đỉnh
                int cost = a[Open[k].index][i]; // Trọng số cạnh
                int new_g = Open[k].g + cost;   // Tính toán g mới
                
                // Trường hợp 1: Đỉnh chưa có trong Open và Close
                if (p[i].color == 0) {
                    Open[l] = p[i];
                    Open[l].color = 1;
                    Open[l].g = new_g; // g = g(cha) + cost
                    Open[l].h = b[i];
                    Open[l].f = Open[l].g + Open[l].h;
                    Open[l].parent = Open[k].index; // Ghi nhận đỉnh cha
                    p[i].color = 1;
                    l++;
                }
                // Trường hợp 2: Đỉnh đã có trong Open
                else if (p[i].color == 1) {
                    int pos = FindPoint(l, Open, i);
                    if (pos == -1) continue;
                    
                    // Nếu đường đi mới tốt hơn
                    if (new_g < Open[pos].g) {
                        Open[pos].g = new_g;
                        Open[pos].f = Open[pos].g + Open[pos].h;
                        Open[pos].parent = Open[k].index; // Cập nhật đỉnh cha
                    }
                }
                // Trường hợp 3: Đỉnh đã có trong Close
                else if (p[i].color == 2) {
                    int pos = FindPoint(w, Close, i);
                    if (pos == -1) continue;
                    
                    // Nếu đường đi mới tốt hơn
                    if (new_g < Close[pos].g) {
                        // Chuyển đỉnh từ Close sang Open để xét lại
                        Close[pos].color = 1;
                        Open[l] = Close[pos];
                        Open[l].g = new_g;
                        Open[l].f = Open[l].g + Open[l].h;
                        Open[l].parent = Open[k].index;
                        l++;
                    }
                }
            }
        }
    }
    // Nếu không tìm thấy đường đi
    if (PathBest.empty())
        cout << "Khong tim thay duong di tu " << start << " den " << finish << endl;
    else
        PrintResult(finish);
}

int main() {
    int n;          // Số đỉnh của đồ thị
    int start;      // Đỉnh bắt đầu
    int finish;     // Đỉnh kết thúc
    int b[100];     // Mảng lưu giá trị heuristic
    
    // Nhập dữ liệu từ bàn phím
    ReadInputFromKeyboard(a, n, start, finish, b);
    
    // Khởi tạo các đỉnh
    Init(n, b);
    
    // Hiển thị thông tin đầu vào
    cout << "\nDinh bat dau: " << start << endl;
    cout << "Dinh ket thuc: " << finish << endl;
    cout << "Ma tran trong so:\n";
    ShowMatrix(a, n);
    cout << "\nGia tri heuristic (h) cho tung dinh:\n";
    for (int i = 0; i < n; i++) {
        cout << "h(" << i << ") = " << b[i] << endl;
    }
    cout << endl;
    
    // Thực hiện thuật toán A*
    AStar(a, n, start, finish, b);
    
    return 0;
}