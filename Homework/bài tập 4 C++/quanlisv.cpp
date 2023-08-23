#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef enum {
    GIOI,
    KHA,
    TB,
    YEU
} typeHocLuc;

typedef enum {
    NAM = 1,
    NU = 2
} typeGioiTinh;

class SinhVien {
private:
    int ID;
    string TEN;
    int TUOI;
    typeGioiTinh GIOITINH;
    double DIEM_TOAN;
    double DIEM_LY;
    double DIEM_HOA;

public:
    SinhVien(string name, int tuoi, typeGioiTinh gioitinh, double diem_toan, double diem_ly, double diem_hoa);
    void setTen(string ten);
    void setTuoi(int tuoi);
    void setGioiTinh(typeGioiTinh gioitinh);
    void setDiemToan(double diem_toan);
    void setDiemLy(double diem_ly);
    void setDiemHoa(double diem_hoa);

    int getId();
    string getTen();
    int getTuoi();
    typeGioiTinh getGioiTinh();
    double getDiemToan();
    double getDiemLy();
    double getDiemHoa();
    double getDiemTb();
    typeHocLuc getHocLuc();

    void hienThi() {
        cout << "ID: " << ID << endl;
        cout << "Tên: " << TEN << endl;
        cout << "Tuổi: " << TUOI << endl;
        cout << "Giới Tính: " << ((GIOITINH == NAM) ? "Nam" : "Nữ") << endl;
        cout << "Điểm Toán: " << DIEM_TOAN << endl;
        cout << "Điểm Lý: " << DIEM_LY << endl;
        cout << "Điểm Hóa: " << DIEM_HOA << endl;
    };
};

SinhVien::SinhVien(string ten, int tuoi, typeGioiTinh gioitinh, double diem_toan, double diem_ly, double diem_hoa) {
    static int Id = 1000;
    this->ID = Id;
    Id++;

    this->TEN = ten;
    this->TUOI = tuoi;
    this->GIOITINH = gioitinh;
    this->DIEM_TOAN = diem_toan;
    this->DIEM_LY = diem_ly;
    this->DIEM_HOA = diem_hoa;
};

void SinhVien::setTen(string ten) {
    TEN = ten;
};

void SinhVien::setTuoi(int tuoi) {
    TUOI = tuoi;
};

void SinhVien::setGioiTinh(typeGioiTinh gioitinh) {
    GIOITINH = gioitinh;
};

void SinhVien::setDiemToan(double diem_toan) {
    DIEM_TOAN = diem_toan;
};

void SinhVien::setDiemLy(double diem_ly) {
    DIEM_LY = diem_ly;
};

void SinhVien::setDiemHoa(double diem_hoa) {
    DIEM_HOA = diem_hoa;
};

int SinhVien::getId() {
    return ID;
}

string SinhVien::getTen() {
    return TEN;
}

int SinhVien::getTuoi() {
    return TUOI;
}

typeGioiTinh SinhVien::getGioiTinh() {
    return GIOITINH;
}

double SinhVien::getDiemToan() {
    return DIEM_TOAN;
}

double SinhVien::getDiemLy() {
    return DIEM_LY;
}

double SinhVien::getDiemHoa() {
    return DIEM_HOA;
}

double SinhVien::getDiemTb() {
    return (DIEM_TOAN + DIEM_LY + DIEM_HOA) / 3;
}

typeHocLuc SinhVien::getHocLuc() {
    if (getDiemTb() >= 8) return GIOI;
    else if (getDiemTb() >= 6.5) return KHA;
    else if (getDiemTb() >= 5) return TB;
    else return YEU;
}

void addSinhVien(vector<SinhVien>& databaseSV) {
    cout << "\nNhập tên: ";
    string ten;
    cin >> ten;

    int tuoi;
    while (1) {
        cout << "Nhập tuổi: ";
        cin >> tuoi;
        if (tuoi > 10 && tuoi < 100) break;
        else cout << "Lỗi!!! Tuổi không hợp lệ.\n";
    }

    cout << "1: NAM\n2: NU\nNhập giới tính (1 hoặc 2): ";
    typeGioiTinh gioitinh;
    int key = 0;
    cin >> key;
    switch (key) {
    case 1:
        gioitinh = NAM;
        break;
    case 2:
        gioitinh = NU;
        break;
    default:
        break;
    }

    double diem_toan;
    while (1) {
        cout << "Nhập điểm Toán: ";
        cin >> diem_toan;
        if (diem_toan >= 0 && diem_toan <= 10) break;
        else cout << "Lỗi!!! Điểm Toán không hợp lệ.\n";
    }

    double diem_ly;
    while (1) {
        cout << "Nhập điểm Lý: ";
        cin >> diem_ly;
        if (diem_ly >= 0 && diem_ly <= 10) break;
        else cout << "Lỗi!!! Điểm Lý không hợp lệ.\n";
    }

    double diem_hoa;
    while (1) {
        cout << "Nhập điểm Hóa: ";
        cin >> diem_hoa;
        if (diem_hoa >= 0 && diem_hoa <= 10) break;
        else cout << "Lỗi!!! Điểm Hóa không hợp lệ.\n";
    }

    SinhVien sv = { ten, tuoi, gioitinh, diem_toan, diem_ly, diem_hoa };
    databaseSV.push_back(sv);
    cout << "\nThêm thành công!\n\n";
}

