/*
 * St7735Adapter.cpp
 *
 *  Created on: Oct 4, 2024
 *      Author: jb23
 */

#include "St7735Adapter.h"
#include "st7735.h"
#include "fonts.h"
#include "stdio.h"
#include <math.h>

namespace ST7735Adapter
{

St7735Adapter::St7735Adapter()
{
}

St7735Adapter::~St7735Adapter()
{
}

void St7735Adapter::init(uint8_t r, uint8_t g, uint8_t b)
{
  ST7735_Init();
  ST7735_FillScreen(ST7735_COLOR565(r, g, b));
}

void St7735Adapter::drawLine(Coordinate start, Coordinate end)
{
  double x1 = start.x;
  double y1 = start.y;
  double x2 = end.x;
  double y2 = end.y;

  double a = (y2 - y1) / (x2 - x1);
  double b = y2 - a * x2;

  for (uint16_t xs = static_cast<uint16_t>(x1); xs <= static_cast<uint16_t>(x2);
      xs++)
  {
    uint16_t ys = static_cast<uint16_t>(a * xs + b);
    ST7735_DrawPixel(xs, ys, ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
  }

}

void St7735Adapter::drawCircle(Coordinate center, uint16_t radius, bool bold)
{
  double x0 = center.x;
  double y0 = center.y;

  int numPoints = 40;

  for (int i = 0; i < numPoints; ++i)
  {
    double theta = 2.0 * M_PI * i / numPoints;

    double x = x0 + radius * cos(theta);
    double y = y0 + radius * sin(theta);

    ST7735_DrawPixel(x, y, ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
    if (bold)
    {
      ST7735_DrawPixel(x + 1, y, ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
      ST7735_DrawPixel(x - 1, y, ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
    }
  }
}

void St7735Adapter::setDrawingColor(uint8_t r, uint8_t g, uint8_t b)
{
  m_drawingColor.r = r;
  m_drawingColor.g = g;
  m_drawingColor.b = b;
}

void St7735Adapter::drawPixel(uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b)
{
  ST7735_DrawPixel(x, y, ST7735_COLOR565(r, g, b));
}

} /* namespace ST7735Adapter */
