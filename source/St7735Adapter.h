/*
 * St7735Adapter.h
 *
 *  Created on: Oct 4, 2024
 *      Author: john bell
 */

#pragma once

#include "stdint.h"
#include <map>

namespace ST7735Adapter
{

#define MATRIX_LENGTH 31

/// St7735Adapter provides a simplifed interface to the LCD library
class St7735Adapter
{

public:
  /// Coordinate on the LCD with x and y ranging from 0 to 127 where the top left corner is 0, 0 and the bottom right corner is 127, 127
  struct Coordinate
  {
    uint16_t x;
    uint16_t y;
  };

  /// DrawingColor defines a RGB value
  struct DrawingColor
  {
    uint8_t r;
    uint8_t g;
    uint8_t b;
  };

  const uint16_t MAX_EXCLUSIVE = 128;
  const uint16_t MIN_INCLUSIVE = 0;

protected:
  DrawingColor m_drawingColor
  { 0xFF, 0xFF, 0xFF };

public:
  St7735Adapter();
  virtual ~St7735Adapter();
  /// init sets the background color of the whole LCD
  void init(uint8_t r, uint8_t g, uint8_t b);
  /// Setting the general drawing color
  void setDrawingColor(uint8_t r, uint8_t g, uint8_t b);
  /// Draws a horizontal line with the color set by setDrawingColor
  void drawLine(Coordinate start, Coordinate end);
  /// Draws a circle
  void drawCircle(Coordinate center, uint16_t radius, bool bold = true);
  /// Draws a pixel with its own color
  void drawPixel(uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b);
};

} /* namespace ST7735Adapter */

