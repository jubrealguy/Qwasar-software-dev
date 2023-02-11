const express = require('express');
const pubroute = require("./routes/public.js")
const protectedroute = require("./routes/protected")
const app = express();

app.use('/', pubroute);
app.use('/', protectedroute);

app.get('/', function(req, res) {
    
    const frankSong = ["Ac-cent-tchu-ate the Positive", "Accidents Will Happen", "Adeste Fideles", "Ad-Lib Blues", "An Affair to Remember (Our Love Affair)", "After You've Gone", "Ain't She Sweet", "Ain't Cha Ever Comin Back?", "Air For English Horn", "Alice Blue Gown", "All Alone", "All By Myself", "All I Do Is Dream of You", "All I Need is the Girl", "All My Tomorrows", "All of Me", "All of You", "All or Nothing at All", "All the Things You Are", "All the Way"];

    let rand = Math.floor(Math.random() * frankSong.length);

    res.send(frankSong[rand]);
})

app.get('/birth_date', (req, res) => {
    res.send("December 12, 1915")
})

app.get('/birth_city', (req, res) => {
    res.send("Hoboken, New Jersey")
})

app.get('/wives', (req, res) => {
    const wives = ["Nancy Barbato", "Ava Gardner", "Mia Farrow", "Barbara Marx"]
    res.send(wives[0] + ", " + wives[1] + ", " + wives[2] + ", " + wives[3]);
})

app.get('/picture', (req, res) => {
    const url = "https://en.wikipedia.org/wiki/Frank_Sinatra#/media/File:Frank_Sinatra2,_Pal_Joey.jpg"
    res.send('<img src =' + url + '>')
})

app.listen(8080);