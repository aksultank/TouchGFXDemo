/*
 * gui.h
 *
 *  Created on: Jan 2, 2020
 *      Author: Kotetsu Yama
 *      Copyright: Kotetsu Yama

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

 */

#ifndef INC_GUI_H_
#define INC_GUI_H_

#define GUI_WIDTH 320
#define GUI_HEIGHT 240

uint8_t *GUI_GetVVRAM(void);
void GUI_FillScreen(uint16_t cl);

#endif /* INC_GUI_H_ */
