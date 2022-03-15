# Copyright (c) 2020 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

if(${MBED_TOOLCHAIN} STREQUAL "GCC_ARM")
    set(STARTUP_FILE TOOLCHAIN_GCC_ARM/startup_stm32l151xc.S)
    set(LINKER_FILE TOOLCHAIN_GCC_ARM/stm32l151xc.ld)
elseif(${MBED_TOOLCHAIN} STREQUAL "ARM")
    set(STARTUP_FILE TOOLCHAIN_ARM/startup_stm32l151xc.S)
    set(LINKER_FILE TOOLCHAIN_ARM/stm32l151xc.sct)
endif()

add_library(mbed-unwr-range INTERFACE)

target_sources(mbed-unwr-range
    INTERFACE
        PeripheralPins.c
        system_clock.c
)

target_include_directories(mbed-unwr-range
    INTERFACE
        .
)

target_sources(mbed-unwr-range
    INTERFACE
        ${STARTUP_FILE}
)

target_link_libraries(mbed-unwr-range INTERFACE mbed-stm32l151xc)
