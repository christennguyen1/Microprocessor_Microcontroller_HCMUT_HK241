#include <WiFi.h>
#include <SoftwareSerial.h>

// Replace with your network credentials
const char* ssid = "Nguyên An";
const char* password = "tom9012003";

// Web server setup
WiFiServer server(80);
String header;

// LED states
String outputRestart = "off";
String outputStart = "off";
String outputRedState = "off";
String outputGreenState = "off";
String outputYellowState = "off";

// GPIO Pins
const int redLED = D5;
const int greenLED = D6;

// Serial communication setup
SoftwareSerial mySerial(D0, D1); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  // Initialize LED pins
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);

  // Connect to Wi-Fi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Start the server
  server.begin();
}

void loop() {
  WiFiClient client = server.available();   // Listen for incoming clients
  if (client) {                             // If a new client connects
    Serial.println("New Client.");
    String currentLine = "";

    while (client.connected()) {
      if (client.available()) {             // If there's bytes to read from the client
        char c = client.read();
        Serial.write(c);
        header += c;

        if (c == '\n') {                   // If the byte is a newline character
          if (currentLine.length() == 0) {
            // Send HTTP response
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close\n");

            // Handle GET requests for LEDs
            if (header.indexOf("GET /restart") >= 0) {
              Serial.println("RESTART");
              outputRestart = "on";
              outputStart = "off";
              mySerial.println("RESTART");
            }
            if (header.indexOf("GET /start") >= 0) {
              Serial.println("START");
              outputRestart = "off";
              outputStart = "on";
              mySerial.println("START");
            }
            if (header.indexOf("GET /manual1") >= 0) {
              Serial.println("MANUAL1");
              mySerial.println("MANUAL1");
            }
            if (header.indexOf("GET /manual2") >= 0) {
              Serial.println("MANUAL2");
              mySerial.println("MANUAL2");
            }
            if (header.indexOf("GET /manual3") >= 0) {
              Serial.println("MANUAL3");
              mySerial.println("MANUAL3");
            }
            if (header.indexOf("GET /red/on") >= 0) {
              Serial.println("Turning RED LED ON");
              outputRedState = "on";
              outputStart = "off";
              digitalWrite(redLED, HIGH);
              mySerial.println("LED_RED");
            } else if (header.indexOf("GET /red/off") >= 0) {
              Serial.println("Turning RED LED OFF");
              outputRedState = "off";
              digitalWrite(redLED, LOW);
            }

            if (header.indexOf("GET /green/on") >= 0) {
              Serial.println("Turning GREEN LED ON");
              outputGreenState = "on";
              outputStart = "off";
              digitalWrite(greenLED, HIGH);
            } else if (header.indexOf("GET /green/off") >= 0) {
              Serial.println("Turning GREEN LED OFF");
              outputGreenState = "off";
              digitalWrite(greenLED, LOW);
            }

            // Send HTML response
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<style>html { font-family: Helvetica; text-align: center;}</style></head>");
            client.println("<body><h1>ESP32 Web Server</h1>");
            client.println("<p>Start: " + outputRedState + "</p>");
            client.println("<p><a href=\"/red/on\"><button>ON</button></a>");
            client.println("<a href=\"/red/off\"><button>OFF</button></a></p>");

            client.println("<p>RED LED - State: " + outputRedState + "</p>");
            client.println("<p><a href=\"/red/on\"><button>ON</button></a>");
            client.println("<a href=\"/red/off\"><button>OFF</button></a></p>");

            client.println("<p>RED LED - State: " + outputRedState + "</p>");
            client.println("<p><a href=\"/red/on\"><button>ON</button></a>");
            client.println("<a href=\"/red/off\"><button>OFF</button></a></p>");

            client.println("<p>GREEN LED - State: " + outputGreenState + "</p>");
            client.println("<p><a href=\"/green/on\"><button>ON</button></a>");
            client.println("<a href=\"/green/off\"><button>OFF</button></a></p>");

            client.println("<form method=\"get\">Input Values:<br>");
            client.println("<label for=\"red\">Red Value:</label><input type=\"number\" id=\"red\" name=\"red\"><br>");
            client.println("<label for=\"yellow\">Yellow Value:</label><input type=\"number\" id=\"yellow\" name=\"yellow\"><br>");
            client.println("<label for=\"green\">Green Value:</label><input type=\"number\" id=\"green\" name=\"green\"><br>");
            client.println("<input type=\"submit\" value=\"Submit\"></form>");

            if (header.indexOf("GET /?red=") >= 0 && header.indexOf("&yellow=") >= 0 && header.indexOf("&green=") >= 0) {
              int redStart = header.indexOf("red=") + 4;
              int redEnd = header.indexOf("&", redStart);
              int yellowStart = header.indexOf("yellow=") + 7;
              int yellowEnd = header.indexOf("&", yellowStart);
              int greenStart = header.indexOf("green=") + 6;
              int greenEnd = header.indexOf(" ", greenStart);

              int redValue = header.substring(redStart, redEnd).toInt();
              int yellowValue = header.substring(yellowStart, yellowEnd).toInt();
              int greenValue = header.substring(greenStart, greenEnd).toInt();

              Serial.printf("Received: Red=%d, Yellow=%d, Green=%d\n", redValue, yellowValue, greenValue);
              // mySerial.println("Set_up!%d!%d!%d", redValue, yellowValue, greenValue);

              if (greenValue == redValue - yellowValue) {
                String message = "Set_up!" + String(redValue) + "!" + String(yellowValue) + "!" + String(greenValue);
                mySerial.println(message);
                // digitalWrite(redLED, HIGH);
                // digitalWrite(greenLED, HIGH);
                Serial.println("Values are valid. LEDs turned ON.");
              } else {
                Serial.println("Invalid values. Please check logic (Green = Red - Yellow). LEDs not turned ON.");
              }
            }

            client.println("</body></html>");
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }

    // Clear header and close the connection
    header = "";
    client.stop();
    Serial.println("Client disconnected.");
  }

  // Automatically send "BAT_LED_1" periodically

}
