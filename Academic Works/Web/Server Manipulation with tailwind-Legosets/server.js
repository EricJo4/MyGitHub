/********************************************************************************
* WEB322 – Assignment 03
*
* I declare that this assignment is my own work in accordance with Seneca's
* Academic Integrity Policy:
*
* https://www.senecacollege.ca/about/policies/academic-integrity-policy.html
*
* Name: Eric Jo Student ID: 137057188 Date: Oct 13, 2023
*
* Published URL: https://bewildered-outfit-goat.cyclic.cloud
*
********************************************************************************/
const legoData = require("./modules/legoSets");
const path = require('path');
const express = require('express');
const app = express();

const HTTP_PORT = process.env.PORT || 3030;

app.use(express.static("public"));

app.get("/", (req, res)=>{
    res.sendFile(path.join(__dirname, "/views/home.html"));
});

app.get("/about", (req, res)=>{
    res.sendFile(path.join(__dirname, "/views/about.html"));
});

app.get("/lego/sets", async (req, res)=>{
    try{
        let allLegoSets = await legoData.getAllSets();
        const theme = req.query.theme;
    
        if(theme) {
            const filteredSets = await legoData.getSetsByTheme(theme);
            res.send(filteredSets);
        } else{
            res.send(allLegoSets);
        }
    } catch(error){
        res.status(404).sendFile(path.join(__dirname, "/views/404.html"));
    }
})


app.get("/lego/sets/:setNum", async (req, res)=>{
    try{
        const setNum = req.params.setNum;
        const result = await legoData.getSetByNum(setNum);
        if(result) {
            res.send(result);
        } else{
            res.status(404).sendFile(path(__dirname, "/views/404.html"));
        }
    } catch(err){
        res.status(404).sendFile(path(__dirname, "/views/404.html"));
    }
})


legoData.initialize().then(()=>{
    app.listen(HTTP_PORT, ()=>{
        console.log(`server listening on: ${HTTP_PORT}`);
    })
}).catch(err=>{
        console.log(`unable to start the server: + ${err}`);
    });
