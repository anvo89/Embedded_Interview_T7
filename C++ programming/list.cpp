#include <iostream>
#include <list>

using namespace std;

int test[]={2,3,4,6};

int main(){
    vector<int> array;
    array.push_back(1);
     array.push_back(3);
      array.push_back(1);
       array.push_back(4);

    vector<int>::iterator it=array.begin()            // dùng interator để lưu địa chỉ;
    
    for (vector<int>::iterator it=array.begin();array.end();i++){
        
    }
    
    return 0;
}