#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>

using namespace std;

class Room{
    private:
        uint8_t roomNumber;
        bool isBooked;
        bool cleaned;
    public:
    Room(uint8_t number){
        roomNumber=number;
        isBooked=false;    
    };
    uint8_t getroomNumber(){
        return roomNumber;
    };
    bool isBooked(){
        return !isBooked;
    };
    void bookRoom(){
        isBooked=true;
    };
    void checkIn(){
        isBooked=true;
    };
    void checkOut(){        
        isBooked=false;
    };
};

/// 
typedef struct{
    uint8_t day;
    uint8_t month;
    uint16_t year;
}typeDate;

typedef struct{
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
}typeTime;

typedef enum{
    IN,
    OUT
}typeStatus;

typedef struct{
    typeTime time;
    typeDate date;
    typeStatus status;
}bookingHistory;

class Customer{
    private:
    uint8_t idRoom;
    string name;
    string phoneNumber;
    string address;
    vector<bookingHistory> bookingHistory;
    public:
    Customer(string customerName, string CustomerPhone, string customeraddress, uint8_t customerIdRoom);
    void addBookingHistory(bookingHistory booking Details);
    void displayBookingHistory();
    
    string getName(){
        return name;
    };
    uint8_t getIdRoom(){
        return idRoom;
    };
    string getPhoneNumber(){
        return phoneNumber;
    };
    string getAddress(){
        return address;
    }
    void setId(uint8_t id){
        idRoom=id;
    };
};
Customer::Customer(string customerName, string customerPhone, string customerAddress, uint8_t customerIdRoom){
    this->idRoom=customerIdRoom;
    this->name=customerName;
    this->phoneNumber=customerPhone;
    this->address=customerAddress;
}
void Customer::addBookingHistory(bookingHistory bookingDetails){
    bookingHistorys.push_back(bookingDetails);
}
//////////

class CustomerManage{
    private:
        vector<customer> databaseCustomers;
    public:
        void addCustomer(Customer& customer);
        void editIdRoomCustomer(vector<Room>& databaseRoom, int idRoom_Current,int idRoom);
        void deleteCustomer();
        vector<Customer>& getDatabase<Customer();
};

void CustomerManage::addCustomer(Customer& customer){
    databaseCustomers.push_back(customer);
};

void CustomerManage::editIdRoomCustomer(vector<Room>& databaseRoom,int idRoom_Current, int idRoom){
    for (uint8_t i=0;i<databaseRoom.size();i++){
        if(databaseRoom[i].getRoomNumber()==idRoom_current) databaseRoom[i].checkOut();
        if(databaseRoom[i].getRoomNumber()==idRoom)databaseRoom[i].bookRoom();
    }
    for(uint8_t i=0;i<databaseRoom.size();i++){
        if (databaseCustomers[i].getIdRoom==idRoom_Current){
            databaseCustomers[i].setId(idRoom);
        }
    }
};

vector<Customers>& CustomerManage::getDatabaseCustomers(){
    return databaseCustomer;
}
////////

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
        bool autheticate(string inputUsername, string inputPassword){
            bool checkSingnUp=(inputUsername==USERNAME&&inputPassword==PASSWORD);
            return checkSingnUp();
        };
    
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
    Employee(string nameEmployee,)
}
