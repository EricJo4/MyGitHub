/********************************************************************************
* WEB322 – Assignment 02
*
* I declare that this assignment is my own work in accordance with Seneca's
* Academic Integrity Policy:
*
* https://www.senecacollege.ca/about/policies/academic-integrity-policy.html
*
* Name: Eric Jo Student ID: 137057188 Date: Sep 29, 2023
*
********************************************************************************/
const setData = require("../data/setData");
const themeData = require("../data/themeData");

let sets = [];

initialize = function(){
  
    setData.forEach(object =>{
        const found_id = themeData.find(element => element.id === object.theme_id);

        const setTheme = {
            ...object,
            theme: found_id? found_id.name: "Unknown"
        };
        sets.push(setTheme);
    })
    return new Promise((resolve, reject)=>{
        resolve();
});
};

getAllSets = function(){
    return new Promise((resolve, reject)=>{
        resolve(sets);
    });
};

getSetByNum = function(setNum){
    const found_setNum = sets.find(element => element.set_num === setNum);
    return new Promise((resolve, reject)=>{
        if(found_setNum){
            resolve(found_setNum);
        } else{
            reject("Unable to find setNum");
        }
    });
};

getSetsByTheme = function(theme){
    const found_theme = sets.filter(element => element.theme.toLowerCase().includes(theme.toLowerCase()));
    return new Promise((resolve,reject)=>{
        if(found_theme){
            resolve(found_theme);
        } else{
            reject("Unable to find theme");
        }
    });
}


module.exports = {initialize, getAllSets, getSetByNum, getSetsByTheme};