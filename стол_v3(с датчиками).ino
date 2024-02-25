#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ESP8266mDNS.h>
#include <Ticker.h>
#include <DHT.h>;
#include <AsyncMqttClient.h>
#include <ArduinoOTA.h>
extern "C" 
{
    #include "user_interface.h"
}
String mqttServer;
int mqttPort;
String mqttUser;
String mqttPassword;
String mqttClientId;
bool mqttConnected;
std::vector<String> inputTopic;
std::vector<String> inputMessage;
AsyncMqttClient mqttClient;
Ticker mqttReconnectTimer;
WiFiEventHandler wifiConnectHandler;
WiFiEventHandler wifiDisconnectHandler;
uint16_t pubPacketId;
bool Unsubscribe_77360925_13;
String Topic_77360925_13;
byte QoS_77360925_13;
bool Received_77360925_13;
String Message_77360925_13;
bool subscribed_77360925_13;
bool rTrig_77360925_13;
bool Unsubscribe_77360925_7;
String Topic_77360925_7;
byte QoS_77360925_7;
bool Received_77360925_7;
String Message_77360925_7;
bool subscribed_77360925_7;
bool rTrig_77360925_7;
bool Unsubscribe_77360925_1;
String Topic_77360925_1;
byte QoS_77360925_1;
bool Received_77360925_1;
String Message_77360925_1;
bool subscribed_77360925_1;
bool rTrig_77360925_1;
bool Unsubscribe_77360925_2;
String Topic_77360925_2;
byte QoS_77360925_2;
bool Received_77360925_2;
String Message_77360925_2;
bool subscribed_77360925_2;
bool rTrig_77360925_2;
bool Unsubscribe_77360925_3;
String Topic_77360925_3;
byte QoS_77360925_3;
bool Received_77360925_3;
String Message_77360925_3;
bool subscribed_77360925_3;
bool rTrig_77360925_3;
bool Unsubscribe_77360925_4;
String Topic_77360925_4;
byte QoS_77360925_4;
bool Received_77360925_4;
String Message_77360925_4;
bool subscribed_77360925_4;
bool rTrig_77360925_4;
bool Unsubscribe_77360925_9;
String Topic_77360925_9;
byte QoS_77360925_9;
bool Received_77360925_9;
String Message_77360925_9;
bool subscribed_77360925_9;
bool rTrig_77360925_9;
bool Send_245667527_2;
String Topic_245667527_2;
String Message_245667527_2;
byte QoS_245667527_2;
bool Retain_245667527_2;
bool qosDelivered_245667527_2;
bool rTrig_245667527_2;
uint16_t packetId_245667527_2;
bool Send_245667527_5;
String Topic_245667527_5;
String Message_245667527_5;
byte QoS_245667527_5;
bool Retain_245667527_5;
bool qosDelivered_245667527_5;
bool rTrig_245667527_5;
uint16_t packetId_245667527_5;
bool Send_245667527_6;
String Topic_245667527_6;
String Message_245667527_6;
byte QoS_245667527_6;
bool Retain_245667527_6;
bool qosDelivered_245667527_6;
bool rTrig_245667527_6;
uint16_t packetId_245667527_6;
bool Send_245667527_7;
String Topic_245667527_7;
String Message_245667527_7;
byte QoS_245667527_7;
bool Retain_245667527_7;
bool qosDelivered_245667527_7;
bool rTrig_245667527_7;
uint16_t packetId_245667527_7;
float Temperature;
float Humidity;
float HeatIndex;
//Libraries
//Constants
#define TYPE DHT21  //DHT 21  (AM2301)
DHT AM(13, TYPE); //Initialize DHT sensor for normal 16mhz Arduino
//Variables
float hum; //Stores humidity value
float temp; //Stores temperature value
unsigned long timingAM2301A;
float Temp;
float Hum;
float HeatInd;
// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain
// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22  // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 3 (on the right) of the sensor to GROUND (if your sensor has 3 pins)
// Connect pin 4 (on the right) of the sensor to GROUND and leave the pin 3 EMPTY (if your sensor has 4 pins)
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor
// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(12, DHTTYPE);
// Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.
unsigned long timingAM2120;
bool ESPControllerWifiClient_HRD = 0;
bool ESPControllerWifiClient_status = 1;
bool ESPControllerWifiClient_isDHCP = 0;
bool ESPControllerWifiClient_IsNeedReconect = 0;
bool ESPControllerWifiClient_workStatus = 1;
char ESPControllerWifiClient_SSID[40] = "408";
char ESPControllerWifiClient_password[40] = "408408408spb";
IPAddress ESPControllerWifiClient_ip(192, 168, 0, 110);
IPAddress  ESPControllerWifiClient_dns (192, 168, 0, 1);
IPAddress  ESPControllerWifiClient_gateway (192, 168, 0, 1);
IPAddress ESPControllerWifiClient_subnet (255, 255, 255, 0);
uint8_t ESPControllerWifiClient_mac[6] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
bool _otaUpadterStatus = 0;
bool _gtv1;
bool _gtv2;
bool _gen7I = 0;
bool _gen7O = 0;
unsigned long _gen7P = 0UL;
float _strFunmax5 = 0.00;
bool _trgt3 = 0;
bool _trgt3I = 0;
int _convertStringToNamberOutput_5 = 0;
bool _gen3I = 0;
bool _gen3O = 0;
unsigned long _gen3P = 0UL;
bool _changeNumber1_Out = 0;
float _changeNumber1_OLV;
bool _gen8I = 0;
bool _gen8O = 0;
unsigned long _gen8P = 0UL;
float _strFunmax1 = 0.00;
bool _trgt2 = 0;
bool _trgt2I = 0;
bool _gen1I = 0;
bool _gen1O = 0;
unsigned long _gen1P = 0UL;
int _convertStringToNamberOutput_1 = 0;
bool _gen9I = 0;
bool _gen9O = 0;
unsigned long _gen9P = 0UL;
float _strFunmax4 = 0.00;
bool _gen2I = 0;
bool _gen2O = 0;
unsigned long _gen2P = 0UL;
long _strFunrand1 = 0L;
bool _trgr1 = 0;
int _convertStringToNamberOutput_14 = 0;
float _strFunmin4 = 0.00;
bool _trgt4 = 0;
bool _trgt4I = 0;
bool _trgt1 = 0;
bool _trgt1I = 0;
long _strFunrand4 = 0L;
float _strFunmax3 = 0.00;
long _strFunrand2 = 0L;
bool _count1I = 0;
int _count1_Value = 0;
bool _count1MaxLO = 0;
bool _count1MinLO = 0;
float _strFunmin1 = 0.00;
float _strFunmax6 = 0.00;
bool _changeNumber3_Out = 0;
float _changeNumber3_OLV;
bool _gen5I = 0;
bool _gen5O = 0;
unsigned long _gen5P = 0UL;
int _convertStringToNamberOutput_8 = 0;
bool _trgt8 = 0;
bool _trgt8I = 0;
int _convertStringToNamberOutput_7 = 0;
float _strFunmax2 = 0.00;
int _convertStringToNamberOutput_3 = 0;
bool _gen4I = 0;
bool _gen4O = 0;
unsigned long _gen4P = 0UL;
float _strFunmin2 = 0.00;
String _tempVariable_String;
float _tempVariable_float;
void setup()
{
    pinMode(0, OUTPUT);
    digitalWrite(0, 0);
    WiFi.mode(WIFI_STA);
    _esp8266WifiModuleClientReconnect();
    randomSeed(analogRead(0));
    wifiConnectHandler = WiFi.onStationModeGotIP(onWifiConnect);
    wifiDisconnectHandler = WiFi.onStationModeDisconnected(onWifiDisconnect);
    mqttClient.onMessage(onMqttMessage);
    mqttClient.onConnect(onMqttConnect);
    mqttClient.onDisconnect(onMqttDisconnect);
    mqttClient.onPublish(onMqttPublish);
    mqttClient.setKeepAlive(15);
    mqttClient.setCleanSession(0);
    Serial.begin(9600);
    AM.begin();
    Serial.begin(9600);
    dht.begin();
}
void loop()
{
    if(ESPControllerWifiClient_IsNeedReconect) 
    {
        _esp8266WifiModuleClientReconnect();
        ESPControllerWifiClient_IsNeedReconect = 0;
    }
    ESPControllerWifiClient_status = WiFi.status() == WL_CONNECTED;
    if (_otaUpadterStatus) 
    {
         ArduinoOTA.handle();
    }
    else
    {
        if(ESPControllerWifiClient_status) 
        {
            ArduinoOTA.setHostname ("FirstESP");
            ArduinoOTA.begin();
            _otaUpadterStatus = 1;
        }
    }
    if (ESPControllerWifiClient_status) 
    {
         if (! ESPControllerWifiClient_HRD) 
        {
            ESPControllerWifiClient_ip =  WiFi.localIP();
            ESPControllerWifiClient_subnet =  WiFi.subnetMask();
            ESPControllerWifiClient_gateway =  WiFi.gatewayIP();
            ESPControllerWifiClient_dns =  WiFi.dnsIP();
            WiFi.macAddress(ESPControllerWifiClient_mac);
            ESPControllerWifiClient_HRD = 1;
        }
    }
     else 
    {
        ESPControllerWifiClient_HRD = 0;
    }
    //Плата:1
//Наименование:Настольная лама и лента
    mqttServer = String("m6.wqtt.ru");
    mqttPort = 11954;
    mqttUser = String("u_FX3M2T");
    mqttPassword = String("aDR7R4tC");
    mqttClientId = String("FirsESP");
    Unsubscribe_77360925_2 = 0;
    Topic_77360925_2 = String("power");
    QoS_77360925_2 = 0;
    sub(Topic_77360925_2, Message_77360925_2, QoS_77360925_2, Received_77360925_2, subscribed_77360925_2, Unsubscribe_77360925_2, rTrig_77360925_2);
    if (_changeNumber1_Out) 
    {
        _changeNumber1_Out = 0;
    }
     else 
    {
        _tempVariable_float = (_stringToFloat(Message_77360925_2));
        if (_tempVariable_float != _changeNumber1_OLV) 
        {
            _changeNumber1_OLV = _tempVariable_float;
            _changeNumber1_Out = 1;
        }
    }
    if(((_gtv1) || (_gtv2))) _trgr1 = 0;
    if(_changeNumber1_Out) _trgr1 = 1;
    if (_trgr1) 
    {
        if (! _gen4I) 
        {
            _gen4I = 1;
            _gen4O = 1;
            _gen4P =  millis();
        }
    }
     else 
    {
        _gen4I = 0 ;
        _gen4O= 0;
    }
     if (_gen4I) 
    {
         if (_gen4O) 
        {
             if (_isTimer(_gen4P , 1)) 
            {
                 _gen4P = millis();
                _gen4O = 0;
            }
        }
         else  
        {
             if (_isTimer(_gen4P , 10)) 
            {
                  _gen4P = millis();
                _gen4O = 1;
            }
        }
    }
    bool  _tmp8 = _changeNumber1_Out;
    if (_tmp8)  
    {
         if (! _trgt8I) _trgt8 = ! _trgt8;
    }
    _trgt8I = _tmp8;
    if (_gen4O)
    {
        if (! _count1I) 
        {
            _count1I = 1;
            if (_trgt8)
            {
                _count1_Value = _count1_Value + 1;
            }
             else
            {
                 _count1_Value = _count1_Value - 1;
            }
        }
    }
     else 
    {
        _count1I = 0;
    }
    _count1MaxLO = _count1_Value >= 255;
    _count1MinLO = _count1_Value <= 0;
    if(_count1_Value >= 255) 
    {
        _count1_Value = 255;
    }
    else 
    {
        if(_count1_Value <= 0) 
        {
            _count1_Value = 0;
        }
    }
    _gtv2 = _count1MinLO;
    Unsubscribe_77360925_7 = 0;
    Topic_77360925_7 = String("ledG");
    QoS_77360925_7 = 0;
    sub(Topic_77360925_7, Message_77360925_7, QoS_77360925_7, Received_77360925_7, subscribed_77360925_7, Unsubscribe_77360925_7, rTrig_77360925_7);
    _tempVariable_String = Message_77360925_7;
    _convertStringToNamberOutput_7 = strtol(_tempVariable_String.c_str(),NULL,10);
    if((_convertStringToNamberOutput_7) > ((map((_count1_Value), (0), (255), (0), (224))))) 
    {
        _strFunmax2 = _convertStringToNamberOutput_7;
    }
     else 
    {
        _strFunmax2 = (map((_count1_Value), (0), (255), (0), (224)));
    }
    Unsubscribe_77360925_3 = 0;
    Topic_77360925_3 = String("MusicSW");
    QoS_77360925_3 = 0;
    sub(Topic_77360925_3, Message_77360925_3, QoS_77360925_3, Received_77360925_3, subscribed_77360925_3, Unsubscribe_77360925_3, rTrig_77360925_3);
    _tempVariable_String = Message_77360925_3;
    _convertStringToNamberOutput_3 = strtol(_tempVariable_String.c_str(),NULL,10);
    bool  _tmp3 = (300) == (_convertStringToNamberOutput_3);
    if (_tmp3)  
    {
         if (! _trgt3I) _trgt3 = ! _trgt3;
    }
    _trgt3I = _tmp3;
    Unsubscribe_77360925_4 = 0;
    Topic_77360925_4 = String("MusicBPM");
    QoS_77360925_4 = 0;
    sub(Topic_77360925_4, Message_77360925_4, QoS_77360925_4, Received_77360925_4, subscribed_77360925_4, Unsubscribe_77360925_4, rTrig_77360925_4);
    _tempVariable_String = Message_77360925_3;
    _convertStringToNamberOutput_8 = strtol(_tempVariable_String.c_str(),NULL,10);
    bool  _tmp2 = (300) == (_convertStringToNamberOutput_8);
    if (_tmp2)  
    {
         if (! _trgt2I) _trgt2 = ! _trgt2;
    }
    _trgt2I = _tmp2;
    if (_trgt2) 
    {
        if (! _gen3I) 
        {
            _gen3I = 1;
            _gen3O = 1;
            _gen3P =  millis();
        }
    }
     else 
    {
        _gen3I = 0 ;
        _gen3O= 0;
    }
     if (_gen3I) 
    {
         if (_gen3O) 
        {
             if (_isTimer(_gen3P , 1)) 
            {
                 _gen3P = millis();
                _gen3O = 0;
            }
        }
         else  
        {
             if (_isTimer(_gen3P , (60000.00)/((_stringToFloat(Message_77360925_4))))) 
            {
                  _gen3P = millis();
                _gen3O = 1;
            }
        }
    }
    if (_gen3O) 
    {
        _strFunrand1 = random(0, 200);
    }
    if((_strFunrand1) < (_convertStringToNamberOutput_8)) 
    {
        _strFunmin1 = _strFunrand1;
    }
     else 
    {
        _strFunmin1 = _convertStringToNamberOutput_8;
    }
    Unsubscribe_77360925_1 = 0;
    Topic_77360925_1 = String("ledB");
    QoS_77360925_1 = 0;
    sub(Topic_77360925_1, Message_77360925_1, QoS_77360925_1, Received_77360925_1, subscribed_77360925_1, Unsubscribe_77360925_1, rTrig_77360925_1);
    _tempVariable_String = Message_77360925_1;
    _convertStringToNamberOutput_1 = strtol(_tempVariable_String.c_str(),NULL,10);
    if((_convertStringToNamberOutput_1) > ((map((_count1_Value), (0), (255), (0), (132))))) 
    {
        _strFunmax1 = _convertStringToNamberOutput_1;
    }
     else 
    {
        _strFunmax1 = (map((_count1_Value), (0), (255), (0), (132)));
    }
    if((_strFunmin1) > (_strFunmax1)) 
    {
        _strFunmax6 = _strFunmin1;
    }
     else 
    {
        _strFunmax6 = _strFunmax1;
    }
    analogWrite(14, _strFunmax6);
    _tempVariable_String = Message_77360925_3;
    _convertStringToNamberOutput_5 = strtol(_tempVariable_String.c_str(),NULL,10);
    bool  _tmp1 = (300) == (_convertStringToNamberOutput_5);
    if (_tmp1)  
    {
         if (! _trgt1I) _trgt1 = ! _trgt1;
    }
    _trgt1I = _tmp1;
    if (_trgt1) 
    {
        if (! _gen2I) 
        {
            _gen2I = 1;
            _gen2O = 1;
            _gen2P =  millis();
        }
    }
     else 
    {
        _gen2I = 0 ;
        _gen2O= 0;
    }
     if (_gen2I) 
    {
         if (_gen2O) 
        {
             if (_isTimer(_gen2P , 1)) 
            {
                 _gen2P = millis();
                _gen2O = 0;
            }
        }
         else  
        {
             if (_isTimer(_gen2P , (60000.00)/((_stringToFloat(Message_77360925_4))))) 
            {
                  _gen2P = millis();
                _gen2O = 1;
            }
        }
    }
    if (_gen2O) 
    {
        _strFunrand2 = random(0, 180);
    }
    if (_trgt3) 
    {
        if (! _gen1I) 
        {
            _gen1I = 1;
            _gen1O = 1;
            _gen1P =  millis();
        }
    }
     else 
    {
        _gen1I = 0 ;
        _gen1O= 0;
    }
     if (_gen1I) 
    {
         if (_gen1O) 
        {
             if (_isTimer(_gen1P , 1)) 
            {
                 _gen1P = millis();
                _gen1O = 0;
            }
        }
         else  
        {
             if (_isTimer(_gen1P , (60000.00)/((_stringToFloat(Message_77360925_4))))) 
            {
                  _gen1P = millis();
                _gen1O = 1;
            }
        }
    }
    if (_gen1O) 
    {
        _strFunrand4 = random(30, 256);
    }
    if((_strFunrand4) < (_convertStringToNamberOutput_3)) 
    {
        _strFunmin4 = _strFunrand4;
    }
     else 
    {
        _strFunmin4 = _convertStringToNamberOutput_3;
    }
    Unsubscribe_77360925_13 = 0;
    Topic_77360925_13 = String("ledR");
    QoS_77360925_13 = 0;
    sub(Topic_77360925_13, Message_77360925_13, QoS_77360925_13, Received_77360925_13, subscribed_77360925_13, Unsubscribe_77360925_13, rTrig_77360925_13);
    _tempVariable_String = Message_77360925_13;
    _convertStringToNamberOutput_14 = strtol(_tempVariable_String.c_str(),NULL,10);
    if((_convertStringToNamberOutput_14) > ((map((_count1_Value), (0), (255), (0), (255))))) 
    {
        _strFunmax3 = _convertStringToNamberOutput_14;
    }
     else 
    {
        _strFunmax3 = (map((_count1_Value), (0), (255), (0), (255)));
    }
    if((_strFunmin4) > (_strFunmax3)) 
    {
        _strFunmax4 = _strFunmin4;
    }
     else 
    {
        _strFunmax4 = _strFunmax3;
    }
    analogWrite(5, _strFunmax4);
    if((_strFunrand2) < (_convertStringToNamberOutput_5)) 
    {
        _strFunmin2 = _strFunrand2;
    }
     else 
    {
        _strFunmin2 = _convertStringToNamberOutput_5;
    }
    if((_strFunmin2) > (_strFunmax2)) 
    {
        _strFunmax5 = _strFunmin2;
    }
     else 
    {
        _strFunmax5 = _strFunmax2;
    }
    analogWrite(4, _strFunmax5);
    _gtv1 = _count1MaxLO;
    //Плата:2
//Наименование:Настольная лампа
    Unsubscribe_77360925_9 = 0;
    Topic_77360925_9 = String("relay");
    QoS_77360925_9 = 0;
    sub(Topic_77360925_9, Message_77360925_9, QoS_77360925_9, Received_77360925_9, subscribed_77360925_9, Unsubscribe_77360925_9, rTrig_77360925_9);
    if (_changeNumber3_Out) 
    {
        _changeNumber3_Out = 0;
    }
     else 
    {
        _tempVariable_float = (_stringToFloat(Message_77360925_9));
        if (_tempVariable_float != _changeNumber3_OLV) 
        {
            _changeNumber3_OLV = _tempVariable_float;
            _changeNumber3_Out = 1;
        }
    }
    bool  _tmp4 = _changeNumber3_Out;
    if (_tmp4)  
    {
         if (! _trgt4I) _trgt4 = ! _trgt4;
    }
    _trgt4I = _tmp4;
    digitalWrite(0, !(_trgt4));
    //Плата:3
    // Wait a few seconds between measurements.
    if (millis() - timingAM2120 > 2000)
    {
        timingAM2120 = millis();
        // Reading temperature or humidity takes about 250 milliseconds!
          // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
          float h = dht.readHumidity();
        // Read temperature as Celsius (the default)
          float t = dht.readTemperature();
        // Check if any reads failed and exit early (to try again).
          if (isnan(h) || isnan(t)) 
        {
            Serial.println(F("Failed to read from AM2120 sensor!"));
            return;
        }
        // Compute heat index in Celsius (isFahreheit = false)
         // float hinc = dht.computeHeatIndex(t, h, false);
        float hinc = -8.78469475556 + 1.61139411*t + 2.3385488388*h + -0.14611605*t*h + -0.0123*t*t + -0.016424*h*h + 0.002211732*t*t*h
        + 0.00072546*t*h*h + -0.000003582*t*t*h*h;
        Temp = t;
        Hum = h;
        HeatInd = hinc;
    }
    if (!(0)) 
    {
        if (! _gen9I) 
        {
            _gen9I = 1;
            _gen9O = 1;
            _gen9P =  millis();
        }
    }
     else 
    {
        _gen9I = 0 ;
        _gen9O= 0;
    }
     if (_gen9I) 
    {
         if (_gen9O) 
        {
             if (_isTimer(_gen9P , 1000)) 
            {
                 _gen9P = millis();
                _gen9O = 0;
            }
        }
         else  
        {
             if (_isTimer(_gen9P , 20000)) 
            {
                  _gen9P = millis();
                _gen9O = 1;
            }
        }
    }
    Send_245667527_7 = _gen9O;
    Topic_245667527_7 = String("HumIn");
    Message_245667527_7 = (_floatToStringWitRaz(Hum,2));
    QoS_245667527_7 = 0;
    Retain_245667527_7 = 0;
    pub(Send_245667527_7, Topic_245667527_7, Message_245667527_7, QoS_245667527_7, Retain_245667527_7, qosDelivered_245667527_7, packetId_245667527_7, rTrig_245667527_7);
    if (!(0)) 
    {
        if (! _gen5I) 
        {
            _gen5I = 1;
            _gen5O = 1;
            _gen5P =  millis();
        }
    }
     else 
    {
        _gen5I = 0 ;
        _gen5O= 0;
    }
     if (_gen5I) 
    {
         if (_gen5O) 
        {
             if (_isTimer(_gen5P , 1000)) 
            {
                 _gen5P = millis();
                _gen5O = 0;
            }
        }
         else  
        {
             if (_isTimer(_gen5P , 20000)) 
            {
                  _gen5P = millis();
                _gen5O = 1;
            }
        }
    }
    Send_245667527_2 = _gen5O;
    Topic_245667527_2 = String("TempIn");
    Message_245667527_2 = (_floatToStringWitRaz(Temp,2));
    QoS_245667527_2 = 0;
    Retain_245667527_2 = !(0);
    pub(Send_245667527_2, Topic_245667527_2, Message_245667527_2, QoS_245667527_2, Retain_245667527_2, qosDelivered_245667527_2, packetId_245667527_2, rTrig_245667527_2);
    // Wait a few seconds between measurements. 
     if (millis() - timingAM2301A > 2000)
    {
        timingAM2301A = millis();
        //Read data and store it to variables hum and temp
          hum = AM.readHumidity();
        temp= AM.readTemperature();
        // Compute heat index in Celsius (isFahreheit = false)
        float hic = -8.78469475556 + 1.61139411*temp + 2.3385488388*hum + -0.14611605*temp*hum + -0.0123*temp*temp + -0.016424*hum*hum +
        0.002211732*temp*temp*hum + 0.00072546*temp*hum*hum + -0.000003582*temp*temp*hum*hum;
        Temperature = temp;
        Humidity = hum;
        HeatIndex = hic;
    }
    if (!(0)) 
    {
        if (! _gen8I) 
        {
            _gen8I = 1;
            _gen8O = 1;
            _gen8P =  millis();
        }
    }
     else 
    {
        _gen8I = 0 ;
        _gen8O= 0;
    }
     if (_gen8I) 
    {
         if (_gen8O) 
        {
             if (_isTimer(_gen8P , 1000)) 
            {
                 _gen8P = millis();
                _gen8O = 0;
            }
        }
         else  
        {
             if (_isTimer(_gen8P , 20000)) 
            {
                  _gen8P = millis();
                _gen8O = 1;
            }
        }
    }
    Send_245667527_6 = _gen8O;
    Topic_245667527_6 = String("HumOut");
    Message_245667527_6 = (_floatToStringWitRaz(Humidity,2));
    QoS_245667527_6 = 0;
    Retain_245667527_6 = 0;
    pub(Send_245667527_6, Topic_245667527_6, Message_245667527_6, QoS_245667527_6, Retain_245667527_6, qosDelivered_245667527_6, packetId_245667527_6, rTrig_245667527_6);
    if (!(0)) 
    {
        if (! _gen7I) 
        {
            _gen7I = 1;
            _gen7O = 1;
            _gen7P =  millis();
        }
    }
     else 
    {
        _gen7I = 0 ;
        _gen7O= 0;
    }
     if (_gen7I) 
    {
         if (_gen7O) 
        {
             if (_isTimer(_gen7P , 1000)) 
            {
                 _gen7P = millis();
                _gen7O = 0;
            }
        }
         else  
        {
             if (_isTimer(_gen7P , 20000)) 
            {
                  _gen7P = millis();
                _gen7O = 1;
            }
        }
    }
    Send_245667527_5 = _gen7O;
    Topic_245667527_5 = String("TempOut");
    Message_245667527_5 = (_floatToStringWitRaz(Temperature,2));
    QoS_245667527_5 = 0;
    Retain_245667527_5 = 0;
    pub(Send_245667527_5, Topic_245667527_5, Message_245667527_5, QoS_245667527_5, Retain_245667527_5, qosDelivered_245667527_5, packetId_245667527_5, rTrig_245667527_5);
}
float  _stringToFloat(String value)
{
    return value.toFloat() ;
}
String  _floatToStringWitRaz(float value, int raz)
{
    return String(value,raz);
}
bool _isTimer(unsigned long startTime, unsigned long period)
{
    unsigned long currentTime;
    currentTime = millis();
    if (currentTime>= startTime) 
    {
        return (currentTime>=(startTime + period));
    }
     else 
    {
        return (currentTime >=(4294967295-startTime+period));
    }
}
void onMqttMessage(char* topic, char* payload, AsyncMqttClientMessageProperties properties, size_t len, size_t index, size_t total)
{
    char msg[len + 1];
    for (size_t i = 0; i < len; i++) 
    {
        	msg[i] = payload[i];
    }
    msg[len] = '\0';
    inputTopic.push_back(String(topic));
    inputMessage.push_back(String(msg));
}
void onWifiConnect(const WiFiEventStationModeGotIP& event)
{
    connectToMqtt();
}
void onWifiDisconnect(const WiFiEventStationModeDisconnected& event)
{
    mqttReconnectTimer.detach();
}
void connectToMqtt()
{
    if ("default" == "default") 
    {
        	mqttClient.setWill(mqttClientId.c_str(), 1, 0, "0");
    }
     else 
    {
        	mqttClient.setWill("default", 1, 0, "0");
    }
    mqttClient.setClientId(mqttClientId.c_str());
    mqttClient.setServer(mqttServer.c_str(), mqttPort);
    mqttClient.setCredentials(mqttUser.c_str(), mqttPassword.c_str());
    mqttClient.connect();
}
void onMqttDisconnect(AsyncMqttClientDisconnectReason reason)
{
    mqttConnected = false;
    	
    if (WiFi.isConnected()) 
    {
            mqttReconnectTimer.once(5, connectToMqtt);
    }
}
void onMqttConnect(bool sessionPresent)
{
    mqttConnected = true;
    if ("default" == "default") 
    {
        	mqttClient.publish(mqttClientId.c_str(), 1, 0, "1");
    }
     else 
    {
        	mqttClient.publish("default", 1, 0, "1");
    }
}
void onMqttPublish(uint16_t packetId)
{
    pubPacketId = packetId;
}
void sub(const String &topic, String &message, const byte &qos, bool &received, bool &subscribed, const bool &unsubscribe, bool &rTrig)
{
    received = false;
    if (unsubscribe) 
    {
        	if (!rTrig) 
        {
            		uint16_t packetId = mqttClient.unsubscribe(topic.c_str());
            		if (packetId > 0) 
            {
                			rTrig = true;
                			subscribed = false;
                			for (uint8_t i = 0; i < inputTopic.size(); i++) 
                {
                    				if (inputTopic[i] == topic) 
                    {
                        					inputTopic.erase(inputTopic.begin() + i);
                        					inputMessage.erase(inputMessage.begin() + i);
                        					if (inputTopic.empty()) 
                        {
                            						inputTopic.shrink_to_fit();
                            						inputMessage.shrink_to_fit();
                            					
                        }
                        				
                    }
                    			
                }
                		
            }
            	
        }
    }
     else 
    {
        	rTrig = false;
        	for (uint8_t i = 0; i < inputTopic.size(); i++) 
        {
            		if (inputTopic[i] == topic) 
            {
                			received = true;
                			message = inputMessage[i];
                			inputTopic.erase(inputTopic.begin() + i);
                			inputMessage.erase(inputMessage.begin() + i);
                			if (inputTopic.empty()) 
                {
                    				inputTopic.shrink_to_fit();
                    				inputMessage.shrink_to_fit();
                    			
                }
                			break;
                		
            }
            	
        }
        	if (mqttClient.connected()) 
        {
            		if (!subscribed) 
            {
                			uint16_t packetId = mqttClient.subscribe(topic.c_str(), qos);
                			if (packetId > 0) 
                {
                    				subscribed = true;
                    			
                }
                		
            }
            	
        }
         else 
        {
            		subscribed = false;
            	
        }
    }
}
void pub(const bool &send, const String &topic, const String &message, const byte &qos, const bool &retain, bool &qosDelivered, uint16_t &packetId, bool &rTrig)
{
    if (send) 
    {
        	if (!rTrig) 
        {
            		packetId = mqttClient.publish(topic.c_str(), qos, retain, message.c_str());
            		if (packetId > 0) 
            {
                			rTrig = true;
                		
            }
            	
        }
    }
     else 
    {
        	rTrig = false;
        	qosDelivered = false;
    }
    if (packetId > 1 && packetId == pubPacketId) 
    {
        	qosDelivered = true;
        	packetId = 0;
    }
}
int hexStrToInt(String instring)
{
    byte len = instring.length();
    if  (len == 0) return 0;
    int result = 0;
    for (byte i = 0; i < 8; i++)    // только первые 8 цыфар влезуть в uint32
    {
        char ch = instring[i];
        if (ch == 0) break;
        result <<= 4;
        if (isdigit(ch))
        result = result | (ch - '0');
        else result = result | (ch - 'A' + 10);
    }
    return result;
}
void _esp8266WifiModuleClientReconnect()
{
    if(_checkMacAddres(ESPControllerWifiClient_mac)) 
    {
          wifi_set_macaddr(0, const_cast<uint8*>(ESPControllerWifiClient_mac));
    }
    if(ESPControllerWifiClient_isDHCP) 
    {
         WiFi.config(0U, 0U, 0U, 0U, 0U);
    }
     else 
    {
        WiFi.config(ESPControllerWifiClient_ip, ESPControllerWifiClient_gateway, ESPControllerWifiClient_subnet, ESPControllerWifiClient_dns , ESPControllerWifiClient_dns);
    }
    WiFi.begin(ESPControllerWifiClient_SSID, ESPControllerWifiClient_password);
}
bool _checkMacAddres(byte array[])
{
    bool result = 0;
    for (byte i = 0; i < 6; i++)
    {
        if (array[i] == 255) 
        {
            return 0;
        }
        if (array[i] > 0) 
        {
            result = 1;
        }
    }
    return result;
}
void _parseMacAddressString(String value, byte array[])
{
    int index;
    byte buffer[6] = {255, 255, 255, 255, 255, 255};
    byte raz = 0;
    String tempString;
    while ((value.length() > 0) && (raz <= 6)) 
    {
        index = value.indexOf(":");
        if (index == -1) 
        {
            tempString = value;
            value = "";
        }
         else 
        {
            tempString = value.substring(0, index);
            value = value.substring(index + 1);
        }
        buffer[raz] = byte(hexStrToInt(tempString));
        raz++;
    }
    if (_checkMacAddres(buffer))
    {
        for (byte i = 0; i < 6; i++)
        {
            array[i] = buffer[i];
        }
    }
}
bool _compareMacAddreses(byte array1[], byte array2[])
{
    for (byte i = 0; i < 6; i++)
    {
        if (array1[i] != array2[i]) 
        {
            return 0;
        }
    }
    return 1;
}
bool _compareMacAddresWithString(byte array[], String value)
{
    byte buffer[6] = {255, 255, 255, 255, 255, 255};
    _parseMacAddressString(value,  buffer);
    return _compareMacAddreses(array, buffer);
}
bool _checkMacAddresString(String value)
{
    byte buffer[6] = {255, 255, 255, 255, 255, 255};
    _parseMacAddressString(value,  buffer);
    return _checkMacAddres(buffer);
}
String _macAddresToString(byte array[])
{
    String result = "";
    String  temp ="";
    for (byte i = 0; i < 6; i++)
    {
        temp=String(array[i],HEX);
        if (temp.length()  < 2) 
        {
            temp = String("0") + temp;
        }
        result = result + temp;
        if (i < 5) 
        {
               result = result + String(":");
        }
    }
    result.toUpperCase();
    return result;
}
