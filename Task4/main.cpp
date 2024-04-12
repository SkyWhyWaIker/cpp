#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

class IGeoFig {
public:
    virtual double square() const = 0;
    virtual double perimeter() const = 0;
};

class CVector2D {
public:
    double x, y;
};

class IPhysObject {
public:
    virtual double mass() const = 0;
    virtual CVector2D position() const = 0;
    virtual bool operator==(const IPhysObject& ob) const = 0;
    virtual bool operator<(const IPhysObject& ob) const = 0;
};

class IPrintable {
public:
    virtual void print() const = 0;
};

class IDialogInitiable {
public:
    virtual void initFromDialog() = 0;
};

class BaseCObject : public IGeoFig, public IPhysObject, public IPrintable, public IDialogInitiable {
public:
    virtual const char* classname() const = 0;
    virtual unsigned int size() const = 0;
    virtual ~BaseCObject() {}
//    virtual void print() const = 0;
//    virtual double square() const = 0;
//    virtual double perimeter() const = 0;
    virtual double Mass() const = 0;
//    virtual CVector2D position() const = 0;
};

// Classes
class Circle : public BaseCObject {
private:
    double radius;
    double mass_;
    CVector2D center;
public:
    Circle(double r, double m) : radius(r), mass_(m) {}
    double square() const override { return M_PI * radius * radius; }
    double perimeter() const override { return 2 * M_PI * radius; }
    double mass() const override { return mass_; }
    double Mass() const override { return mass_; }
    CVector2D position() const override { return center; }
    bool operator==(const IPhysObject& ob) const override { return mass_ == ob.mass(); }
    bool operator<(const IPhysObject& ob) const override { return mass_ < ob.mass(); }
    void initFromDialog() override {}
    const char* classname() const override { return "Circle"; }
    unsigned int size() const override { return sizeof(*this); }
    void print() const override {
        std::cout << "Circle: radius = " << radius << ", mass = " << mass_ << ", center = (" << center.x << ", " << center.y << ")\n";
    }
};

class Rectangle : public BaseCObject {
private:
    double width;
    double height;
    double mass_;
    CVector2D center;
public:
    Rectangle(double w, double h, double m) : width(w), height(h), mass_(m){}
    double square() const override {
        return width * height;
    }
    double perimeter() const override {
        return 2 * (width + height);
    }
    double mass() const override {return mass_; }
    double Mass() const override { return mass_; }
    CVector2D position() const override { return center; }
    bool operator==(const IPhysObject& ob) const override {
        return mass_ == ob.mass();
    }
    bool operator<(const IPhysObject& ob) const override {
        return mass_ < ob.mass();
    }
    void initFromDialog() override {
    }
    const char* classname() const override {
        return "Rectangle";
    }
    unsigned int size() const override {
        return sizeof(*this);
    }
    void print() const override {
        std::cout << "Rectangle: width = " << width << ", height = " << height << ", mass = " << mass_ << ", center = (" << center.x << ", " << center.y << ")\n";
    }
};

int main() {
    std::vector<std::unique_ptr<BaseCObject>> shapes;

    // User input for shapes
    char choice;
    do {
        std::cout << "Enter 'c' for circle, 'r' for rectangle, or 'q' to quit: ";
        std::cin >> choice;

        if (choice == 'c') {
            double radius, mass, x, y;
            std::cout << "Enter radius, mass, and coordinates (x y): ";
            std::cin >> radius >> mass >> x >> y;
            shapes.push_back(std::make_unique<Circle>(radius, mass));
        } else if (choice == 'r') {
            double width, height, mass, x, y;
            std::cout << "Enter width, height, mass, and coordinates (x y): ";
            std::cin >> width >> height >> mass >> x >> y;
            shapes.push_back(std::make_unique<Rectangle>(width, height, mass));
        }
    } while (choice != 'q');


    // Display all shapes
    for (const auto& shape : shapes) {
        shape->print();
    }

    size_t memoryUsage = 0;
    for (const auto& shape : shapes) {
        memoryUsage += sizeof(*shape);
    }
    std::cout << "Memory usage: " << memoryUsage << " bytes\n";

    // Total area of all shapes
    double totalArea = 0;
    for (const auto& shape : shapes) {
        totalArea += shape->square();
    }
    std::cout << "Total area: " << totalArea << '\n';

    // Total perimeter of all shapes
    double totalPerimeter = 0;
    for (const auto& shape : shapes) {
        totalPerimeter += shape->perimeter();
    }
    std::cout << "Total perimeter: " << totalPerimeter << '\n';

    // Center of mass calculation
    double totalMass = 0.0;
    double centerX = 0.0;
    double centerY = 0.0;

    for (const auto& shape : shapes) {
        double mass = shape->mass();
        totalMass += mass;
        CVector2D pos = shape->position();
        centerX += mass * pos.x;
        centerY += mass * pos.y;
    }

    centerX /= totalMass;
    centerY /= totalMass;

    std::cout << "Center of mass: (" << centerX << ", " << centerY << ")\n";

    return 0;
}
