#define PIN_RELAY 8
#define PIN_GERK_IN 28
#define PIN_GERK_OUT 32
bool light = false;
bool door_is_open = true;
bool flag;
bool pin_gerk;

void setup() {
  pinMode(PIN_RELAY, OUTPUT);
  pinMode(PIN_GERK_OUT, OUTPUT);
  pinMode(PIN_GERK_IN, INPUT_PULLUP);
  pinMode(13, INPUT);
  Serial.begin(9600);
  digitalWrite(PIN_RELAY, HIGH);
  flag = !digitalRead(PIN_GERK_IN);
  
  
  // put your setup code here, to run once:

}

void loop() {
  pin_gerk = digitalRead(PIN_GERK_IN); 
  Serial.println(String(pin_gerk) + "--" + String(flag));
    
  if (flag == digitalRead(PIN_GERK_IN)) {
    digitalWrite(PIN_RELAY, light);
    delay(3500);
    light = !light;
  }
  flag = !digitalRead(PIN_GERK_IN);
  
}
