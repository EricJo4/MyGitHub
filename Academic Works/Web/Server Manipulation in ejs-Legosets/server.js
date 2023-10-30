/********************************************************************************
* WEB322 – Assignment 04
*
* I declare that this assignment is my own work in accordance with Seneca's
* Academic Integrity Policy:
*
* https://www.senecacollege.ca/about/policies/academic-integrity-policy.html
*
* Name: Eric Jo Student ID: 137057188 Date: Oct 30, 2023
*
* Published URL: ___________________________________________________________
*
********************************************************************************/
const legoData = require("./modules/legoSets");
const path = require('path');
const express = require('express');
const app = express();

const HTTP_PORT = process.env.PORT || 3030;

app.use(express.static("public"));



app.set("view engine", "ejs");


app.get("/", (req, res)=>{
    res.render("home");
});

app.get("/about", (req, res)=>{
    res.render("about");
});

app.get("/lego/sets", async (req, res)=>{
    try{
        let allLegoSets = await legoData.getAllSets();
        const theme = req.query.theme;
    
        if(theme) {
            const filteredSets = await legoData.getSetsByTheme(theme);
            if(filteredSets.length === 0){
                throw new Error ("No matched results");
            }
            res.render("sets",{sets:filteredSets});
        } else{
            res.render("sets",{sets:allLegoSets});
        }
    } catch(error){
        res.status(404).render("404", {message: "Unable to find requested sets"});
    }
})


app.get("/lego/sets/:setNum", async (req, res)=>{
    try{
        const setNum = req.params.setNum;
        const result = await legoData.getSetByNum(setNum);
        if(result) {
            res.render("set", {set: result});
        } else{
            throw new Error("No matching result");
        }
    } catch(err){
        res.status(404).render("404", {message: "Unable to find requested set"});
    }
})

app.use((req, res, next) =>{
    res.status(404).render("404", {message:"I'm sorry, we're unable to find what you're looking for"});
    next();
})

legoData.initialize().then(()=>{
    app.listen(HTTP_PORT, ()=>{
        console.log(`server listening on: ${HTTP_PORT}`);
    })
}).catch(err=>{
        console.log(`unable to start the server: + ${err}`);
    });
