# Follow Bot
Follow Bot is an Arduino bot moves by 4 DC motors that navigates by ultra-sonic and infrared sensors.  The bot is powered by a 12 volt power supply with a 3 prong rocker switch for easy on/off
![Follow Bot](https://i.imgur.com/UTKvsoD.jpg?2)

## Prerequisites / Dependencies
* [Arduino IDE](https://www.arduino.cc/en/software)
* [Adafruit Motor Shield Library](https://learn.adafruit.com/adafruit-motor-shield/library-install)

## Parts and Materials
| Link | Image |
| ---- | :----: |
[Arduino UNO](https://www.amazon.com/gp/product/B008GRTSV6/ref=ppx_yo_dt_b_asin_title_o05_s01?ie=UTF8&psc=1) | ![Arduino UNO](https://i.imgur.com/P2OkzD2.jpg?2)
[4WD 2 Layer Smart Robot Car Chassis Kit](https://www.amazon.com/gp/product/B075LD4FPN/ref=ppx_yo_dt_b_asin_title_o05_s02?ie=UTF8&psc=1) | ![Chassis Kit](https://i.imgur.com/hdt89Wt.jpg)
[L293D Motor Drive Shield](https://www.amazon.com/gp/product/B01FVJQWAQ/ref=ppx_yo_dt_b_asin_title_o02_s01?ie=UTF8&psc=1) | ![Motor Drive Shield](https://i.imgur.com/n9J1S71.jpg?2)
[Ultrasonic Module HC-SR04](https://www.amazon.com/gp/product/B01JG09DCK/ref=ppx_yo_dt_b_asin_title_o05_s00?ie=UTF8&psc=1) | ![Ultrasonic](https://i.imgur.com/TwpwVXW.jpg?2)
[IR Infrared Sensor](https://www.amazon.com/gp/product/B01I57HIJ0/ref=ppx_yo_dt_b_asin_title_o04_s01?ie=UTF8&psc=1) | ![Infrared Sensor](https://i.imgur.com/4sfu7bH.jpg?2)
Soldering Iron | ![Soldering Iron](https://i.imgur.com/e4BuTGIt.jpg?1)
[M/M Jumper Wires](https://www.amazon.com/gp/product/B07XMG9LSZ/ref=ppx_yo_dt_b_asin_title_o05_s00?ie=UTF8&psc=1) | 
[Battery Holder](https://www.amazon.com/gp/product/B014YSFMXI/ref=ppx_yo_dt_b_asin_title_o05_s03?ie=UTF8&psc=1) | 
[Rocker Switch](https://www.amazon.com/gp/product/B07WBWVP4J/ref=ppx_yo_dt_b_asin_title_o04_s02?ie=UTF8&psc=1) | 
  
## Testing and Assembly
The chassis kit includes instructions so the assembly was fairly straight forward, however the 4 AA battery pack didnt not supply enough power and had to substituted for a 6 AA battery pack. To attach additional analong sensors to the motor shield, you will need to solder on additional header connectors to the open A0-A5 pin holes. The rocker switch will also have to be connected to the battery pack to supply power to the Arduino. 

![Chassis Assembly](https://i.imgur.com/Wl8qOiK.jpg?2)
![Attach Headers 1](https://i.imgur.com/Q8JbIOd.jpg?2)
![Attach Headers 2](https://i.imgur.com/MpqulGs.jpg?2)

## Final Product 
![FollowBot](https://i.imgur.com/UTKvsoD.jpg?2)  
![FollowBot - Gif](https://i.imgur.com/qZ82uqZ.gifv)
