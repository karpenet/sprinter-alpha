################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/cores/esp8266/libb64/cdecode.c \
/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/cores/esp8266/libb64/cencode.c 

C_DEPS += \
./core/core/libb64/cdecode.c.d \
./core/core/libb64/cencode.c.d 

AR_OBJ += \
./core/core/libb64/cdecode.c.o \
./core/core/libb64/cencode.c.o 


# Each subdirectory must supply rules for building sources it contributes
core/core/libb64/cdecode.c.o: /Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/cores/esp8266/libb64/cdecode.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/Applications/Eclipse.app/Contents/Eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/tools/sdk/include" "-I/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/tools/sdk/lwip/include" -c -Wall -Wextra -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L  -DARDUINO=10802 -DARDUINO_ESP8266_ESP12 -DARDUINO_ARCH_ESP8266 -DESP8266  -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/cores/esp8266" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/variants/espino" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/libraries/ESP8266WiFi" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/libraries/ESP8266WiFi/src" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/libraries/Wire" -I"/Users/karpenet/Documents/workspace/Sprinter/libraries/Sprinter-I2CCommunication" -I"/Users/karpenet/Documents/workspace/Sprinter/libraries/Sprinter-Messages" -I"/Users/karpenet/Documents/workspace/Sprinter/libraries/Sprinter-WifiCommunication" -I"/Users/karpenet/Documents/workspace/Sprinter/libraries/Sprinter-WifiConfig" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/libb64/cencode.c.o: /Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/cores/esp8266/libb64/cencode.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/Applications/Eclipse.app/Contents/Eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/tools/sdk/include" "-I/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/tools/sdk/lwip/include" -c -Wall -Wextra -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L  -DARDUINO=10802 -DARDUINO_ESP8266_ESP12 -DARDUINO_ARCH_ESP8266 -DESP8266  -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/cores/esp8266" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/variants/espino" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/libraries/ESP8266WiFi" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/libraries/ESP8266WiFi/src" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/libraries/Wire" -I"/Users/karpenet/Documents/workspace/Sprinter/libraries/Sprinter-I2CCommunication" -I"/Users/karpenet/Documents/workspace/Sprinter/libraries/Sprinter-Messages" -I"/Users/karpenet/Documents/workspace/Sprinter/libraries/Sprinter-WifiCommunication" -I"/Users/karpenet/Documents/workspace/Sprinter/libraries/Sprinter-WifiConfig" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


