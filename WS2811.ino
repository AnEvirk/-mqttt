#include <ESP8266WiFi.h>
#include "RT_HW_BASE.h"
#include "FastLED.h"
#include <Ticker.h>
#include <WiFiUdp.h>
#include <ESP8266mDNS.h>
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
bool Unsubscribe_77360925_3;
String Topic_77360925_3;
byte QoS_77360925_3;
bool Received_77360925_3;
String Message_77360925_3;
bool subscribed_77360925_3;
bool rTrig_77360925_3;
bool Unsubscribe_77360925_5;
String Topic_77360925_5;
byte QoS_77360925_5;
bool Received_77360925_5;
String Message_77360925_5;
bool subscribed_77360925_5;
bool rTrig_77360925_5;
bool Unsubscribe_77360925_4;
String Topic_77360925_4;
byte QoS_77360925_4;
bool Received_77360925_4;
String Message_77360925_4;
bool subscribed_77360925_4;
bool rTrig_77360925_4;
bool en_color_all;
int R;
int G;
int B;
bool Unsubscribe_77360925_1;
String Topic_77360925_1;
byte QoS_77360925_1;
bool Received_77360925_1;
String Message_77360925_1;
bool subscribed_77360925_1;
bool rTrig_77360925_1;
bool en_g;
byte brightness;
byte ballColors[3][3] = {  {0xff, 0, 0},   {0xff, 0xff, 0xff},   {0   , 0   , 0xff}, };
int BOTTOM_INDEX= 0; // светодиод начала отсчёта
int TOP_INDEX= int(200 / 2);
int EVENODD= 200 % 2;
CRGB leds[200];
int ledsX[200][3]; //-ARRAY FOR COPYING WHATS IN THE LED STRIP CURRENTLY (FOR CELL-AUTOMATA, MARCH, ETC)
int thisdelay= 20; //-FX LOOPS DELAY VAR
int thisstep= 10; //-FX LOOPS DELAY VAR
int thishue= 0; //-FX LOOPS DELAY VAR
int thissat= 255; //-FX LOOPS DELAY VAR
int thisindex= 0;
int thisRED= 0;
int thisGRN= 0;
int thisBLU= 0;
int idex= 0; //-LED INDEX (0 to LED_COUNT-1
int ihue= 0; //-HUE (0-255)
int ibright= 0; //-BRIGHTNESS (0-255)
int isat= 0; //-SATURATION (0-255)
int bouncedirection= 0; //-SWITCH FOR COLOR BOUNCE (0-1)
float tcount= 0.0; //-INC VAR FOR SIN LOOPS
int lcount= 0; //-ANOTHER COUNTING VAR
bool Unsubscribe_77360925_2;
String Topic_77360925_2;
byte QoS_77360925_2;
bool Received_77360925_2;
String Message_77360925_2;
bool subscribed_77360925_2;
bool rTrig_77360925_2;
bool Random_burst;
byte time_rb;
bool Pulse_one_color_all_rev;
byte time_ocar;
bool Rainbow_loop;
byte time_rl;
bool Rainbow_fade;
byte time_rf;
bool Ems_lightsALL;
byte time_elall;
bool Unsubscribe_77360925_6;
String Topic_77360925_6;
byte QoS_77360925_6;
bool Received_77360925_6;
String Message_77360925_6;
bool subscribed_77360925_6;
bool rTrig_77360925_6;
bool Unsubscribe_77360925_7;
String Topic_77360925_7;
byte QoS_77360925_7;
bool Received_77360925_7;
String Message_77360925_7;
bool subscribed_77360925_7;
bool rTrig_77360925_7;
bool Unsubscribe_77360925_8;
String Topic_77360925_8;
byte QoS_77360925_8;
bool Received_77360925_8;
String Message_77360925_8;
bool subscribed_77360925_8;
bool rTrig_77360925_8;
bool Unsubscribe_77360925_9;
String Topic_77360925_9;
byte QoS_77360925_9;
bool Received_77360925_9;
String Message_77360925_9;
bool subscribed_77360925_9;
bool rTrig_77360925_9;
bool ESPControllerWifiClient_HRD = 0;
bool ESPControllerWifiClient_status = 1;
bool ESPControllerWifiClient_isDHCP = 0;
bool ESPControllerWifiClient_IsNeedReconect = 0;
bool ESPControllerWifiClient_workStatus = 1;
char ESPControllerWifiClient_SSID[40] = "408";
char ESPControllerWifiClient_password[40] = "408408408spb";
IPAddress ESPControllerWifiClient_ip(192, 168, 0, 109);
IPAddress  ESPControllerWifiClient_dns (192, 168, 0, 1);
IPAddress  ESPControllerWifiClient_gateway (192, 168, 0, 1);
IPAddress ESPControllerWifiClient_subnet (255, 255, 255, 0);
uint8_t ESPControllerWifiClient_mac[6] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
bool _otaUpadterStatus = 0;
bool _gtv2;
bool _gtv1;
bool _changeNumber3_Out = 0;
float _changeNumber3_OLV;
float _strFunmax3 = 0.00;
bool _trgt2 = 0;
bool _trgt2I = 0;
bool _trgt6 = 0;
bool _trgt6I = 0;
bool _trgt3 = 0;
bool _trgt3I = 0;
float _strFunmax1 = 0.00;
bool _trgr2 = 0;
bool _gen2I = 0;
bool _gen2O = 0;
unsigned long _gen2P = 0UL;
bool _changeNumber4_Out = 0;
float _changeNumber4_OLV;
bool _gen1I = 0;
bool _gen1O = 0;
unsigned long _gen1P = 0UL;
int _convertStringToNamberOutput_5 = 0;
bool _tim1I = 0;
bool _tim1O = 0;
unsigned long _tim1P = 0UL;
bool _trgt4 = 0;
bool _trgt4I = 0;
int _convertStringToNamberOutput_3 = 0;
float _strFunmax2 = 0.00;
bool _changeNumber5_Out = 0;
float _changeNumber5_OLV;
bool _changeNumber1_Out = 0;
float _changeNumber1_OLV;
bool _changeNumber2_Out = 0;
float _changeNumber2_OLV;
bool _count2I = 0;
int _count2_Value = 0;
bool _count2MaxLO = 0;
bool _count2MinLO = 0;
bool _trgt5 = 0;
bool _trgt5I = 0;
bool _trgt1 = 0;
bool _trgt1I = 0;
int _convertStringToNamberOutput_4 = 0;
bool _changeNumber6_Out = 0;
float _changeNumber6_OLV;
String _tempVariable_String;
float _tempVariable_float;
void setup()
{
    WiFi.mode(WIFI_STA);
    _esp8266WifiModuleClientReconnect();
    wifiConnectHandler = WiFi.onStationModeGotIP(onWifiConnect);
    wifiDisconnectHandler = WiFi.onStationModeDisconnected(onWifiDisconnect);
    mqttClient.onMessage(onMqttMessage);
    mqttClient.onConnect(onMqttConnect);
    mqttClient.onDisconnect(onMqttDisconnect);
    mqttClient.onPublish(onMqttPublish);
    mqttClient.setKeepAlive(15);
    mqttClient.setCleanSession(0);
    LEDS.setBrightness(100);
    LEDS.addLeds<WS2811, 2, GRB>(leds, 200);
    one_color_all(0, 0, 0);
    LEDS.show();
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
            ArduinoOTA.setHostname ("WS2811");
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
//Наименование:Включение цветов по отдельности ws2811
    en_g = !(0);
    brightness = 255;
    if (en_g) 
    {
        LEDS.setBrightness(brightness);
        mqttServer = String("m6.wqtt.ru");
        mqttPort = 11954;
        mqttUser = String("u_FX3M2T");
        mqttPassword = String("aDR7R4tC");
        mqttClientId = String("WS2811");
        if (!(0)) 
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
                 if (_isTimer(_gen1P , 601000)) 
                {
                      _gen1P = millis();
                    _gen1O = 1;
                }
            }
        }
        Unsubscribe_77360925_3 = 0;
        Topic_77360925_3 = String("R");
        QoS_77360925_3 = 0;
        sub(Topic_77360925_3, Message_77360925_3, QoS_77360925_3, Received_77360925_3, subscribed_77360925_3, Unsubscribe_77360925_3, rTrig_77360925_3);
        _tempVariable_String = Message_77360925_3;
        _convertStringToNamberOutput_5 = strtol(_tempVariable_String.c_str(),NULL,10);
        Unsubscribe_77360925_1 = 0;
        Topic_77360925_1 = String("NiceLight");
        QoS_77360925_1 = 0;
        sub(Topic_77360925_1, Message_77360925_1, QoS_77360925_1, Received_77360925_1, subscribed_77360925_1, Unsubscribe_77360925_1, rTrig_77360925_1);
        Unsubscribe_77360925_4 = 0;
        Topic_77360925_4 = String("B");
        QoS_77360925_4 = 0;
        sub(Topic_77360925_4, Message_77360925_4, QoS_77360925_4, Received_77360925_4, subscribed_77360925_4, Unsubscribe_77360925_4, rTrig_77360925_4);
        _tempVariable_String = Message_77360925_4;
        _convertStringToNamberOutput_4 = strtol(_tempVariable_String.c_str(),NULL,10);
        if (_changeNumber2_Out) 
        {
            _changeNumber2_Out = 0;
        }
         else 
        {
            _tempVariable_float = (_stringToFloat(Message_77360925_1));
            if (_tempVariable_float != _changeNumber2_OLV) 
            {
                _changeNumber2_OLV = _tempVariable_float;
                _changeNumber2_Out = 1;
            }
        }
        if(((_gtv2) || (_gtv1))) _trgr2 = 0;
        if(_changeNumber2_Out) _trgr2 = 1;
        if (_trgr2) 
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
                 if (_isTimer(_gen2P , 10)) 
                {
                      _gen2P = millis();
                    _gen2O = 1;
                }
            }
        }
        bool  _tmp2 = _changeNumber2_Out;
        if (_tmp2)  
        {
             if (! _trgt2I) _trgt2 = ! _trgt2;
        }
        _trgt2I = _tmp2;
        if (_gen2O)
        {
            if (! _count2I) 
            {
                _count2I = 1;
                if (_trgt2)
                {
                    _count2_Value = _count2_Value + 1;
                }
                 else
                {
                     _count2_Value = _count2_Value - 1;
                }
            }
        }
         else 
        {
            _count2I = 0;
        }
        _count2MaxLO = _count2_Value >= 255;
        _count2MinLO = _count2_Value <= 0;
        if(_count2_Value >= 255) 
        {
            _count2_Value = 255;
        }
        else 
        {
            if(_count2_Value <= 0) 
            {
                _count2_Value = 0;
            }
        }
        if(((map((_count2_Value), (0), (255), (0), (143)))) > (_convertStringToNamberOutput_4)) 
        {
            _strFunmax3 = (map((_count2_Value), (0), (255), (0), (143)));
        }
         else 
        {
            _strFunmax3 = _convertStringToNamberOutput_4;
        }
        Unsubscribe_77360925_5 = 0;
        Topic_77360925_5 = String("G");
        QoS_77360925_5 = 0;
        sub(Topic_77360925_5, Message_77360925_5, QoS_77360925_5, Received_77360925_5, subscribed_77360925_5, Unsubscribe_77360925_5, rTrig_77360925_5);
        _tempVariable_String = Message_77360925_5;
        _convertStringToNamberOutput_3 = strtol(_tempVariable_String.c_str(),NULL,10);
        if(((map((_count2_Value), (0), (255), (0), (224)))) > (_convertStringToNamberOutput_3)) 
        {
            _strFunmax2 = (map((_count2_Value), (0), (255), (0), (224)));
        }
         else 
        {
            _strFunmax2 = _convertStringToNamberOutput_3;
        }
        if(((Received_77360925_3) || (((Received_77360925_5) || (((Received_77360925_4) || (Received_77360925_1))))))) 
        {
            _tim1O = 1;
            _tim1I = 1;
        }
         else 
        {
             if(_tim1I) 
            {
                _tim1I = 0;
                _tim1P = millis();
            }
             else 
            {
                 if (_tim1O) 
                {
                    if (_isTimer(_tim1P, 10000)) _tim1O = 0;
                }
            }
        }
        if(((map((_count2_Value), (0), (255), (0), (255)))) > (_convertStringToNamberOutput_5)) 
        {
            _strFunmax1 = (map((_count2_Value), (0), (255), (0), (255)));
        }
         else 
        {
            _strFunmax1 = _convertStringToNamberOutput_5;
        }
        en_color_all = ((_gen1O) || (_tim1O));
        R = _strFunmax2;
        G = _strFunmax1;
        B = _strFunmax3;
        if (en_color_all) 
        {
            		one_color_all (R, G, B);
            	
            		LEDS.show();
            	
        }
        _gtv1 = _count2MinLO;
        _gtv2 = _count2MaxLO;
        //Плата:2
