//
// Created by bzahov on 8.01.20 г..
//

#include <iostream>

static const char *const WHITE_COLOR = "white";
static const char *const GREEN_COLOR = "green";
static const char *const RED_COLOR = "red";
using namespace std;

class Point;

class Circle;

class Point {
private:
    int x, y;
public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(int xx, int yy) : x(xx), y(yy) {
        /*x = xx;
        y = yy;*/
    }

    ~Point() {}

    string toString() {
        return "X:" + to_string(x) + " Y:" + to_string(y);
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        Point::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Point::y = y;
    }
};

class Circle {
private:
    Point center;
    int radius;
    string color;

public:
    Circle() {
        center = Point();
        radius = 0;
        color = "default";
    }

    Circle(const Point &center, int radius, const string &name)
            : center(center), radius(radius), color(name) {}

    const Point &getCenter() const {
        return center;
    }

    void setCenter(const Point &center) {
        Circle::center = center;
    }

    int getRadius() const {
        return radius;
    }

    void setRadius(int radius) {
        Circle::radius = radius;
    }

    const string &getColor() const {
        return color;
    }

    void setColor(const string &color) {
        Circle::color = color;
    }

    string toString() {
        return center.toString() + " radius: " + to_string(radius) + " color:" + color;
    }
};

bool isThatColor(const string& checkedColor, const string& color);

int main() {
    int sizeOfArr = 6;
    Circle *arr = new Circle[sizeOfArr];
    Circle c1(Point(6, 3), 2, WHITE_COLOR);
    Circle c2(Point(2, 3), 2, WHITE_COLOR);
    Circle c3(Point(8, 3), 2, GREEN_COLOR);
    Circle c4(Point(1, 3), 2, GREEN_COLOR);
    Circle c5(Point(9, 2), 2, RED_COLOR);
    Circle c6(Point(8, 5), 5, RED_COLOR);
    arr[0] = c1;
    arr[1] = c2;
    arr[2] = c3;
    arr[3] = c4;
    arr[4] = c5;
    arr[5] = c6;

    for (int i = 0; i < sizeOfArr; ++i) {
        Circle currentCircle = arr[i];

        if (isThatColor( currentCircle.getColor(), RED_COLOR)) {
            cout << currentCircle.toString() << endl;
        }
    }
    return 0;
}

bool isThatColor(const string& checkedColor, const string& color) {
    return checkedColor == color;
}
