#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_9DOF.h>
#include <Adafruit_L3GD20_U.h>

#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUdp.h>         // UDP library from: bjoern@cs.stanford.edu 12/30/2008



/* Assign a unique ID to the sensors */
Adafruit_9DOF                 dof   = Adafruit_9DOF();
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(30301);
Adafruit_LSM303_Mag_Unified   mag   = Adafruit_LSM303_Mag_Unified(30302);
Adafruit_L3GD20 gyro;

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 178);
IPAddress ip_remote(192, 168, 1, 192);
unsigned int localPort = 8888; 
unsigned int Port_remote = 4012; 


// An EthernetUDP instance to let us send and receive packets over UDP
EthernetUDP Udp;


void initSensors()
{
  if(!accel.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println(F("Ooops, no LSM303 detected ... Check your wiring!"));
    while(1);
  }
  if(!mag.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }
  if (!gyro.begin(GYRO_RANGE_250DPS))
  {
    /* There was a problem detecting the L3GD20 ... check your connections */
    Serial.println("Ooops, no L3GD20 detected ... Check your wiring!");
    while(1);
  }

}


void setup(void)
{
  Serial.begin(115200);
  Serial.println(F("Adafruit 9 DOF Pitch/Roll/Heading Example")); Serial.println("");
  /* Initialise the sensors */
  initSensors();
  Ethernet.begin(mac, ip);
  Udp.begin(localPort);
}


void loop(void)
{
  sensors_event_t accel_event;
  sensors_event_t mag_event;
  sensors_vec_t   orientation;

  // Read the gyro accelerometer and magnetometer
  accel.getEvent(&accel_event);
  mag.getEvent(&mag_event);
  gyro.read();

  // Fusion accel/mag data 
  if (dof.fusionGetOrientation(&accel_event, &mag_event, &orientation))
  {
    /* 'orientation' should have valid .roll and .pitch fields */
  }

    // send a reply to the IP address and port that sent us the packet we received
    //Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
 
    Udp.beginPacket(ip_remote, Port_remote);
    Udp.write(highByte((int)(orientation.roll*10)));
    Udp.write(lowByte((int)(orientation.roll*10)));
    Udp.write(highByte((int)(orientation.pitch*10)));
    Udp.write(lowByte((int)(orientation.pitch*10)));
    Udp.write(highByte((int)(orientation.heading*10)));
    Udp.write(lowByte((int)(orientation.heading*10)));
   
    /*Udp.write(highByte((int)(gyro.data.x*10)));
    Udp.write(lowByte((int)(gyro.data.x*10)));
    Udp.write(highByte((int)(gyro.data.y*10)));
    Udp.write(lowByte((int)(gyro.data.y*10)));
    Udp.write(highByte((int)(gyro.data.z*10)));
    Udp.write(lowByte((int)(gyro.data.z*10)));*/
    
    Udp.endPacket();

    Serial.print(F("Orientation: "));
    Serial.print(orientation.roll);
    Serial.print(F(" "));
    Serial.print(orientation.pitch);
    Serial.print(F(" "));
    Serial.print(gyro.data.z);
    Serial.println(F(""));
  
      delay(30); 
}
