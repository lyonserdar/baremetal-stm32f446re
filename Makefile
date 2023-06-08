CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0 -Wall -mfloat-abi=hard
LDFLAGS= -mcpu=$(MACH) -mthumb -specs=nano.specs -specs=nosys.specs -T stm32f446re.ld -Wl,-Map=final.map -mfloat-abi=hard
LDFLAGS_SH= -mcpu=$(MACH) -mthumb -specs=rdimon.specs -specs=nosys.specs -T stm32f446re.ld -Wl,-Map=final.map -mfloat-abi=hard

all: startup_stm32f446re.o syscalls.o main.o stm32f446re.o stm32f446re_gpio.o final.elf

sh: startup_stm32f446re.o main.o stm32f446re.o stm32f446re_gpio.o final_sh.elf

startup_stm32f446re.o: startup_stm32f446re.c
	$(CC) $(CFLAGS) -o $@ $^

syscalls.o.o: syscalls.c
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -o $@ $^

stm32f446re.o: stm32f446re.c
	$(CC) $(CFLAGS) -o $@ $^

stm32f446re_gpio.o: stm32f446re_gpio.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf: startup_stm32f446re.o syscalls.o main.o stm32f446re.o stm32f446re_gpio.o
	$(CC) $(LDFLAGS) -o $@ $^

final_sh.elf: startup_stm32f446re.o main.o stm32f446re.o stm32f446re_gpio.o
	$(CC) $(LDFLAGS_SH) -o $@ $^

clean:
	rm -rf *.o *.elf

upload:
	openocd -f board/st_nucleo_f4.cfg
