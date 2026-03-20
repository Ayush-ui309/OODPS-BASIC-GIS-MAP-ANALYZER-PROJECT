#include "classes.h"
#include <iostream>
#include <cmath>

// GeoObject Constructor
GeoObject::GeoObject(int id, string name) {
    this->id = id;
    this->name = name;
}
int GeoObject::getID() {
    return id;
}
string GeoObject::getName() {
    return name;
}

// Point Constructor
Point::Point(int id, string name, double x, double y)
: GeoObject(id, name) {
    this->x = x;
    this->y = y;
}

double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

void Point::display() {
    cout << "Point ID: " << id << " Name: " << name
         << " (" << x << "," << y << ")" << endl;
}

// Line Constructor
Line::Line(int id, string name, Point p1, Point p2)
: GeoObject(id, name), p1(p1), p2(p2) {}

double Line::calculateDistance() {

    double x1 = p1.getX();
    double y1 = p1.getY();
    double x2 = p2.getX();
    double y2 = p2.getY();

    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

void Line::display() {

    cout << "Line ID: " << id << " Name: " << name << endl;
    cout << "Distance: " << calculateDistance() << endl;
}

// Polygon Constructor
Polygon::Polygon(int id, string name, vector<Point> vertices)
: GeoObject(id, name) {
    this->vertices = vertices;
}

double Polygon::calculateArea() {

    double area = 0;
    int n = vertices.size();

    for(int i=0;i<n;i++) {

        double x1 = vertices[i].getX();
        double y1 = vertices[i].getY();

        double x2 = vertices[(i+1)%n].getX();
        double y2 = vertices[(i+1)%n].getY();

        area = area + (x1*y2 - x2*y1);
    }

    if(area < 0)
        area = -area;

    return area/2;
}

void Polygon::display() {

    cout << "Polygon ID: " << id << " Name: " << name << endl;
    cout << "Area: " << calculateArea() << endl;
}

// MapLayer addObject
void MapLayer::addObject(GeoObject* obj) {
    objects.push_back(obj);
}

// MapLayer displayObjects
void MapLayer::displayObjects() {

    for(int i=0;i<objects.size();i++) {
        objects[i]->display();
    }
}

// MapLayer totalObjects
int MapLayer::totalObjects() {
    return objects.size();
}

// MapLayer largestPolygonArea
double MapLayer::largestPolygonArea() {

    double maxArea = 0;

    for(int i=0;i<objects.size();i++) {

        Polygon* p = dynamic_cast<Polygon*>(objects[i]);

        if(p != NULL) {

            double area = p->calculateArea();

            if(area > maxArea)
                maxArea = area;
        }
    }

    return maxArea;
}
