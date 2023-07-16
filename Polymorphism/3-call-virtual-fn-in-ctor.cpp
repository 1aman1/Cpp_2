#include <iostream>

class Shape
{
public:
    virtual void draw() const
    {
        std::cout << "Drawing a generic shape." << std::endl;
    }
};

class Circle : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing a square." << std::endl;
    }
};

int main()
{
    Shape *shapePtr = new Circle();
    shapePtr->draw();

    shapePtr = new Square();
    shapePtr->draw();

    delete shapePtr;

    return 0;
}
