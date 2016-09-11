//#define REVERSE_PINS_ALLOWED
#include <ESP8266WiFi.h>

const char WifiSSID[] = "Minibot";
const char WifiPassword[] = "awesomeRobot";

const char LEFT_FORWARD_MOTOR_PIN = 2;
const char RIGHT_FORWARD_MOTOR_PIN = 0;

#ifdef REVERSE_PINS_ALLOWED
const char LEFT_REVERSE_MOTOR_PIN = 3;
const char RIGHT_REVERSE_MOTOR_PIN = 1;
#endif //REVERSE_PINS_ALLOWED

const char PACKET_SIZE = 100;

// The code in between the tags below will be deleted when compress.js is called. compress.js uses line numbers. Ensure that the tags below are on their own lines.
// << DO NOT DELETE THIS | 1 >>
const String rootHTML = "<!DOCTYPE HTML> <html lang='en'> <head> <meta charset='utf-8'> <meta name='viewport' content='width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no'> <style> html{ margin:0;height:100%;}#joystickController{ padding:0;top:0;bottom:0;left:0;right:0;position:absolute;text-align:center;}#controllerTable{ position:absolute;top:0;bottom:0;left:0;right:0;height:100%;width:100%;}.controllerButton{ background-color:red;border:1px solid black;text-align:center;width:33.33333333333%;height:33.33333333333%;}#bottomGoBackButton{ position:fixed;bottom:0;left:0;display:none;}#homeScreen{ margin:8px;text-align:center;}#homeScreenTable{ margin-left:auto;margin-right:auto;}#controllerJoystickCanvas{ display:inline;}#keyboardController{ margin:8px;}#directionalStatus{ margin:8px;text-align:center;font-size:24px;}#buttonController{ display:none;}#joystickController{ display:none;}#keyboardController{ display:none;}#settingsTitle{ text-align:center;}#settingsController{ text-align:center;display:none;}.instructions{ font-size:small;}#bottomStatus{ position:fixed;bottom:0;//text-align:right;width:100%;}#bottomLastCommand{ float:right;margin-right:10px;}</style> <title>Minibots Controller</title> </head> <body> <div id='homeScreen'> Hello! Welcome to the minibots controller. Please select a method of controlling your minibot! <table id='homeScreenTable'> <tr> <td><button id='goToJoystick'>Joystick</button></td> <td><button id='goToButtons'>Buttons</button></td> </tr> <tr> <td><button id='goToKeyboard'>Keyboard</button></td> <td><button id='goToSettings'>Settings</button></td> </tr> </table> </div> <div id='buttonController'> <table id='controllerTable'> <tr> <td></td> <td id='forwardButton' class='controllerButton'>Forward</td> <td></td> </tr> <tr> <td id='leftButton' class='controllerButton'>Left</td> <td id='stopButton' class='controllerButton'>Stop</td> <td id='rightButton' class='controllerButton'>Right</td> </tr> <tr> <td id='goBackButton' class='controllerButton'>Go Back to Main Page</td> <td id='reverseButton' class='controllerButton'>Reverse</td> <td></td> </tr> </table> </div> <div id='joystickController'> <canvas id='controllerJoystickCanvas'> </canvas> </div> <div id='keyboardController'> Your keyboard can be a controller as well! <div class='instructions'> <table> <tr> <td>Up:</td> <td>UpArrow</td> <td>or</td> <td>W</td> </tr> <tr> <td>Down:</td> <td>DownArrow</td> <td>or</td> <td>S</td> </tr> <tr> <td>Left:</td> <td>LeftArrow</td> <td>or</td> <td>A</td> </tr> <tr> <td>Right:</td> <td>RightArrow</td> <td>or</td> <td>D</td> </tr> <td>Stop:</td> <td>Space</td> </table> </div> <br><br> <div id='directionalStatus'> This </div> </div> <div id='settingsController'> <h1>Settings</h1> To fix alignment:<br> <input type='range' id='alignRangeId'><br> <input type='number' id='alignNumberId'><br> <div class='instructions'> Negative numbers will pull the robot to the left.<br> Positive numbers will pull the robot to the right. </div> <br> <select id='modeSelector'> <option value='normal'>Normal</option> <option value='forwardOnly'>Forward Only</option> <option value='experimental'>Experimental</option> </select> <br> <br> <div id='leftRightStopController'> Left:<br> <input type='range' id='stopLeftRangeId'><br> <input type='number' id='stopLeftNumberId'><br> <br> Right:<br> <input type='range' id='stopRightRangeId'><br> <input type='number' id='stopRightNumberId'><br> </div> <br> The last command sent to the robot is shown at the bottom of the page!<br> It is shown with the notation (left, right) rounded to the nearest integer.<br> <br> You can find the code for this project <a href='https://github.com/Minibots/minibotsController'>here</a>. <br><br> </div> <div id='bottomStatus'> <button id='bottomGoBackButton'>Go Back</button> <span id='bottomLastCommand'></span> </div> <script type='text/javascript'>function initializeRangeNumberSystemWithId(e,t,o){var n=document.getElementById(t),l=document.getElementById(e);initializeRangeNumberSystem(l,n,o)}function loadLeftRightStopController(){localStorage.mode=modeSelector.value,'experimental'==modeSelector.value?showElement(leftRightStopController):hideElement(leftRightStopController)}function initializeRangeNumberSystem(e,t,o){localStorage[o]||(localStorage[o]=0),t.value=1*localStorage[o],e.value=1*localStorage[o]+50,onRangeNumberChange(e,t,o)}function onRangeNumberChange(e,t,o){var n;e.onchange=function(){n=t.value=e.value-50,localStorage[o]=n},t.onchange=function(){n=e.value=1*t.value+50,localStorage[o]=n}}function hideElement(e){e.style.display='none'}function showElement(e){e.style.display='block'}function functReset(e,t){var o=Math.min(window.innerWidth,window.innerHeight);context.canvas.width=4*o/5,context.canvas.height=4*o/5,drawBackground(),drawCenter(e,t)}function drawBackground(){var e=Math.min(canvas.width,canvas.height);context.beginPath(),context.lineWidth=4,context.arc(e/2,e/2,e/3,0,2*Math.PI),context.stroke()}function drawCenter(e,t){var o=Math.min(canvas.width,canvas.height);e==-1&&t==-1&&(e=o/2,t=o/2),context.beginPath(),context.lineWidth=3,context.arc(e,t,o/8,0,2*Math.PI),context.stroke()}function controllerDown(){functReset(-1,-1),moveRobot(0,0),clicked=!0}function controllerUp(){'none'!=document.getElementById('joystickController').style.display&&(functReset(-1,-1),moveRobot(0,0),clicked=!1)}function controllerMove(e){e.preventDefault();var t=mousePosition(canvas,e,mouse);moveController(t)}function moveController(e){var t=Math.min(canvas.width,canvas.height);functReset(e.x,e.y);var o=-(e.y-t/2)/(t/3),n=(e.x-t/2)/(t/3),l=100*n+100*o,c=-100*n+100*o;l>100&&(l=100),l<-100&&(l=-100),c>100&&(c=100),c<-100&&(c=-100),null!=l&&null!=c&&(moveRobot(l,c),count=0)}function mousePosition(e,t,o){var n=e.getBoundingClientRect();if(o)return{x:t.clientX-n.left,y:t.clientY-n.top};var l=t.targetTouches[0];return console.log(n.left),{x:l.pageX-n.left,y:l.pageY-n.top}}function moveRobot(e,t){1*localStorage.align<0&&(e*=1+1*localStorage.align/100),1*localStorage.align>0&&(t*=1-1*localStorage.align/100);var o=modeSelector.value;'forwardOnly'==o?(e<0&&(e=0),t<0&&(t=0)):'experimental'==o&&(e=1*localStorage.stopLeft+e,t=1*localStorage.stopRight+t);var n='left='+e+'&right='+t;document.getElementById('bottomLastCommand').innerHTML='('+Math.round(e)+', '+Math.round(t)+')',getData('/command',n,function(e){console.log(e)}),console.log(n)}function postData(e,t,o){var n=new XMLHttpRequest;n.open('POST',e,!0),n.setRequestHeader('Content-type','application/x-www-form-urlencoded'),n.onreadystatechange=function(){n.readyState==XMLHttpRequest.DONE&&200==n.status&&o(n.responseText)},n.send(t)}function getData(e,t,o){var n=new XMLHttpRequest;n.open('POST',e+'?'+t,!0),n.onload=function(){n.status<400&&n.status>=200&&o(n.responseText)},n.send(t)}var modeSelector=document.getElementById('modeSelector'),joystickController=document.getElementById('joystickController'),buttonController=document.getElementById('buttonController'),keyboardController=document.getElementById('keyboardController'),settingsController=document.getElementById('settingsController'),leftRightStopController=document.getElementById('leftRightStopController'),homeScreen=document.getElementById('homeScreen'),bottomGoBackButton=document.getElementById('bottomGoBackButton');initializeRangeNumberSystemWithId('alignRangeId','alignNumberId','align'),initializeRangeNumberSystemWithId('stopLeftRangeId','stopLeftNumberId','stopLeft'),initializeRangeNumberSystemWithId('stopRightRangeId','stopRightNumberId','stopRight'),localStorage.mode||(localStorage.mode='normal'),modeSelector.value=localStorage.mode,loadLeftRightStopController(),modeSelector.onchange=function(){loadLeftRightStopController()};var canvas=document.getElementById('controllerJoystickCanvas'),context=canvas.getContext('2d'),count=0;functReset(-1,-1),window.onresize=function(e){functReset(-1,-1)};var clicked=!1,mouse=!0;canvas.onmousedown=function(){mouse&&controllerDown()},window.onmouseup=function(){mouse&&controllerUp()},canvas.onmousemove=function(e){mouse=!0,clicked&&controllerMove(e)},canvas.addEventListener('touchstart',controllerDown,!1),canvas.addEventListener('touchend',controllerUp,!1),canvas.addEventListener('touchcancel',controllerUp,!1),canvas.addEventListener('touchmove',controllerMove,!1),canvas.addEventListener('touchmove',function(){mouse=!1},!1),document.getElementById('rightButton').onclick=function(){moveRobot(100,-100)},document.getElementById('forwardButton').onclick=function(){moveRobot(100,100)},document.getElementById('stopButton').onclick=function(){moveRobot(0,0)},document.getElementById('leftButton').onclick=function(){moveRobot(-100,100)},document.getElementById('reverseButton').onclick=function(){moveRobot(-100,-100)},document.getElementById('goBackButton').onclick=function(){hideElement(buttonController),showElement(homeScreen),hideElement(bottomGoBackButton)},document.getElementById('bottomGoBackButton').onclick=function(){hideElement(joystickController),hideElement(buttonController),hideElement(keyboardController),hideElement(settingsController),showElement(homeScreen),hideElement(bottomGoBackButton)},document.getElementById('goToButtons').onclick=function(){showElement(buttonController),hideElement(homeScreen),hideElement(bottomGoBackButton)},document.getElementById('goToJoystick').onclick=function(){showElement(joystickController),hideElement(homeScreen),showElement(bottomGoBackButton)},document.getElementById('goToKeyboard').onclick=function(){showElement(keyboardController),hideElement(homeScreen),showElement(bottomGoBackButton)},document.getElementById('goToSettings').onclick=function(){showElement(settingsController),hideElement(homeScreen),showElement(bottomGoBackButton)},window.onkeydown=function(e){'none'!=document.getElementById('keyboardController').style.display&&(39!=e.keyCode&&68!=e.keyCode||moveRobot(-100,100),38!=e.keyCode&&87!=e.keyCode||moveRobot(100,100),32==e.keyCode&&moveRobot(0,0),37!=e.keyCode&&65!=e.keyCode||moveRobot(100,-100),40!=e.keyCode&&83!=e.keyCode||moveRobot(-100,-100),document.getElementById('directionalStatus').innerHTML=e.keyCode)};</script> </body> </html> ";
// << DO NOT DELETE THIS | 2 >>

