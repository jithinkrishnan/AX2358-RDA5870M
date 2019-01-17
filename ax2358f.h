#ifndef ax2358f_H_
#define ax2358f_H_

#include <IRremote.h>
//#include <IRremoteInt.h>
//#include <IRremoteTools.h>
#include <Arduino.h>
#include <Wire.h>
#include <EEPROM.h>
//#include <Encoder.h>


//ax2358 definitions - 6CH Audio Processor
#define AX2358F_ADDRESS      0x4A // Chip address - 0x94 >>1 => 0x4A 
#define AX2358F_IN6CH        0xCF
#define AX2358F_IN_FM        0xCB
#define AX2358F_IN_AUX1      0xCA
#define AX2358F_IN_AUX2      0xC9
#define AX2358F_IN_USB       0xC8

#define AX2358F_SURRENH_ON   0xD0
#define AX2358F_SURRENH_OFF  0xD1
#define AX2358F_MIXCHAN_0DB  0x90
#define AX2358F_MIXCHAN_6DB  0x91
#define AX2358F_FL_MUTE      0xF1
#define AX2358F_FL_UNMUTE    0xF0
#define AX2358F_FR_MUTE      0xF3
#define AX2358F_FR_UNMUTE    0xF2
#define AX2358F_RL_MUTE      0xF9
#define AX2358F_RL_UNMUTE    0xF8
#define AX2358F_RR_MUTE      0xFB
#define AX2358F_RR_UNMUTE    0xFA
#define AX2358F_CEN_MUTE     0xF5
#define AX2358F_CEN_UNMUTE   0xF4
#define AX2358F_SW_MUTE      0xF7
#define AX2358F_SW_UNMUTE    0xF6
#define AX2358F_ALL_MUTE     0xFF
#define AX2358F_ALL_UNMUTE   0xFE

#define AX2358F_FL_1DB       0x90
#define AX2358F_FL_10DB      0x80
#define AX2358F_FR_1DB       0x50
#define AX2358F_FR_10DB      0x40
#define AX2358F_RL_1DB       0x70
#define AX2358F_RL_10DB      0x60
#define AX2358F_RR_1DB       0xB0
#define AX2358F_RR_10DB      0xA0
#define AX2358F_CEN_1DB      0x10
#define AX2358F_CEN_10DB     0x00
#define AX2358F_SW_1DB       0x30
#define AX2358F_SW_10DB      0x20
#define AX2358F_ALLCH_1DB    0xE0
#define AX2358F_ALLCH_10DB   0xD0

//general constants
#define CHAN_ALL    0 // Master Volume
#define CHAN_FL     1 // Front channel Left Volume
#define CHAN_FR     2 // Front channel Right Volume
#define CHAN_RL     3 // Rear channel Left Volume
#define CHAN_RR     4 // Rear channel Right Volume
#define CHAN_CEN    5 // Centre Channel Volume
#define CHAN_SW     6 // Subwoofer Volume

#define FRONT_CHLS  7 // Front R+L Volume
#define REAR_CHLS   8 // Rear R+L Volume
#define CHAN_MUTE     9
#define CHAN_UNMUTE   10

#define OFFSET_FL   0
#define OFFSET_FR   1
#define OFFSET_RL   2
#define OFFSET_RR   3
#define OFFSET_CEN  4
#define OFFSET_SW   5
#define OFFSET_FRONT_CHLS  6
#define OFFSET_REAR_CHLS   7

#define INPUT_SURROUND  0
#define INPUT_FM        1
#define INPUT_AUX1      2
#define INPUT_AUX2      3
#define INPUT_USB       4

#define MIN_ATTENUATION         0
#define MAX_ATTENUATION         40
#define SERIAL_SPEED            9600
#define INITIAL_ENCODER_POS     -999
#define UNKNOWN_VALUE           -1
#define UNKNOWN_BYTE            99
#define ON  1
#define OFF 0
#define VOLUME_OFFSET_HALF  15

