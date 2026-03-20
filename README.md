# Basic GIS Map Analyzer

## Introduction
The **Basic GIS Map Analyzer** is an educational end-to-end project that demonstrates core **Object-Oriented Programming (OOP)** concepts in **C++** and visualizes computed GIS-style metrics using a **Flask** web dashboard.  
The C++ program models **Points**, **Lines**, and **Polygons**, computes basic metrics, exports results to a **CSV** file, and the Flask app reads that CSV to render a dashboard.

## Problem Statement
Build a simple GIS-style analyzer that:
1. Uses OOP concepts in C++ to model geographic objects.
2. Computes basic metrics:
   - Line distance
   - Polygon area
3. Exports computed results to a CSV file.
4. Displays the results in a Flask-based web dashboard.

## Features
- OOP modeling of `Point`, `Line`, `Polygon`, and `MapLayer`
- Runtime polymorphism using a virtual base method (`GeoObject::display()`)
- CSV export of computed values
- Flask dashboard with:
  - Home summary
  - Data view tables
  - Statistics (total objects, largest polygon area, per-polygon areas)
- Clear separation between the C++ backend and the Flask frontend

## Technologies Used
- C++
- Flask (Python)
- CSV (file handling with Python `csv.reader`)
- HTML/CSS/JavaScript for the dashboard UI

## Project Architecture
- **C++ Backend (`cpp/`)**
  - Creates geometric objects (points/lines/polygons)
  - Uses `MapLayer` to store objects and demonstrate polymorphic behavior
  - Computes:
    - `Line::calculateDistance()`
    - `Polygon::calculateArea()`
  - Writes results to `cpp/data.csv`

- **Flask Dashboard (`web/`)**
  - Reads `../cpp/data.csv`
  - Provides routes that render templates:
    - `/home` (summary)
    - `/data` (tables)
    - `/stats` (statistics)

## OOP Concepts Used
- **Inheritance**
  - `Point`, `Line`, and `Polygon` inherit from the base class `GeoObject`
- **Polymorphism**
  - `GeoObject` defines a pure virtual function `display()`
  - `MapLayer` stores `GeoObject*` and calls `display()` polymorphically
  - `largestPolygonArea()` uses runtime type checks (`dynamic_cast`) to operate on polygons
- **Encapsulation**
  - Geometry data fields are kept `private` / `protected`
  - Access is provided through getter methods and class methods

## File Structure
```
GIS_PROJECT/
+-- cpp/
|   +-- main.cpp
|   +-- classes.h
|   +-- classes.cpp
|   +-- data.csv
+-- web/
|   +-- app.py
|   +-- templates/
|   |   +-- intro.html
|   |   +-- index.html
|   |   +-- data_view.html
|   |   +-- stats.html
|   +-- static/
|       +-- style.css
|       +-- script.js
+-- README.md
```

## How to Run the Project

### 1) Build and run the C++ backend
From the project root:
```bash
cd cpp
g++ main.cpp classes.cpp -o gis
./gis
```
This generates or updates `cpp/data.csv`.

### 2) Run the Flask dashboard
Open a new terminal from the project root:
```bash
cd web
python app.py
```
Then open:
- `http://127.0.0.1:5000/` (intro)
- `http://127.0.0.1:5000/home` (dashboard)
- `http://127.0.0.1:5000/data` (data view)
- `http://127.0.0.1:5000/stats` (statistics)

## Screenshots
- Home Page: *(add screenshot here)*
- Data View: *(add screenshot here)*
- Statistics Page: *(add screenshot here)*

## Conclusion
This project demonstrates a complete educational workflow: **OOP-based GIS modeling and computation in C++**, exporting results to **CSV**, and presenting them in a **Flask dashboard** for interactive viewing and evaluation.