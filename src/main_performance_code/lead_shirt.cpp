// // Lead dancer code 
// // coded for Vetri's shirt 
// // Reason for Vetri shirt : that shirt design was completed first

// // Import required libraries
// #include <WiFi.h>
// #include <AsyncTCP.h>
// #include <ESPAsyncWebServer.h>
// #include <FastLED.h>


// // Replace with your network credentials
// const char* ssid = "";
// const char* password = "";

// bool ledState = 0;
// const int ledPin = 2;

// // Create AsyncWebServer object on port 80
// AsyncWebServer server(80);
// AsyncWebSocket ws("/ws");

// const char index_html[] PROGMEM = R"rawliteral(
// <!DOCTYPE html>
// <html>
//   <head>
//     <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">
//     <title>ESP32 WebSocket Server</title>
//     <style>
//     html{font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}
//     body{margin-top: 50px;}
//     h1{color: #444444;margin: 50px auto;}
//     p{font-size: 19px;color: #888;}
//     #state{font-weight: bold;color: #444;}
//     .switch{margin:25px auto;width:80px}
//     .toggle{display:none}
//     .toggle+label{display:block;position:relative;cursor:pointer;outline:0;user-select:none;padding:2px;width:80px;height:40px;background-color:#ddd;border-radius:40px}
//     .toggle+label:before,.toggle+label:after{display:block;position:absolute;top:1px;left:1px;bottom:1px;content:""}
//     .toggle+label:before{right:1px;background-color:#f1f1f1;border-radius:40px;transition:background .4s}
//     .toggle+label:after{width:40px;background-color:#fff;border-radius:20px;box-shadow:0 2px 5px rgba(0,0,0,.3);transition:margin .4s}
//     .toggle:checked+label:before{background-color:#4285f4}
//     .toggle:checked+label:after{margin-left:42px}
//     </style>
//   </head>
//   <body>
//     <h1>ESP32 WebSocket Server</h1>
//     <div class="switch">
//       <input id="toggle-btn" class="toggle" type="checkbox" %CHECK%>
//       <label for="toggle-btn"></label>
//     </div>
//     <p>On-board LED: <span id="state">%STATE%</span></p>

//     <script>
// 	  window.addEventListener('load', function() {
// 		var websocket = new WebSocket(`ws://${window.location.hostname}/ws`);
// 		websocket.onopen = function(event) {
// 		  console.log('Connection established');
// 		}
// 		websocket.onclose = function(event) {
// 		  console.log('Connection died');
// 		}
// 		websocket.onerror = function(error) {
// 		  console.log('error');
// 		};
// 		websocket.onmessage = function(event) {
// 		  if (event.data == "1") {
// 			document.getElementById('state').innerHTML = "ON";
// 			document.getElementById('toggle-btn').checked = true;
// 		  }
// 		  else {
// 			document.getElementById('state').innerHTML = "OFF";
// 			document.getElementById('toggle-btn').checked = false;
// 		  }
// 		};
		
// 		document.getElementById('toggle-btn').addEventListener('change', function() { websocket.send('toggle'); });
// 	  });
// 	</script>
//   </body>
// </html>
// )rawliteral";

// void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
//   AwsFrameInfo *info = (AwsFrameInfo*)arg;
//   if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
//     data[len] = 0;
//     if (strcmp((char*)data, "toggle") == 0) {
//       ledState = !ledState;
//       ws.textAll(String(ledState));
//     }
//   }
// }

// void eventHandler(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
//   switch (type) {
//     case WS_EVT_CONNECT:
//       Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
//       break;
//     case WS_EVT_DISCONNECT:
//       Serial.printf("WebSocket client #%u disconnected\n", client->id());
//       break;
//     case WS_EVT_DATA:
//       handleWebSocketMessage(arg, data, len);
//       //digitalWrite(ledPin, ledState);
//       break;
//     case WS_EVT_PONG:
//     case WS_EVT_ERROR:
//       break;
//   }
// }

// String processor(const String& var){
//   if(var == "STATE"){
//       return ledState ? "ON" : "OFF";
//   }
//   if(var == "CHECK"){
//     return ledState ? "checked" : "";
//   }
//   return String();
// }


