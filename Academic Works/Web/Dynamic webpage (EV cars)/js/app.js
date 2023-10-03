/**
 * WEB222 – Assignment 04
 *
 * I declare that this assignment is my own work in accordance with
 * Seneca Academic Policy. No part of this assignment has been
 * copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Please update the following with your information:
 *
 *      Name:       Eric Jo
 *      Student ID: 137057188
 *      Date:       23 July 2022
 */

// All of our data is available on the global `window` object.
// Create local variables to work with it in this file.
const { products, categories } = window;

// Here, we create arrays of descriptions for Tesla, Porsche, Ford, GM, Benz, and Volkswagen EV cars respectively
let TeslaArr = [];
let PorscheArr = [];
let FordArr = [];
let GMArr = [];
let BenzArr = [];
let VolksArr = [];

for (let i = 0; i < products.length; i++) {
  products[i].categories.forEach(function (element) {
    if (element === "RODM-TESLA" && products[i].discontinued === false) {
      TeslaArr.push(products[i].description);
    } 
    else if (element === "RODM-PORSCHE" && products[i].discontinued === false) {
      PorscheArr.push(products[i].description);
    } 
    else if (element === "RODM-FORD" && products[i].discontinued === false) {
      FordArr.push(products[i].description);
    } 
    else if (element === "RODM-GM" && products[i].discontinued === false) {
      GMArr.push(products[i].description);
    } 
    else if (element === "RODM-BENZ" && products[i].discontinued === false) {
      BenzArr.push(products[i].description);
    } 
    else if (element === "RODM-Volks" && products[i].discontinued === false) {
      VolksArr.push(products[i].description);
    }
  });
}

// Creating the navbar dynamically
let menu = document.getElementById("menu");
for (let i = 0; i < categories.length; i++) {
  let newMenuItem = document.createElement("button");
  newMenuItem.textContent = categories[i].name;
  newMenuItem.id = categories[i].name;
  menu.appendChild(newMenuItem);
}

// Prints the description of product
function descriptionPrinter(category) {
  // Whenever the user clicks on an element, the program prints the description of the product to the console
  let tableRows = document.getElementsByClassName("tbl-row");

  // Using the length as per the category and printing description by using the parallel array concept
  if (category === "RODM-TESLA") {
    for (let i = 0; i < TeslaArr.length; i++) {
      tableRows[i].addEventListener("click", function () {
        console.log(TeslaArr[i]);
      });
    }
  } else if (category === "RODM-PORSCHE") {
    for (let i = 0; i < PorscheArr.length; i++) {
      tableRows[i].addEventListener("click", function () {
        console.log(PorscheArr[i]);
      });
    }
  } else if (category === "RODM-FORD") {
    for (let i = 0; i < FordArr.length; i++) {
      tableRows[i].addEventListener("click", function () {
        console.log(FordArr[i]);
      });
    }
  } else if (category === "RODM-GM") {
    for (let i = 0; i < GMArr.length; i++) {
      tableRows[i].addEventListener("click", function () {
        console.log(GMArr[i]);
      });
    }
  } else if (category === "RODM-BENZ") {
    for (let i = 0; i < BenzArr.length; i++) {
      tableRows[i].addEventListener("click", function () {
        console.log(BenzArr[i]);
      });
    }
  } else if (category === "RODM-VOLKS") {
    for (let i = 0; i < VolksArr.length; i++) {
      tableRows[i].addEventListener("click", function () {
        console.log(VolksArr[i]);
      });
    }
  }
}

// Creates all the cells for a particular category
function createCells(category) {
  // Fetching the tbody element
  var tbodyRef = document.getElementById("categoryProducts");
  var newRow, newCell, newText;

  // Iterating through the products and creating rows
  for (let i = 0; i < products.length; i++) {
    // creates a table row
    document.createElement("tr");

    // Iterating over array
    products[i].categories.forEach(function (element) {
      if (element === category && products[i].discontinued === false) {
        newRow = tbodyRef.insertRow();
        newRow.className = "tbl-row";

        // Insert a cell at the end of the row
        newCell = newRow.insertCell();
        // Append a text node to the cell
        newText = document.createTextNode(products[i].title);
        newCell.appendChild(newText);

        // Insert a cell at the end of the row
        newCell = newRow.insertCell();
        newCell.id = i;
        // Append a text node to the cell
        newText = document.createTextNode(products[i].description);
        newCell.appendChild(newText);

        // Insert a cell at the end of the row
        newCell = newRow.insertCell();
        // Append a text node to the cell
        newText = document.createTextNode(
          (products[i].price / 100).toLocaleString("en-CA", {
            currency: "CAD",
            style: "currency",
          })
        ); // Converting to Canadian Currency
        newCell.appendChild(newText);
      }
    });
  }
}

// Display Tesla by default
document.getElementById("categoryProducts").innerHTML = "";
document.getElementById("selected-category").textContent = "Tesla";
createCells("RODM-TESLA");

// Function that shows a product list based on category and update the heading
function showProductList(category) {
  // Clearing all the elements so that they dont stay
  document.getElementById("categoryProducts").innerHTML = "";

  // Changing the human readable names to IDs
  for (let k = 0; k < categories.length; k++) {
    if (categories[k].name === category) {
      category = categories[k].id;
    }
  }

  // Creating cells for categories
  createCells(category);
  descriptionPrinter(category);
}

// Change the heading and show product list
let menuArr = document.querySelector("#menu").querySelectorAll("button");
for (let i = 0; i < menuArr.length; i++) {
  menuArr[i].addEventListener("click", function () {
    document.getElementById("selected-category").innerHTML =
      menuArr[i].textContent;
    showProductList(menuArr[i].textContent);
  });
}

// As the default category is Tesla, we call the function by passing 'Tesla' as the category
descriptionPrinter("RODM-TSLA");
