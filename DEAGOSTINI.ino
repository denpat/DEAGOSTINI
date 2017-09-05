/* -*- c++ -*- */

/*
    This firmware is UNOFFICIAL version of the original Marlin
Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm.

This is a modified version partially rewrited by Dennis Patella (Ðen) WASProject on 2014/2015 
http://www.wasproject.it
and adapted for WASP DELTA PRINTERS and WASP HARDWARE 
The use with different hardware is absolutely not tested and not recommended
Some improvements: 
- full compatibility with DELTA WASP MACHINES
- Integrated recovery print
- Emergency stop with print rescue
- Manual levelling delta
- improvement in changing filament (M600)
- pause M25 with extruder lifting
- some additional lcd menu
- ...and much more
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 */

#include "Configuration.h"
#include "pins.h"

#ifdef ULTRA_LCD
  #if defined(LCD_I2C_TYPE_PCF8575)
    #include <Wire.h>
    #include <LiquidCrystal_I2C.h>
  #elif defined(LCD_I2C_TYPE_MCP23017) || defined(LCD_I2C_TYPE_MCP23008)
    #include <Wire.h>
    #include <LiquidTWI2.h>
  #elif defined(DOGLCD)
    #include <U8glib.h> // library for graphics LCD by Oli Kraus (https://code.google.com/p/u8glib/)
  #else
    #include <LiquidCrystal.h> // library for character LCD
  #endif
#endif

#if defined(DIGIPOTSS_PIN) && DIGIPOTSS_PIN > -1
#include <SPI.h>
#endif

#if defined(DIGIPOT_I2C)
  #include <Wire.h>
#endif
