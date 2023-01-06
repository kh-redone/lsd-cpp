#include<iostream>

class Shape
{
    public:
        float width;
        float height;
        Shape(const float& width, const float& height)
        : width(width), height(height){};
};

class triangle : public Shape
{
    public:
    using Shape::Shape;
    float area() const { return 0.5 * width*height;};
};

class rectangle : public Shape
{
    public:
    using Shape::Shape;
    float area() const { return width * height;};
};

int main()
{
  triangle t(5, 5);
  rectangle r(5, 5);

  std::cout << t.area() << std::endl;  // Output: 12.5
  std::cout << r.area() << std::endl;  // Output: 25

  return 0;
}