WiFiServer server(80);

void setup()
{
  Serial.begin(115200);

  //Setup WiFi
  WiFi.mode(WIFI_AP);
  WiFi.softAP(WifiSSID, WifiPassword);
  server.begin();

  //Setup pins
  pinMode(LEFT_FORWARD_MOTOR_PIN, OUTPUT);
  digitalWrite(LEFT_FORWARD_MOTOR_PIN, LOW);

  pinMode(RIGHT_FORWARD_MOTOR_PIN, OUTPUT);
  digitalWrite(RIGHT_FORWARD_MOTOR_PIN, LOW);
  
#ifdef REVERSE_PINS_ALLOWED
  pinMode(LEFT_REVERSE_MOTOR_PIN, OUTPUT);
  digitalWrite(LEFT_REVERSE_MOTOR_PIN, LOW);

  pinMode(RIGHT_REVERSE_MOTOR_PIN, OUTPUT);
  digitalWrite(RIGHT_REVERSE_MOTOR_PIN, LOW);
#endif //REVERSE_PINS_ALLOWED
  
}

void loop()
{
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }

  String request = client.readStringUntil('\r');

  Serial.println(request);

  int firstSpace = request.indexOf(' ');
  int secondSpace = request.indexOf(' ', firstSpace + 1);
  String url = request.substring(firstSpace + 1, secondSpace);

  Serial.println(url);

  double leftMotorPower = getDoubleParameter("left", url);
  double rightMotorPower = getDoubleParameter("right", url);

  Serial.println("Left: " + (String)leftMotorPower + " Right: " + (String)rightMotorPower);
  
