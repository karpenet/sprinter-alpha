################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
INO_SRCS += \
../Sprinter.ino 

CPP_SRCS += \
../sloeber.ino.cpp 

LINK_OBJ += \
./sloeber.ino.cpp.o 

INO_DEPS += \
./Sprinter.ino.d 

CPP_DEPS += \
./sloeber.ino.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
Sprinter.o: ../Sprinter.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/tools/sdk/include" "-I/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/tools/sdk/lwip/include" -c -Wall -Wextra -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -ffunction-sections -fdata-sections -DF_CPU=80000000L  -DARDUINO=10802 -DARDUINO_ESP8266_ESP12 -DARDUINO_ARCH_ESP8266 -DESP8266  -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/cores/esp8266" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/variants/espino" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/libraries/ESP8266WiFi" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/libraries/ESP8266WiFi/src" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/libraries/Wire" -I"/Users/karpenet/Documents/workspace/Sprinter/libraries/Sprinter-I2CCommunication" -I"/Users/karpenet/Documents/workspace/Sprinter/libraries/Sprinter-Messages" -I"/Users/karpenet/Documents/workspace/Sprinter/libraries/Sprinter-WifiCommunication" -I"/Users/karpenet/Documents/workspace/Sprinter/libraries/Sprinter-WifiConfig" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

sloeber.ino.cpp.o: ../sloeber.ino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse//arduinoPlugin/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/tools/sdk/include" "-I/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/tools/sdk/lwip/include" -c -Wall -Wextra -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -ffunction-sections -fdata-sections -DF_CPU=80000000L  -DARDUINO=10802 -DARDUINO_ESP8266_ESP12 -DARDUINO_ARCH_ESP8266 -DESP8266  -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/cores/esp8266" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/variants/espino" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/libraries/ESP8266WiFi" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/libraries/ESP8266WiFi/src" -I"/Users/karpenet/Library/Arduino15/packages/esp8266/hardware/esp8266/2.2.0/libraries/Wire" -I"/Users/karpenet/Documents/workspace/Sprinter/libraries/Sprinter-I2CCommunication" -I"/Users/karpenet/Documents/workspace/Sprinter/libraries/Sprinter-Messages" -I"/Users/karpenet/Documents/workspace/Sprinter/libraries/Sprinter-WifiCommunication" -I"/Users/karpenet/Documents/workspace/Sprinter/libraries/Sprinter-WifiConfig" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


