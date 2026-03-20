// Wait until the page loads
document.addEventListener("DOMContentLoaded", function () {

    // 1️⃣ Smooth Page Fade-In
    document.body.style.opacity = "1";


    // 2️⃣ Card Hover Effect (for dashboard boxes)
    const cards = document.querySelectorAll(".card");

    cards.forEach(function(card) {
        card.addEventListener("mouseover", function() {
            card.style.transform = "translateY(-5px)";
            card.style.transition = "0.2s";
        });

        card.addEventListener("mouseout", function() {
            card.style.transform = "translateY(0)";
        });
    });


    // 3️⃣ Table Row Highlight (for data page)
    const rows = document.querySelectorAll("table tr");

    rows.forEach(function(row) {
        row.addEventListener("mouseover", function() {
            row.style.backgroundColor = "#e6f0ff";
        });

        row.addEventListener("mouseout", function() {
            row.style.backgroundColor = "";
        });
    });

});
