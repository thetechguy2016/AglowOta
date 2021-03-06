
# [AglowOTA](https://ota.aglow.co.in)

[<img src="https://camo.githubusercontent.com/a0d668eded16a6f9a285eca4ca3f7867eb543447/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f4275792532306d6525323061253230636f666665652d253234352d6f72616e67653f7374796c653d666f722d7468652d6261646765266c6f676f3d6275792d6d652d612d636f66666565" />](https://www.buymeacoffee.com/aglow)
---
## Product Overview

- AglowOTA provides over-the-air(OTA) service for your complete product line at a single place.
You can add as many Projects as you want. Each project has N number of products.
Have control over each product individually.

**The very first time we provide the functionallity to update n number of devices
just a click away.**

## We provide two different tracks to update your product for your ease.

* Test Track
  * It helps you to test your code on your testing devices just to make sure everything is perfect to go ahead with.
  * under test track the device will check every 2 minute, if is there any new update, The device will update automatically.
* Production Track
  * It will push your final code to the live devices installed all around the world.
  * under producting track we have two options to check for new version.
    * Device will check every 30 Minute if there is a new update, The device will update automatically.
    * Device will check every 60 Minute if there is a new update, The device will update automatically. **(Recommended)**
    
## Secure OTA Update

 * We use https to secure your device binary, which takes steps to verify that the address actually belongs to right organization, thus protecting your customers from man-in-the-middle attacks. When setting up your SSL certificate, ensure a high level of security by choosing a 2048-bit key.


## If you getting error while compiling
 * Check this below link and folow the instruction
 * https://github.com/arduino/Arduino/issues/10473#issuecomment-654114166
 * You can find the platform.txt of ESP8266 here
    * MacOS - /Users/username/Library/Arduino15/packages/esp8266/hardware/esp8266/2.7.1/platform.txt
    
## How to install

#### Manual Install ####
* For Windows: Download the Repository and extract the .zip inside Documents>Arduino>Libraries>{Place "AglowOTA" folder here}

* For Linux: Download the Repository and extract the .zip inside Sketchbook>Libraries>{Place "AglowOTA" folder here}

* For MacOS: Download the Repository and extract the .zip inside Users>username>Documents>Arduino>libraries>{Place "AglowOta" folder here}

#### Manually through IDE ####
* Download the Repository, Go to Sketch>Include Library>Add .zip Library> Select the Downloaded .zip File.

## Documentation
AglowOta provide a very simple way to add OTA functionality to your device.

### Auto Update

```
ota.setAutoUpdate(true);
ota.begin(product_id, project_id, mod, tim, currentVersion );
```

### Manual Update
```
ota.setCheckCallback(isAnyNewUpdate);
ota.begin(product_id, project_id, mod, tim, currentVersion);

void isAnyNewUpdate(uint16_t ver){
  Serial.println(ver);
  if(currentVersion > ver) {
      // update trigger in manual update
    ota.update();
  }
}
```

## Auto Update Sample Code

```

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
```

## Manual Update Sample Code

```
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

    //setting up callback for https check for new version
    ota.setCheckCallback(isAnyNewUpdate);
    ota.begin(product_id, project_id, mod, tim, currentVersion);

}

// this function returns the Live version avalable on the dashbard.
// here you can check the current version on device and the version available on dashboard
// if the version is greater then the current version udpdate the device.
void isAnyNewUpdate(uint16_t ver){
  Serial.println(ver);
  if(currentVersion > ver) {
      // update trigger in manual update
    ota.update();
  }
}

void loop() {}
```