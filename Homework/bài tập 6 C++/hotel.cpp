#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

class Room {
private:
    uint8_t roomNumber;
    bool isBooked;

public:
    Room(uint8_t number) {
        roomNumber = number;
        isBooked = false;
    }

    uint8_t getRoomNumber() {
        return roomNumber;
    }

    bool isRoomBooked() {
        return isBooked;
    }

    void bookRoom() {
        isBooked = true;
    }

    void checkIn() {
        isBooked = true;
    }

    void checkOut() {
        isBooked = false;
    }

};

class HotelManager {
private:
    vector<Room> rooms;

public:
    HotelManager(uint8_t numRooms) {
        for (uint8_t i = 1; i <= numRooms; i++) {
            Room room(i);
            rooms.push_back(room);
        }
    }

    void displayRoomStatus() {
        cout << "Room Status:\n";
        for (Room& room : rooms) {
            cout << "Room " << static_cast<int>(room.getRoomNumber()) << ": ";
            if (room.isRoomBooked()) {
                cout << "Booked";
            } else {
                cout << "Available";
            }
            cout << endl;
        }
    }

    void bookRoom(uint8_t roomNumber) {
        for (Room& room : rooms) {
            if (room.getRoomNumber() == roomNumber) {
                if (!room.isRoomBooked()) {
                    room.bookRoom();
                    cout << "Room " << static_cast<int>(roomNumber) << " has been booked." << endl;
                } else {
                    cout << "Room " << static_cast<int>(roomNumber) << " is already booked." << endl;
                }
                return;
            }
        }
        cout << "Room " << static_cast<int>(roomNumber) << " not found." << endl;
    }

    void checkIn(uint8_t roomNumber) {
        for (Room& room : rooms) {
            if (room.getRoomNumber() == roomNumber) {
                if (room.isRoomBooked()) {
                    room.checkIn();
                    cout << "Guest has checked in to Room " << static_cast<int>(roomNumber) << "." << endl;
                } else {
                    cout << "Room " << static_cast<int>(roomNumber) << " is not booked." << endl;
                }
                return;
            }
        }
        cout << "Room " << static_cast<int>(roomNumber) << " not found." << endl;
    }

    void checkOut(uint8_t roomNumber) {
        for (Room& room : rooms) {
            if (room.getRoomNumber() == roomNumber) {
                if (room.isRoomBooked()) {
                    room.checkOut();
                    cout << "Guest has checked out of Room " << static_cast<int>(roomNumber) << "." << endl;
                } else {
                    cout << "Room " << static_cast<int>(roomNumber) << " is not booked." << endl;
                }
                return;
            }
        }
        cout << "Room " << static_cast<int>(roomNumber) << " not found." << endl;
    }

    void startCleaning(uint8_t roomNumber) {
        for (Room& room : rooms) {
            if (room.getRoomNumber() == roomNumber) {
                if (!room.isRoomBooked()) {
                    room.startCleaning();
                    cout << "Room " << static_cast<int>(roomNumber) << " is now being cleaned." << endl;
                } else {
                    cout << "Cannot start cleaning for Room " << static_cast<int>(roomNumber) << " as it's booked." << endl;
                }
                return;
            }
        }
        cout << "Room " << static_cast<int>(roomNumber) << " not found." << endl;
    }

};

typedef struct {
    uint8_t day;
    uint8_t month;
    uint16_t year;
} typeDate;

typedef struct {
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
} typeTime;

typedef enum {
    IN,
    OUT
} typeStatus;

typedef struct {
    typeTime time;
    typeDate date;
    typeStatus status;
} bookingHistory;

class Customer {
private:
    uint8_t idRoom;
    string name;
    string phoneNumber;
    string address;
    vector<bookingHistory> bookingHistory;

public:
    Customer(string customerName, string customerPhone, string customerAddress, uint8_t customerIdRoom)
        : idRoom(customerIdRoom), name(customerName), phoneNumber(customerPhone), address(customerAddress) {}

    uint8_t getIdRoom() {
        return idRoom;
    }

    string getName() {
        return name;
    }

    string getPhoneNumber() {
        return phoneNumber;
    }

    string getAddress() {
        return address;
    }

    void setId(uint8_t id) {
        idRoom = id;
    }
void Customer::addBookingHistory(bookingHistory bookingDetails) {
    bookingHistory.push_back(bookingDetails);
}

    }

    void displayBookingHistory() {
        cout << "Booking History for Customer ID " << static_cast<int>(idRoom) << ":\n";
        for (const bookingHistory& booking : bookingHistory) {
            cout << "Date: " << static_cast<int>(booking.date.day) << "/"
                 << static_cast<int>(booking.date.month) << "/"
                 << static_cast<int>(booking.date.year) << endl;
            cout << "Time: " << static_cast<int>(booking.time.hour) << ":"
                 << static_cast<int>(booking.time.minute) << ":"
                 << static_cast<int>(booking.time.second) << endl;
            if (booking.status == IN) {
                cout << "Status: Checked In" << endl;
            } else {
                cout << "Status: Checked Out" << endl;
            }
            cout << "---------------------" << endl;
        }
    }
};

