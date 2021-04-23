// I2C Eavesdropper Class
// Modified by Lydia Calderon-Aceituno and Matthew Lochridge

/* mbed Microcontroller Library
 * Copyright (c) 2006-2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "drivers/I2CEve.h"

// #if DEVICE_I2CSLAVE

namespace mbed {

I2CEve::I2CEve(PinName sda, PinName scl) : _i2c()
{
    i2c_init(&_i2c, sda, scl);
    i2c_frequency(&_i2c, 100000);
    i2c_slave_mode(&_i2c, 1);
}

I2CEve::I2CEve(const i2c_pinmap_t &static_pinmap) : _i2c()
{
    i2c_init_direct(&_i2c, &static_pinmap);
    i2c_frequency(&_i2c, 100000);
    i2c_slave_mode(&_i2c, 1);
}

void I2CEve::frequency(int hz)
{
    i2c_frequency(&_i2c, hz);
}

void I2CEve::address(int address)
{
    int addr = (address & 0xFF) | 1;
    i2c_slave_address(&_i2c, 0, addr, 0);
}

int I2CEve::receive(void)
{
    return i2c_slave_receive(&_i2c);
}

int I2CEve::read(char *data, int length)
{
    return i2c_slave_read(&_i2c, data, length) != length;
}

int I2CEve::read(void)
{
    return i2c_byte_read(&_i2c, 0);
}

void I2CEve::stop(void)
{
    i2c_stop(&_i2c);
}

}

#endif
