#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

#define write(s) cout << s << endl
#define input(s, x) cout << s; cin >> x

using namespace std;

typedef struct MiengDat {
    string maso;
    double dongia;
    double dientich;
    string loai;
    double thanhtien;
    double datcoc;
    double giamgia;
} MiengDat;

typedef struct Congty {
    string tenCty;
    string diachiCty;
    int soMiengDat;
    vector<MiengDat> dsMD;
    double tongdongia;
    double tongdientich;
    double tongthanhtien;
    double tongdatcoc;
    double tonggiamgia;
} Congty;

int main() {
    int n;
    write("Pham Viet Hoa - 5128 - IT3040 - 20221 - Tuan 21 - 721342");
    input("Nhap Thong tin so Cong ty BDS: ", n);
    
    vector<Congty> dsCty(n);
    
    while (true) {
        write("Pham Viet Hoa - 5128 - IT3040 - 20221 - Tuan 21 - 721342");
        write("**  CHUONG TRINH QUAN LY BAT DONG SAN  **");
        write("**1. NHAP THONG TIN CONG TY  **");
        write("**2. IN KET QUA DIEN TICH MIENG DAT  **");
        write("**0. Thoat                             **");
        write("*****************************************");
        write("**  Nhap lua chon cua ban  **");
        
        int choice;
        cin >> choice;
        
        switch(choice) {
            case 0: {
                write("Ban da chon thoat chuong trinh");
                return 0;
            }
            case 1: {
                cout << endl;
                write("Ban da chon nhap MIENG DAT VA DO DAI!");
                int k = 0;
                for (auto& cty: dsCty) {
                    cty.tongdongia = 0;
                    cty.tongdientich = 0;
                    cty.tongthanhtien = 0;
                    cty.tongdatcoc = 0;
                    cty.tonggiamgia = 0;
                    
                    cout << "Nhap thong tin Cong ty " << ++k << " :" << endl;
                    cout << "\tTen Cong ty: "; cin.ignore(); getline(cin, cty.tenCty);
                    cout << "\tDia chi cong ty: "; getline(cin, cty.diachiCty);
                    input("\tSo Mieng Dat: ", cty.soMiengDat);
                    write("\tNhap ds cac mieng dat: ");
                    
                    cty.dsMD.resize(cty.soMiengDat);
                    int count = 0;
                    
                    for (auto &md: cty.dsMD) {
                        cout << "\tMa mieng dat thu (MD001, MD002, MD003) " << ++count << " : ";
                        cin.ignore(); cin >> md.maso;
                        if (md.maso == "MD001") md.dongia = 50;
                        else if (md.maso == "MD002") md.dongia = 30;
                        else md.dongia = 10;
                        cout << "\t\tDon gia theo m^2: " << md.dongia << endl;
                        input("\t\tMieng dat Hinh(Vuong, Thang, Tamgiac, HCNhat): ", md.loai);
                        if (md.loai == "Vuong") {
                            double canh;
                            cout << "\t\tCanh hinh vuong: "; cin >> canh; 
                            md.dientich = canh * canh;
                        } else if (md.loai == "Tamgiac") {
                            double chieucao, canhday;
                            cout << "\t\tChieu cao: "; cin >> chieucao;
                            cout << "\t\tCanh day: "; cin >> canhday;
                            md.dientich = (chieucao * canhday) / 2;
                        } else if (md.loai == "HCNhat") {
                            double chieudai, chieurong;
                            cout << "\t\tChieu dai: "; cin >> chieudai;
                            cout << "\t\tChieu rong: "; cin >> chieurong;
                            md.dientich = chieudai * chieurong;
                        } else {
                            double daylon, daynho, chieucao;
                            cout << "\t\tDay nho: "; cin >> daynho;
                            cout << "\t\tDay lon: "; cin >> daylon;
                            cout << "\t\tChieu cao: "; cin >> chieucao;
                            md.dientich = (daynho + daylon) * chieucao / 2;
                        }
                        cout << "\t\tDien tich: " << md.dientich << endl;
                        md.thanhtien = md.dientich * md.dongia;
                        cout << "\t\tThanh tien: " << md.thanhtien << endl;
                        
                        if (md.maso == "MD001") md.datcoc = md.thanhtien * 0.7;
                        else if (md.maso == "MD002") md.datcoc = md.thanhtien * 0.5;
                        else md.datcoc = md.thanhtien * 0.3;
                        cout << "\t\tTien dat coc: " << md.datcoc << endl;
                        
                        if (md.loai == "Thang" || md.loai == "Tamgiac") {
                            md.giamgia = md.thanhtien * 0.1;
                        } else md.giamgia = 0;
                        cout << "\t\tGiam gia: " << md.giamgia << endl;
                        
                        cty.tongdongia += md.dongia;
                        cty.tongdientich += md.dientich;
                        cty.tongthanhtien += md.thanhtien;
                        cty.tongdatcoc += md.datcoc;
                        cty.tonggiamgia += md.giamgia;
                    }
                }
                cout << endl;
                write("Ban da nhap thanh cong!");
                write("Bam phim bat ky de tiep tuc!");
                cout << endl;
                break;
            }
            case 2: {
                cout << endl;
                cout << "Ban da chon IN RA MIENG DAT !" << endl;
                double tongthanhtien = 0;
                double tongdientich = 0;
                double tongdatcoc = 0;
                double tonggiamgia = 0;

                for (auto& cty: dsCty) {
                    cout << endl << endl;
                    cout << "\tTen Cong ty: " << cty.tenCty << endl;
                    cout << "\tDia chi: " << cty.diachiCty << endl;
                    cout << "\tSo mieng dat: " << cty.soMiengDat << endl;
                    cout << "\tDon gia trung binh: " << cty.tongdongia / cty.soMiengDat << endl;
                    cout << "\tTong dien tich: " << cty.tongdientich << endl;
                    cout << "\tTong thanh tien: " << cty.tongthanhtien << endl;
                    cout << "\tTong dat coc: " << cty.tongdatcoc << endl;
                    cout << "\tTong giam gia: " << cty.tonggiamgia << endl;

                    tongthanhtien += cty.tongthanhtien;
                    tongdientich += cty.tongdientich;
                    tongdatcoc += cty.tongdatcoc;
                    tonggiamgia += cty.tonggiamgia;

                    cout << "\t\tChi tiet cac mieng dat: " << endl;

                    cout << internal << "\t"
                        << setw(10) << "MaMD"
                        << setw(20) << "Hinh dang"
                        << setw(20) << "Don gia"
                        << setw(20) << "Dien tich"
                        << setw(20) << "Thanh tien"
                        << setw(20) << "Giam gia"
                        << setw(20) << "Dat coc"
                        << endl;

                    for (auto& md: cty.dsMD) {
                        cout << internal << "\t"
                            << setw(10) << md.maso
                            << setw(20) << md.loai
                            << setw(20) << md.dongia
                            << setw(20) << md.dientich
                            << setw(20) << md.thanhtien
                            << setw(20) << md.giamgia
                            << setw(20) << md.datcoc
                            << endl;
                    }
                }
                cout << endl << endl;
                cout << "\tTong Thanh tien cac cong ty: " << tongthanhtien << endl;
                cout << "\tTong Dien tich cac cong ty: " << tongdientich << endl;
                cout << "\tTong Dat coc cac cong ty: " << tongdatcoc << endl;
                cout << "\tTong Giam gia cua cac cong ty: " << tonggiamgia << endl;
                cout << endl;
                cout << "Bam phi bat ky de tiep tuc!" << endl; 
                break;
            }
            default: {
                cout << "Lua chon khong hop le!" << endl;
                cout << "Bam phi bat ky de tiep tuc!" << endl;
                break;
            }
        }
    }
    return 0;
}

