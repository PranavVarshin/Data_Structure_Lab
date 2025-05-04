#include <iostream>
using namespace std;

class Shape {
public:
    virtual void calculateArea() = 0;  // Pure virtual function (Abstract Class)
};

// Square Class
class Square : public Shape {
    double* side;
public:
    Square(double s) {
        side = new double(s);
    }
    void calculateArea() override {
        cout << "Area of Square: " << (*side) * (*side) << endl;
    }
    ~Square() {
        delete side;
    }
};

// Cube Class
class Cube : public Shape {
    double* side;
public:
    Cube(double s) {
        side = new double(s);
    }
    void calculateArea() override {
        cout << "Surface Area of Cube: " << 6 * (*side) * (*side) << endl;
    }
    ~Cube() {
        delete side;
    }
};

// Rectangle Class
class Rectangle : public Shape {
    double* length;
    double* width;
public:
    Rectangle(double l, double w) {
        length = new double(l);
        width = new double(w);
    }
    void calculateArea() override {
        cout << "Area of Rectangle: " << (*length) * (*width) << endl;
    }
    ~Rectangle() {
        delete length;
        delete width;
    }
};

// Cuboid Class
class Cuboid : public Shape {
    double* length;
    double* width;
    double* height;
public:
    Cuboid(double l, double w, double h) {
        length = new double(l);
        width = new double(w);
        height = new double(h);
    }
    void calculateArea() override {
        cout << "Surface Area of Cuboid: " << 2 * ((*length * *width) + (*width * *height) + (*height * *length)) << endl;
    }
    ~Cuboid() {
        delete length;
        delete width;
        delete height;
    }
};

int main() {
    char choice;
    while (true) {
        cout << "\nMenu:";
        cout << "\na. Square";
        cout << "\nb. Cube";
        cout << "\nc. Rectangle";
        cout << "\nd. Cuboid";
        cout << "\ne. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 'e') {
            cout << "Exiting program...\n";
            break;//Ends the while loop and exits the program
        }

        Shape* shape = nullptr;

        switch (choice) {
            case 'a': {
                double side;
                cout << "Enter the side length of Square: ";
                cin >> side;
                shape = new Square(side);
                break;
            }
            case 'b': {
                double side;
                cout << "Enter the side length of Cube: ";
                cin >> side;
                shape = new Cube(side);
                break;
            }
            case 'c': {
                double length, width;
                cout << "Enter the length and width of Rectangle: ";
                cin >> length >> width;
                shape = new Rectangle(length, width);
                break;
            }
            case 'd': {
                double length, width, height;
                cout << "Enter the length, width, and height of Cuboid: ";
                cin >> length >> width >> height;
                shape = new Cuboid(length, width, height);
                break;
            }
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
                continue;
        }

        if (shape) {
            shape->calculateArea();
            delete shape;
        }
    }
    return 0;
}
