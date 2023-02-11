const express = require('express');
const router = express.Router();

function checkAuthentication(req, res, next) {
    array = atob(String(req.headers.authorization).split(' ')[1])
    array1 = array.split(':');

    username = array1[0];
    password = array1[1];

    if (username === "admin" && password === "admin") {
        return next();
    }

    res.set("WWW-Authenticate", 'Basic realm="Restricted Area"');
    res.status(401).send("Not authorized");
}

router.get('/protected', checkAuthentication, (req, res) => {
    res.send("Welcome, authenticated client")
})

module.exports = router;