//Наименование:Анимации
        Unsubscribe_77360925_2 = 0;
        Topic_77360925_2 = String("RB");
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
        bool  _tmp1 = _changeNumber1_Out;
        if (_tmp1)  
        {
             if (! _trgt1I) _trgt1 = ! _trgt1;
        }
        _trgt1I = _tmp1;
        Random_burst = _trgt1;
        time_rb = 40;
        if (Random_burst) 
        {
            thisdelay = time_rb;
            					      thissat =  255;
            						random_burst();
            					
        }
        Unsubscribe_77360925_6 = 0;
        Topic_77360925_6 = String("POC");
        QoS_77360925_6 = 0;
        sub(Topic_77360925_6, Message_77360925_6, QoS_77360925_6, Received_77360925_6, subscribed_77360925_6, Unsubscribe_77360925_6, rTrig_77360925_6);
        if (_changeNumber3_Out) 
        {
            _changeNumber3_Out = 0;
        }
         else 
        {
            _tempVariable_float = (_stringToFloat(Message_77360925_6));
            if (_tempVariable_float != _changeNumber3_OLV) 
            {
                _changeNumber3_OLV = _tempVariable_float;
                _changeNumber3_Out = 1;
            }
        }
        bool  _tmp3 = _changeNumber3_Out;
        if (_tmp3)  
        {
             if (! _trgt3I) _trgt3 = ! _trgt3;
        }
        _trgt3I = _tmp3;
        Pulse_one_color_all_rev = _trgt3;
        time_ocar = 40;
        if (Pulse_one_color_all_rev) 
        {
            thisdelay  = time_ocar;
            					              thishue = 0;
            						        pulse_one_color_all_rev();
            					
        }
        Unsubscribe_77360925_7 = 0;
        Topic_77360925_7 = String("RL");
        QoS_77360925_7 = 0;
        sub(Topic_77360925_7, Message_77360925_7, QoS_77360925_7, Received_77360925_7, subscribed_77360925_7, Unsubscribe_77360925_7, rTrig_77360925_7);
        if (_changeNumber4_Out) 
        {
            _changeNumber4_Out = 0;
        }
         else 
        {
            _tempVariable_float = (_stringToFloat(Message_77360925_7));
            if (_tempVariable_float != _changeNumber4_OLV) 
            {
                _changeNumber4_OLV = _tempVariable_float;
                _changeNumber4_Out = 1;
            }
        }
        bool  _tmp4 = _changeNumber4_Out;
        if (_tmp4)  
        {
             if (! _trgt4I) _trgt4 = ! _trgt4;
        }
        _trgt4I = _tmp4;
        Rainbow_loop = _trgt4;
        time_rl = 40;
        if (Rainbow_loop) 
        {
            thisdelay = time_rl;
            					  thisstep =  10 ;
            					  thissat =  255;
            					  rainbow_loop();
            					
        }
        Unsubscribe_77360925_8 = 0;
        Topic_77360925_8 = String("RF");
        QoS_77360925_8 = 0;
        sub(Topic_77360925_8, Message_77360925_8, QoS_77360925_8, Received_77360925_8, subscribed_77360925_8, Unsubscribe_77360925_8, rTrig_77360925_8);
        if (_changeNumber5_Out) 
        {
            _changeNumber5_Out = 0;
        }
         else 
        {
            _tempVariable_float = (_stringToFloat(Message_77360925_8));
            if (_tempVariable_float != _changeNumber5_OLV) 
            {
                _changeNumber5_OLV = _tempVariable_float;
                _changeNumber5_Out = 1;
            }
        }
        bool  _tmp5 = _changeNumber5_Out;
        if (_tmp5)  
        {
             if (! _trgt5I) _trgt5 = ! _trgt5;
        }
        _trgt5I = _tmp5;
        Rainbow_fade = _trgt5;
        time_rf = 40;
        if (Rainbow_fade) 
        {
            thisdelay =  time_rf ;
            					   thissat =  255;
            					   rainbow_fade();
            					
        }
        Unsubscribe_77360925_9 = 0;
        Topic_77360925_9 = String("PLS");
        QoS_77360925_9 = 0;
        sub(Topic_77360925_9, Message_77360925_9, QoS_77360925_9, Received_77360925_9, subscribed_77360925_9, Unsubscribe_77360925_9, rTrig_77360925_9);
        if (_changeNumber6_Out) 
        {
            _changeNumber6_Out = 0;
        }
         else 
        {
            _tempVariable_float = (_stringToFloat(Message_77360925_9));
            if (_tempVariable_float != _changeNumber6_OLV) 
            {
                _changeNumber6_OLV = _tempVariable_float;
                _changeNumber6_Out = 1;
            }
        }
        bool  _tmp6 = _changeNumber6_Out;
        if (_tmp6)  
        {
             if (! _trgt6I) _trgt6 = ! _trgt6;
        }
        _trgt6I = _tmp6;
        Ems_lightsALL = _trgt6;
        time_elall = 40;
        if (Ems_lightsALL) 
        {
            thisdelay = time_elall;
            					   thishue = 255;
            					   thissat =  125;
            						ems_lightsALL();
            					
        }
        //Плата:3
