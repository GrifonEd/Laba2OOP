
#include <conio.h>
#include <iostream>
using namespace std;

class Animal { //Создание класса
public :
    int size, age;           //Создание атрибутов(публичных)
    Animal() {                        // Создание Конструктора без параметров 
        printf("Animal()\n");
        size = 0;
        age = 0;
    }
    Animal(int size, int age) {            // Создание Конструктора с параметрами
        printf("Animal(int size, int age)\n");
        this->size = size;
        this->age = age;
    }
    Animal(const Animal &a) {                  // Создание Конструктора копирования
        printf("Animal(const Animal &a)\n");
        size = a.size;
        age = a.age;
    }
    ~Animal() {                      // Создание деструктора
        printf("%d, %d\n",size, age);
        printf("~Animal()\n");
    }
};
int main()
{
    {
    Animal a;
    Animal a2(10, 20);                   // Создание объектов класса
    Animal a3(a2);
    }
    
    {
        Animal *a = new Animal;
        Animal *a2 = new Animal(10, 20);
        Animal* a3 = new Animal(*a2);

        delete a;
        delete a2;
        delete a3;
    }




 
}


