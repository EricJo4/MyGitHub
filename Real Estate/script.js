document.getElementById('ContactForm'). addEventListener('submit', function(event){
    event.preventDefault();//data is not sent to the server until it passes all criteria.
    const emailPattern = /^[a-zA-Z0-9]+@[a-zA-z0-9]+\.[a-zA-Z]{2,}$/;
    const phonePattern = /^\d{3}-\d{3}-\d{4}/;
    const typeOfPropertyPattern = /^[Cc][Oo][Nn][Dd][Oo]|[Hh][Oo][Uu][Ss][Ee]/;
    const numberOfBedroomsPattern = /^[1-9]-[1-9]$/;
    const priceRangePattern = /^\d{6,7}-\d{6,7}$/;


    const firstName = document.getElementById('firstname').value;
    const lastName = document.getElementById('lastname').value;
    const email = document.getElementById('email').value;
    const phone = document.getElementById('phone').value;
    const ToP = document.getElementById('ToP').value;
    const NoB = document.getElementById('NoB').value;
    const PR = document.getElementById('PR').value;

    if(!firstName||!lastName||!email||!phone||!ToP||!NoB||!PR){
        alert("All fields are mandatory. Please fill out all the fields.");
        return;
    }
    if(!emailPattern.test(email)){
        alert("Invalid Email format");
        return;
    }
    if(!phonePattern.test(phone)){
        alert("Please input valid phone format(xxx-xxx-xxxx)");
        return;
    }
    if(!typeOfPropertyPattern.test(ToP)){
        alert("Please input valid type of property(Condo or House)");
        return;
    }
    if(!numberOfBedroomsPattern.test(NoB)){
        alert("Please input valid format(1-3)");
        return;
    }
    if(!priceRangePattern.test(PR)){
        alert("Please input valid format(100000-9999999)");
        return;
    }

    alert("Thanks for contacting us. You will get the reply as soon as possible.");
    return;

});