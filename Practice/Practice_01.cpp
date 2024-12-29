#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

inline void write(const string &s)
{
    cout << s << endl;
}

inline void input(const string &s, auto &input)
{
    cout << s;
    cin >> input;
}

typedef struct Product
{
    string id;
    string name;
    int quantity;
    double unit_price;
    double promotion;
    double sum;
} Product;

typedef struct Order
{
    string supplier;
    int day;
    int month;
    int year;
    int num_products;
    vector<Product> products;
    double paid;
    double total_reduction;
    double total_sum;
} Order;

int main()
{
    int n;
    write("Pham Viet Hoa - 5128 - 744466 - 20241");
    input("Nhap so Phieu nhap: ", n);

    vector<Order> orders(n);
    while (true)
    {
        write("**  CHUONG TRINH QUAN LY NHA CUNG CAP  **");
        write("**  1. Nhap Nha Cung cap Phieu nhap    **");
        write("**  2. In ket qua Phieu nhap           **");
        write("**  0. Thoat                           **");
        write("*****************************************");
        write("** Nhap lua chon cua ban: **");

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 0:
        {
            write("Ban da chon thoat chuong trinh!");
            return 0;
        }
        case 1:
        {
            write("Ban da chon nhap danh sach Phieu nhap San pham");
            int k = 0;
            for (auto &order : orders)
            {
                order.total_sum = 0;
                order.total_reduction = 0;

                cout << "Nhap thong tin Phieu nhap " << ++k << ":" << endl;
                cout << "\tTen nha cung cap: ";
                cin.ignore();
                getline(cin, order.supplier);
                input("\tNgay: ", order.day);
                input("\tThang: ", order.month);
                input("\tNam: ", order.year);
                input("\tSo luong san pham: ", order.num_products);
                write("\tNhap danh sach san pham:");

                order.products.resize(order.num_products);
                int count = 0;
                for (auto &product : order.products)
                {
                    cout << "\tSan Pham " << ++count << endl;
                    cout << "\t\tMa so san pham: ";
                    cin.ignore();
                    getline(cin, product.id);
                    cout << "\t\tTen san pham: ";
                    getline(cin, product.name);
                    input("\t\tSo luong san pham: ", product.quantity);
                    input("\t\tDon gia nhap: ", product.unit_price);
                    product.sum = product.quantity * product.unit_price;

                    if (product.quantity < 50)
                        product.promotion = product.sum * 0.01;
                    else if (product.quantity < 100)
                        product.promotion = product.sum * 0.02;
                    else if (product.quantity < 200)
                        product.promotion = product.sum * 0.025;
                    else
                        product.promotion = product.sum * 0.03;

                    order.total_sum += product.sum;
                    order.total_reduction += product.promotion;
                }

                input("\tSo tien da thanh toan: ", order.paid);
            }
            write("Ban da nhap thanh cong!");
            write("Bam phim bat ky de tiep tuc!");
            break;
        }
        case 2:
        {
            double total_sum = 0;
            double total_promotion = 0;
            double total_paid = 0;

            write("Ban da chon xuat Phieu nhap, !");
            for (auto &order : orders)
            {
                cout << "________________________________________________" << endl;
                cout << "Ten nha cung cap: " << order.supplier << endl;
                cout << "Ngay thu: Ngay " << order.day << " thang " << order.month << " nam " << order.year << endl;
                cout << "Tong da thanh toan: " << order.paid << endl;
                cout << "Tong phai thanh toan: " << order.total_sum << endl;
                cout << "Tong tien giam: " << order.total_reduction << endl;

                total_sum += order.total_sum;
                total_paid += order.paid;
                total_promotion += order.total_reduction;

                double unpaid = (order.total_sum - order.total_reduction - order.paid) > 0 ? (order.total_sum - order.total_reduction - order.paid) : 0;
                cout << "\t\tChua thanh toan: " << unpaid << endl;
                write("\tChi tiet cac san pham: ");
                cout << "MaSP \tTen San pham \tDon gia" << "\tSo luong" << "\tThanh tien" << "\tGiam gia" << "\tgiam" << endl;
                for (auto &product : order.products)
                {
                    cout << left << setw(10) << product.id << setw(10) << product.name << setw(10) << product.unit_price
                         << setw(10) << product.quantity << setw(10) << product.sum << setw(10) << product.promotion << endl;
                }
            }
            cout << "________________________________________________" << endl;
            cout << "Tong phai thanh toan cac phieu nhap: " << total_sum << endl;
            cout << "Tong da thanh toan cac phieu nhap: " << total_paid << endl;
            cout << "Tong duoc giam cac phieu nhap: " << total_promotion << endl;
            cout << "Tong chua thanh toan: " << (total_sum - total_promotion - total_paid) << endl;
            write("Bam phim bat ky de tiep tuc!");
            break;
        }
        default:
        {
            write("Lua chon khong hop le!");
            write("Bam phim bat ky de tiep tuc!");
        }
        }
    }
    return 0;
}