// // //FastLED setup 

// #define NUM_LEDS  1000
// #define LED_PIN   2

// CRGB leds[NUM_LEDS];

// void setup(){
//   // Serial port for debugging purposes
//   Serial.begin(9600);

//   // pinMode(ledPin, OUTPUT);
//   // digitalWrite(ledPin, LOW);

//   // Serial.print("Connecting to ");
//   // Serial.println(ssid);
  
//   // Connect to Wi-Fi
//   // WiFi.begin(ssid, password);
  
//   // while (WiFi.status() != WL_CONNECTED) {
//   //   delay(1000);
//   //   Serial.print(".");
//   // }
  
//   // Serial.println("");
//   // Serial.println("Connected..!");
//   // Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

//   // ws.onEvent(eventHandler);
//   // server.addHandler(&ws);

//   // // Route for root / web page
//   // server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
//   //   request->send_P(200, "text/html", index_html, processor);
//   // });

//   // Start server
//   // server.begin();

//   //FASTLED setup 
//   FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
//   FastLED.setBrightness(100);
// }

// void loop() {
//   // ws.cleanupClients();
  
//   //Pudhiya manidha boomiku vaa frame 
//   // song bit starts at 00:04 sec ends at 00:11 ; so totally 7 seconds 
//   //140 LEDs in 7 seconds if delay is 50
//   //frame1 code starts 

//   int  end = 144  ;  
//   int counter1 = 0 , counter2 = 145 ; 
//   //for idea 1 pant code 
//   // int counter3=288 , counter4 = 375 ; 
//   for(int i = 0 ; i < end ; i++){
//     //counter1 and counter2 is for shirt 
//     //pant code must be added 
//     leds[counter1] = CRGB::Blue ; 
//     leds[counter2] = CRGB::Blue ; 
//     // leds[counter3] = CRGB::Blue ; 
//     // leds[counter4] = CRGB::Blue ; 
//     counter1++ ; counter2++ ; 
//     // counter3++ ; counter4++ ; 
//     delay(50) ; 
//     FastLED.show() ; 
//   }

//   //this delay is for blue light to be visible till pudhiya manidha fully ends 
//   delay(1000) ; 
  

//   //appo sillunu oru kaathu - blackout 
//   FastLED.clear() ; 
//   FastLED.show() ; 
//   delay(3000) ; //maybe 4 seconds ku maathikalaam 

//   //yellow for red heart frame 
//   fill_solid(leds , NUM_LEDS , CRGB::Yellow) ; 
//   FastLED.show();
//   delay(9000); 

//   end = 10 ; 
//   for(int i = 0 ; i < end ;i++){
//     FastLED.clear() ; 
//     FastLED.show() ; 
//     delay(50) ; 
//     fill_solid(leds , NUM_LEDS , CRGB::Yellow) ; 
//     FastLED.show() ; 
//     delay(50) ; 
//   }

//   //palichunu irukura heart frame 
//   fill_solid(leds , NUM_LEDS , CRGB::LawnGreen) ; 
//   delay(20000) ; 

//   //blackout 
//   FastLED.clear() ; 
//   FastLED.show() ; 
//   delay(3000) ; //maybe 4 seconds ku maathikalaam 

//   //wings frame 
//   fill_solid(leds , NUM_LEDS , CRGB::Pink) ; 
//   FastLED.show() ; 
//   delay(9000) ; 


//   //blue heart frame 
//   fill_solid(leds , NUM_LEDS , CRGB::Pink) ; 
//   FastLED.show() ; 
//   delay(8000) ; 


//   //moon frame 
//   fill_solid(leds , NUM_LEDS , CRGB::RoyalBlue) ; 
//   FastLED.show() ; 
//   delay(16000) ; 

//   //moon frame 
//   fill_solid(leds , NUM_LEDS , CRGB::Green) ; 
//   FastLED.show() ; 
//   delay(10000) ; 

//   //blackout 
//   FastLED.clear() ; 
//   FastLED.show() ; 
//   delay(2000) ; //maybe 4 seconds ku maathikalaam
//   //chumma delay 
  
//   delay(20000) ; 
//   FastLED.clear() ; 
//   delay(100) ; 

 
// }