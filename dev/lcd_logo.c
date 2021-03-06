#include "lcd.h"

static const unsigned char lcd_logo[] =
#if CONFIG_GRLCD_FLIP == 0
  { 0x00, 0x1D, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0xFF, 0xFF, 0xFF, 0x00, 0x2D, 0x80, 0xC0, 0xC0, 0x80, 0x00, 0x09, 0x80, 0x80, 0x00, 0x03, 0x80, 0xC0, 0xC0, 0x80, 0x00, 0x02, 0xC0, 0xE0, 0xE0, 0xC0, 0x00, 0x02, 0x60, 0xF0, 0xF0, 0x60, 0x00, 0x02, 0x60, 0xF0, 0xF0, 0x60, 0x00, 0x03, 0x80, 0x80, 0x00, 0x0E, 0xFF, 0xFF, 0xFF, 0x00, 0x06, 0x80, 0xE0, 0xE0, 0xF0, 0x70, 0x78, 0x38, 0x38, 0x38, 0x38, 0x78, 0x70, 0xF0, 0xE0, 0xE0, 0x00, 0x04, 0xF0, 0xF0, 0xF0, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x00, 0x03, 0xF0, 0xF0, 0xF0, 0x01, 0x1F, 0x1F, 0x01, 0x00, 0x02, 0x06, 0xFF, 0xFF, 0x06, 0x00, 0x02, 0x03, 0xFF, 0xFF, 0x03, 0x00, 0x02, 0x01, 0xFF, 0xFF, 0x01, 0x00, 0x03, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x03, 0x03, 0xFF, 0xFF, 0x03, 0x00, 0x02, 0x80, 0xC0, 0xC0, 0x80, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0x00, 0x06, 0x3F, 0xFF, 0xFF, 0xE0, 0xC0, 0xC0, 0x80, 0x80, 0x80, 0x00, 0x04, 0x01, 0x01, 0x00, 0x04, 0xFF, 0xFF, 0xFF, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x04, 0xFF, 0xFF, 0xFF, 0x00, 0x07, 0x7F, 0x7F, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x03, 0x01, 0xFF, 0xFF, 0x01, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0x00, 0x09, 0x01, 0x01, 0x03, 0x07, 0x07, 0x07, 0x0F, 0x0E, 0x1E, 0xFC, 0xFC, 0xF0, 0x00, 0x04, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x04, 0xFF, 0xFF, 0xFF, 0x00, 0x0D, 0x3F, 0x3F, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x03, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF, 0x00, 0x06, 0x1E, 0x1E, 0x3C, 0x38, 0x78, 0x70, 0x70, 0x70, 0x70, 0x78, 0x38, 0x3C, 0x1F, 0x1F, 0x07, 0x00, 0x04, 0x7F, 0x7F, 0x7F, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x70, 0x00, 0x03, 0x7F, 0x7F, 0x7F, 0x00, 0x13, 0x0F, 0x0F, 0x00, 0x04, 0x7F, 0x7F, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0x7F, 0x7F, 0x00, 0x04, 0x0F, 0x0F };
#else
  { 0x00, 0x1D, 0xFF, 0xFF, 0xFF, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF, 0x00, 0x2D, 0x01, 0x03, 0x03, 0x01, 0x00, 0x09, 0x01, 0x01, 0x00, 0x03, 0x01, 0x03, 0x03, 0x01, 0x00, 0x02, 0x03, 0x07, 0x07, 0x03, 0x00, 0x02, 0x06, 0x0F, 0x0F, 0x06, 0x00, 0x02, 0x06, 0x0F, 0x0F, 0x06, 0x00, 0x03, 0x01, 0x01, 0x00, 0x0E, 0xFF, 0xFF, 0xFF, 0x00, 0x06, 0x01, 0x07, 0x07, 0x0F, 0x0E, 0x1E, 0x1C, 0x1C, 0x1C, 0x1C, 0x1E, 0x0E, 0x0F, 0x07, 0x07, 0x00, 0x04, 0x0F, 0x0F, 0x0F, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x00, 0x03, 0x0F, 0x0F, 0x0F, 0x80, 0xF8, 0xF8, 0x80, 0x00, 0x02, 0x60, 0xFF, 0xFF, 0x60, 0x00, 0x02, 0xC0, 0xFF, 0xFF, 0xC0, 0x00, 0x02, 0x80, 0xFF, 0xFF, 0x80, 0x00, 0x03, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x03, 0xC0, 0xFF, 0xFF, 0xC0, 0x00, 0x02, 0x01, 0x03, 0x03, 0x01, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0x00, 0x06, 0xFC, 0xFF, 0xFF, 0x07, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x04, 0x80, 0x80, 0x00, 0x04, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x04, 0xFF, 0xFF, 0xFF, 0x00, 0x07, 0xFE, 0xFE, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x03, 0x80, 0xFF, 0xFF, 0x80, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0x00, 0x09, 0x80, 0x80, 0xC0, 0xE0, 0xE0, 0xE0, 0xF0, 0x70, 0x78, 0x3F, 0x3F, 0x0F, 0x00, 0x04, 0xFF, 0xFF, 0xFF, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0x00, 0x04, 0xFF, 0xFF, 0xFF, 0x00, 0x0D, 0xFC, 0xFC, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0xFF, 0xFF, 0xFF, 0x00, 0x06, 0x78, 0x78, 0x3C, 0x1C, 0x1E, 0x0E, 0x0E, 0x0E, 0x0E, 0x1E, 0x1C, 0x3C, 0xF8, 0xF8, 0xE0, 0x00, 0x04, 0xFE, 0xFE, 0xFE, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x00, 0x03, 0xFE, 0xFE, 0xFE, 0x00, 0x13, 0xF0, 0xF0, 0x00, 0x04, 0xFE, 0xFE, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFF, 0xFF, 0x00, 0x04, 0xFE, 0xFE, 0x00, 0x04, 0xF0, 0xF0 };
#endif

void lcd_logo_draw(void) {
  /* draw the logo which is 107 columns wide split over all 6 pages.
     There are 10 blank columns on the left side and 11 black columns
     on the right side */
  int p, c;
  const unsigned char *data = (unsigned char*) lcd_logo;
  int zerocount = 0;
  for (p = 0; p < 6; p++) {
    lcd_page(p);
    lcd_column(4); /* left-most column */
    for (c = 0; c < 10; c++) {
      lcd_data(0);
    }
    for (c = 0; c < 107; c++) {
      if (zerocount) {
        zerocount--;
        lcd_data(0);
      } else if (*data) {
        lcd_data(*data++);
      } else {
        // Original logo data contains runs of zeros. These are
        // run-length encoded. Any 0x00 byte is followed by a byte
        // that is the number of zero bytes present in the original
        // logo data.
        data++;
        zerocount = *data - 1;
        data++;
        lcd_data(0);
      }
    }
    for (c = 0; c < 11; c++) {
      lcd_data(0);
    }
  }
}
