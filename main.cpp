#include <iostream>

using std::cout;

class Elements {
public:
    virtual void info() = 0;
    virtual ~Elements() {} //Виртуальный деструктор
};

class Fire :public Elements {
public:
    void info() {
        cout << "One more light\n";
    }
};

class Water :public Elements {
public:
    void info() {
        cout << "One more a cup of water\n";
    }
};



class Factory {
public:
    virtual Elements* Create() = 0; //Чистая виртуальная функция показывает, что в производстве будет метод Create
    virtual ~Factory() {}
};



class FireFactory :public Factory {
public:
    Elements* Create() {
        return new Fire; //создаем объект огонек
    }
};

class WaterFactory :public Factory {
public:
    Elements* Create() {
        return new Water;//<-- Создаём объект водичка
    }
};




Elements* foo(Factory *value) {
    return value->Create();
}


int main() {
    FireFactory Fire;
    WaterFactory Water;

    Factory *ptr1 = &Fire;  //Указатели на объекты нужных типов
    Factory *ptr2 = &Water;


    Elements *ObjectElements1 = foo(ptr1); //Создали огонек
    Elements *ObjectElements2 = foo(ptr2); //Создали водичку

    ObjectElements1->info();
    ObjectElements2->info();

    delete ObjectElements1, delete ObjectElements2;

}
