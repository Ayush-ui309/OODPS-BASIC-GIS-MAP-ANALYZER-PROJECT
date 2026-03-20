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
    points=0;
    lines=0;
    polygons=0;

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

            line_count = 0
            poly_count = 0

            for row in reader:

                if row[0] == "Point":
                    points.append(row)

                elif row[0] == "Line":
                    line_count += 1

                    if line_count == 1:
                        points_taken = "P1 → P2"
                    elif line_count == 2:
                        points_taken = "P3 → P4"
                    else:
                        points_taken = "-"

                    row.append(points_taken)
                    lines.append(row)

                elif row[0] == "Polygon":
                    poly_count += 1

                    if poly_count == 1:
                        points_taken = "P1, P2, P3"
                    elif poly_count == 2:
                        points_taken = "P2, P3, P4, P5"
                    elif poly_count == 3:
                        points_taken = "P1, P3, P5, P2, P4"
                    else:
                        points_taken = "-"

                    row.append(points_taken)
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
