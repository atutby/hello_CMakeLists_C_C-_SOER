#include <iostream>

class HelloWorld
{
public:
    HelloWorld() {}
    void say()
    {
        std::cout << "Hello World" << std::endl;
    }
};

extern "C" void sayHello()
{
    HelloWorld hw;
    hw.say();
}