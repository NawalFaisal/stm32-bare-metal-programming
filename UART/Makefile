CFLAGS = -mcpu=cortex-m4 -mthumb -nostdlib

all: firmware.elf

firmware.elf: startup.s main.c
	arm-none-eabi-gcc $(CFLAGS) -T link.ld startup.s main.c -o firmware.elf

clean:
	rm -f firmware.elf

flash:
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program firmware.elf verify reset exit"