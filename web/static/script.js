// Modern Interactive UI Enhancements
document.addEventListener("DOMContentLoaded", function () {

    // 1️⃣ Smooth Page Fade-In
    document.body.style.opacity = "1";

    // 2️⃣ Enhanced Card Hover Effects
    const cards = document.querySelectorAll(".card");
    
    cards.forEach(function(card) {
        // Add subtle pulse animation to first card
        if (card === cards[0]) {
            card.classList.add("pulse-animation");
        }

        card.addEventListener("mouseenter", function() {
            this.style.transform = "translateY(-8px) scale(1.02)";
            this.style.boxShadow = "0 15px 30px rgba(37, 99, 235, 0.2)";
        });

        card.addEventListener("mouseleave", function() {
            this.style.transform = "translateY(0) scale(1)";
            this.style.boxShadow = "0 4px 6px -1px rgba(0, 0, 0, 0.1)";
        });
    });

    // 3️⃣ Enhanced Table Interactions
    const rows = document.querySelectorAll("table tbody tr");

    rows.forEach(function(row) {
        row.addEventListener("mouseenter", function() {
            this.style.backgroundColor = "rgba(37, 99, 235, 0.1)";
            this.style.transform = "translateX(4px)";
            this.style.transition = "all 0.3s ease";
        });

        row.addEventListener("mouseleave", function() {
            this.style.backgroundColor = "";
            this.style.transform = "translateX(0)";
        });
    });

    // 4️⃣ Button Ripple Effect
    const buttons = document.querySelectorAll(".button");
    
    buttons.forEach(function(button) {
        button.addEventListener("click", function(e) {
            let ripple = document.createElement('span');
            ripple.classList.add('ripple');
            this.appendChild(ripple);
            
            let x = e.clientX - e.target.offsetLeft;
            let y = e.clientY - e.target.offsetTop;
            
            ripple.style.left = x + 'px';
            ripple.style.top = y + 'px';
            
            setTimeout(() => {
                ripple.remove();
            }, 600);
        });
    });

    // 5️⃣ Scroll Animation for Cards
    const observerOptions = {
        threshold: 0.1,
        rootMargin: "0px 0px -50px 0px"
    };

    const observer = new IntersectionObserver(function(entries) {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                entry.target.style.opacity = "1";
                entry.target.style.transform = "translateY(0)";
            }
        });
    }, observerOptions);

    // Observe all cards for scroll animation
    document.querySelectorAll('.card').forEach(card => {
        card.style.opacity = "0";
        card.style.transform = "translateY(20px)";
        card.style.transition = "opacity 0.6s ease, transform 0.6s ease";
        observer.observe(card);
    });

    // 6️⃣ Header Sticky Effect
    const header = document.querySelector('header');
    if (header) {
        window.addEventListener('scroll', () => {
            if (window.scrollY > 50) {
                header.style.background = "rgba(255, 255, 255, 0.95)";
                header.style.boxShadow = "0 2px 10px rgba(0,0,0,0.1)";
            } else {
                header.style.background = "var(--card-bg)";
                header.style.boxShadow = "none";
            }
        });
    }

    // 7️⃣ Loading Animation for Data Tables
    const tables = document.querySelectorAll('table');
    tables.forEach(table => {
        table.style.opacity = "0";
        table.style.transform = "translateY(20px)";
        table.style.transition = "opacity 0.5s ease, transform 0.5s ease";
        
        setTimeout(() => {
            table.style.opacity = "1";
            table.style.transform = "translateY(0)";
        }, 200);
    });
});