class CustomerManager {
private:
    vector<Customer> customers;

public:
    void addCustomer(Customer& customer) {
        customers.push_back(customer);
    }

    void editCustomer(string phoneNumber, string newName, string newAddress) {
        for (Customer& customer : customers) {
            if (customer.getPhoneNumber() == phoneNumber) {
                customer.name = newName;
                customer.address = newAddress;
                cout << "Customer information updated." << endl;
                return;
            }
        }
        cout << "Customer not found with the provided phone number." << endl;
    }

    void deleteCustomer(string phoneNumber) {
        for (auto it = customers.begin(); it != customers.end(); ++it) {
            if (it->getPhoneNumber() == phoneNumber) {
                it = customers.erase(it);
                cout << "Customer deleted." << endl;
                return;
            }
        }
        cout << "Customer not found with the provided phone number." << endl;
    }

    void displayCustomers() {
        cout << "List of Customers:\n";
        for (const Customer& customer : customers) {
            cout << "Name: " << customer.getName() << endl;
            cout << "Phone Number: " << customer.getPhoneNumber() << endl;
            cout << "Address: " << customer.getAddress() << endl;
            cout << "Booking History:\n";
            for (const bookingHistory& booking : customer.bookingHistory) {
                cout << " - " << "Date: " << static_cast<int>(booking.date.day) << "/"
                     << static_cast<int>(booking.date.month) << "/"
                     << static_cast<int>(booking.date.year) << " ";
                cout << "Time: " << static_cast<int>(booking.time.hour) << ":"
                     << static_cast<int>(booking.time.minute) << ":"
                     << static_cast<int>(booking.time.second) << " ";
                if (booking.status == IN) {
                    cout << "Status: Checked In" << endl;
                } else {
                    cout << "Status: Checked Out" << endl;
                }
            }
            cout << "---------------------" << endl;
        }
    }
};
class User{
    private:
        string USERNAME;
        string PASSWORD;
    public:
        User(string username="manager",string password="admin");
        string getUserName(){
            return USERNAME;
        };
        string getPassword(){
            return PASSWORD;
        };
        void setUserName(string inputUsername){
            USERNAME=inputUsername;
        };
        void setPassword(string inputPassword){
            PASSWORD=inputPassword;
        };
       bool User::authenticate(string inputUsername, string inputPassword) {
         if (inputUsername == USERNAME && inputPassword == PASSWORD) {
        return true;
        } else {
        throw runtime_error("Xác thực không thành công. Tên người dùng hoặc mật khẩu không đúng.");
    }
}


};
User::User(string username,string password){
    this->USERNAME=username;
    this->PASSWORD=password;
}
///////
typedef enum{
    JANITOR,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    LAUGGAGE_STAFF,
    GRADENER
}typePosition;

typedef struct{
    typeTime;
    typeDate;
    typeStatus status;
}Schedule;

class Employee{
    private:
    uint8_t id;
    string name;
    string phoneNumber;
    JobPosition position;
    Schedule schedule;
    public:
    Employee(string nameEmployee,string phoneNumberEmployee, JobPosition positionEmployee,Schedule scheduleEmployee);

    string getName(){
            return name;
    };
    string getphoneNumber(){
        return phoneNumber;
    };
    Jobposition getPosition(){
        return position;
    };
};

Employee::Employee(string nameEmployee,string phoneNumberEmployee, JobPosition positionEmployee,Schedule scheduleEmployee){
    static uint8_t idEmployee=100;
    this->id=idEmployee;
    idEmployee++;

    this->name=nameEmployee;
    this->phoneNumber=phoneNumberEmployee;
    this->position=positionEmployee;
    this->schedule=scheduleEmployee;

};


/////

class EmployeeManager{
    private:
        vector<Employee> databaseEmployee;
    public:
        void addEmployee(Employee employee);
        bool getAutheticate(string inputPassword, string inputUsername);

};

void EmployeeManager::addEmployee(Employee employee_){
    databaseEmployee.push_back(employee_);
};


/////

class SecurityManagement{
    private:
        User user;
        vector<User> databaseUser;
        bool checkSignup;
    public:
        void addUser(string inputUsername, string input Password);
        void eraseUser(string inputUsername);
        void editUser(string inputUsername, string inputPassword);
        void setPasswordManager(string inputPassword){
            user.setPassword(inputPassword);
        };
        bool getCheckSignup(string inputUserName,string inputPassword){
            if (user.authenticate(inputUsername,inputPassword)) return true;
            else return false;
        };
        vector<User>& getDatabaseUser(){
            return getDatabaseUser;
        };
        void addUser(string inputUsername, string inputPassword) {
        // Kiểm tra xem người dùng có tồn tại trong cơ sở dữ liệu không
        for (const User& existingUser : databaseUser) {
            if (existingUser.getUserName() == inputUsername) {
                cout << "User with this username already exists. Cannot add duplicate users." << endl;
                return;
            }
        }

        // Nếu không có người dùng trùng tên người dùng, thêm người dùng mới vào cơ sở dữ liệu
        User newUser(inputUsername, inputPassword);
        databaseUser.push_back(newUser);
        cout << "User added successfully." << endl;
    }

