#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

inline void input(const string& s, auto& input) {
    cout << s;
    cin >> input;
}

typedef struct NgayvaoDang {
    int day;
    int month;
    int year;
} NgayvaoDang;

typedef struct DangVien {
    int sothedv;
    string tenDV;
    NgayvaoDang ngayvaodang;
    string chucvuDang;
    double luong;
    double dangphi;
    double tienphucap;
    double phaidong;
} DangVien;

typedef struct ChiBo {
    string tenCB;
    string diachi;
    int soDangVien;
    double tongluong;
    double tongdangphithu;
    double tongtrocap;
    double chibogiulai;
    double nopcaptren;
    vector<DangVien> dsDangVien;
} ChiBo;

int main() {
    int n;
    cout << "De4_8_IT3040_20211" << endl;
    cout << "Pham Viet Hoa - 20225128 - 744466" << endl;
    input("Nhap so Chi Bo: ", n);

    vector<ChiBo> dsChiBo(n);
    while (true) {
        cout << "** CHUONG TRINH QUAN LY Chi bo - Dang Vien **" << endl;
        cout << "** 1. Nhap cac chi bo **" << endl;
        cout << "** 2. In ket qua ds Chi bo Dang vien **" << endl;
        cout << "** 0. Thoat  **" << endl;
        cout <<"****************************************" << endl;
        cout << "** Nhap lua chon cua ban **" << endl;

        int choice;
        cin >> choice;
        switch(choice) {
            case 0: {
                cout << "Ban da chon thoat chuong trinh!" << endl;
                return 0;
            }
            case 1: {
                cout << "Ban da chon nhap ds Chi bo Dang vien!" << endl;
                int k = 0;
                
                for (auto& chibo : dsChiBo) {
                    chibo.tongluong = 0;
                    chibo.tongdangphithu = 0;
                    chibo.tongtrocap = 0;
                    cout << "Nhap thong tin Chi bo thu " << ++k << " :" << endl;
                    input("\tTen Chi bo: ", chibo.tenCB);
                    input("\tSo dang vien: ", chibo.soDangVien);
                    chibo.dsDangVien.resize(chibo.soDangVien);

                    cout << "\tNhap ds Dang vien: " << endl;
                    int count = 0;
                    for (auto& dv: chibo.dsDangVien) {
                        cout << "\tDang vien thu " << ++count << endl;
                        input("\t\tSo the: ", dv.sothedv);
                        cout << "\t\tTen Dang vien: "; cin.ignore(); getline(cin, dv.tenDV);
                        cout << "\t\tNgay vao Dang: " << endl;
                        input("\t\tNgay: ", dv.ngayvaodang.day);
                        input("\t\tThang: ", dv.ngayvaodang.month);
                        input("\t\tNam: ", dv.ngayvaodang.year);
                        input("\t\tLuong: ", dv.luong);
                        dv.dangphi = dv.luong * 0.01;
                        input("\t\tChuc vu: ", dv.chucvuDang);

                        if (dv.chucvuDang == "BiThu") dv.tienphucap = dv.luong * 0.05;
                        else if (dv.chucvuDang == "PBThu") dv.tienphucap = dv.luong * 0.025;
                        else if (dv.chucvuDang == "Uyvien") dv.tienphucap = dv.luong * 0.015;
                        else dv.tienphucap = 0;

                        chibo.tongluong += dv.luong;
                        chibo.tongdangphithu += dv.dangphi;
                        chibo.tongtrocap += dv.tienphucap;
                    }
                    chibo.chibogiulai = chibo.tongdangphithu * 0.7;
                    chibo.nopcaptren = chibo.tongdangphithu * 0.3;
                }

                cout << endl;
                cout << "Ban da nhap thanh cong!" << endl;
                cout << "Bam phim bat ky de tiep tuc!" << endl;
                break;
            }
            case 2: {
                double tongluongcacchibo = 0;
                double tongdangphithu = 0;
                double tongnopcaptren = 0;
                cout << "Ban da chon xuat DS Chi bo, !" << endl;
                for (auto& chibo: dsChiBo) {
                    cout << "_________________________________________________________________________" << endl;
                    cout << endl;
                    cout << "\tTen Chi bo: " << chibo.tenCB << endl;
                    cout << "\tSo Dang vien: " << chibo.soDangVien << endl;
                    cout << "\tTong luong: " << chibo.tongluong << endl;
                    cout << "\tTong thu Dang phi: " << chibo.tongdangphithu << endl;
                    cout << "\tTong nop DP cap tren: " << chibo.nopcaptren << endl;
                    cout << "\tTong tro cap phuc vu: " << chibo.tongtrocap << endl;
                    cout << "\tBan thu Dang phi" << endl;
                    cout << left << setw(10) << "So the" 
                        << setw(20) << "HotenDV" 
                        << setw(20) << "Ngayvaodang"
                        << setw(20) << "Tuoidang" 
                        << setw(20) << "Chucvu" 
                        << setw(20) << "Trocap" 
                        << setw(20) << "Luong" 
                        << setw(20) << "DangPhi" << endl;

                    for (auto &dv: chibo.dsDangVien) {
                        cout << left 
                            << setw(10) << dv.sothedv 
                            << setw(20) << dv.tenDV 
                            << setw(20) << (to_string(dv.ngayvaodang.day) + "-" + 
                                            to_string(dv.ngayvaodang.month) + "-" + 
                                            to_string(dv.ngayvaodang.year)) 
                            << setw(20) << 2024 - dv.ngayvaodang.year 
                            << setw(20) << dv.chucvuDang 
                            << setw(20) << dv.tienphucap 
                            << setw(20) << dv.luong 
                            << setw(20) << dv.dangphi << endl;
                    }
                    cout << endl;

                    tongluongcacchibo += chibo.tongluong;
                    tongdangphithu += chibo.tongdangphithu;
                    tongnopcaptren += chibo.nopcaptren;
                }

                cout << endl;
                cout << "Tong luong cac chi bo: " << tongluongcacchibo << endl;
                cout << "Tong Dang phi thu duoc " << tongdangphithu << endl;
                cout << "Tong nop Cap tren " << tongnopcaptren << endl;
                cout << "_________________________________________________________________________" << endl;
                cout << "Bam phim bat ky de tiep tuc!" << endl; 
                break;
            }
            default: {
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
        }
    }

}