#ifndef REVERSE_PINS_ALLOWED
  setPinPower(LEFT_FORWARD_MOTOR_PIN, leftMotorPower);
  setPinPower(RIGHT_FORWARD_MOTOR_PIN, rightMotorPower);
#else
  if (leftMotorPower > 0)
  {
    setPinPower(LEFT_FORWARD_MOTOR_PIN, leftMotorPower);
    setPinPower(LEFT_REVERSE_MOTOR_PIN, 0);
  }
  else
  {
    setPinPower(LEFT_FORWARD_MOTOR_PIN, 0);
    setPinPower(LEFT_REVERSE_MOTOR_PIN, -1*leftMotorPower);
  }

  if (rightMotorPower > 0)
  {
    setPinPower(RIGHT_FORWARD_MOTOR_PIN, rightMotorPower);
    setPinPower(RIGHT_REVERSE_MOTOR_PIN, 0);
  }
  else
  {
    setPinPower(RIGHT_FORWARD_MOTOR_PIN, 0);
    setPinPower(RIGHT_REVERSE_MOTOR_PIN, -1*rightMotorPower);
  }
#endif

  client.flush();
  if (url == "/")
  {
    String response = addHeaderAndFooter(rootHTML);
    int i = 0;
    while (1)
    {
      int endIndex = i + PACKET_SIZE;
      if (endIndex > response.length())
        endIndex = response.length();
      client.print(response.substring(i, endIndex));
      if (endIndex == response.length()) break;
      i += PACKET_SIZE;
    }
  }
  else
  {
    client.print("");
  }
  delay(1);
}

