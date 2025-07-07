#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef struct Node* node;

//cap phat dong mot node moi voi du lieu x
node makeNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

//kiem tra rong
bool isEmpty(node head){
    return head == NULL;
}

//dem so node
int countNode(node head){
    int cnt = 0;
    while (head != NULL){
        cnt++;
        head = head->next; //gan head tro toi node ke tiep
    }
    return cnt;
}

//them 1 node vao dau danh sach
void insertFirst(node& head, int x){
    node tmp = makeNode(x);
    if (isEmpty(head)){
        head = tmp;
    } 
    else {
        tmp->next = head; //gan node moi tro toi node dau
        head = tmp; //gan head tro toi node moi
    }
}

//them 1 node vao cuoi danh sach
void insertLast(node& head, int x){
    node tmp = makeNode(x);
    if (isEmpty(head)){
        head = tmp;
    }
    else {
        node p = head; //tao con tro p tro toi head
        while (p->next != NULL){
            p = p->next;
        }
        p->next = tmp; //gan node cuoi tro toi node moi
    }
}

//them phan tu vao vi tri pos
void insertMiddle(node& head, int x, int pos){
    int n = countNode(head);
    if (pos <= 0 || pos > n + 1){
        cout << "Vi tri khong hop le" << endl;
        return;
    }
    if (pos == 1){
        insertFirst(head, x);
    }
    else if (pos == n + 1){
        insertLast(head, x);
    }
    else {
        node tmp = makeNode(x);
        node p = head;
        for (int i = 1; i < pos - 1; i++){
            p = p->next; //di chuyen con tro p den vi tri pos - 1
        }
        tmp->next = p->next; //gan node moi tro toi node ke tiep
        p->next = tmp; //gan node truoc tro toi node moi
    }
}

//xoa node dau
void deleteFirst(node& head){
    if (isEmpty(head)){
        return;
    }
    head = head->next; //gan head tro toi node ke tiep
}

//xoa node cuoi
void deleteLast(node& head){
    if (isEmpty(head))
        return;
    node truoc = NULL;
    node sau = head;
    while (sau->next != NULL){
        truoc = sau; //gan truoc tro toi node sau
        sau = sau->next; //di chuyen con tro sau den node ke tiep
    }
    if (truoc == NULL){ //neu danh sach chi co 1 phan tu
        head = NULL; //gan head tro toi NULL
    }
    else {
        truoc->next = NULL; //gan node truoc tro toi NULL
    }
}

//xoa node tai vi tri pos
void deleteMiddle(node& head, int pos){
    int n = countNode(head);
    if (pos <= 0 || pos > n+1){
        return;
    }
    if (pos == 1){
        deleteFirst(head);
    }
    else if (pos == n){
        deleteLast(head);
    }
    else {
        node truoc = NULL;
        node sau = head;
        for (int i = 1; i < pos; i++){
            truoc = sau; //gan truoc tro toi node sau
            sau = sau->next; //di chuyen con tro sau den node ke tiep
        }
        truoc->next = sau->next; //gan node truoc tro toi node ke tiep
        delete sau; //giai phong bo nho
    }
}
//hien thi danh sach
void display(node head){
    cout << "-------------------------------\n";
    while (head != NULL){
        cout << head->data << " ";
        head = head->next; //di chuyen con tro den node ke tiep
    }
    cout << "\n-------------------------------\n";
    cout << endl;
}

void sapxep(node& head){
    for (node p = head; p->next != NULL; p = p->next){
        node min = p;
        for (node q = p->next; q != NULL; q = q->next){
            if (q->data < min->data)
                min = q;
        }
        int tmp = min->data;
        min->data = p->data;
        p->data = tmp;
    }
}

int main() {
    node head = NULL; //khai bao con tro head
    while (1){
        cout << "-----------MENU--------------\n";
        cout << "0.Thoat!\n";
        cout << "1.Chen phan tu vao dau danh sach\n";
        cout << "2.Chen phan tu vao cuoi danh sach\n";
        cout << "3.Chen phan tu vao giua danh sach\n";
        cout << "4.Xoa phan tu o dau\n";
        cout << "5.Xoa phan tu o cuoi\n";
        cout << "6.Xoa phan tu o giua\n";
        cout << "7.Duyet danh sach lien ket\n";
        cout << "8.Sap xep danh sach lien ket\n";
        cout << "------------------------------------\n";
        cout << "Nhap lua chon: ";
        int lc; cin >> lc;
        if (lc == 1){
            int x; cout << "Nhap gia tri can chen: "; cin >> x;
            insertFirst(head, x);
        }
        else if (lc == 2){
            int x; cout << "Nhap gia tri can chen: "; cin >> x;
            insertLast(head, x);
        }
        else if (lc == 3){
            int x; cout << "Nhap gia tri can chen: "; cin >> x;
            int pos; cout << "Nhap vi tri can chen: "; cin >> pos;
            insertMiddle(head, x, pos);
        }
        else if (lc == 4){
            deleteFirst(head);
        }
        else if (lc == 5){
            deleteLast(head);
        }
        else if (lc == 6){
            int pos; cout << "Nhap vi tri can xoa: "; cin >> pos;
            deleteMiddle(head, pos);
        }
        else if (lc == 7){
            display(head);
        }
        else if (lc == 8){
            sapxep(head);
        }
        else if (lc == 0){
            break;
        }
    }
    return 0;
}