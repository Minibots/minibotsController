var http = require('http');
var fs = require('fs');
var express = require("express");
var bodyParser = require("body-parser");
var app = express();
var portNo = 5005;


app.use(bodyParser.urlencoded({ extended: false }));

app.use('/', express.static(__dirname+'/'));

app.all('*', function(req,res){
	console.log(req.body);
	res.send("Passback");
	res.end("yes");
});

app.listen(portNo, function() { 
	console.log('Check Port ' + portNo + '....');
});

