#include<iostream>
using namespace std;

class Cat {
    private:
        string name;
        string color;
        int age;
    public:
        Cat(string name, string color, int age);
        Cat(const Cat& rhs);
        Cat& operator=(const Cat& rhs);
        void getCat();
};

Cat::Cat(string name, string color, int age):
    name(name),
    color(color),
    age(age)
{
    cout<<"Cat constructor! \n";
}

Cat::Cat(const Cat& rhs) : 
    name(rhs.name),
    color(rhs.color)
    // age(rhs.age) // Item 12, make sure to copy all parts of an object! 
{
    cout<<"Cat copy constructor! \n";
}

Cat& Cat::operator=(const Cat& rhs)
{
    // Item 11, identity test: if it is a self-assigment, do nothing
    if(name == rhs.name && color == rhs.color && age == rhs.age)
    {
        cout<<"Objects are the same, no copy needed! \n";
        return *this;
    }
    cout<<"Cat copy assigment operator! \n";
    name = rhs.name;
    color = rhs.color;
    // age = rhs.age; // Item 12, make sure to copy all parts of an object! 
    return *this; // Item 10, return a reference to *this
}

void Cat::getCat(){
    cout<<"Cat name: "<<this->name<<" color: "<<this->color<<" age: "<<this->age<<"\n";
}

int main(){

    Cat C1("Tom", "black", 7);
    Cat C2("Felix", "orange", 4);

    C1.getCat();
    C2.getCat();

    // Use Cat copy constructor
    Cat C4(C1);
    C4.getCat();

    // Use Cat copy assigment operator
    C1 = C2;
    C1.getCat();

    Cat C3("Lola", "white", 1);
    C3.getCat();

    C1 = C2 = C3;
    C1.getCat();
    C2.getCat();

    // Item 11, identity test
    // Cat C5("Puf", "gray", 3);
    // Cat C6(C5);
    // C6.getCat();
    // C5 = C6;

    return 0;
}