#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NgaySinh{
    int ngay;
    int thang;
    int nam;
};

struct SinhVien{
    char ma[10] ;
    char ten[40];
    NgaySinh ns;
    float diemTB;
};

struct node{
    SinhVien data;
    node *link;
};

struct List{
    node *first;
    node *last;
};

void Init(List &ds);
node *newNode(SinhVien sv);
int addLast(List &ds, node *p);
int insertLast(List &ds, SinhVien sv);
void Tao1SV(SinhVien &sv);
void TaoDSLK_SV(List &ds, int n);
void Xuat1SV(SinhVien sv);
void XuatDSLK_SV(List ds);
node *searchSV(List ds, char ma[]);
int insertSV(List &ds, SinhVien sv, int vt);

int main()
{
    int n, vt;
    List ds;
    Init(ds);
    printf("Nhap kich thuoc dslk: ");
    scanf("%d", &n);
    TaoDSLK_SV(ds, n);
    XuatDSLK_SV(ds);
    SinhVien sv;
    Tao1SV(sv);
    scanf("%d", &vt);
    insertSV(ds, sv, vt);
    XuatDSLK_SV(ds);
    return 0;
}

void Init(List &ds){
    ds.first = ds.last = NULL;
}

node *newNode(SinhVien sv){
    node *p = new node;
    if(p == NULL){
        printf("Khong du bo nho!\n");
        return NULL;
    }
    p->data = sv;
    p->link = NULL;
    return p;
}

int addFirst(List &ds, node *p){
    if(ds.first == NULL){
        ds.first = ds.last = p;
        return 1;
    }else if(searchSV(ds, p->data.ma) != NULL){
        printf("Trung ma!\n");
        return -1;
    }else{
        p->link = ds.first;
        ds.first = p;
        return 1;
    }
}

int addLast(List &ds, node *p){
    if(ds.first == NULL){
        ds.first = ds.last = p;
        return 1;
    }else if(searchSV(ds, p->data.ma) != NULL){
        printf("Trung ma!\n");
        return -1;
    }
    else{
        ds.last->link = p;
        ds.last = p;
        return 1;
    }
}

int insertFirst(List &ds, SinhVien sv){
    node *p = newNode(sv);
    if(p == NULL)
        return 0;
    addFirst(ds, p);
}

int insertLast(List &ds, SinhVien sv){
    node *p = newNode(sv);
    if(p == NULL)
        return 0;
    addLast(ds, p);
    return 1;
}

void Tao1SV(SinhVien &sv){
    fflush(stdin);
    printf("Nhap ma sv: ");
    scanf("%s", &sv.ma);
    fflush(stdin);
    printf("Nhap ten sv: ");
    gets(sv.ten);
    printf("Nhap ngay thang nam sinh sv: ");
    scanf("%d/%d/%d", &sv.ns.ngay, &sv.ns.thang, &sv.ns.nam);
    printf("Nhap diem trung binh sv: ");
    scanf("%f", &sv.diemTB);
}

void TaoDSLK_SV(List &ds, int n){
    printf("\n");
    SinhVien sv;
    for(int i = 1; i <= n; i++){
        printf("\nNhap sv thu %d:\n\n", i);
        Tao1SV(sv);
        insertLast(ds, sv);
        //insertFirst(ds, sv);
    }
}

void Xuat1SV(SinhVien sv){
    printf("%s %s %d/%d/%d %.2f\n", sv.ma, sv.ten, sv.ns.ngay, sv.ns.thang, sv.ns.nam, sv.diemTB);
}

void XuatDSLK_SV(List ds){
    printf("\n");
    for(node *p = ds.first; p != NULL; p = p->link)
        Xuat1SV(p->data);
}

node *searchSV(List ds, char ma[]){
    for(node *p = ds.first; p != NULL; p = p->link)
        if(strcmp(p->data.ma, ma) == 0)
            return p;
    return NULL;
}

int insertSV(List &ds, SinhVien sv, int vt){
    int dem = 1;
    node *p, *q, *n;
    n = newNode(sv);
    p = q = ds.first;
    if(vt == 1)
        insertFirst(ds, sv);
    while(p != NULL && dem != vt){
        q = p;
        p = p->link;
        dem++;
    }
    if(dem == vt){
        q->link = n;
        n->link = p;
    }
    if(p->link == NULL){
        insertLast(ds, sv);
    }

}
