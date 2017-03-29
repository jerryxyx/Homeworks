//
//  main.cpp
//  Q20
//
//  Created by 夏宇轩 on 3/1/17.
//  Copyright (c) 2017 夏宇轩. All rights reserved.
//





#include <iostream>
using namespace std;


//14,15
class AbstractCar{
protected:
    string car_type;
    string car_number;
public:
    AbstractCar(string carType="",string car_number=""):car_type(carType),car_number(car_number){};
    virtual void show_type()=0;
    string get_car_number(){
        return car_number;
    }
};

class Sportscar:public AbstractCar{
protected:
    int speed=180;
public:
    Sportscar():AbstractCar("sports car"){};
    Sportscar(string car_number):AbstractCar("sports car",car_number){};
    ~Sportscar(){
        cout<<"delete sports car"<<endl;
    }
    void show_speed(){
        cout<<"this car's speed is "<<speed<<endl;
    }
    void show_type(){
        cout<<this->car_type<<endl;
    }
    //virtual void show_value()=0;
};

class Muslecar: public AbstractCar{
protected:
    int strength=500;
public:
    Muslecar():AbstractCar("muscle car"){};
    void show_strength(){
        cout<<"this car's strength is "<<strength<<endl;
    }
    void show_type(){
        cout<<car_type<<endl;
    }
};
class Porsche: public Sportscar{};
class Lamborghini: public Sportscar{};
class Mustang: public Sportscar, public Muslecar{};

class Porsche911 : public Porsche{
protected:
    int value= 1000000;
};


//17
struct A{
protected:
    int value;
    int data;
public:
    A(){};//converting constructor (since c++11)
    A(int a):value(a){};//converting constructor
    explicit A(int a, int b):value(a),data(b){};//explicit constructor
};



//19
class Animal{
    int weight;
public:
    int getWeight() { return weight;};
};
class WaterAnimal : virtual public Animal {};
class LandAnimal : virtual public Animal {};
class Amphibian : public WaterAnimal, public LandAnimal {};




int main(int argc, const char * argv[]) {
    // insert code here...
    char *bArray = new char[25] ; //char buf[25]
    //    int *bArray = new int[5];
    cout << "bArray is just being created, and its address is:"<<&bArray << endl;
    cout << "ptr bArray point to this address: "<<bArray << endl;
    bArray[0] = 'a';
    char a_char ='b';
    char *charPointer;
    charPointer= &a_char;
    bArray[1] = a_char;
    cout << "charPointer: "<<charPointer<<endl;
    cout << "bArray is "<<bArray<<endl;
    cout << "bArray[0] is: "<<&bArray[0] << endl;
    cout << "bArray[1] is: "<<&bArray[1] << endl;
    //    delete bArray;
    delete [] bArray;
    cout << "after delete bArray" << endl;
    //    for (int i = 0; i < 10000; ++i) {
    //        cout << "bArray's address is:"<<&bArray << endl;
    //        cout << i<<"ptr bArray point to this address: "<<bArray << endl;
    //    }
    
    bArray[2] = 'b';
    cout << "bArray[2] is: "<<bArray[2] << endl;
    
    //    delete bArray;
    cout << "after delete[] bArray" << endl;
    //3
    
    
    Sportscar* a_sports_car=new Sportscar;
    a_sports_car->show_type();
    delete a_sports_car;
    
    
    
    
    
    //14
    Porsche * a_prosche=new Porsche;
    a_prosche->show_speed();
    Mustang* a_mustang = new Mustang;
    a_mustang->show_strength();
    a_mustang->show_speed();
    //a_mustang->show_type();
    
    //16
    for(int i=1;i<5;i++){
        for(int j=1;j<5;j++){
            cout<<"["<<i<<","<<j<<"]";
        }
        cout<<endl;
    }
    
    //16
    int count1;
    int count2;
    for(int i=0;i<3;i++){
        int party;
        cout<<"please input which party do you like to support: (1/2)"<<endl;
        cin>>party;
        switch (party) {
            case 1:
                count1++;
                break;
            case 2:
                count2++;
                break;
            default:
                cout<<"invalid vote!"<<endl;
                break;
        }
    }
    cout<<"party1:"<<count1<<"\n"<<"party2:"<<count2<<endl;
    
    //17
    A aa(10);//OK: direct-initialization selects A::A(int)
    A a1=10;//OK: copy-initialization selects A::A(int)
    A a2={10};//OK: copy-list-initialization selects A::A(int)
    //A a3={1,2}; //error: copy-list-initialization selected an explicit constructor
    
    //18
    
    try{
        throw 10;
    }
    catch(int e){
        cout<<"the exception number: "<<e<<endl;
    }
    
    //19
    //Amphibian* frog;
    //frog->getWeight();
    
    //20
    Sportscar* sportscar =new Sportscar;
    delete sportscar;
    //delete[] Sportscar;//wrong
    Sportscar* sportscarArray=new Sportscar[3];
    sportscarArray[0]=Sportscar("666666");
    sportscarArray[1]=Sportscar("999999");
    sportscarArray[2]=Sportscar("A12345");
    for(int i=0; i<3;i++){
        cout<<"the car number of "<<i<<" is "<<sportscarArray[i].get_car_number()<<endl;
    }
    delete[] sportscarArray;
    //delete sportscarArray;//wrong
    
    int * int1 = new int(1);
    delete[] int1;//ok
    //delete int1;
    int * int2 = new int[3];
    int2[0]=1;
    int2[1]=2;
    int2[2]=3;
    for(int i=0;i<3;i++){
        cout<<"the int array["<<i<<"] is "<<int2[i]<<endl;
    }
    delete int2;
    int2 = nullptr;
    delete int2;
    int2 = nullptr;
    
    
    
    
    
    
}