    void eraseUser(string inputUsername) {
        // Tìm kiếm và xóa người dùng theo tên người dùng
        for (auto it = databaseUser.begin(); it != databaseUser.end(); ++it) {
            if (it->getUserName() == inputUsername) {
                it = databaseUser.erase(it);
                cout << "User deleted successfully." << endl;
                return;
            }
        }

        cout << "User with this username not found. Cannot delete." << endl;
    }
 void editUser(string inputUsername, string inputPassword) {
        // Tìm kiếm và sửa đổi thông tin người dùng theo tên người dùng
        for (User& existingUser : databaseUser) {
            if (existingUser.getUserName() == inputUsername) {
                existingUser.setPassword(inputPassword);
                cout << "User information updated successfully." << endl;
                return;
            }
        }

        cout << "User with this username not found. Cannot edit." << endl;
    }

    void setPassword(string inputUsername, string newPassword) {
        // Tìm kiếm và đặt lại mật khẩu cho người dùng theo tên người dùng
        for (User& existingUser : databaseUser) {
            if (existingUser.getUserName() == inputUsername) {
                existingUser.setPassword(newPassword);
                cout << "Password updated successfully." << endl;
                return;
            }
        }

        cout << "User with this username not found. Cannot update password." << endl;
    }
}

int main() {
    HotelManager hotel(10); // Khởi tạo quản lý khách sạn với 10 phòng
    CustomerManager customerManager;

    uint8_t customerId = 1; // Bắt đầu với ID khách hàng là 1

    while (true) {
        cout << "Hotel Management System" << endl;
        cout << "1. Display Room Status" << endl;
        cout << "2. Book Room" << endl;
        cout << "3. Check In" << endl;
        cout << "4. Check Out" << endl;
        cout << "7. Customer Management" << endl;
        cout << "8. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.displayRoomStatus();
                break;
            case 2: {
                uint8_t roomToBook;
                cout << "Enter room number to book: ";
                cin >> roomToBook;
                hotel.bookRoom(roomToBook);
                break;
            }
            case 3: {
                uint8_t roomToCheckIn;
                cout << "Enter room number to check in: ";
                cin >> roomToCheckIn;
                hotel.checkIn(roomToCheckIn);
                break;
            }
            case 4: {
                uint8_t roomToCheckOut;
                cout << "Enter room number to check out: ";
                cin >> roomToCheckOut;
                hotel.checkOut(roomToCheckOut);
                break;
            }
            
            case 7:
                while (true) {
                    cout << "Customer Management System" << endl;
                    cout << "1. Add Customer" << endl;
                    cout << "2. Edit Customer" << endl;
                    cout << "3. Delete Customer" << endl;
                    cout << "4. Display Customers" << endl;
                    cout << "5. Back to Main Menu" << endl;

                    int customerChoice;
                    cout << "Enter your choice: ";
                    cin >> customerChoice;

                    switch (customerChoice) {
                        case 1: {
                            string name, phone, address;
                            cout << "Enter customer name: ";
                            cin.ignore();
                            getline(cin, name);
                            cout << "Enter customer phone number: ";
                            cin >> phone;
                            cout << "Enter customer address: ";
                            cin.ignore();
                            getline(cin, address);

                            Customer newCustomer(customerId, name, phone, address);
                            customerManager.addCustomer(newCustomer);
                            cout << "Customer added successfully. Customer ID: " << static_cast<int>(customerId) << endl;
                            customerId++; // Tăng ID cho khách hàng tiếp theo
                            break;
                        }
                        case 2: {
                            uint8_t editId;
                            string newName, newAddress;
                            cout << "Enter customer ID to edit: ";
                            cin >> editId;
                            cout << "Enter new name: ";
                            cin.ignore();
                            getline(cin, newName);
                            cout << "Enter new address: ";
                            getline(cin, newAddress);
                            customerManager.editCustomer(editId, newName, newAddress);
                            break;
                        }
                        case 3: {
                            uint8_t deleteId;
                            cout << "Enter customer ID to delete: ";
                            cin >> deleteId;
                            customerManager.deleteCustomer(deleteId);
                            break;
                        }
                        case 4:
                            customerManager.displayCustomers();
                            break;
                        case 5:
                            cout << "Returning to Main Menu." << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                    }

                    if (customerChoice == 5) {
                        break;
                    }
                }
                break;
            case 8:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
