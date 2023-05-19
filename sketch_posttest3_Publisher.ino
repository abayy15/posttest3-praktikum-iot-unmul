/*
 * Tutorial By IOTkece
 */
const int Sensor_Pir = D0;
const int LED1 = D1; //red
const int LED2 = D2; //green
const int sensor_suara = D4;
int Keadaan_Sensor;
int nilaiSensor = 0;

void setup() {
Serial.begin(9600);
pinMode(D0, INPUT);
pinMode(D1, OUTPUT);
pinMode(D2, OUTPUT);
pinMode(D4, INPUT);
delay(100);
}

void loop() {
 Keadaan_Sensor = digitalRead(Sensor_Pir);
 nilaiSensor = analogRead(sensor_suara);

 if (Keadaan_Sensor == HIGH) {
  Serial.println("Sensor Mendeteksi Pergerakan");
  if (nilaiSensor > 550){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  nilaiSensor = analogRead(sensor_suara);
  Serial.print ("Sensor = ");
  Serial.print (nilaiSensor);
  Serial.println ("\t => SUARA TERDETEKSI");
  }else {
    //turn Relay off:
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    nilaiSensor = analogRead(sensor_suara);
    Serial.print ("Sensor = ");
    Serial.println (nilaiSensor);
   }
 }
 else {
  Serial.println("Sensor Tidak Mendeteksi Pergerakan");
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  nilaiSensor = analogRead(sensor_suara);
  Serial.print ("Sensor = ");
  Serial.println (nilaiSensor);
 }
 delay(2000);
}
