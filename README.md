# Basic GIS Map Analyzer

## Introduction
Basic GIS Map Analyzer is a small educational project that demonstrates core Object-Oriented Programming concepts in C++ and presents the generated GIS data through a Flask-based web dashboard. The C++ program models Points, Lines, and Polygons, writes the results to a CSV file, and the Flask app reads that CSV to display summaries, tables, and statistics.

## Problem Statement
Build a simple GIS-style analyzer that:
- Uses OOP principles in C++ to model geographic objects
- Computes basic metrics (line distance, polygon area)
- Stores results in a CSV file
- Displays the data in a web dashboard using Flask

## Features
- OOP modeling of Point, Line, Polygon, and MapLayer
- Polymorphic display of objects
- CSV export of computed values
- Flask dashboard with summary, data view, and statistics pages
- Clean separation of C++ backend and web frontend

## Technologies Used
- C++
- Flask (Python)
- CSV file handling
- HTML/CSS/JavaScript

## Project Architecture
- **C++ Backend**: Builds the GIS objects, computes values, and writes `cpp/data.csv`.
- **Flask Dashboard**: Reads `cpp/data.csv` and renders the dashboard in `web/`.

## OOP Concepts Used
- **Inheritance**: `Point`, `Line`, and `Polygon` inherit from `GeoObject`.
- **Polymorphism**: `GeoObject*` pointers in `MapLayer` call overridden `display()` methods.
- **Encapsulation**: Data members are protected/private with getter methods.

## File Structure
```
GIS_PROJECT/
+-- cpp/
¦   +-- main.cpp
¦   +-- classes.h
¦   +-- classes.cpp
¦   +-- data.csv
+-- web/
¦   +-- app.py
¦   +-- templates/
¦   ¦   +-- intro.html
¦   ¦   +-- index.html
¦   ¦   +-- data_view.html
¦   ¦   +-- stats.html
¦   +-- static/
¦       +-- style.css
¦       +-- script.js
+-- README.md
```

## How to Run (Step-by-Step)

### 1) Build and run the C++ program
From the project root:
```
cd cpp

g++ main.cpp classes.cpp -o gis

./gis
```
This generates or updates `cpp/data.csv`.

### 2) Run the Flask dashboard
From the project root:
```
cd web

python app.py
```
Open in browser:
- `http://127.0.0.1:5000/`

## Screenshots
- Home Page: *(add screenshot here)*
- Data View: *(add screenshot here)*
- Statistics Page: *(add screenshot here)*

## Conclusion
This project demonstrates a complete flow from OOP-based C++ modeling to a Flask web interface, showing how computed GIS data can be exported to CSV and visualized through a simple dashboard.