void capNhatSinhVien(vector<SinhVien>& databaseSV, int id) {
    for (int i = 0; i < databaseSV.size(); i++) {
        if (databaseSV[i].getId() == id) {
            cout << "Nhập thông tin mới cho sinh viên có ID " << id << ":\n";
            // Nhập và cập nhật thông tin mới cho sinh viên
            string ten;
            int tuoi;
            typeGioiTinh gioitinh;
            double diem_toan, diem_ly, diem_hoa;

            cout << "Tên: ";
            cin >> ten;
            cout << "Tuổi: ";
            cin >> tuoi;
            cout << "Giới tính (1: Nam, 2: Nữ): ";
            int gioitinhInt;
            cin >> gioitinhInt;
            gioitinh = (gioitinhInt == 1) ? NAM : NU;
            cout << "Điểm Toán: ";
            cin >> diem_toan;
            cout << "Điểm Lý: ";
            cin >> diem_ly;
            cout << "Điểm Hóa: ";
            cin >> diem_hoa;

            // Cập nhật thông tin của sinh viên
            databaseSV[i].setTen(ten);
            databaseSV[i].setTuoi(tuoi);
            databaseSV[i].setGioiTinh(gioitinh);
            databaseSV[i].setDiemToan(diem_toan);
            databaseSV[i].setDiemLy(diem_ly);
            databaseSV[i].setDiemHoa(diem_hoa);

            cout << "Cập nhật thành công!\n";
            return; // Kết thúc hàm sau khi cập nhật thành công
        }
    }
    
    // Nếu không tìm thấy sinh viên với ID đó
    cout << "Không tìm thấy sinh viên có ID " << id << ".\n";
}
void xoaSinhVien(vector<SinhVien>& databaseSV, int Id){
    for (auto i=databaseSV.begin();i!=databaseSV.end(); ++i) {
        if (i->getId() == Id) {
            databaseSV.erase(i);
            cout << "Xóa thông tin sinh viên có ID " << Id << ":\n";
            return;
        }
    }
}
void findSinhvien(vector<SinhVien>& databaseSV, string ten){
    for (auto i=databaseSV.begin();i!=databaseSV.end(); ++i) {
        if (i->getTen() == ten) {
            i->hienThi();
            
}
    }
}
void sapXepTheoDiemTB(vector<SinhVien>& databaseSV) {
    for (int i = 0; i < databaseSV.size() - 1; i++) {
        for (int j = i + 1; j < databaseSV.size(); j++) {
            if (databaseSV[i].getDiemTb() < databaseSV[j].getDiemTb()) {
                swap(databaseSV[i], databaseSV[j]);
            }
        }
    }

    // Hiển thị danh sách sinh viên sau khi sắp xếp
    cout << "Danh sách sinh viên sau khi sắp xếp theo điểm trung bình:\n";
    for (int i = 0; i < databaseSV.size(); i++) {
        cout << "Sinh viên thứ " << i + 1 << ":\n";
        databaseSV[i].hienThi(); // Sử dụng hàm hienThi() để hiển thị thông tin và điểm trung bình, học lực
    }
}

int main() {
    vector<SinhVien> databaseSV;

    int key = 0;
    while (1) {
        cout << "1. Thêm Sinh Viên\n";
        cout << "2. Cập nhật Thông Tin Sinh Viên\n";
        cout << "3. Xóa Sinh Viên\n";
        cout << "4. Tìm kiếm sinh viên theo tên \n";
        cout << "5. Hiển thị thông tin sv\n";
        cout << "6. Sắp xếp sinh viên theo điểm trung bình\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> key;
        string an;
        switch (key) {
        case 1:
            addSinhVien(databaseSV);
            break;
        case 2:
            int id;
            cout << "Nhập ID của sinh viên cần cập nhật: ";
            cin >> id;
            capNhatSinhVien(databaseSV, id);
            break;
        case 3:
            int Id;
            cout<<"Nhập ID của sinh viên cần xóa: ";
            cin>>id;
            xoaSinhVien(databaseSV,id);
            break;
        case 4:
            
            cout<<"Nhập tên của sinh viên cần tìm: ";
            cin>>an;
            findSinhvien(databaseSV,an);
            break;        
        case 5:
            for (int i = 0; i < databaseSV.size(); i++) {
                cout << "Sinh viên thứ " << i + 1 << ":\n";
                databaseSV[i].hienThi();
            }
            break;
         case 6:
            sapXepTheoDiemTB(databaseSV);
            cout << "Sắp xếp thành công!\n";
            break;
        case 7:
            cout << "Thoát khỏi chương trình.\n";
            return 0;
        default:
            cout << "Lựa chọn không hợp lệ. Vui lòng thử lại.\n";
            break;
        }
    }

    return 0;
}
