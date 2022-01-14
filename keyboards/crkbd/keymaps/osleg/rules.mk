OLED_ENABLE = yes
OLED_DRIVER = SSD1306

WPM_ENABLE = no

BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE = no

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
RGB_MATRIX_CUSTOM_USER = no

LTO_ENABLE = yes



BOOTMAGIC_ENABLE = no     # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no       # Mouse keys
#EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
NKRO_ENABLE = yes            # USB Nkey Rollover
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output

ifeq ($(strip $(CUSTOM_DRASHNA_CODE_ENABLED)), yes)
	SRC += ./caps_word.c \
				 ./unicode.c \
				 ./callbacks.c \
				 ./drashna.c \
				 ./keyrecords/process_records.c
endif

VIM_MODE = yes
ifeq ($(strip $(VIM_MODE)), yes)
	SRC += ./vimmode.c
endif
