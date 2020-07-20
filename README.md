# [AglowOTA](https://ota.aglow.co.in)

[<img src="https://camo.githubusercontent.com/a0d668eded16a6f9a285eca4ca3f7867eb543447/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f4275792532306d6525323061253230636f666665652d253234352d6f72616e67653f7374796c653d666f722d7468652d6261646765266c6f676f3d6275792d6d652d612d636f66666565" />](https://www.buymeacoffee.com/aglow)
---
## Product Overview

- AglowOTA provides over-the-air(OTA) service for your complete product line at a single place.
You can add as many Projects as you want. Each project has N number of products.
Have control over each product individually.

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
    * MacOs - /Users/username/Library/Arduino15/packages/esp8266/hardware/esp8266/2.7.1/platform.txt
    
## How to install

#### Manual Install ####
* For Windows: Download the Repository and extract the .zip in Documents>Arduino>Libraries>{Place "AglowOTA" folder Here}

* For Linux: Download the Repository and extract the .zip in Sketchbook>Libraries>{Place "AglowOTA" folder Here}

#### Manually through IDE ####
* Download the Repository, Go to Sketch>Include Library>Add .zip Library> Select the Downloaded .zip File.