//Наименование:Последний ws2811
    }
}
float  _stringToFloat(String value)
{
    return value.toFloat() ;
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
void one_color_all(int cred, int cgrn, int cblu)
{
    for (int i = 0 ; i < 200; i++) 
    {
        leds[i].setRGB(cred, cgrn, cblu);
    }
}
void one_color_allHSV(int ahue)
{
     //-SET ALL LEDS TO ONE COLOR (HSV)
      for (int i = 0 ; i < 200; i++) 
    {
        leds[i] = CHSV(ahue, thissat, 255);
    }
}
void set_color_led(int adex, int cred, int cgrn, int cblu)
{
      leds[adex].setRGB(cred, cgrn, cblu);
}
int horizontal_index(int i)
{
    //-ONLY WORKS WITH INDEX < TOPINDEX
      if (i == BOTTOM_INDEX) 
    {
        return BOTTOM_INDEX;
    }
    if (i == TOP_INDEX && EVENODD == 1) 
    {
        return TOP_INDEX + 1;
    }
    if (i == TOP_INDEX && EVENODD == 0) 
    {
        return TOP_INDEX;
    }
    return 200 - i;
}
int antipodal_index(int i)
{
    int iN = i + TOP_INDEX;
    if (i >= TOP_INDEX) 
    {
        iN = (i + TOP_INDEX) % 200;
    }
    return iN;
}
int adjacent_cw(int i)
{
    int r;
    if (i < 200 - 1) 
    {
        r = i + 1;
    }
    else 
    {
        r = 0;
    }
    return r;
}
int adjacent_ccw(int i)
{
    int r;
    if (i > 0) 
    {
        r = i - 1;
    }
    else 
    {
        r = 200 - 1;
    }
    return r;
}
void copy_led_array()
{
      for (int i = 0; i < 200; i++) 
    {
        ledsX[i][0] = leds[i].r;
        ledsX[i][1] = leds[i].g;
        ledsX[i][2] = leds[i].b;
    }
}
void setPixel(int Pixel, byte red, byte green, byte blue)
{
    leds[Pixel].r = red;
    leds[Pixel].g = green;
    leds[Pixel].b = blue;
}
void setAll(byte red, byte green, byte blue)
{
    for (int i = 0; i < 200; i++) 
    {
        setPixel(i, red, green, blue);
    }
    FastLED.show();
}
void random_burst()
{
    idex = random(0, 200);
    ihue = random(0, 255);
    leds[idex] = CHSV(ihue, thissat, 255);
    LEDS.show();
    delay(thisdelay);
}
void pulse_one_color_all_rev()
{
    if (bouncedirection == 0) 
    {
        isat++;
        if (isat >= 255) 
        {
            bouncedirection = 1;
        }
    }
    if (bouncedirection == 1) 
    {
        isat = isat - 1;
        if (isat <= 1) 
        {
            bouncedirection = 0;
        }
    }
    for (int idex = 0 ; idex < 200; idex++) 
    {
        leds[idex] = CHSV(thishue, isat, 255);
    }
    LEDS.show();
    delay(thisdelay);
}
void rainbow_loop()
{
    idex++;
    ihue = ihue + thisstep;
    if (idex >= 200) 
    {
        idex = 0;
    }
    if (ihue > 255) 
    {
        ihue = 0;
    }
    leds[idex] = CHSV(ihue, thissat, 255);
    LEDS.show();
    delay(thisdelay);
}
void rainbow_fade()
{
    ihue++;
    if (ihue > 255) 
    {
        ihue = 0;
    }
    for (int idex = 0 ; idex < 200; idex++) 
    {
        leds[idex] = CHSV(ihue, thissat, 255);
    }
    LEDS.show();
    delay(thisdelay);
}
void ems_lightsALL()
{
    idex++;
    if (idex >= 200) 
    {
        idex = 0;
    }
    int idexR = idex;
    int idexB = antipodal_index(idexR);
    int thathue = (thishue + 160) % 255;
    leds[idexR] = CHSV(thishue, thissat, 255);
    leds[idexB] = CHSV(thathue, thissat, 255);
    LEDS.show();
    delay(thisdelay);
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
