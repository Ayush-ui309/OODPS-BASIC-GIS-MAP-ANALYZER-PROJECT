#include <fstream>
#include <iostream>
#include <vector>
#include "classes.h"

using namespace std;

int main() {

    MapLayer layer;

    // Create Points
    Point p1(1,"A",10,20);
    Point p2(2,"B",30,40);
    Point p3(3,"C",20,10);
    Point p4(4,"D",50,60);
    Point p5(5,"E",70,30);

    // Create Lines
    Line l1(6,"line1",p1,p3);
    Line l2(7,"line2",p3,p4);

    // Polygon 1 (Triangle)
    vector<Point> polyPoints1;
    polyPoints1.push_back(p1);
    polyPoints1.push_back(p2);
    polyPoints1.push_back(p3);
    Polygon poly1(8,"Triangle",polyPoints1);

    // Polygon 2 (Quadrilateral)
    vector<Point> polyPoints2;
    polyPoints2.push_back(p2);
    polyPoints2.push_back(p1);
    polyPoints2.push_back(p4);
    polyPoints2.push_back(p3);
    Polygon poly2(9,"Quadrilateral",polyPoints2);

    // Polygon 3 pentagon
    vector<Point> polyPoints3;
    polyPoints3.push_back(p1);
    polyPoints3.push_back(p4);
    polyPoints3.push_back(p5);
    polyPoints3.push_back(p2);
    polyPoints3.push_back(p3);
    Polygon poly3(10,"pentagon",polyPoints3);

    // Add objects to MapLayer (Using Pointer)
    layer.addObject(&p1);
    layer.addObject(&p2);
    layer.addObject(&p3);
    layer.addObject(&p4);
    layer.addObject(&p5);

    layer.addObject(&l1);
    layer.addObject(&l2);

    layer.addObject(&poly1);
    layer.addObject(&poly2);
    layer.addObject(&poly3);

    // Display all objects
    layer.displayObjects();
    cout << "Total GeoObjects in MapLayer: " << layer.totalObjects() << endl;
    cout << "Largest Polygon Area in MapLayer: " << layer.largestPolygonArea() << endl;
    ofstream file("data.csv");

// Header
file << "Type,ID,Name,X1,Y1,Value,Points" << endl;

/* =======================
   WRITE POINTS
======================= */

file << "Point," << p1.getID() << "," << p1.getName()
     << "," << p1.getX() << "," << p1.getY()
     << ",,\"(" << p1.getX() << ", " << p1.getY() << ")\"" << endl;

file << "Point," << p2.getID() << "," << p2.getName()
     << "," << p2.getX() << "," << p2.getY()
     << ",,\"(" << p2.getX() << ", " << p2.getY() << ")\"" << endl;

file << "Point," << p3.getID() << "," << p3.getName()
     << "," << p3.getX() << "," << p3.getY()
     << ",,\"(" << p3.getX() << ", " << p3.getY() << ")\"" << endl;

file << "Point," << p4.getID() << "," << p4.getName()
     << "," << p4.getX() << "," << p4.getY()
     << ",,\"(" << p4.getX() << ", " << p4.getY() << ")\"" << endl;

file << "Point," << p5.getID() << "," << p5.getName()
     << "," << p5.getX() << "," << p5.getY()
     << ",,\"(" << p5.getX() << ", " << p5.getY() << ")\"" << endl;

/* =======================
   WRITE LINES
======================= */

file << "Line," << l1.getID() << "," << l1.getName()
     << "," << l1.calculateDistance()
     << ",,\"" << l1.getPointsString() << "\"" << endl;

file << "Line," << l2.getID() << "," << l2.getName()
     << "," << l2.calculateDistance()
     << ",,\"" << l2.getPointsString() << "\"" << endl;

/* =======================
   WRITE POLYGONS
======================= */

file << "Polygon," << poly1.getID() << "," << poly1.getName()
     << "," << poly1.calculateArea()
     << ",,\"" << poly1.getPointsString() << "\"" << endl;

file << "Polygon," << poly2.getID() << "," << poly2.getName()
     << "," << poly2.calculateArea()
     << ",,\"" << poly2.getPointsString() << "\"" << endl;

file << "Polygon," << poly3.getID() << "," << poly3.getName()
     << "," << poly3.calculateArea()
     << ",,\"" << poly3.getPointsString() << "\"" << endl;

file.close();


    return 0;
}