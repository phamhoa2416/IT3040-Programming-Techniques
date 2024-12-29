#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define write(s) cout << s << endl

inline void input(const string& s, auto& input) {
    cout << s;
    cin >> input;
}

typedef struct NhanVien {
    string maNV;
    string hotenNV;
    int namsinh;
    double hesoluong;
    double luong;
    string chucdanh;
    double phucap;
    double tongluong;
    double congdoanphi;
} NhanVien;

typedef struct PhongBan {
    string tenPB;
    string diachi;
    int sonhanvien;
    double luongtoithieu;
    double tongluong;
    double tongcongdoanphi;
    vector<NhanVien> dsNV;
} PhongBan;

int main() {
    write("Kip 12h30 Tuan 17 Ngay 28/12/2024");
    write("Kiem tra thuc hanh - Quan ly Nhan vien");
    write("Pham Viet Hoa - 744466 - 2024.1");

    int n;
    input("Nhap so Phong ban: ", n);
    vector<PhongBan> dsPB(n);
    
    while (true) {
        write("** CHUONG TRINH QUAN LY Phong Ban - Nhan Vien **");
        write("**1. Nhap cac Phong ban **");
        write("**2. In ket qua ds phong ban va Nhan vien **");
        write("**0. Thoat **");
        write("********************************************");
        write("** Nhap lua chon cua ban: **");

        int choice;
        cin >> choice;
        switch (choice) {
            case 0: {
                write("Pham Viet Hoa - 744466 - 2024.1");
                write("Ban da chon thoat chuong trinh!");
                return 0;
            }
            case 1: {
                write("Pham Viet Hoa - 744466 - 2024.1");
                write("Ban da chon nhap ds Phong ban - Nhan vien!");
                int k = 0;
                for (auto &pb: dsPB) {
                    pb.tongluong = 0;
                    pb.tongcongdoanphi = 0;
                    cout << "Nhap thong tin phong ban thu " << ++k << " :" << endl;
                    input("\tTen Phong Ban: ", pb.tenPB);
                    input("\tDia chi: ", pb.diachi);
                    input("\tLuong toi thieu: ", pb.luongtoithieu);
                    input("\tSo nhan vien: ", pb.sonhanvien);

                    pb.dsNV.resize(pb.sonhanvien);
                    int count = 0;
                    write("\tNhap ds Nhan vien: ");

                    for (auto &nv: pb.dsNV) {
                        cout << "\tNhan vien thu " << ++count << endl;
                        input("\t\tMaNV: ", nv.maNV);
                        cout << "\t\tHo ten Nhan vien: "; cin.ignore(); getline(cin, nv.hotenNV);
                        input("\t\tNhap nam sinh: ", nv.namsinh);
                        input("\t\tNhap HS Luong: ", nv.hesoluong);
                        input("\t\tNhap chuc danh: ", nv.chucdanh);

                        nv.luong = nv.hesoluong * pb.luongtoithieu;
                        if (nv.chucdanh == "GVCC") nv.phucap = 2000;
                        else if (nv.chucdanh == "GVC") nv.phucap = 1500;
                        else if (nv.chucdanh == "GVTS") nv.phucap = 1000;
                        else if (nv.chucdanh == "CBKT") nv.phucap = 750;
                        else nv.phucap = 500;

                        nv.tongluong = nv.luong + nv.phucap;
                        nv.congdoanphi = nv.tongluong * 0.01;
                        pb.tongluong += nv.tongluong;
                        pb.tongcongdoanphi += nv.congdoanphi;
                    }
                }
                write("Ban da nhap thanh cong!");
                write("Pham Viet Hoa - 744466 - 2024.1");
                write("Bam phim bat ky de tiep tuc!");
                break;
            }
            case 2: {
                write("Pham Viet Hoa - 744466 - 2024.1");
                write("Ban da chon xuat DS Phong ban, !");
                write("_______________________________________________________________________________________________________________________");
                for (auto &pb: dsPB) {
                    cout << "\tTen phong ban: " << pb.tenPB << endl;
                    cout << "\tDia chi: " << pb.diachi << endl;
                    cout << "\tLuong TT: " << pb.luongtoithieu << endl;
                    cout << "\tTong Luong PB: " << pb.tongluong << endl;
                    cout << "\tTong Cong doan phi: " << pb.tongcongdoanphi << endl;
                    cout << "\tBang Luong Nhan vien: " << endl;

                    cout << left << setw(10) << "MaNV" << setw(20) << "HotenNV" << setw(20) << "Chucdanh" 
                    << setw(20) << "PCCD" << setw(20) << "HesoL" << setw(20) << "Luong" << setw(20) << "CDP" << setw(20) << "Con nhan" << endl;

                    for (auto nv: pb.dsNV) {
                        cout << left << setw(10) << nv.maNV << setw(20) << nv.hotenNV << setw(20) << nv.chucdanh
                        << setw(20) << nv.phucap << setw(20) << nv.hesoluong << setw(20) << nv.tongluong << setw(20)
                        << nv.congdoanphi << setw(20) << nv.tongluong - nv.congdoanphi << endl;
                    }
                }
                write("_______________________________________________________________________________________________________________________");
                write("Bam phim bat ky de tiep tuc!");
                write("Pham Viet Hoa - 744466 - 2024.1");
                break;
            }
            default: {
                write("Khong co chuc nang nay!");
                write("Bam phim bat ky de tiep tuc!");
                write("Pham Viet Hoa - 744466 - 2024.1");
            }
        }
    }
    return 0;
}