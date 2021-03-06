/**
  ******************************************************************************
  * File Name          : TouchGFXHAL.cpp
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
#include <TouchGFXHAL.hpp>

/* USER CODE BEGIN TouchGFXHAL.cpp */

#include <touchgfx/hal/OSWrappers.hpp>
#include "stm32f4xx.h"
#include "LCDManager.h"

using namespace touchgfx;

void TouchGFXHAL::initialize()
{
    // Calling parent implementation of initialize().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
    // Please note, HAL::initialize() must be called to initialize the framework.

#if 0
	// Original
    TouchGFXGeneratedHAL::initialize();
#endif
}

/**
 * Gets the frame buffer address used by the TFT controller.
 *
 * @return The address of the frame buffer currently being displayed on the TFT.
 */
uint16_t* TouchGFXHAL::getTFTFrameBuffer() const
{
    // Calling parent implementation of getTFTFrameBuffer().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

#if 0
	// Original
    return TouchGFXGeneratedHAL::getTFTFrameBuffer();
#else
    return 0;
#endif
}

/**
 * Sets the frame buffer address used by the TFT controller.
 *
 * @param [in] address New frame buffer address.
 */
void TouchGFXHAL::setTFTFrameBuffer(uint16_t* address)
{
    // Calling parent implementation of setTFTFrameBuffer(uint16_t* address).
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.

#if 0
	// Original
    TouchGFXGeneratedHAL::setTFTFrameBuffer(address);
#endif
}

/**
 * This function is called whenever the framework has performed a partial draw.
 *
 * @param rect The area of the screen that has been drawn, expressed in absolute coordinates.
 *
 * @see flushFrameBuffer().
 */
void TouchGFXHAL::flushFrameBuffer(const touchgfx::Rect& rect)
{
    // Calling parent implementation of flushFrameBuffer(const touchgfx::Rect& rect).
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
    // Please note, HAL::flushFrameBuffer(const touchgfx::Rect& rect) must
    // be called to notify the touchgfx framework that flush has been performed.
#if 0
	// Original
    TouchGFXGeneratedHAL::flushFrameBuffer(rect);
#else
    TouchGFXGeneratedHAL::flushFrameBuffer(rect);
    frameBufferAllocator->markBlockReadyForTransfer();
    if (!LCDManager_IsTransmittingData())
    {
      touchgfx::Rect r;
      const uint8_t* pixels = frameBufferAllocator->getBlockForTransfer(r);
      LCDManager_SendFrameBufferBlockWithPosition((uint8_t*)pixels, r.x, r.y, r.width, r.height);
    }
#endif
}

/**
 * Configures the interrupts relevant for TouchGFX. This primarily entails setting
 * the interrupt priorities for the DMA and LCD interrupts.
 */
void TouchGFXHAL::configureInterrupts()
{
    // Calling parent implementation of configureInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
#if 0
	// Original
    TouchGFXGeneratedHAL::configureInterrupts();
#endif
}

/**
 * Used for enabling interrupts set in configureInterrupts()
 */
void TouchGFXHAL::enableInterrupts()
{
    // Calling parent implementation of enableInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
#if 0
	// Original
    TouchGFXGeneratedHAL::enableInterrupts();
#endif
}

/**
 * Used for disabling interrupts set in configureInterrupts()
 */
void TouchGFXHAL::disableInterrupts()
{
    // Calling parent implementation of disableInterrupts().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
#if 0
	// Original
    TouchGFXGeneratedHAL::disableInterrupts();
#endif
}

/**
 * Configure the LCD controller to fire interrupts at VSYNC. Called automatically
 * once TouchGFX initialization has completed.
 */
void TouchGFXHAL::enableLCDControllerInterrupt()
{
    // Calling parent implementation of enableLCDControllerInterrupt().
    //
    // To overwrite the generated implementation, omit call to parent function
    // and implemented needed functionality here.
#if 0
	// Original
    TouchGFXGeneratedHAL::enableLCDControllerInterrupt();
#endif
}

#if 0
void TouchGFXHAL::endFrame()
{
    while(LCDManager_IsTransmittingData())
    {
    }
}
#endif

static volatile bool blockIsTransferred = false;

namespace touchgfx
{
void FrameBufferAllocatorWaitOnTransfer()
{
  while(!blockIsTransferred);
}

void FrameBufferAllocatorSignalBlockDrawn()
{
    blockIsTransferred = false;
    return;
}


void startNewTransfer()
{
    FrameBufferAllocator* fba = HAL::getInstance()->getFrameBufferAllocator();
    fba->freeBlockAfterTransfer();
    blockIsTransferred = true;

    if (fba->hasBlockReadyForTransfer())
    {
        touchgfx::Rect r;
        const uint8_t* pixels = fba->getBlockForTransfer(r);
        LCDManager_SendFrameBufferBlockWithPosition((uint8_t*)pixels, r.x, r.y, r.width, r.height);
    }
}
}

void LCDManager_TransferComplete()
{
    touchgfx::startNewTransfer();
}

extern "C" void touchgfx_signalVSyncTimer(void)
{
    HAL::getInstance()->vSync();
    touchgfx::OSWrappers::signalVSync();
}


/* USER CODE END TouchGFXHAL.cpp */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
