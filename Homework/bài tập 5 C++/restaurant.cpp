#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Forward declarations
class Food;
class Invoice;
class InvoiceItem;
class Table;

class Food {
private:
    int ID;
    string NAME;
    double PRICE;

public:
    Food(string name, double price);
    void setName(string name);
    void setPrice(double price);

    int getId();
    string getName();
    double getPrice();

    void display();
};

class InvoiceItem {
private:
    Food food;
    int quantity;

public:
    InvoiceItem(Food& _food, int _quantity);
    Food& getFood();
    int getQuantity();
    double getTotalPrice();
};

class Invoice {
private:
    vector<InvoiceItem> items;

public:
    void addItem(Food& food, int quantity);
    double getTotalAmount();
    void display();
};

class Table {
public:
    int number;
    bool status;  // true if occupied, false if not
    Invoice invoice;

    Table(int _number, bool _status);
    void setStatus(bool _status);
};

Food::Food(string name, double price) {
    static int Id = 1000;
    this->ID = Id;
    Id++;
    this->NAME = name;
    this->PRICE = price;
}

void Food::setName(string name) {
    NAME = name;
}

void Food::setPrice(double price) {
    PRICE = price;
}

int Food::getId() {
    return ID;
}

string Food::getName() {
    return NAME;
}

double Food::getPrice() {
    return PRICE;
}

void Food::display() {
    cout << "ID: " << ID << endl;
    cout << "Name: " << NAME << endl;
    cout << "Price: " << PRICE << endl;
}

InvoiceItem::InvoiceItem(Food& _food, int _quantity) : food(_food), quantity(_quantity) {}

Food& InvoiceItem::getFood() {
    return food;
}

int InvoiceItem::getQuantity() {
    return quantity;
}

double InvoiceItem::getTotalPrice() {
    return food.getPrice() * quantity;
}

void Invoice::addItem(Food& food, int quantity) {
    InvoiceItem item(food, quantity);
    items.push_back(item);
}

double Invoice::getTotalAmount() {
    double total = 0.0;
    for (InvoiceItem& item : items) {
        total += item.getTotalPrice();
    }
    return total;
}

void Invoice::display() {
    cout << "      _____Hóa đơn_____" << endl;
    for (InvoiceItem& item : items) {
        Food& food = item.getFood();
        cout << "Name: " << food.getName() << endl;
        cout << "Quantity: " << item.getQuantity() << endl;
        cout << "Price per unit: " << food.getPrice() << endl;
        cout << "Total price: " << item.getTotalPrice() << endl;
        cout << "_______________" << endl;
    }
    cout << "Total amount: " << getTotalAmount() << endl;
}

Table::Table(int _number, bool _status) : number(_number), status(_status) {}

void Table::setStatus(bool _status) {
    status = _status;
}

void addFood(vector<Food>& databaseFood) {
    cout << "\nEnter Name: ";
    cin.ignore();
    string name;
    getline(cin, name);

    double price;
    while (1) {
        cout << "Enter Price: ";
        cin >> price;
        if (price > 0 && price < 1000000000)
            break;
        else
            cout << "Error!!!\n";
    }

    Food food(name, price);
    databaseFood.push_back(food);
    cout << "\nAdd successfully!\n\n";
}

void updateFood(vector<Food>& databaseFood, int id) {
    for (int i = 0; i < databaseFood.size(); i++) {
        if (databaseFood[i].getId() == id) {
            cout << "Add new information of " << id << ":\n";

            string name;
            double price;

            cout << "NAME: ";
            cin.ignore();
            getline(cin, name);

            cout << "PRICE: ";
            cin >> price;

            databaseFood[i].setName(name);
            databaseFood[i].setPrice(price);

            cout << "ADD SUCCESSFULLY !";
            return;
        }
    }
}

void eraseFood(vector<Food>& databaseFood, int id) {
    for (auto i = databaseFood.begin(); i != databaseFood.end(); ++i) {
        if (i->getId() == id) {
            cout << "Bạn có chắc chắn muốn xóa món ăn có ID " << id << "?" << endl;
            cout << "_______________" << endl;
            cout << "1: Có" << endl;
            cout << "0: Quay lại" << endl;
            cout << "_______________" << endl;
            cout << "Nhập lựa chọn: ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                databaseFood.erase(i);
                cout << "Đã xóa thông tin Food " << id << endl;
            } else {
                cout << "Hủy xóa món ăn." << endl;
            }
            return;
        }
    }
}

void displayTableStatus(vector<Table>& tables) {
    cout << "      _____Danh sách bàn_____" << endl;
    cout << "Số bàn   ";
    for (Table& table : tables) {
        cout << table.number << "     ";
    }
    cout << endl;
    cout << "Status    ";
    for (Table& table : tables) {
        cout << (table.status ? "x" : "0") << "     ";
    }
    cout << endl;
}

void displayFoodMenu(vector<Food>& databaseFood) {
    cout << "      _____Danh sách món_____" << endl;
    for (Food& food : databaseFood) {
        cout << "ID: " << food.getId() << endl;
        cout << "Name: " << food.getName() << endl;
        cout << "Price: " << food.getPrice() << endl;
        cout << "_______________" << endl;
    }
}
// Function prototypes
void addFood(vector<Food> &databaseFood);
void updateFood(vector<Food> &databaseFood, int id);
void eraseFood(vector<Food> &databaseFood, int id);
void displayTableStatus(const vector<Table> &tables);
void displayFoodMenu(vector<Food> &databaseFood);
void staffProgram(vector<Food> &databaseFood, vector<Table> &tables, int numberOfTables);

