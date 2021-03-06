#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include "clas.hpp"
using namespace std;

int main(int ac, char *argv[]) {
  int i,n,k;
  if (argc <= 2) {
      cout << "Не заданы имена файлов" << endl;
      return 0;
  }
  food foo;
  drink dr;
  ifstream f(argv[1]);
  ifstream d(argv[2]);
  if (!f.is_open() & d.is_open()) {
      cout << "Ошибка открытия файлов" << endl;
      return 0;
  }
  f>>n;
  shop* df2 = new shop[n];
  for (int i=0;i<n;i++){
    f>>foo;
    df2[i].foo=foo;
  }

  d>>k;
  for (int i=0;i<k;i++){
    d>>dr;
    df2[i].dr=dr;
  }
  f.close();
  d.close();
  SetLocale(LC_ALL, "Rus");
  int b;
  for(;;){
    system("clear");
    cout<<"Выберите одну из команд:"<<endl;
    cout<<"1-Посмотреть арсенал магазина"<<endl;
    cout<<"2-Посмотреть информацию о конкретном товаре"<<endl;
    cout<<"3-Добавить товар на склад"<<endl;
    cout<<"4-Удалить товар со склада"<<endl;
    cout<<"5-Изменить информацию о товаре" << endl;
    cout<<"6-Выход"<<endl;
    cin>>b;
    while (b==1){
      
      system("clear");
      cout<<"Еда"<<endl;
      for (int i=0;i<n;i++){
        cout<<df2[i].foo;
      }
      cout<<"Напитки"<<endl;
      for (int i=0;i<k;i++){
        cout<<df2[i].dr;
      }
      cout<<"1-Посмотреть еще раз"<<endl;
      cout<<"0-Вернуться назад"<<endl;
      cin>>b;
    }


    while (b==2){
      system("clear");
      cout<<"Введите 1 если напиток, 0-если еда\n";
      int h;
      cin>>h;
      if (h==0){
        string name;
        cin>> name;
        print_food(df2, n,name);
      }
      else{
        string name;
        cin>>name;
        print_drink(df2, k,name);
      }
      cout<<"2-Посмотреть ещё раз"<<endl;
      cout<<"0-Вернуться назад"<<endl;
      cin>>b;
    }
    while (b==3){
      system("clear");
      cout<<"Введите 1 если напиток, 0-если еда\n";
      int h;
      cin>>h;
      if (h==0){
        push_food(df2,n,k);
      }
      else{
        push_drink(df2,n,k);
      }
      cout<<"3-добавить ещё товар:\n";
      cout<<"0-Вернуться назад:\n";
      cin>>b;
    }
    while (b==4){
      system("clear");
      cout<<"Введите 1 если напиток, 0-если еда\n";
      int h;
      cin>>h;
      if (h==0){
        delete_food(df2,n,k);
      }
      else{
        delete_drink(df2,n,k);
      }
      cout<<"4-Удалить еще один продукт\n";
      cout<<"0-Вернуться назад\n";
      cin>>b;
    }
    if (b == 5) {
        system("clear");
        cout<< "Введите 1 если напиток, 0-если еда\n";
        int h;
        cin >> h;
        if (h == 0) {
            fix_food(df2, n, k);
        }
        else {
            fix_drink(dd2, n, k);
        }
        cout << "5-Изменить ещё один продукт" << endl;
        cout << "0-Вернуться назад" << endl;
        cin >> b;
    }
    if (b==6){
      system("clear");
      ofstream f(argv[1], ios_base::trunc);
      ofstream d(argv[2], ios_base::trunc);
      f<<n<<endl;
      for (int i=0;i<n;i++)
        f<<df2[i].foo;
      d<<k<<endl;
      for (int i=0;i<k;i++)
        d<<df2[i].dr;
      f.close();
      d.close();
      return 0;
    }
  }
}