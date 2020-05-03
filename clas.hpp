#ifndef CLAS_HPP
#define CLAS_HPP
#include <iostream>
using namespace std;
class food{
public: 
string name;
int weight;
int price;
friend ostream& operator <<(ostream& out, const food& foo);
friend istream& operator >>(istream& in, food& foo);
};

class drink{
  public:
string name;
int price;
friend ostream& operator <<(ostream& out, const drink& dr);
friend istream& operator >>(istream& in, drink& dr);
};

class shop{
public:  
food foo;
drink dr;
shop(){};

~shop(){};

};
void print_food (shop* df, int n,string name);
void print_drink (shop* dd, int n,string name);
void  push_food (shop* (&df), int& n);
void push_drink (shop* dd, int n);
void delete_food(shop* (&df), int& n);
void delete_drink(shop* (&dd), int& n);

#endif // TEST_H
