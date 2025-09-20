#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;


---------Sàng số nguyên tố-----------
int prime[10000001]; // N = 10^7

void sang(){
        //Bước 1 : Coi tất cả các số từ 0 tới N là số nguyên tố
	for(int i = 0; i <= 10000000; i++){
		prime[i] = 1;
	}
        //Bước 2 : Sàng
	prime[0] = prime[1] = 0;
	for(int i = 2; i <= sqrt(10000000); i++){
		if(prime[i]){
			for(int j = i * i; j <= 10000000; j += i){
				prime[j] = 0;
			}
		}
	}
}

int main(){
	sang();
	for(int i = 0; i <= 30; i++){
		if(prime[i]){
			cout << i << " ";
		}
	}
	return 0;
}
------------------------------------------

// Dijkstra: tìm đường ngắn nhất từ đỉnh s
vector<ll> dijkstra(int n, vector<vector<pair<int,int>>>& g, int s) {
    // n = số đỉnh, g[u] = danh sách (v, w): cạnh u->v có trọng số w
    vector<ll> dist(n, INF);          // khoảng cách từ s đến mỗi đỉnh
    vector<bool> visited(n, false);   // đánh dấu đỉnh đã xử lý
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

    // khởi tạo
    dist[s] = 0;
    pq.push({0, s}); // (khoảng cách, đỉnh)

    while (!pq.empty()) {
        auto [du, u] = pq.top(); pq.pop();
        if (visited[u]) continue;     // nếu đã xử lý thì bỏ qua
        visited[u] = true;

        // Duyệt tất cả đỉnh kề u
        for (auto [v, w] : g[u]) {
            if (dist[v] > du + w) {   // nếu tìm được đường ngắn hơn
                dist[v] = du + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist; // dist[i] = khoảng cách ngắn nhất từ s đến i
}

// BFS từ đỉnh s
void BFS(int n, vector<vector<int>>& g, int s) {
    vector<bool> visited(n, false); // đánh dấu đã thăm
    queue<int> q;

    visited[s] = true;
    q.push(s);

    cout << "Thu tu duyet BFS tu dinh " << s << ": ";

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";

        // duyệt tất cả đỉnh kề u
        for (int v : g[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n";
}

// DFS dùng đệ quy
void DFS_util(int u, vector<vector<int>>& g, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " "; // xử lý đỉnh u

    for (int v : g[u]) {
        if (!visited[v]) {
            DFS_util(v, g, visited);
        }
    }
}
// Bài toán: Chọn các đoạn không giao nhau
vector<pair<int, int>> intervals = {{1, 3}, {2, 4}, {3, 5}};
sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
    return a.second < b.second;
});

int count = 0, last_end = -1;
for(auto& [start, end] : intervals) {
    if(start >= last_end) {
        count++;
        last_end = end;
    }
}

// Bài toán Greedy: Chọn các đoạn không giao nhau
vector<pair<int, int>> intervals = {{1, 3}, {2, 4}, {3, 5}};
sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
    return a.second < b.second;
});

int count = 0, last_end = -1;
for(auto& [start, end] : intervals) {
    if(start >= last_end) {
        count++;
        last_end = end;
    }
}

// Fibonacci với DP
int fib(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

// Knapsack 0-1
int knapsack(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    
    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(weights[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], 
                              values[i-1] + dp[i-1][w-weights[i-1]]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

// Cấu trúc node cây nhị phân
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Duyệt cây
void inorder(TreeNode* root) {
    if(root) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

// Tách từ trong string
string s = "hello world icpc";
istringstream iss(s);
string word;
while(iss >> word) {
    cout << word << endl;
}

//  Two Pointers & Sliding Window: Tìm cặp có tổng bằng target
vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    sort(nums.begin(), nums.end());
    while(left < right) {
        int sum = nums[left] + nums[right];
        if(sum == target) return {left, right};
        else if(sum < target) left++;
        else right--;
    }
    return {};
}

// Binary Search
vector<int> arr = {1, 3, 5, 7, 9};
bool found = binary_search(arr.begin(), arr.end(), 5);

// Custom Comparator
sort(arr.begin(), arr.end(), [](int a, int b) {
    return a > b; // giảm dần
});

// Stack và Queue
stack<int> st;
queue<int> q;
deque<int> dq;

// Priority Queue (Max Heap)
priority_queue<int> pq;
// Min Heap
priority_queue<int, vector<int>, greater<int>> min_pq;

/********************** Các Container Dạng Dãy (Sequence Containers) **********************/

    // 1. std::vector - Mảng động, có thể thay đổi kích thước, lưu trữ liền kề.
    std::vector<int> vec = {1, 2, 3}; // Khởi tạo với danh sách khởi tạo.

    // Các hàm thành viên phổ biến:
    vec.push_back(4); // Thêm phần tử vào cuối. Độ phức tạp O(1) trung bình.
    // Tham số: const T& value - giá trị cần thêm.
    
    vec.pop_back(); // Xóa phần tử cuối. Không trả về giá trị. O(1).
    // Không có tham số.
    
    vec.insert(vec.begin() + 1, 5); // Chèn phần tử tại vị trí. O(n) do cần dịch chuyển.
    // Tham số: iterator pos, const T& value - vị trí và giá trị cần chèn.
    
    vec.erase(vec.begin() + 2); // Xóa phần tử tại vị trí. O(n).
    // Tham số: iterator pos - vị trí cần xóa.
    
    vec.size(); // Trả về số phần tử. O(1).
    // Không có tham số, trả về size_t.
    
    vec.capacity(); // Trả về dung lượng đã cấp phát. O(1).
    // Không có tham số, trả về size_t.
    
    vec.resize(5); // Thay đổi kích thước, thêm phần tử mặc định nếu cần. O(n) nếu mở rộng.
    // Tham số: size_t n - kích thước mới.
    
    vec.reserve(10); // Đặt trước bộ nhớ cho ít nhất n phần tử. O(n) nếu tái cấp phát.
    // Tham số: size_t n - dung lượng tối thiểu.
    
    vec.front(); // Trả về tham chiếu đến phần tử đầu. O(1).
    // Không có tham số, lỗi nếu rỗng.
    
    vec.back(); // Trả về tham chiếu đến phần tử cuối. O(1).
    // Không có tham số, lỗi nếu rỗng.
    
    vec.at(0); // Truy cập phần tử tại chỉ số với kiểm tra giới hạn. Ném ngoại lệ out_of_range nếu sai.
    // Tham số: size_t pos - chỉ số.
    
    vec.clear(); // Xóa toàn bộ phần tử, kích thước về 0. O(n).
    // Không có tham số.
    
    vec.empty(); // Kiểm tra container rỗng. O(1).
    // Trả về bool.
    
    vec.begin(); // Trả về iterator đến đầu.
    vec.end();   // Trả về iterator đến vị trí sau phần tử cuối.
    // Dùng cho vòng lặp hoặc thuật toán.

    // 2. std::list - Danh sách liên kết đôi, chèn/xóa hiệu quả ở mọi vị trí.
    std::list<int> lst = {1, 2, 3};

    // Các hàm thành viên phổ biến (tương tự vector, nhưng không hỗ trợ truy cập ngẫu nhiên):
    lst.push_back(4); // Thêm vào cuối. O(1).
    lst.push_front(0); // Thêm vào đầu. O(1). (Đặc trưng của list/deque)
    // Tham số: const T& value.
    
    lst.pop_back(); // Xóa phần tử cuối. O(1).
    lst.pop_front(); // Xóa phần tử đầu. O(1).
    
    lst.insert(lst.begin(), 5); // Chèn trước vị trí. O(1) cho chèn, nhưng tìm vị trí là O(n).
    
    lst.erase(--lst.end()); // Xóa tại vị trí. O(1) nếu iterator hợp lệ.
    
    lst.size(); // O(1) từ C++11, trước đó là O(n).
    
    lst.front(); // Tham chiếu đến phần tử đầu.
    lst.back();  // Tham chiếu đến phần tử cuối.
    
    lst.clear(); // O(n).
    lst.empty();
    
    lst.sort(); // Sắp xếp danh sách. O(n log n).
    // Không có tham số, sắp xếp ổn định.
    
    lst.merge(std::list<int>{6,7}); // Gộp danh sách đã sắp xếp khác. O(n).
    // Tham số: list& other - danh sách khác, giả định đã sắp xếp.
    
    lst.unique(); // Xóa các phần tử trùng lặp liên tiếp. O(n).
    // Giả định danh sách đã sắp xếp.
    
    lst.reverse(); // Đảo ngược danh sách. O(n).

    // 3. std::deque - Hàng đợi hai đầu, hiệu quả ở cả hai đầu.
    std::deque<int> deq = {1, 2, 3};

    // Tương tự vector, nhưng:
    deq.push_front(0); // Thêm vào đầu. O(1).
    deq.pop_front();   // Xóa phần tử đầu. O(1).
    
    // Hỗ trợ truy cập ngẫu nhiên như vector: deq[0], deq.at(0).
    // Các hàm khác tương tự vector: insert, erase, size, v.v.

    /********************** Các Container Liên Kết (Associative Containers) **********************/

    // 4. std::set - Tập hợp các phần tử duy nhất, sắp xếp, thường dùng cây đỏ-đen.
    std::set<int> s = {1, 2, 3};

    // Các hàm thành viên phổ biến:
    auto [it, inserted] = s.insert(4); // Chèn nếu chưa có. Trả về pair<iterator, bool>.
    // Tham số: const T& value.
    
    s.erase(2); // Xóa theo giá trị. Trả về size_t (số phần tử xóa, 0 hoặc 1).
    // Hoặc xóa theo iterator.
    
    s.find(3); // Trả về iterator đến phần tử hoặc end() nếu không tìm thấy. O(log n).
    
    s.count(3); // Trả về 1 nếu có, 0 nếu không. O(log n).
    
    s.lower_bound(2); // Iterator đến phần tử đầu tiên >= giá trị. O(log n).
    s.upper_bound(2); // Iterator đến phần tử đầu tiên > giá trị. O(log n).
    
    s.size();
    s.empty();
    s.clear();
    
    s.begin(); s.end(); // Thứ tự đã sắp xếp.

    // 5. std::map - Cặp khóa-giá trị, khóa duy nhất, sắp xếp.
    std::map<int, std::string> m = {{1, "một"}, {2, "hai"}};

    // Các hàm thành viên phổ biến:
    auto [it, inserted] = m.insert({3, "ba"}); // Chèn cặp khóa-giá trị.
    
    m[4] = "bốn"; // Chèn hoặc gán. [] tạo giá trị mặc định nếu chưa có.
    
    m.at(1); // Truy cập giá trị theo khóa, ném ngoại lệ nếu không tìm thấy.
    
    m.erase(2); // Xóa theo khóa.
    
    m.find(1); // Iterator đến cặp hoặc end().
    
    m.count(1); // 0 hoặc 1.
    
    m.lower_bound(1);
    m.upper_bound(1);
    
    m.size();
    m.empty();
    m.clear();

    /********************** Các Container Liên Kết Không Sắp Xếp **********************/

    // 6. std::unordered_set - Tập hợp băm, trung bình O(1).
    std::unordered_set<int> us = {1, 2, 3};

    // Tương tự set, nhưng không sắp xếp:
    us.insert(4);
    us.erase(2);
    us.find(3);
    us.count(3);
    us.size();
    us.empty();
    us.clear();
    // Không có lower/upper_bound vì không sắp xếp.

    // 7. std::unordered_map - Bản đồ băm.
    std::unordered_map<int, std::string> um = {{1, "một"}};

    um.insert({2, "hai"});
    um[3] = "ba";
    um.at(1);
    um.erase(2);
    um.find(1);
    um.count(1);
    um.size();

    /********************** Các Container Bộ Đệm (Container Adapters) **********************/

    // 8. std::stack - Ngăn xếp LIFO, dựa trên vector/deque/list.
    std::stack<int> stk;
    stk.push(1); // Thêm vào đỉnh.
    stk.pop();   // Xóa đỉnh.
    stk.top();   // Tham chiếu đến đỉnh.
    stk.size();
    stk.empty();

    // 9. std::queue - Hàng đợi FIFO.
    std::queue<int> q;
    q.push(1);    // Thêm vào cuối.
    q.pop();      // Xóa đầu.
    q.front();    // Tham chiếu đến đầu.
    q.back();     // Tham chiếu đến cuối.
    q.size();

    // 10. std::priority_queue - Hàng đợi ưu tiên, mặc định là max-heap.
    std::priority_queue<int> pq;
    pq.push(1);   // Chèn và tổ chức lại heap.
    pq.pop();     // Xóa phần tử lớn nhất.
    pq.top();     // Tham chiếu đến phần tử lớn nhất.
    pq.size();

    /********************** Container Mảng Kích Thước Cố Định **********************/

    // 11. std::array - Bao bọc mảng kích thước cố định, tương thích STL.
    std::array<int, 5> arr = {1, 2, 3, 4, 5};

    // Các hàm thành viên:
    arr.size(); // Hằng số thời gian biên dịch.
    arr.front();
    arr.back();
    arr.at(0);  // Truy cập có kiểm tra giới hạn.
    arr.fill(0); // Điền tất cả bằng giá trị.
    arr.begin(); arr.end(); // Dùng cho thuật toán.

    /********************** Các Thuật Toán Thường Dùng cho Mảng/Container **********************/

    // Các hàm này từ <algorithm>, dùng cho mảng thô hoặc container có iterator.
    // Ví dụ với mảng thô:
    int raw_arr[5] = {5, 3, 1, 4, 2};
    

    // std::sort - Sắp xếp dãy. O(n log n).
    std::sort(std::begin(raw_arr), std::end(raw_arr)); // Sắp xếp tăng dần.
    // Tham số: RandomAccessIterator first, last. Có thể dùng comparator.

    // std::find - Tìm kiếm tuyến tính.
    auto it_find = std::find(std::begin(raw_arr), std::end(raw_arr), 3); // Trả về iterator hoặc end().
    // Tham số: InputIterator first, last; const T& value.

    // std::reverse - Đảo ngược dãy.
    std::reverse(std::begin(raw_arr), std::end(raw_arr));

    // std::fill - Điền giá trị vào dãy.
    std::fill(std::begin(raw_arr), std::end(raw_arr), 0);

    // std::max_element - Tìm phần tử lớn nhất.
    auto max_it = std::max_element(std::begin(raw_arr), std::end(raw_arr));

    // std::min_element - Tìm phần tử nhỏ nhất.
    auto min_it = std::min_element(std::begin(raw_arr), std::end(raw_arr));

    // std::count - Đếm số lần xuất hiện.
    size_t cnt = std::count(std::begin(raw_arr), std::end(raw_arr), 2);

    // std::binary_search - Kiểm tra phần tử trong dãy đã sắp xếp. O(log n).
    bool found = std::binary_search(std::begin(raw_arr), std::end(raw_arr), 4);
    // Yêu cầu dãy đã sắp xếp.

    // std::for_each - Áp dụng hàm cho từng phần tử.
    std::for_each(std::begin(raw_arr), std::end(raw_arr), [](int& x) { x += 1; });

    // Các thuật toán này hoạt động với begin()/end() của bất kỳ container nào, ví dụ: vector, list, v.v.
    // Với list, nên dùng lst.sort() thay vì std::sort() vì std::sort yêu cầu truy cập ngẫu nhiên.

    // Lưu ý: Với mảng thô, dùng std::begin(arr)/std::end(arr) từ <iterator> để tương thích.
    // Mảng thô suy biến thành con trỏ, nên các hàm này rất cần thiết.