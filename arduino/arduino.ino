//https://majenko.co.uk/blog/reading-serial-arduino

// test program for p5js to send data to arduino to handle colors for a 10x10 led matrix
// data is send as 100;100;100+100;100;101+100;100;102+|
// the + is used for marking a new led color 3-pair and | is used for marking end of data message
// 255;255;255+ is 12 characters, so for 100 leds that would make up for 1200 characters. 
// Include the ending character | and you'll need 1201 characters for the dataSize

const int sizeData = 1201;
char buf[sizeData];

int readline(int readch, char *buffer, int len) {
  static int pos = 0;
  int rpos;

  if (readch > 0) {
    switch (readch) {
      case '\r': // Ignore CR
        break;
      case '|': // Return on new-line
        rpos = pos;
        pos = 0;  // Reset position index ready for next time
        return rpos;
      default:
        if (pos < len - 1) {
          buffer[pos++] = readch;
          buffer[pos] = 0;
        }
    }
  }
  return 0;
}

void setup() {
  Serial.begin(115200);
  Serial.println("arduino ready");
}

void loop() {
  if (readline(Serial.read(), buf, sizeData) > 0) {
    Serial.print("You entered: >");
    Serial.print(buf);
    Serial.println("<");
  }
}