#include <Wire.h>
#include <SoftwareSerial.h>

#define DS3231_ADDRESS 0x68

SoftwareSerial BT(10,11);

int light = 4;
int fan = 5;

char cmd;

int startHour = 0;
int startMinute = 1;

int stopHour = 0;
int stopMinute = 2;

bool scheduleOnDone = false;
bool scheduleOffDone = false;

/* BCD to Decimal */
byte bcdToDec(byte val)
{
 return ((val / 16 * 10) + (val % 16));
}

/* Read RTC */
void readRTC(byte *hour, byte *minute)
{
 Wire.beginTransmission(DS3231_ADDRESS);
 Wire.write(0);
 Wire.endTransmission();

 Wire.requestFrom(DS3231_ADDRESS, 3);

 byte seconds = bcdToDec(Wire.read() & 0x7F);
 *minute = bcdToDec(Wire.read());
 *hour = bcdToDec(Wire.read() & 0x3F);
}

/* Bluetooth control */
void bluetooth_control()
{
 if(BT.available())
 {
  cmd = BT.read();

  if(cmd=='A')
  {
   digitalWrite(light,LOW);
   Serial.println("Light ON (Bluetooth)");
  }

  if(cmd=='a')
  {
   digitalWrite(light,HIGH);
   Serial.println("Light OFF (Bluetooth)");
  }

  if(cmd=='B')
  {
   digitalWrite(fan,LOW);
   Serial.println("Fan ON (Bluetooth)");
  }

  if(cmd=='b')
  {
   digitalWrite(fan,HIGH);
   Serial.println("Fan OFF (Bluetooth)");
  }
 }
}

/* Schedule control */
void schedule_control()
{
 byte hour, minute;

 readRTC(&hour,&minute);

 Serial.print("Time: ");
 Serial.print(hour);
 Serial.print(":");
 Serial.println(minute);

 /* Schedule ON */
 if(hour == startHour && minute >= startMinute && scheduleOnDone == false)
 {
  Serial.println("Schedule ON Triggered");

  digitalWrite(light,LOW);
  digitalWrite(fan,LOW);

  scheduleOnDone = true;
 }

 /* Schedule OFF */
 if(hour == stopHour && minute >= stopMinute && scheduleOffDone == false)
 {
  Serial.println("Schedule OFF Triggered");

  digitalWrite(light,HIGH);
  digitalWrite(fan,HIGH);

  scheduleOffDone = true;
 }
}

void setup()
{
 Serial.begin(9600);
 BT.begin(9600);

 pinMode(light,OUTPUT);
 pinMode(fan,OUTPUT);

 digitalWrite(light,HIGH);
 digitalWrite(fan,HIGH);

 Wire.begin();
}

void loop()
{
 bluetooth_control();
 schedule_control();

 delay(1000);
}
