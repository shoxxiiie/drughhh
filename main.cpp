#include <iostream>
#include <fstream>
#include <string>

template <typename T1, typename T2>
class Base {
protected:
    T1 value1;
    T2 value2;

public:
    Base(T1 v1, T2 v2) : value1(v1), value2(v2) {}
    virtual void display() const {
        std::cout << "Value1: " << value1 << ", Value2: " << value2 << std::endl;
    }
    virtual ~Base() = default;
};

template <typename T1, typename T2, typename T3, typename T4>
class Child : public virtual Base<T1, T2> {
protected:
    T3 value3;
    T4 value4;

public:
    Child(T1 v1, T2 v2, T3 v3, T4 v4) : Base<T1, T2>(v1, v2), value3(v3), value4(v4) {}
    void display() const override {
        Base<T1, T2>::display();
        std::cout << "Value3: " << value3 << ", Value4: " << value4 << std::endl;
    }
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public virtual Child<T1, T2, T3, T4> {
protected:
    T5 value5;
    T6 value6;

public:
    Child2(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6)
        : Child<T1, T2, T3, T4>(v1, v2, v3, v4), value5(v5), value6(v6) {}
    void display() const override {
        Child<T1, T2, T3, T4>::display();
        std::cout << "Value5: " << value5 << ", Value6: " << value6 << std::endl;
    }
};

int main() {
    Base<int, double>* base = new Base<int, double>(1, 2.5);
    base->display();

    Child<int, double, char, std::string>* child = new Child<int, double, char, std::string>(1, 2.5, 'A', "hello");
    child->display();

    Child2<int, double, char, std::string, bool, float>* child2 =
        new Child2<int, double, char, std::string, bool, float>(1, 2.5, 'A', "hello", true, 3.14f);
    child2->display();

    delete base;
    delete child;
    delete child2;

    return 0;
}
