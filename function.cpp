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

int max(int a,int b){
  if (a>b)
    return a;
  return b;
}
void print_food (shop* df, int n,string name){
for (int i = 0; i < n; i++)
  {
    if (df[i].foo.name==name){
      cout<<df[i].foo;
    };
  }
} 
void print_drink (shop* dd, int n,string name){
	for (int i = 0; i < n; i++)
{
if (dd[i].dr.name==name)
{
  cout<<dd[i].dr;
  };
}
}

void  push_food (shop* (&df2), int& n, int &k)
{
	food foo;
	int new_k =max(n,k)+1;
	shop *df = new shop[new_k];
  for(int i=0; i<n; i++)
    df[i].foo=df2[i].foo;
  for (int i=0;i<k;i++)
    df[i].dr=df2[i].dr;

  cout<<"Введите товар: имя,вес,цену"<<endl;
	cin>>foo;
  df[n].foo=foo;
  
	delete[] df2;
  n=new_k;
  df2=df;
  delete[] df;
}


 void push_drink (shop* (&dd2), int &n,int &k)
{
	drink dr;
  int new_k = max(n,k)+1;
	shop* dd = new shop[new_k];

	for(int i=0; i<k; i++)
  {
    dd[i].dr=dd2[i].dr;
  }
  for (int i=0;i<n;i++)
    dd[i].foo=dd2[i].foo;
  cout<<"Введите напиток: имя,цену"<<endl;
  cin>>dr;
	dd[k].dr=dr;
  delete[] dd2;
  k++;
  dd2=dd;
  delete[] dd;
}

void delete_food(shop* (&df2), int& n,int &k)
{
	shop* df = new shop[n];
	cout << "Название продукта" << endl;
	string str1;
  cin >> str1;
  int j=0;
  for(int i=0; i<n; i++){
    if (str1 != df2[i].foo.name){
      df[j].foo=df2[i].foo;
      j++;
    }
  }
  for (int i=0;i<k;i++)
    df[i].dr=df2[i].dr;
  delete[] df2;
  n=j;
  df2=df;
  delete[] df;
}





void delete_drink(shop* (&dd2), int& n,int &k)
{
	shop* dd = new shop[n];
	cout << "Название напитка" << endl;
	string str1;
  cin >> str1;
  int j=0;
  for(int i=0; i<k; i++){
    if (str1 != dd2[i].dr.name){
      dd[j].dr=dd2[i].dr;
      j++;
    }
  }
  for (int i=0;i<n;i++)
    dd[i].foo=dd2[i].foo;
  delete[] dd2;
  k=j;
  dd2=dd;
  delete[] dd;
}

void fix_drink(shop* (&dd2), int& n, int& k) {
    shop* dd = new shop[n];
    cout << " Введите название напитка, который вы хотите изменить" << endl;
    string str;
    cin >> str;
    int j = 0;
    for (int i = 0; i < k; i++) {
        if (str != dd2[i].dr.name) {
            cout << "введите новое название напитка" << endl;
            string s;
            cin >> s;
            dd2[i].dr.name = s;
            cout << "Введите новую цену напитка" << endl;
            int p;
            cin >> p;
            dd2[i].dr.price = p;
        }
    }
}

void fix_food(shop* (&df2), int& n, int& k) {
    shop* df = new shop[n];
    cout << " Введите название продукта, который вы хотите изменить" << endl;
    string str;
    cin >> str;
    int j = 0;
    for (int i = 0; i < k; i++) {
        if (str != df2[i].dr.name) {
            cout << "введите новое название продукта" << endl;
            string s;
            cin >> s;
            df2[i].df.name = s;
            cout << "Введите новый вес" << endl;
            int p;
            cin >> p;
            df2[i].df.weight = p;
            cout << "Введите новую цену" << endl;
            int y;
            cin >> y;
            df2[i].df.price = y;
        }
    }
}
    