int main() {
    vector<Food> databaseFood;
    vector<Table> tables;
    int numberOfTables;

    cout << "Nhập số lượng bàn: ";
    cin >> numberOfTables;

    for (int i = 1; i <= numberOfTables; ++i) {
        Table table(i, false);
        tables.push_back(table);
    }

    int role;
    cout << "Chọn vai trò (1: Manager, 2: Staff): ";
    cin >> role;

    if (role == 1) { // Manager
        int key = 0;
        while (1) {
            cout << "_______________" << endl;
            cout << "1: Set số bàn" << endl;
            cout << "2: Thêm món vào menu" << endl;
            cout << "3: Sửa món" << endl;
            cout << "4: Xóa món" << endl;
            cout << "5: Danh sách món" << endl;
            cout << "6: Tạo hóa đơn cho bàn" << endl;
            cout << "0: Quay lại" << endl;
            cout << "_______________" << endl;
            cout << "Nhập lựa chọn: ";
            cin >> key;

            switch (key) {
                case 1:
                    int newNumberOfTables;
                    cout << "Nhập số lượng bàn mới: ";
                    cin >> newNumberOfTables;
                    tables.clear();
                    for (int i = 1; i <= newNumberOfTables; ++i) {
                        Table table(i, false);
                        tables.push_back(table);
                    }
                    break;
                case 2:
                    addFood(databaseFood);
                    break;
                case 3:
                    int idToUpdate;
                    cout << "Nhập ID món ăn cần sửa: ";
                    cin >> idToUpdate;
                    updateFood(databaseFood, idToUpdate);
                    break;
                case 4:
                    int idToDelete;
                    cout << "Nhập ID món ăn cần xóa: ";
                    cin >> idToDelete;
                    eraseFood(databaseFood, idToDelete);
                    break;
                case 5:
                    displayFoodMenu(databaseFood);
                    break;
                case 6:
                    int tableNumber;
                    cout << "Nhập số bàn cho hóa đơn: ";
                    cin >> tableNumber;
                    if (tableNumber >= 1 && tableNumber <= numberOfTables) {
                        Table& selectedTable = tables[tableNumber - 1];
                        if (selectedTable.status) {
                            Invoice invoice;
                            while (1) {
                                cout << "Chọn món (nhập ID) hoặc 0 để hoàn thành hóa đơn: ";
                                int foodId;
                                cin >> foodId;
                                if (foodId == 0) {
                                    selectedTable.invoice = invoice;
                                    selectedTable.status = false;
                                    break;
                                } else {
                                    cout << "Nhập số lượng: ";
                                    int quantity;
                                    cin >> quantity;
                                    for (Food& food : databaseFood) {
                                        if (food.getId() == foodId) {
                                            invoice.addItem(food, quantity);
                                        }
                                    }
                                }
                            }
                        } else {
                            cout << "Bàn đã thanh toán hoặc không tồn tại." << endl;
                        }
                    } else {
                        cout << "Số bàn không hợp lệ." << endl;
                    }
                    break;
                case 0:
                    cout << "Chọn vai trò (1: Manager, 2: Staff): ";
                    return 0;
                default:
                    cout << "Lựa chọn không hợp lệ!" << endl;
            }
        }
    } else if (role == 2) { // Staff
            staffProgram(databaseFood, tables, numberOfTables);
        } else {
            cout << "Lựa chọn không hợp lệ!" << endl;
        }}

void staffProgram(vector<Food> &databaseFood, vector<Table> &tables, int numberOfTables) {
    displayTableStatus(tables);
    int tableNumber;
    cout << "Nhập số bàn: ";
    cin >> tableNumber;
    if (tableNumber >= 1 && tableNumber <= numberOfTables) {
        Table &selectedTable = tables[tableNumber - 1];
        if (selectedTable.status) {
            cout << "Bàn này đang được sử dụng." << endl;
        } else {
            selectedTable.setStatus(true);
            cout << "Đã chọn bàn số " << tableNumber << " và đánh dấu là đã có khách." << endl;

            Invoice invoice;
            while (1) {
                cout << "_______________" << endl;
                cout << "Bàn " << tableNumber << endl;
                cout << "1: Thêm món" << endl;
                cout << "2: Sửa món" << endl;
                cout << "3: Xóa món" << endl;
                cout << "4: Danh sách món" << endl;
                cout << "5: Thanh toán" << endl;
                cout << "0: Quay lại" << endl;
                cout << "Nhập lựa chọn: ";
                int Key;
                cin >> Key;


                    switch (Key) {
                        case 1:
                            if (selectedTable.invoice.getTotalAmount() == 0) {
                                addFood(databaseFood);
                            } else {
                                cout << "Bạn không thể thêm món vào hóa đơn đã thanh toán hoặc có món ăn trong hóa đơn." << endl;
                            }
                            break;
                        case 2:
                            int IdToUpdate;
                            cout << "Nhập ID món ăn cần sửa: ";
                            cin >> IdToUpdate;
                            updateFood(databaseFood, IdToUpdate);
                            break;
                        case 3:
                            int IdToDelete;
                            cout << "Nhập ID món ăn cần xóa: ";
                            cin >> IdToDelete;
                            eraseFood(databaseFood, IdToDelete);
                            break;
                        case 4:
                            displayFoodMenu(databaseFood);
                            break;
                        case 5:
                            if (selectedTable.invoice.getTotalAmount() > 0) {
                                selectedTable.invoice = invoice;
                                selectedTable.status = false;
                                cout << "Đã thanh toán cho bàn số " << tableNumber << endl;
                            } else {
                                cout << "Hóa đơn trống hoặc đã thanh toán." << endl;
                            }
                            break;
                        default:
                            cout << "Lựa chọn không hợp lệ!" << endl;
                    }
                }
            }
        } else {
            cout << "Số bàn không hợp lệ." << endl;
        }
}
