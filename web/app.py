from flask import Flask, render_template
import csv
import os

app = Flask(__name__)

CSV_FILE = "../cpp/data.csv"

@app.route('/')
def intro():
    return render_template("intro.html")


# ================= HOME PAGE =================
@app.route('/home')
def home():
    total_records = 0
    points=0
    lines=0
    polygons=0

    if os.path.exists(CSV_FILE):
        with open(CSV_FILE, newline='') as file:
            reader = csv.reader(file)
            rows = list(reader)
            total_records = len(rows) - 1
            for row in rows[1:]:
                object_type = row[0]
                if object_type == "Point":
                    points += 1
                elif object_type == "Line":
                    lines += 1
                elif object_type == "Polygon":
                    polygons += 1        

    return render_template("index.html", total=total_records, points=points, lines=lines, polygons=polygons)


# ================= DATA VIEW PAGE =================
@app.route('/data')
def data_view():

    points = []
    lines = []
    polygons = []

    if os.path.exists(CSV_FILE):
        with open(CSV_FILE, newline='') as file:
            reader = csv.reader(file)
            next(reader, None)

            for row in reader:

                if row[0] == "Point":
                    points.append(row)

                elif row[0] == "Line":
                    lines.append(row)

                elif row[0] == "Polygon":
                    polygons.append(row)

    return render_template("data_view.html",
                           points=points,
                           lines=lines,
                           polygons=polygons)


# ================= STATISTICS PAGE =================
@app.route('/stats')
def stats():

    total_objects = 0
    largest_polygon = 0
    largest_polygon_name = ""
    polygons_area={}

    if os.path.exists(CSV_FILE):
        with open(CSV_FILE, newline='') as file:
            reader = csv.reader(file)
            next(reader, None)

            for row in reader:
                if row[0] in ["Point", "Line", "Polygon"]:
                    total_objects += 1

                if row[0] == "Polygon":
                    value = float(row[3])
                    name=row[2]
                    polygons_area[name] = value
                    name=row[2]
                    if value > largest_polygon:
                        largest_polygon = value
                        largest_polygon_name = name

    return render_template("stats.html",
                           total_objects=total_objects,
                           largest_polygon=largest_polygon,
                           largest_polygon_name=largest_polygon_name,
                           polygon_areas=polygons_area)


# ================= MAIN =================
if __name__ == "__main__":
    app.run(debug=True)
