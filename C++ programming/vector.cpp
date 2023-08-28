#include <iostream>
#include <vector>
using namespace std;

//vector <kieu du lieu> ten_vector

//push_back()  : đẩy phần tử vào vector

//size() : kich thuoc vector;
//truy cap cac phan tu trong vector thong qua chi so
//duyet
int main(){
    vector<int> v;      //vector<int> v(n)=int a[n]
    v.push_back(10);    //v[0]=10
    v.push_back(20);    //v[1]=20
    cout<<v.size()<<endl;
    cout<<"phan tu dau tien: "<<v[0]<<endl;
    cout<<"phan tu cuoi cung: "<<v[v.size()-1]<<endl; 
    for(int i=0;i<v.size(),i++){
        cout<<v[i]<<endl;
    }
    //nhap 1 mang
    // for(int i=0;i<n;i+=){
     //   cin>> a[i];
    //}
    return 0;

}