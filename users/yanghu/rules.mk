SRC += tap_hold.c \
			 combo.c \
			 process_record.c

TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
  SRC += oled.c
endif
