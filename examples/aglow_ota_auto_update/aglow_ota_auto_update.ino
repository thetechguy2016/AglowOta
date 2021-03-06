#include "ota_https.h"



#define WIFI_SSID "Aglow"
#define WIFI_PASSWORD "aglowbytickle"


/*
In test mode the api will check every 2 minute for testing purpose
as we have two different track please use TEST for testing purpose only as we 
have to pay so much for the cloud call. and we give this service for free.
If you like our service please donate so that we can keep working for every one.
https://www.buymeacoffee.com/aglow
*/

DEV_MODE mod = TEST; // and "PROD" for production device

CHECK_TIME tim = MIN30; // and "MIN60" to check every 60 MIN
uint16_t currentVersion = 456;

void isAnyNewUpdate(uint16_t ver);
String project_id = "-MABYaaxuPPlubL9ThXH";
String product_id = "-MABZxCVaNXrxn0cTPdS";

OtaHttps ota;

void setup()
{
    Serial.begin(115200);
    while (!Serial){}

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }

    ota.setAutoUpdate(true);
    /*
    This library will check the server every 30 Min or 60 Min based on what to select,
    whenevery it will find version > then current version it will push new update.
    */
    ota.begin(product_id, project_id, mod, tim, currentVersion);

}


void loop() {}