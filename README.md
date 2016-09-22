#Minibots Controller

This controller is designed to control a robot with a mobile device over Wi-Fi!

## To upload it to a ESP8266:
To setup the environment, please follow these [instructions](https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/installing-the-esp8266-arduino-addon).

Once the environment is setup, please connect the ESP8266 to the computer. Instructions for that depend on the module, and the programmer used.

Open the esp8266_code project with the Arduino IDE and upload! Make sure that the board selected is the Generic ESP8266 and the serial port is correct!

## To test the project on your computer:

These commands tested with node v5.10.0 and npm 3.8.5. (Use *node -v* to find out which version you have).

```
git clone https://github.com/Minibots/minibotsController.git

cd minibotsController/

npm install

npm start
```

Then navigate to http://localhost:5005 in your web browser.

## To build from source:

The robot requires a single file webpage. The code will be minified and combined into a single HTML file. To build this, you need to have Node.js.


Make sure you have run the install command:

```
npm install
```

Then you can create the compressed file by running:
```
node compress.js
```

or Unix users can use the bash script ```compress.sh```

Note that this will update the file compressed.html as well as the file esp8266_code.ino

## Troubleshooting

Note that on some machines, the ``` node ``` command may not work properly. It may be that you have a different version of Node.js installed. Try running ``` nodejs ``` instead.

## Acknowledgments
This project used jQuery at one point in time. It does not anymore however. You can see their license at [http://jquery.org/license](http://jquery.org/license).
