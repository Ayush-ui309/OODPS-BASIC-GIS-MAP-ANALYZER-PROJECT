#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base Class
class GeoObject {
protected:
    int id;
    string name;

public:
    GeoObject(int id, string name);
    virtual void display() = 0;
    int getID();
    string getName();
};

// Point Class
class Point : public GeoObject {
private:
    double x;
    double y;

public:
    Point(int id, string name, double x, double y);

    double getX();
    double getY();

    void display();
};

// Line Class
class Line : public GeoObject {
private:
    Point p1;
    Point p2;

public:
    Line(int id, string name, Point p1, Point p2);

    double calculateDistance();
    string getPointsString();

    void display();
};

// Polygon Class
class Polygon : public GeoObject {
private:
    vector<Point> vertices;

public:
    Polygon(int id, string name, vector<Point> vertices);

    double calculateArea();
    string getPointsString();

    void display();
};

// MapLayer Class
class MapLayer {
private:
    vector<GeoObject*> objects;

public:
    void addObject(GeoObject* obj);
    void displayObjects();
    int totalObjects();
    double largestPolygonArea();
};
