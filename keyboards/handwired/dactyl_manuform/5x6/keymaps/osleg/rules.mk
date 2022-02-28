EXTRAFLAGS += -flto
RGBLIGHT_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER_ENABLE = yes
LTO_ENABLE = yes
RAW_ENABLE = no
NKRO_ENABLE = yes

VELOCIKEY_ENABLE = no
WPM_ENABLE = no


DEBOUNCE_TYPE = sym_eager_pk

VIM_MODE = yes
ifeq ($(strip $(VIM_MODE)), yes)
	SRC += ./vimmode.c
endif

CAPS_WORDS = yes
ifeq ($(strip $(CAPS_WORDS)), yes)
	SRC += ./caps_word.c
endif



BOOTMAGIC_ENABLE = no     # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no       # Mouse keys
#EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output
AUTO_SHIFT_ENABLE = no      # THIS IS HUGE

