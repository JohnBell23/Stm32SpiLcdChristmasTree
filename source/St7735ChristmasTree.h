/*
 * St7735ChristmasTree.h
 *
 *  Created on: Oct 19, 2024
 *      Author: john bell
 */

#include "St7735Adapter.h"

#pragma once

namespace ST7735Adapter
{

class St7735ChristmasTree
{
private:
  St7735Adapter &m_st7735Adapter;

  ST7735Adapter::St7735Adapter::Coordinate flake1
  { 120, 0 };
  ST7735Adapter::St7735Adapter::Coordinate flake4
  { 120, 70 };
  ST7735Adapter::St7735Adapter::Coordinate flake2
  { 110, 20 };
  ST7735Adapter::St7735Adapter::Coordinate flake5
  { 110, 55 };
  ST7735Adapter::St7735Adapter::Coordinate flake3
  { 105, 5 };
  ST7735Adapter::St7735Adapter::Coordinate flake6
  { 105, 15 };
  ST7735Adapter::St7735Adapter::Coordinate flake7
  { 105, 35 };
  ST7735Adapter::St7735Adapter::Coordinate flake8
  { 105, 95 };
  ST7735Adapter::St7735Adapter::Coordinate flake851
  { 85, 10 };
  ST7735Adapter::St7735Adapter::Coordinate flake852
  { 85, 50 };
  ST7735Adapter::St7735Adapter::Coordinate flake853
  { 85, 60 };
  ST7735Adapter::St7735Adapter::Coordinate flake854
  { 85, 85 };
  ST7735Adapter::St7735Adapter::Coordinate flake855
  { 85, 100 };
  ST7735Adapter::St7735Adapter::Coordinate flake901
  { 90, 13 };
  ST7735Adapter::St7735Adapter::Coordinate flake902
  { 90, 25 };
  ST7735Adapter::St7735Adapter::Coordinate flake903
  { 90, 40 };
  ST7735Adapter::St7735Adapter::Coordinate flake904
  { 90, 70 };
  ST7735Adapter::St7735Adapter::Coordinate flake905
  { 90, 75 };

  ST7735Adapter::St7735Adapter::Coordinate flake51
  { 5, 7 };
  ST7735Adapter::St7735Adapter::Coordinate flake52
  { 5, 28 };
  ST7735Adapter::St7735Adapter::Coordinate flake53
  { 5, 47 };
  ST7735Adapter::St7735Adapter::Coordinate flake54
  { 5, 60 };
  ST7735Adapter::St7735Adapter::Coordinate flake55
  { 5, 80 };

  ST7735Adapter::St7735Adapter::Coordinate flake101
  { 10, 8 };
  ST7735Adapter::St7735Adapter::Coordinate flake102
  { 10, 18 };
  ST7735Adapter::St7735Adapter::Coordinate flake103
  { 10, 51 };
  ST7735Adapter::St7735Adapter::Coordinate flake104
  { 10, 69 };
  ST7735Adapter::St7735Adapter::Coordinate flake105
  { 10, 90 };

  ST7735Adapter::St7735Adapter::Coordinate flake181
  { 18, 11 };
  ST7735Adapter::St7735Adapter::Coordinate flake182
  { 18, 32 };
  ST7735Adapter::St7735Adapter::Coordinate flake183
  { 18, 49 };
  ST7735Adapter::St7735Adapter::Coordinate flake184
  { 18, 54 };
  ST7735Adapter::St7735Adapter::Coordinate flake185
  { 18, 61 };
  ST7735Adapter::St7735Adapter::Coordinate flake186
  { 18, 66 };
  ST7735Adapter::St7735Adapter::Coordinate flake187
  { 18, 73 };

  void animateFlake(ST7735Adapter::St7735Adapter::Coordinate &flake);

public:
  St7735ChristmasTree(St7735Adapter &st7735Adapter) :
      m_st7735Adapter(st7735Adapter)
  {
  }
  virtual ~St7735ChristmasTree();

  /// generate base picture
  void drawScene();

  /// to be called every 100ms
  void animate();

};

} /* namespace ST7735Adapter */

