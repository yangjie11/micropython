/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 SummerGift <SummerGift@qq.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdio.h>
#include <string.h>

#include "py/mphal.h"
#include "py/runtime.h"

#if MICROPY_PY_MACHINE_LCD

#include "machine_lcd.h"
#include <drv_lcd.h>

#define LCD_INSTR (0)
#define LCD_DATA (1)

#define LCD_CHAR_BUF_W (16)
#define LCD_CHAR_BUF_H (4)

#define LCD_PIX_BUF_W (128)
#define LCD_PIX_BUF_H (32)
#define LCD_PIX_BUF_BYTE_SIZE (LCD_PIX_BUF_W * LCD_PIX_BUF_H / 8)

typedef struct _machine_lcd_obj_t {
    mp_obj_base_t base;

    // hardware control for the LCD
//    const spi_t *spi;
//    const pin_obj_t *pin_cs1;
//    const pin_obj_t *pin_rst;
//    const pin_obj_t *pin_a0;
//    const pin_obj_t *pin_bl;

    // character buffer for stdout-like output
//    char char_buffer[LCD_CHAR_BUF_W * LCD_CHAR_BUF_H];
//    int line;
//    int column;
//    int next_line;

    // double buffering for pixel buffer
//    byte pix_buf[LCD_PIX_BUF_BYTE_SIZE];
//    byte pix_buf2[LCD_PIX_BUF_BYTE_SIZE];
} machine_lcd_obj_t;

STATIC void lcd_delay(void) {
    __asm volatile ("nop\nnop");
}

STATIC void lcd_out(machine_lcd_obj_t *lcd, int instr_data, uint8_t i) {
//    lcd_delay();
//    mp_hal_pin_low(lcd->pin_cs1); // CS=0; enable
//    if (instr_data == LCD_INSTR) {
//        mp_hal_pin_low(lcd->pin_a0); // A0=0; select instr reg
//    } else {
//        mp_hal_pin_high(lcd->pin_a0); // A0=1; select data reg
//    }
//    lcd_delay();
//    HAL_SPI_Transmit(lcd->spi->spi, &i, 1, 1000);
//    lcd_delay();
//    mp_hal_pin_high(lcd->pin_cs1); // CS=1; disable
}

// write a string to the LCD at the current cursor location
// output it straight away (doesn't use the pixel buffer)
STATIC void lcd_write_strn(machine_lcd_obj_t *lcd, const char *str, unsigned int len) {
//    int redraw_min = lcd->line * LCD_CHAR_BUF_W + lcd->column;
//    int redraw_max = redraw_min;
//    for (; len > 0; len--, str++) {
//        // move to next line if needed
//        if (lcd->next_line) {
//            if (lcd->line + 1 < LCD_CHAR_BUF_H) {
//                lcd->line += 1;
//            } else {
//                lcd->line = LCD_CHAR_BUF_H - 1;
//                for (int i = 0; i < LCD_CHAR_BUF_W * (LCD_CHAR_BUF_H - 1); i++) {
//                    lcd->char_buffer[i] = lcd->char_buffer[i + LCD_CHAR_BUF_W];
//                }
//                for (int i = 0; i < LCD_CHAR_BUF_W; i++) {
//                    lcd->char_buffer[LCD_CHAR_BUF_W * (LCD_CHAR_BUF_H - 1) + i] = ' ';
//                }
//                redraw_min = 0;
//                redraw_max = LCD_CHAR_BUF_W * LCD_CHAR_BUF_H;
//            }
//            lcd->next_line = 0;
//            lcd->column = 0;
//        }
//        if (*str == '\n') {
//            lcd->next_line = 1;
//        } else if (*str == '\r') {
//            lcd->column = 0;
//        } else if (*str == '\b') {
//            if (lcd->column > 0) {
//                lcd->column--;
//                redraw_min = 0; // could optimise this to not redraw everything
//            }
//        } else if (lcd->column >= LCD_CHAR_BUF_W) {
//            lcd->next_line = 1;
//            str -= 1;
//            len += 1;
//        } else {
//            lcd->char_buffer[lcd->line * LCD_CHAR_BUF_W + lcd->column] = *str;
//            lcd->column += 1;
//            int max = lcd->line * LCD_CHAR_BUF_W + lcd->column;
//            if (max > redraw_max) {
//                redraw_max = max;
//            }
//        }
//    }

//    // we must draw upside down, because the LCD is upside down
//    for (int i = redraw_min; i < redraw_max; i++) {
//        uint page = i / LCD_CHAR_BUF_W;
//        uint offset = 8 * (LCD_CHAR_BUF_W - 1 - (i - (page * LCD_CHAR_BUF_W)));
//        lcd_out(lcd, LCD_INSTR, 0xb0 | page); // page address set
//        lcd_out(lcd, LCD_INSTR, 0x10 | ((offset >> 4) & 0x0f)); // column address set upper
//        lcd_out(lcd, LCD_INSTR, 0x00 | (offset & 0x0f)); // column address set lower
//        int chr = lcd->char_buffer[i];
//        if (chr < 32 || chr > 126) {
//            chr = 127;
//        }
//        const uint8_t *chr_data = &font_petme128_8x8[(chr - 32) * 8];
//        for (int j = 7; j >= 0; j--) {
//            lcd_out(lcd, LCD_DATA, chr_data[j]);
//        }
//    }
}