String addHeaderAndFooter(String input)
{
  String output = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
  output += input;
  output += "\n";
  return output;
}

void setPinPower(int pin, double power)
{
  const int MIN_PWM = 0;
  const int MAX_PWM = 1023;

  int pwm = (int)MAX_PWM*power;

  if (pwm > MAX_PWM)
    pwm = MAX_PWM;
  if (pwm < MIN_PWM)
    pwm = MIN_PWM;

  analogWrite(pin, pwm);
}


double getDoubleParameter(String parameterName, String url)
{
  return stringToDouble(getParameter(parameterName, url));
}

double getIntParameter(String parameterName, String url)
{
  return stringToInt(getParameter(parameterName, url));
}

String getParameter(String parameterName, String url)
{
  int questionMark = url.indexOf('?');
  if (questionMark == -1)
    return "";
  String parameters = url.substring(questionMark);

  int startOfParameterValue = parameters.indexOf("?" + parameterName + "=");
  if (startOfParameterValue == -1)
    startOfParameterValue = parameters.indexOf("&" + parameterName + "=");

  int startOfNextParameterName = parameters.indexOf('&', startOfParameterValue + 1);
  String parameterString;
  if (startOfNextParameterName == -1)
    parameterString = parameters.substring(startOfParameterValue + 1);
  else
    parameterString = parameters.substring(startOfParameterValue + 1, startOfNextParameterName);

  String parameterValue = parameterString;

  parameterValue.replace(parameterName + "=", "");
  return parameterValue;
}


int stringToInt(String inputString)
{
  int i = 0;
  if (inputString[0] == '-')
    i = 1;
  int output = 0;
  for (; i < inputString.length(); i++)
  {
    output = output*10 + ((int)inputString[i] - 48);
  }
  if (inputString[0] == '-')
    output *= -1;
  return output;
}

double stringToDouble(String inputString)
{
  double output = 0;
  int i = 0;
  if (inputString[0] == '-')
    i = 1;

  for (; i < inputString.length(); i++)
  {
    if (inputString[i] == '.')
    {
      i++;
      break;
    }

    output = output*10 + ((int)inputString[i] - 48);
  }
  int j = 0;
  for (; i < inputString.length(); i++)
  {
    j++;
    output = output + ((int)inputString[i] - 48)/(double)pow(10.0,j);
  }

  if (inputString[0] == '-')
    output *= -1;

  return output;
}
