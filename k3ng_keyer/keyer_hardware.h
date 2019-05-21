/*  keyer_hardware.h


  Edit this file to enable specific hardware profiles.

  When enabling a hardware option below, the default keyer_pin_settings.h, keyer_features_and_options.h, and keyer_settings.h files are not compiled.

  See the comments on each line to determine what files are compiled and should be customized.

*/

// #define HARDWARE_NANOKEYER_REV_D   // https://nanokeyer.wordpress.com/nanokeyer-info/  edit these files: keyer_pin_settings_nanokeyer_rev_d.h, keyer_features_and_options_nanokeyer_rev_d.h, keyer_settings_nanokeyer_rev_d.h  
 #define HARDWARE_K5BCQ   // edit these files: keyer_pin_settings_k5bcq.h, keyer_features_and_options_k5bcq.h, keyer_settings_k5bcq.h 
// #define HARDWARE_MEGAKEYER // https://github.com/w6ipa/megakeyer
// #define HARDWARE_TEST_EVERYTHING
// #define HARDWARE_TEST


/* 


    HARDWARE_GENERIC_STM32F103C  (Contributed by sp5iou)

      How to deal with those boards with Arduino: https://www.techshopbd.com/uploads/product_document/STM32bluepillarduinoguide(1).pdf


    Funtronics FK-10 Programming Notes (Contributed by Disneysw 2016-12-10)

      Programming the unit is accomplished by selecting "Mega2560" as the target processor and uploading to the rear USB port with the front
      switch set to the Arduino position

      Note: in order to get the FK-10 USB Host port working correctly you will need to patch the file "UsbCore.h" in the USB_Host_Shield library.
      At the time of writing it is line 41 that needs modified to change "P10" to "P53" i.e. from

           #else
             typedef MAX3421e<P10, P9> MAX3421E; // Official Arduinos (UNO, Duemilanove, Mega, 2560, Leonardo, Due etc.) or Teensy 2.0 and 3.0
           #endif

      to:

           #else
             typedef MAX3421e<P53, P9> MAX3421E; // Official Arduinos (UNO, Duemilanove, Mega, 2560, Leonardo, Due etc.) or Teensy 2.0 and 3.0
           #endif


*/


// Do not touch anything below this line!
// Serial port class definitions for various devices

#if defined(ARDUINO_MAPLE_MINI)||defined(ARDUINO_GENERIC_STM32F103C) //sp5iou 20180329
  #define PRIMARY_SERIAL_CLS USBSerial
  #define SECONDARY_SERIAL_CLS USBSerial 
#elif defined(ARDUINO_AVR_PROMICRO) || defined(ARDUINO_AVR_LEONARDO) || defined(ARDUINO_AVR_MICRO) || defined(ARDUINO_AVR_YUN) || defined(ARDUINO_AVR_ESPLORA) || defined(ARDUINO_AVR_LILYPAD_USB) || defined(ARDUINO_AVR_ROBOT_CONTROL) || defined(ARDUINO_AVR_ROBOT_MOTOR) || defined(ARDUINO_AVR_LEONARDO_ETH)
  #define PRIMARY_SERIAL_CLS Serial_
  #define SECONDARY_SERIAL_CLS Serial_ 
#elif defined(TEENSYDUINO)
  #define PRIMARY_SERIAL_CLS usb_serial_class
  #define SECONDARY_SERIAL_CLS usb_serial_class
#else
  #define PRIMARY_SERIAL_CLS HardwareSerial
  #define SECONDARY_SERIAL_CLS HardwareSerial 
#endif
  
