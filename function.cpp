#include <iostream>
#include <fstream>
#include <string>
#include "clas.hpp"
istream & operator >>(istream & in, food &foo) {
    
    in >> foo.name; 
    in >> foo.weight>>foo.price;
    return in;
}
ostream & operator <<(ostream & out, const food &foo) {
    out << foo.name;
    out<<endl;
    out<<foo.weight;
    out<<endl;
    out<<foo.price<<endl;
    return out;
}


istream & operator >>(istream & in, drink &dr) {
    
    in >> dr.name; 
    in >> dr.price;
    return in;
}
ostream & operator <<(ostream & out, const drink &dr) {
    out<<dr.name<<endl;
    out<<dr.price<<endl;
    return out;
}


void print_food (shop* df, int n,string name)
{
for (int i = 0; i < n; i++)
{
if (df[i].foo.name==name)
{
  cout<<df[i].foo;
  };
}
} 
void print_drink (shop* dd, int n,string name)
{
	for (int i = 0; i < n; i++)
{
if (dd[i].dr.name==name)
{
  cout<<dd[i].dr;
  };
}
}

void  push_food (shop* (&df), int& n)
{
	food foo;
	shop* df2 = new shop[n];
	int k = n;
	int new_k = ++n;
	df = new shop[new_k];
  for(int i=0; i<=n; i++)
  {
    df2[i]=df[i];
  }

	cout << "Введите название товара" << endl;
	cin >> foo.name;
	cout << "Введите вес товара" << endl;
	cin >> foo.weight;
	cout << "Введите цену товара" << endl;
	cin >> foo.price;
	delete[] df2;
}


 void push_drink (shop* dd, int n)
{
	drink dr;
	shop* dd2 = new shop[n];
	int k = n;
	int new_k = ++n;
  dd = new shop[new_k];
	 for(int i=0; i<=n; i++)
  {
    dd2[i]=dd[i];
  }

	cout << "Введите название товара" << endl;
	cin >> dr.name;
	cout << "Введите цену товара" << endl;
	cin >> dr.price;
	delete[] dd2;
}

void delete_food(shop* (&df), int& n)
{
	shop* df2 = new shop[n];
	cout << "Название продукта" << endl;
	string str1;
  cin >> str1;
  for(int i=0; i<=n; i++){
    if (str1 != df[i].foo.name){
     n--;
df= new shop[n];
    }
  }
}


void delete_drink(shop* (&dd), int& n)
{
	shop* dd2 = new shop[n];
	cout << "Название напитка" << endl;
	string str1;
  cin >> str1;
  for(int i=0; i<=n; i++){
    if (str1 != dd[i].dr.name){
     n--;
dd= new shop[n];
    }
  }
}
