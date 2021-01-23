#ifndef SETTINGS_H
#define SETTINGS_H

// ===== Light Settings
#define LIGHTS_OFF LOW
#define LIGHTS_DIM_LEVEL 20 // 0 to 255
#define LIGHTS_BRIGHT_LEVEL 255 // 0 to 255

#define LIGHT_INDICATOR_FLASH_PERIOD_MILLISECONDS 500UL // must be UL, amount of time between indicator flashes

// ===== BEEP Settings
#define BUZZER_FREQUENCY 400

// ===== Sensor Settings
#define AMBIENT_LIGHT_THRESHOLD 700

// ===== Controller Settings
#define RF_CONTROLLER_ID 0
#define RF_CAR_ID 1
#define CONTROLLER_ANALOG_MAX_VALUE 512

// ===== Motor Settings
#define MOTOR_MAX_SPEED 255

#endif