/// \classmethod \constructor(skin_position)
///
/// Construct an LCD object in the given skin position.  `skin_position` can be 'X' or 'Y', and
/// should match the position where the LCD pyskin is plugged in.
STATIC mp_obj_t machine_lcd_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    // check arguments
    mp_arg_check_num(n_args, n_kw, 1, 1, false);

    // get LCD position
    const char *lcd_id = mp_obj_str_get_str(args[0]);

    // create lcd object
    machine_lcd_obj_t *lcd = m_new_obj(machine_lcd_obj_t);
    lcd->base.type = &machine_lcd_type;

    return MP_OBJ_FROM_PTR(lcd);
}

/// \method command(instr_data, buf)
///
/// Send an arbitrary command to the LCD.  Pass 0 for `instr_data` to send an
/// instruction, otherwise pass 1 to send data.  `buf` is a buffer with the
/// instructions/data to send.
STATIC mp_obj_t machine_lcd_command(mp_obj_t self_in, mp_obj_t instr_data_in, mp_obj_t val) {
    machine_lcd_obj_t *self = MP_OBJ_TO_PTR(self_in);

//    // get whether instr or data
//    int instr_data = mp_obj_get_int(instr_data_in);

//    // get the buffer to send from
//    mp_buffer_info_t bufinfo;
//    uint8_t data[1];
//    machine_buf_get_for_send(val, &bufinfo, data);

//    // send the data
//    for (uint i = 0; i < bufinfo.len; i++) {
//        lcd_out(self, instr_data, ((byte*)bufinfo.buf)[i]);
//    }

    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_3(machine_lcd_command_obj, machine_lcd_command);

/// \method contrast(value)
///
/// Set the contrast of the LCD.  Valid values are between 0 and 47.
//STATIC mp_obj_t machine_lcd_contrast(mp_obj_t self_in, mp_obj_t contrast_in) {
//    machine_lcd_obj_t *self = MP_OBJ_TO_PTR(self_in);
//    int contrast = mp_obj_get_int(contrast_in);
//    if (contrast < 0) {
//        contrast = 0;
//    } else if (contrast > 0x2f) {
//        contrast = 0x2f;
//    }
//    lcd_out(self, LCD_INSTR, 0x81); // electronic volume mode set
//    lcd_out(self, LCD_INSTR, contrast); // electronic volume register set
//    return mp_const_none;
//}
//STATIC MP_DEFINE_CONST_FUN_OBJ_2(machine_lcd_contrast_obj, machine_lcd_contrast);

/// \method light(value)
///
/// Turn the backlight on/off.  True or 1 turns it on, False or 0 turns it off.
STATIC mp_obj_t machine_lcd_light(mp_obj_t self_in, mp_obj_t value) {
    machine_lcd_obj_t *self = MP_OBJ_TO_PTR(self_in);
    if (mp_obj_is_true(value)) {
        lcd_display_on(); // set pin high to turn backlight on
    } else {
        lcd_display_off();// set pin low to turn backlight off
    }
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(machine_lcd_light_obj, machine_lcd_light);

/// \method write(str)
///
/// Write the string `str` to the screen.  It will appear immediately.
STATIC mp_obj_t machine_lcd_write(mp_obj_t self_in, mp_obj_t str) {
    machine_lcd_obj_t *self = MP_OBJ_TO_PTR(self_in);
    size_t len;
    const char *data = mp_obj_str_get_data(str, &len);
    lcd_write_strn(self, data, len);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(machine_lcd_write_obj, machine_lcd_write);

/// \method fill(colour)
///
/// Fill the screen with the given colour (0 or 1 for white or black).
///
/// This method writes to the hidden buffer.  Use `show()` to show the buffer.
STATIC mp_obj_t machine_lcd_fill(mp_obj_t self_in, mp_obj_t col_in) {
    machine_lcd_obj_t *self = MP_OBJ_TO_PTR(self_in);
    int col = mp_obj_get_int(col_in);
    if (col) {
        col = BLACK;
    }
    else
    {
        col = WHITE;
    }
    
    lcd_clear(col);

    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(machine_lcd_fill_obj, machine_lcd_fill);

/// \method get(x, y)
///
/// Get the pixel at the position `(x, y)`.  Returns 0 or 1.
///
/// This method reads from the visible buffer.
STATIC mp_obj_t machine_lcd_get(mp_obj_t self_in, mp_obj_t x_in, mp_obj_t y_in) {
    machine_lcd_obj_t *self = MP_OBJ_TO_PTR(self_in);
//    int x = mp_obj_get_int(x_in);
//    int y = mp_obj_get_int(y_in);
//    if (0 <= x && x <= 127 && 0 <= y && y <= 31) {
//        uint byte_pos = x + 128 * ((uint)y >> 3);
//        if (self->pix_buf[byte_pos] & (1 << (y & 7))) {
//            return mp_obj_new_int(1);
//        }
//    }
    return mp_obj_new_int(0);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_3(machine_lcd_get_obj, machine_lcd_get);

/// \method pixel(x, y, colour)
///
/// Set the pixel at `(x, y)` to the given colour (0 or 1).
///
/// This method writes to the hidden buffer.  Use `show()` to show the buffer.
STATIC mp_obj_t machine_lcd_pixel(size_t n_args, const mp_obj_t *args) {
    machine_lcd_obj_t *self = MP_OBJ_TO_PTR(args[0]);
//    int x = mp_obj_get_int(args[1]);
//    int y = mp_obj_get_int(args[2]);
//    if (0 <= x && x <= 127 && 0 <= y && y <= 31) {
//        uint byte_pos = x + 128 * ((uint)y >> 3);
//        if (mp_obj_get_int(args[3]) == 0) {
//            self->pix_buf2[byte_pos] &= ~(1 << (y & 7));
//        } else {
//            self->pix_buf2[byte_pos] |= 1 << (y & 7);
//        }
//    }
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(machine_lcd_pixel_obj, 4, 4, machine_lcd_pixel);

/// \method text(str, x, y, colour)
///
/// Draw the given text to the position `(x, y)` using the given colour (0 or 1).
///
/// This method writes to the hidden buffer.  Use `show()` to show the buffer.
STATIC mp_obj_t machine_lcd_text(size_t n_args, const mp_obj_t *args) {
    // extract arguments
//    machine_lcd_obj_t *self = MP_OBJ_TO_PTR(args[0]);
//    size_t len;
//    const char *data = mp_obj_str_get_data(args[1], &len);
//    int x0 = mp_obj_get_int(args[2]);
//    int y0 = mp_obj_get_int(args[3]);
//    int col = mp_obj_get_int(args[4]);

//    // loop over chars
//    for (const char *top = data + len; data < top; data++) {
//        // get char and make sure its in range of font
//        uint chr = *(byte*)data;
//        if (chr < 32 || chr > 127) {
//            chr = 127;
//        }
//        // get char data
//        const uint8_t *chr_data = &font_petme128_8x8[(chr - 32) * 8];
//        // loop over char data
//        for (uint j = 0; j < 8; j++, x0++) {
//            if (0 <= x0 && x0 < LCD_PIX_BUF_W) { // clip x
//                uint vline_data = chr_data[j]; // each byte of char data is a vertical column of 8 pixels, LSB at top
//                for (int y = y0; vline_data; vline_data >>= 1, y++) { // scan over vertical column
//                    if (vline_data & 1) { // only draw if pixel set
//                        if (0 <= y && y < LCD_PIX_BUF_H) { // clip y
//                            uint byte_pos = x0 + LCD_PIX_BUF_W * ((uint)y >> 3);
//                            if (col == 0) {
//                                // clear pixel
//                                self->pix_buf2[byte_pos] &= ~(1 << (y & 7));
//                            } else {
//                                // set pixel
//                                self->pix_buf2[byte_pos] |= 1 << (y & 7);
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }

    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(machine_lcd_text_obj, 5, 5, machine_lcd_text);

/// \method show()
///
/// Show the hidden buffer on the screen.
STATIC mp_obj_t machine_lcd_show(mp_obj_t self_in) {
    machine_lcd_obj_t *self = MP_OBJ_TO_PTR(self_in);
//    memcpy(self->pix_buf, self->pix_buf2, LCD_PIX_BUF_BYTE_SIZE);
//    for (uint page = 0; page < 4; page++) {
//        lcd_out(self, LCD_INSTR, 0xb0 | page); // page address set
//        lcd_out(self, LCD_INSTR, 0x10); // column address set upper; 0
//        lcd_out(self, LCD_INSTR, 0x00); // column address set lower; 0
//        for (uint i = 0; i < 128; i++) {
//            lcd_out(self, LCD_DATA, self->pix_buf[128 * page + 127 - i]);
//        }
//    }
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(machine_lcd_show_obj, machine_lcd_show);

STATIC const mp_rom_map_elem_t machine_lcd_locals_dict_table[] = {
    // instance methods
    { MP_ROM_QSTR(MP_QSTR_command), MP_ROM_PTR(&machine_lcd_command_obj) },
//    { MP_ROM_QSTR(MP_QSTR_contrast), MP_ROM_PTR(&machine_lcd_contrast_obj) },
    { MP_ROM_QSTR(MP_QSTR_light), MP_ROM_PTR(&machine_lcd_light_obj) },
    { MP_ROM_QSTR(MP_QSTR_write), MP_ROM_PTR(&machine_lcd_write_obj) },
    { MP_ROM_QSTR(MP_QSTR_fill), MP_ROM_PTR(&machine_lcd_fill_obj) },
    { MP_ROM_QSTR(MP_QSTR_get), MP_ROM_PTR(&machine_lcd_get_obj) },
    { MP_ROM_QSTR(MP_QSTR_pixel), MP_ROM_PTR(&machine_lcd_pixel_obj) },
    { MP_ROM_QSTR(MP_QSTR_text), MP_ROM_PTR(&machine_lcd_text_obj) },
    { MP_ROM_QSTR(MP_QSTR_show), MP_ROM_PTR(&machine_lcd_show_obj) },
};

STATIC MP_DEFINE_CONST_DICT(machine_lcd_locals_dict, machine_lcd_locals_dict_table);

const mp_obj_type_t machine_lcd_type = {
    { &mp_type_type },
    .name = MP_QSTR_LCD,
    .make_new = machine_lcd_make_new,
    .locals_dict = (mp_obj_dict_t*)&machine_lcd_locals_dict,
};

#endif // MICROPY_PY_MACHINE_LCD