//defaults
#define DEFAULT_POWER       0
#define DEFAULT_VOLUME      30
#define DEFAULT_OFFSET      30
#define DEFAULT_INPUT       INPUT_SURROUND
#define DEFAULT_MUTE        0
#define DEFAULT_ENHANCEMENT 0
#define DEFAULT_MIXCH_BOOST 0

//Arduino pins
#define ENC_A       2
#define ENC_B       3
#define LED_CLK     5
#define LED_DATA    6
#define IR          7
//#define LED_EN1     8
//#define LED_EN2     9
#define BTN_COM       11
//#define MUTE_NEG    12
#define ONBOARD_LED   13
#define POWER_ON_LED  11
#define POWER_OFF_LED 12

// ONIX HT Remote
#define IR_VOLDOWN       0x807FA05F
#define IR_VOLUP         0x807F906F
#define IR_POWER         0x807F827D
#define IR_INPUT_DVD     0x807F20DF
#define IR_INPUT_AUX1    0x807F22DD 
#define IR_INPUT_AUX2    0x80 
#define IR_INPUT_FM      0x807FA25D 
#define IR_INPUT_USB     0x807F629D
#define IR_RESET_CFG     0x807F1AE5
#define IR_SURR_EN       0X807F02FD 
#define IR_MIX_CH_BOOST  0x38C728D7 // no key assigned
//#define IR_REPEAT        0xFFFFFFFF
#define IR_FRL_VOLUP     0X807F40BF
#define IR_FRL_VOLDOWN   0X807FC03F
#define IR_FRR_VOLUP     0X807F00FF
#define IR_FRR_VOLDOWN   0X807F807F 
#define IR_CT_VOLUP      0X807F50AF
#define IR_CT_VOLDOWN    0X807F609F
#define IR_RRL_VOLUP     0X807F48B7
#define IR_RRL_VOLDOWN   0X807FC837
#define IR_RRR_VOLUP     0X807F08F7
#define IR_RRR_VOLDOWN   0X807F8877
#define IR_MUTE_UNMUTE   0X807F42BD
#define IR_SUB_VOLUP     0x807FD02F
#define IR_SUB_VOLDOWN   0x807FE01F
#define IR_SAVE_CFG      0x807F12ED
#define IR_TUNE_UP       0x807F926D
#define IR_TUNE_DOWN     0x807FB04F
#define IR_CH_NEXT       0x807F32CD
#define IR_CH_PREV       0x807F728D
#define IR_SLEEP_UP      0x807F30CF
#define IR_SLEEP_DOWN    0x807FF00F



//EEPROM addresses
#define ADDR_INPUT          0
#define ADDR_MUTE           1
#define ADDR_ENHANCEMENT    2
#define ADDR_MIXCHBOOST     3
#define ADDR_MAINVOLUME     4
#define ADDR_OFFSET_FL      5
#define ADDR_OFFSET_FR      6
#define ADDR_OFFSET_RL      7
#define ADDR_OFFSET_RR      8
#define ADDR_OFFSET_CEN     9
#define ADDR_OFFSET_SUB     10

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
    void loop();
    void setup();
    void initAmp();
    void initRadio();
    void setInput(byte input);
    void setSurroundEnhancement(byte enhancement);
    void setMixerChannel6Db(byte mix6db);
    void setMute(byte mute);
    void increaseVolume();
    void decreaseVolume();
    void applyGlobalVolume();
    void setChannelVolume(byte channel, byte volume);
    void ax2358fAudioSwitching(byte command);
    void ax2358f(byte channel, byte value);
    void handleInfrared(unsigned long decodedValue);
    void storeParameters();
    void restoreParameters();
    void restoreDefaults();
    bool ValidateIRCode(unsigned long decodedValue);
    void blinkLed();
#ifdef __cplusplus
} // extern "C"
#endif

#endif

