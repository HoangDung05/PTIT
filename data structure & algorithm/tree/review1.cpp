// đề bài: nhập vào cây nhị phân các số nguyên. Xuất ra màn hình các phần từ của cây nhị phân

#include<bits/stdc++.h>
using namespace std;

// khai báo cấu trúc 1 cái node
struct Node
{
    int data;
    Node *pLeft;
    Node *pRight;
};

typedef struct Node* node;

// hàm thêm phần tử x vào cây nhị phân
void ThemNodeVaoCay(node &root, int x)
{
    // nếu cây rỗng
    if (root == NULL)
    {
        node p = new Node();
        p->data = x; // thêm dữ liệu x vào data
        p->pLeft = NULL;
        p->pRight = NULL;
        root = p; // node p chính là node gốc
    }
    else
    {
        // nếu ptu them vào nhỏ hơn node gốc => thêm nó vào bên trái
        if (x < root->data)
        {
            ThemNodeVaoCay(root->pLeft, x);
        }
        else // vì BST không lưu các phần tử trùng nhau nên trường hợp còn lại là x > root
        {
            ThemNodeVaoCay(root->pRight, x);
        }
    }
}

//hàm xuất cây nhị phân theo NLR
void Duyet_NLR(node root)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (root != NULL)
    {
        cout << root->data << " "; // xuất dữ liệu trong node
        Duyet_NLR(root->pLeft); // duyệt qua trái
        Duyet_NLR(root->pRight); // qua qua phải
    }

}

// hàm xuất cây nhị phân theo NRL
void Duyet_NRL(node root)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (root != NULL)
    {
        cout << root->data << " "; // xuất dữ liệu trong node
        Duyet_NRL(root->pRight); // duyệt qua phải
        Duyet_NRL(root->pLeft); // qua qua trái
    }

}

// hàm xuất cây nhị phân theo LNR
void Duyet_LNR(node root)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (root != NULL)
    {
        Duyet_LNR(root->pLeft); // qua qua trái
        cout << root->data << " "; // xuất dữ liệu trong node
        Duyet_LNR(root->pRight); // duyệt qua phải
    }

}

// hàm xuất cây nhị phân theo RNL
void Duyet_RNL(node root)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (root != NULL)
    {
        Duyet_RNL(root->pRight); // duyệt qua phải
        cout << root->data << " "; // xuất dữ liệu trong node
        Duyet_RNL(root->pLeft); // qua qua trái
    }
}

// hàm xuất cây nhị phân theo LRN
void Duyet_LRN(node root)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (root != NULL)
    {
        Duyet_LRN(root->pLeft); // qua qua trái
        Duyet_LRN(root->pRight); // duyệt qua phải
        cout << root->data << " "; // xuất dữ liệu trong node
    }
}

// hàm xuất cây nhị phân theo RLN
void Duyet_RLN(node root)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (root != NULL)
    {
        Duyet_RLN(root->pRight); // duyệt qua phải
        Duyet_RLN(root->pLeft); // qua qua trái
        cout << root->data << " "; // xuất dữ liệu trong node
    }
}

// hàm nhập dữ liệu
void Menu(node &root)
{
    while (1)
    {
        cout << "==============MENU==============\n";
        cout << "0. Ket thuc\n";
        cout << "1. Nhap du lieu\n";
        cout << "2. Xuat du lieu cay theo NLR\n";
        cout << "3. Xuat du lieu cay theo NRL\n";
        cout << "4. Xuat du lieu cay theo LNR\n";
        cout << "5. Xuat du lieu cay theo RNL\n";
        cout << "6. Xuat du lieu cay theo LRN\n";
        cout << "7. Xuat du lieu cay theo RLN\n";   
        cout << "================================\n";
        
        int luachon;
        cout << "Nhap lua chon: "; cin >> luachon;
        if (luachon < 0 || luachon > 7)
            cout << "Lua chon khong hop le!\n";
        else if (luachon == 1)
        {
            int x;
            cout << "Nhap so nguyen x: "; cin >> x;
            ThemNodeVaoCay(root, x);
        }
        else if (luachon == 2)
        {
            cout << "Duyet cay theo NLR: ";
            Duyet_NLR(root);
            cout << endl;
        }
        else if (luachon == 3)
        {
            cout << "Duyet cay theo NRL: ";
            Duyet_NRL(root);
            cout << endl;
        }
        else if (luachon == 4)
        {
            cout << "Duyet cay theo LNR: ";
            Duyet_LNR(root);
            cout << endl;
        }
        else if (luachon == 5)
        {
            cout << "Duyet cay theo RNL: ";
            Duyet_RNL(root);
            cout << endl;
        }
        else if (luachon == 6)
        {
            cout << "Duyet cay theo LRN: ";
            Duyet_LRN(root);
            cout << endl;
        }
        else if (luachon == 7)
        {
            cout << "Duyet cay theo RLN: ";
            Duyet_RLN(root);
            cout << endl;
        }
        else if (luachon == 0)

            break;
    }
    
}

int main()
{
    node root;
    root = NULL; // khởi tạo cây
    Menu(root);
    return 0;
}