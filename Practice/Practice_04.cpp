#include <iostream>
#include <vector>
#include <iomanip>
#define write(s) cout << s << endl
#define input(s, input) cout << s; cin >> input

using namespace std;

typedef struct Monhoc {
    string maMH;
    double sotinchi;
    double sotinchiLT;
    double sotinchiTH;
    double sotinchiBT;
    double sotinchiHP;
    string loaigio;
} Monhoc;

typedef struct Hocvien {
    string maHV;
    string hotenHV;
    int somonhoc;
    double sotienhoc;
    double tienhoc1tin;
    double sotiendanop;
    double sotienphaidong;
    vector<Monhoc> dsMH;
} Hocvien;


int main() {
    int n;
    write("De2_6_IT3040_20211");
    write("Pham Viet Hoa - 744466 - 2024.1");
    input("Nhap so sinh vien: ", n);

    vector<Hocvien> dsHV(n);
    while (true) {
        write("** CHUONG TRINH QUAN LY HOC PHI **");
        write("**1. Nhap cac sinh vien, va mon hoc  **");
        write("**2. In ds sinh vien va hoc phi cac mon **");
        write("**0. Thoat  **");
        write("*******************************************");
        write("** Nhap lua chon cua ban: **");

        int choice;
        cin >> choice;
        switch (choice) {
            case 0: {
                write("Ban da chon thoat chuong trinh");
                return 0;
            }
            case 1: {
                write("Ban da chon nhap ds sinh vien!");
                int k = 0;
                for (auto& hv: dsHV) {
                    hv.sotienhoc = 0;
                    hv.sotienphaidong = 0;
                    cout << "Nhap thong tin cua sv thu " << ++k << " :" << endl;
                    cout << "\tTen sinh vien: "; cin.ignore(); getline(cin, hv.hotenHV);
                    input("\tSo mon hoc: ", hv.somonhoc);
                    input("\tSo tien mot tin chi: ", hv.tienhoc1tin);
                    
                    hv.dsMH.resize(hv.somonhoc);
                    int count = 0;
                    for (auto& mh: hv.dsMH) {
                        cout << "\tMon hoc thu " << ++count << endl;
                        input("\tMa mon hoc: ", mh.maMH);
                        input("\t\tSo tin chi: ", mh.sotinchi);
                        input("\t\tNhap tin chi LT: ", mh.sotinchiLT);
                        input("\t\tNhap tin chi BT: ", mh.sotinchiBT);
                        input("\t\tNhap tin chi TH: ", mh.sotinchiTH);
                        mh.sotinchiHP = mh.sotinchiLT + mh.sotinchiBT + mh.sotinchiTH * 1.5;
                        
                        if (mh.sotinchiTH == 3 && mh.sotinchiLT == 0 && mh.sotinchiBT == 0) {
                            mh.loaigio = "DAMH";
                        } else if (mh.sotinchi == 6) {
                            mh.loaigio = "DATN Cu Nhan";
                        } else if (mh.sotinchi == 12) {
                            mh.loaigio = "DATN Ky su";
                        } else if (mh.sotinchiLT >= 1) {
                            if (mh.sotinchiBT >= 1 && mh.sotinchiTH == 0) {
                                mh.loaigio = "LT-BT";
                            } else if (mh.sotinchiBT == 0 && mh.sotinchiTH >= 1) {
                                mh.loaigio = "LT-TN";
                            } else if (mh.sotinchiBT >= 1 && mh.sotinchiTH >= 1) {
                                mh.loaigio = "LT-BT-TN";
                            }
                        }

                        hv.sotienhoc += mh.sotinchiHP * hv.tienhoc1tin;
                    }

                    input("\tHoc phi da nop: ", hv.sotiendanop);
                    hv.sotienphaidong = hv.sotienhoc - hv.sotiendanop;
                }

                cout << endl;
                write("Ban da nhap thanh cong!");
                write("Bam phim bat ky de tiep tuc!");
                break;
            }
            case 2: {
                cout << endl;
                write("Ban da chon xuat DS sinh vien, !");
                write("_______________________________________________________________________________________________________________________");
                for (auto&hv: dsHV) {
                    cout << endl;
                    cout << "Ten sv: " << hv.hotenHV << endl;
                    cout << "So mon hoc: " << hv.somonhoc << endl;
                    cout << "So tien 1 TC: " << hv.tienhoc1tin << endl;
                    cout << "Phai nop: " << hv.sotienhoc << endl;
                    cout << "Da nop dot 1: " << hv.sotiendanop << endl;
                    cout << "Tong tien thieu: " << hv.sotienphaidong << endl;
                    if (hv.sotienphaidong == 0) {
                        cout << "Tinh trang: Da nop het hoc phi!" << endl;
                    } else {
                        cout << "Tinh trang nop HP: Con thieu!" << endl;
                    }
                    cout << "Chi tiet hoc phi cac mon hoc: " << endl;
                    cout << left 
                        << setw(10) << "MaMH"
                        << setw(20) << "Loai gio"
                        << setw(20) << "Khoi luong"
                        << setw(20) << "Hocphiphainop" << endl;

                    for (auto& mh: hv.dsMH) {
                        cout << left
                            << setw(10) << mh.maMH
                            << setw(20) << mh.loaigio
                            << setw(20) << to_string(static_cast<int>(mh.sotinchi)) 
                            + "(" + to_string(static_cast<int>(mh.sotinchiLT)) 
                            + "-" + to_string(static_cast<int>(mh.sotinchiBT))
                            + "-" + to_string(static_cast<int>(mh.sotinchiTH))
                            + "-" + to_string(static_cast<int>(mh.sotinchi * 2)) + ")"
                            << setw(20) << mh.sotinchiHP * hv.tienhoc1tin << endl;
                    }
                    cout << endl;
                    write("_______________________________________________________________________________________________________________________");
                }
                cout << endl;
                write("Bam phim bat ky de tiep tuc!");
                break;
            }
        }
    }

    return 0;
}
