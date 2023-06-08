### To run the openocd
```
make upload
```

### To run the gdb
```
arm-none-eabi-gdb
```
```
target remote localhost:3333
```
```
monitor reset init
```
```
monitor flash write_image erase final.elf
```
```
monitor reset halt
```
```
monitor reset
```
```
monitor halt
```

```
monitor resume
```
### Semihosting
```
monitor arm semihosting enable
```
```
monitor flash write_image erase final.elf
```
```
monitor reset
```
```
quit
```

