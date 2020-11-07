
#include <conio.h>
#include <iostream>
using namespace std;

class Animal { //Создание класса
private:
    int character=0;
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
        printf("%d, %d, %d\n",size, age, character);
        printf("~Animal()\n");
    }
    void train(int time, int strength) {
        size = size + time * strength;
        age = age + time * strength;
    }
    void recreation();
};
void Animal::recreation() {
    size = size - 1;
    age = age - 1;
    character = character + 1;
}
class Birds : public Animal { //Создание класса наследника
protected :
    int SizeWings;                        //Создание атрибутов наследования 
public:
    Birds(): Animal() {                        // Создание Конструктора без параметров 
        printf("Birds()\n");
        SizeWings = 0;
    }
    Birds(int size, int age,int SizeWings) : Animal(size,age) {            // Создание Конструктора с параметрами
        printf("Birds(int size, int age,int SizeWings)\n");
        this->SizeWings = SizeWings;
    }
    Birds(const Birds& a) {                  // Создание Конструктора копирования
        printf("Birds(const Birds& a)\n");
        size = a.size;
        age = a.age;
        SizeWings = a.SizeWings;
    }
    ~Birds() {                      // Создание деструктора
        printf("%d, %d, %d\n", size, age, SizeWings);
        printf("~Birds()\n");
    }
    void train_fly(int new_SizeWings) { 
        SizeWings = new_SizeWings;
    }

};
int main()
{
    setlocale(LC_CTYPE, "Russian");
    {
        printf("Создание объектов статически\n");
    Animal a;
    Animal a2(10, 20);                   // Создание объектов класса
    Animal a3(a2);
    }
    system("pause");
    system("cls");
    {
        printf("Создание объектов динамически\n");
        Animal *a = new Animal;
        Animal *a2 = new Animal(10, 20);
        Animal* a3 = new Animal(*a2);

        delete a;
        delete a2;
        delete a3;
    }
    system("pause");
    system("cls");
    {
        printf("Работа методов и доступа к атрибутам\n");
        Animal* a = new Animal(10, 20);
        a->train(2, 3);
        a->recreation();                   // Добавляем к атрибуту "сharecter" 1 через метод даже к приватному.
        a->age = 0; // Можем обратиться к возрасту, потому что атрибут "age" публичный
        // a->character не можем обратиться, потому что атрибут "сharecter" приватный
        delete a;
        
    }
    system("pause");
    system("cls");
    {
        printf("Работа с наследованием\n");   // Создание объекта потомка
        Birds* a = new Birds(10, 20, 15);
        delete a;
    }

 
}


