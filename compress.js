//compress.js
//This file compresses index.html and its dependencies into compressed.html
var Inliner = require('inliner');
var fs = require('fs');

var outputFile = "esp8266_code/esp8266_code.ino"

new Inliner('index.html', function (error, html)
{
    if (error) throw error;
    while (html.indexOf('"') != -1)
	      html = html.replace('"',"'");

    console.log("The compressed code is " + html.length + " bytes.")
    
    fs.writeFile("compressed.html", html, function(err) {
    		if(err)
            console.log(err);
		    //console.log("Compressed!!! Checkout compressed.html");
  	});
    fs.readFile(outputFile, function(err, data) {
        if (err)
            console.log(err);
        var newCode = replaceCode(data, html);
        fs.writeFile(outputFile, newCode, function(err) {
            if(err)
                console.log(err);
            //console.log("Compressed!!! Checkout compressed.html");
        });
        
    });
});



function replaceCode(data, inputHTML)
{
    var doNotDeleteOne = "// << DO NOT DELETE THIS | 1 >>";
    var doNotDeleteTwo = "// << DO NOT DELETE THIS | 2 >>";
    var allLines = data.toString().split('\n');
    var firstNoDelete = -1;
    var secondNoDelete = -1;
    for (var i = 0; i < allLines.length; i++)
    {
        if (allLines[i].indexOf(doNotDeleteOne) != -1)
            firstNoDelete = i;
        if (allLines[i].indexOf(doNotDeleteTwo) != -1)
            secondNoDelete = i;
    }
    if (firstNoDelete >= doNotDeleteTwo || firstNoDelete != -1 || secondNoDelete != -1)
    {
        var replaceCode = 'const String rootHTML = "' + inputHTML + '";'
        allLines.splice(firstNoDelete + 1, secondNoDelete - firstNoDelete - 1, replaceCode);
        var newCode = allLines.join('\n');
        console.log("Updated " + outputFile + "!");
        return newCode;
    }
    else
    {
        console.log("The ESP8266 code was not replaced. There was a problem. The first No Delete:" + firstNoDelete + ". The second No Delete: " + secondNoDelete);
    }
    return data;
}
