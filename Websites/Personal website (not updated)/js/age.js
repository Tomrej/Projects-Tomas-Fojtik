function age() {
    var today = new Date();
    var age = document.getElementById("age");

    var year = 2007;
    var month = 7;
    var day = 14;
    var hour = 14;

    var current_year = today.getFullYear();
    var current_month = today.getMonth() + 1;
    var current_day = today.getDate();
    var current_hour = today.getHours();
    var current_minute = today.getMinutes();
    var current_second = today.getSeconds();

    var years = current_year - year;
    var months = current_month - month;
    var days = current_day - day;
    var hours = current_hour - hour;

    if (months < 0 || (months === 0 && current_day < day)) {
        years--;
        months += 12;
    }
    if (days < 0) {
        months--;
        var daysInLastMonth = new Date(current_year, current_month - 1, 0).getDate();
        days += daysInLastMonth;
    }
    if (hours < 0) {
        days--;
        hours += 24;
    }

    age.innerHTML = "<p><b class=\"gradient\">Jsem starý:</b> " + years + " let, " + months + " měsíců, " + days + " dnů, " + hours + " hodin, " + current_minute + " minut, " + current_second + " sekund." + "</p>";
}

age();
setInterval(age, 1000);
