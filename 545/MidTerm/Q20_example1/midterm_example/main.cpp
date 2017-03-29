//
//  main.cpp
//  midterm_example
//
//  Created by 夏宇轩 on 2/28/17.
//  Copyright (c) 2017 夏宇轩. All rights reserved.
//

#include <iostream>
using namespace std;

class MyBox{
protected:
    int length;
    int width;
    int height;
    
public:
    MyBox(int length=0,int width=0,int height=0):length(length),width(width),height(height){};
    
    void show_box(){
        cout<<"length:"<<length<<"width:"<<width<<"height:"<<height<<endl;
    }
    
    MyBox operator = (MyBox box2){
        cout<<" operator overload"<<endl;
        this->length = box2.length;
        this->height = box2.height;
        this->width = box2.width;
        return *this;
    }
};
//4,5,6,11
class AbstractCar{
protected:
    int price;
public:
    AbstractCar(int price):price(price){};
    virtual void show_price()=0;
    virtual ~AbstractCar(){
        cout<<"destructor in base"<<endl;
    }
};

class Porsche: public AbstractCar{
public:
    Porsche(int price=0):AbstractCar(price){};
    void show_price(){
        cout<<"the porsche's price is:"<<this->price<<endl;
    }
    ~Porsche(){
        cout<<"destructor in Porsche"<<endl;
    }
};
class Lamborghini: public AbstractCar{
public:
    Lamborghini(int price=0):AbstractCar(price){};
    void show_price(){
        cout<<"the Lamborghini's price is:"<<this->price<<endl;
    }
    ~Lamborghini(){
        cout<<"destructor in Lamborghini"<<endl;
    }
};
//6
class base {
public:
    base()
    { cout<<"Constructing base \n"; }
    virtual ~base()
    { cout<<"Destructing base \n"; }
};

class derived: public base {
public:
    derived()
    { cout<<"Constructing derived \n"; }
    ~derived()
    { cout<<"Destructing derived \n"; }
};
//9
inline int factorial(int n)
{
    if(!n)return 1;
    else return n*factorial(n-1);
}

//11
class CarFactory{
public:
    CarFactory(string factoryType):factoryType(factoryType){};
    virtual AbstractCar* createCar(int price=0)=0;
protected:
    string factoryType;
};
class PorscheFactory : public CarFactory{
public:
    PorscheFactory():CarFactory("Porsche"){};
    AbstractCar* createCar(int price=0){
        return new Porsche(price);
    }
};
class LamborghiniFactory : public CarFactory{
public:
    LamborghiniFactory():CarFactory("Lamborghini"){};
    AbstractCar* createCar(int price=0){
        return new Lamborghini(price);
    }
};


//20
struct MyClass {
    MyClass() {std::cout <<"MyClass constructed\n";}
    ~MyClass() {
        std::cout <<"MyClass destroyed\n";
    
    }
};


int main(int argc, const char * argv[]) {
    // 1
    int a =10;
    int& ref=a;
    ref++;
    cout<<ref<<"\n"<<&ref;
    
    
    
    //2
    cout<<"example2"<<endl;
    MyBox box1(1,1,1);
    box1.show_box();
    MyBox box2(1,2,3);
    box2.show_box();
    
    box2=box1;
    box2.operator=(box1);
    box2.show_box();
    
    //3
    
    //4
    Porsche myPorsche(1000000);
    myPorsche.show_price();
    //6
    derived *d = new derived();
    base *b = d;
    delete b;
    //getchar();
    
    //7
    int number =10;
    int number1(10);
    int number2={10};
    int number3;
    number3 = number;
    
    //9
    cout<<factorial(2)<<endl;
    //11
    cout<<"polymorphism"<<endl;
    AbstractCar *car[10];
    CarFactory* carFactory;
    LamborghiniFactory* fac1=new LamborghiniFactory;
    PorscheFactory* fac2 = new PorscheFactory;
    carFactory=fac1;
    car[0]=carFactory->createCar(10);
    car[0]->show_price();
    carFactory=fac2;
    car[1]=carFactory->createCar(20);
    car[1]->show_price();
    
    //12
    string my_str="hello world";
    char char_array[10]="how r you";
    my_str=char_array;
    cout<<my_str<<endl;
    char * char_ptr;
    char my_char= 'c';
    char_ptr=char_array;
    char_ptr= &my_char;
    
    
    
    //20
    MyClass * pt;
    cout<<"pt after declaration"<<pt<<endl;
    pt = new MyClass[3];
    cout<<"pt after definition"<<pt<<endl;
    delete[] pt;
    cout<<pt<<endl;


    return 0;
}

