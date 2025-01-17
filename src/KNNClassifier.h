/*
  This file is part of the Arduino_KNN library.
  Copyright (c) 2020 Arduino SA. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _KNN_CLASSIFIER_H_
#define _KNN_CLASSIFIER_H_

#include <Arduino.h>

class KNNNode;

class KNNClassifier {
public:
  KNNClassifier(int inputLength);
  virtual ~KNNClassifier();

  void addExample(const float input[], int class_);
  int classify(const float input[], int k = 3);
  int classifyWeighted(const float input[], int k, float w = 1.0);

  float confidence();

  void clearClass(int class_);
  void clearAllClasses();

  int getCountByClass(int class_);
  int getCount();

  // int save(Print& out);
  // int load(Stream& in);

private:
  int _inputLength;
  KNNNode* _examples;

  float _confidence;
};

#endif
