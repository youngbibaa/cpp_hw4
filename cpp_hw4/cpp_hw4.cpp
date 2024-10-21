#include <iostream>
#include <cstring> // Для strcpy_s
using namespace std;

class Human {
    char* fullname;
    int size;
    int age;

public:
    static int humansCount;
    Human() : fullname{ nullptr }, size{ 0 }, age{ 0 } {}

    Human(const char* fullname, int size, int age)
        : fullname{ new char[size] }, size{ size }, age{ age }
    {
        strcpy_s(this->fullname, size, fullname);
        humansCount++;
    }

    Human(const Human& other)
        : fullname{ new char[other.size] }, size{ other.size }, age{ other.age }
    {
        strcpy_s(this->fullname, other.size, other.fullname);
        humansCount++;
    }


    ~Human() {
        delete[] fullname;
        humansCount--;
    }
};

class Apartment {
    int floor;
    int apartment_number;
    Human* humans;
    int count;

public:
    static int apartmentsCount;

    Apartment() : floor{ 0 }, apartment_number{ 0 }, humans{ nullptr }, count{ 0 } {}

    Apartment(int floor, int apartment_number, Human* humans, int count)
        : floor{ floor }, apartment_number{ apartment_number }, humans{ new Human[count] }, count{ count }
    {
        for (int i = 0; i < count; i++) {
            this->humans[i] = humans[i];
        }
        apartmentsCount++;
    }

    Apartment(const Apartment& other)
        : floor{ other.floor }, apartment_number{ other.apartment_number }, humans{ new Human[other.count] }, count{ other.count }
    {
        for (int i = 0; i < count; i++) {
            humans[i] = other.humans[i];
        }
        apartmentsCount++;
    }

  

    ~Apartment() {
        delete[] humans;
        apartmentsCount--;
    }
};

class House {
    char* address;
    int size;
    int house_number;
    Apartment* apartments;
    int count;

public:
    House() : address{ nullptr }, size{ 0 }, house_number{ 0 }, apartments{ nullptr }, count{ 0 } {}

    House(const char* address, int size, int house_number, Apartment* apartments, int count)
        : address{ new char[size] }, size{ size }, house_number{ house_number }, apartments{ new Apartment[count] }, count{ count }
    {
        strcpy_s(this->address, size, address);
        for (int i = 0; i < count; i++) {
            this->apartments[i] = apartments[i];
        }
    }

    House(const House& other)
        : address{ new char[other.size] }, size{ other.size }, house_number{ other.house_number }, apartments{ new Apartment[other.count] }, count{ other.count }
    {
        strcpy_s(address, size, other.address);
        for (int i = 0; i < count; i++) {
            apartments[i] = other.apartments[i];
        }
    }

    ~House() {
        delete[] address;
        delete[] apartments;
    }
};

int Human::humansCount = 0;
int Apartment::apartmentsCount = 0;

int main() {
    Human h1("John Doe", 9, 30);
    Human h2("Jane Doe", 9, 28);
    Human h3("Jane Doe", 9, 20);
    Human h4("Jane Doe", 9, 25);

    Human* humans1 = new Human[2]{ h1, h2 };
    Human* humans2 = new Human[2]{ h3, h4 };

    Apartment apartments1{ 5, 149, humans1, 2 };
    Apartment apartments2{ 5, 149, humans2, 2 };

    Apartment* apartments = new Apartment[2]{ apartments1, apartments2 };

    House house{"respublika", 11, 54,  apartments, 2};

  

    return 0;
}
