#ifndef OTA_HTTPS
#define OTA_HTTPS

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  //#include "WProgram.h"
#endif

// #include <ESP8266WiFi.h>
// #include <EEPROM.h>
// #include <WiFiClientSecureBearSSL.h>
// #include <ESP8266HTTPClient.h>

#include <WiFiClientSecure.h>
#include <ESP8266httpUpdate.h>
#include "Ticker.h"

//EWPI
//EWM

enum DEV_MODE{
  TEST,
  PROD
};

enum CHECK_TIME{
  MIN30,
  MIN60
};

#define SSL_CLIENT BearSSL::WiFiClientSecure
#define ATOMIC_FS_UPDATE

class OtaHttps
{
  private:
      // function
      String fileUrl();
      void setNtpClock();
      void checkForUpdates();
      void setCallbacks();
      void _prepareOtaUrl(String ver);
      // variables

      String pdId;
      String pjId;
      uint16_t FW_VERSION = 0;
      String deviceMode = "";
      
      void Update();
      SSL_CLIENT client;
      Ticker _clockTicker;
      Ticker _checkTicker;
      //client.setX509Time(1593013662);

  public:
      // product id and project id with device Mode
      void begin(String pdId, String pjId, DEV_MODE mod, CHECK_TIME tim , uint16_t fwVersion);
      void setInsecure();
      void update_started();
      void update_finished();
      void update_progress(int cur, int total);
      void update_error(int err);
};

#endif