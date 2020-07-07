// Example program
#include <iostream>
#include <string>

class A {
    public:
        A() = default;
        A(const std::string& str) {
            s = str;
        }
        virtual void print() {
            std::cout << "base print: " << s << std::endl;
        }
    private:
        std::string s;
};

class B : public A {
    public:
        B() = default;
        B(const std::string& str) {
            s = str;
        }
        void print() override {
            std::cout << "derived print: " << s << std::endl;
        }
    private:
        std::string s;
};

int main()
{
    // run-time poly
  B* pb = new B("b-sal");
  A* pa = pb;
  pa->print(); // "derived print: b-sal"
}

