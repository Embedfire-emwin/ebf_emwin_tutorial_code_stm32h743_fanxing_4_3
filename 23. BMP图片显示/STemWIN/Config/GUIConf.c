/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2017  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.44 - Graphical user interface for embedded applications **
All  Intellectual Property rights  in the Software belongs to  SEGGER.
emWin is protected by  international copyright laws.  Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with the following terms:

The  software has  been licensed  to STMicroelectronics International
N.V. a Dutch company with a Swiss branch and its headquarters in Plan-
les-Ouates, Geneva, 39 Chemin du Champ des Filles, Switzerland for the
purposes of creating libraries for ARM Cortex-M-based 32-bit microcon_
troller products commercialized by Licensee only, sublicensed and dis_
tributed under the terms and conditions of the End User License Agree_
ment supplied by STMicroelectronics International N.V.
Full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : GUIConf.c
Purpose     : Display controller initialization
---------------------------END-OF-HEADER------------------------------
*/

/**
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2018 STMicroelectronics. 
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license SLA0044,
  * the "License"; You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *                      http://www.st.com/SLA0044
  *
  ******************************************************************************
  */

#include "GUI.h"
#include "./lcd/bsp_NT35510_lcd.h"
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
//
// Define the available number of bytes available for the GUI
//
#if USE_EXTMEMHEAP
  #define GUI_NUMBYTES   (1024 * 1024 * 8)    // x Byte
  #define GUI_EXTBUFADD  (0xD2000000-GUI_NUMBYTES)//32MB SDRAM的最后8MB作为STemWIN动态内存
#else
  #define GUI_NUMBYTES  (1024 * 80)    // x KByte
#endif

#define GUI_BLOCKSIZE 0x80

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
#if USE_EXTMEMHEAP
  static U32 HeapMem[GUI_NUMBYTES / 4] __attribute__((at(GUI_EXTBUFADD)));
#else
  static U32 extMem[GUI_NUMBYTES / 4];
#endif

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/

/*********************************************************************
*
*       Get_ExtMemHeap
*
* Purpose:
*   Allocate heap from external memory
*/
#if USE_EXTMEMHEAP
U32* Get_ExtMemHeap (void)
{
  return HeapMem;
}
#endif

/*********************************************************************
*
*       GUI_X_Config
*
* Purpose:
*   Called during the initialization process in order to set up the
*   available memory for the GUI.
*/
void GUI_X_Config(void)
{
#if USE_EXTMEMHEAP
  GUI_ALLOC_AssignMemory(HeapMem, GUI_NUMBYTES);
	GUI_ALLOC_SetAvBlockSize(GUI_BLOCKSIZE);
#else	
  GUI_ALLOC_AssignMemory(extMem, GUI_NUMBYTES);	
	GUI_ALLOC_SetAvBlockSize(GUI_BLOCKSIZE);
#endif
}

//
// Physical display size
//
#define XSIZE_PHYS  LCD_Y_LENGTH // To be adapted to x-screen size
#define YSIZE_PHYS  LCD_X_LENGTH // To be adapted to y-screen size

/*********************************************************************
*
*       LCD_X_Config
*
* Function description:
*   Called during the initialization process in order to set up the
*   display driver configuration.
*
*/
void LCD_X_Config(void) {
  //
  // Set display driver and color conversion
  //
  GUI_DEVICE_CreateAndLink(&GUIDRV_Template_API, GUICC_M565, 0, 0);
  //
  // Display driver configuration, required for Lin-driver
  //
  LCD_SetSizeEx (0,XSIZE_PHYS  , YSIZE_PHYS);
  LCD_SetVSizeEx(0,XSIZE_PHYS  , YSIZE_PHYS);
}

/*********************************************************************
*
*       LCD_X_DisplayDriver
*
* Function description:
*   This function is called by the display driver for several purposes.
*   To support the according task the routine needs to be adapted to
*   the display controller. Please note that the commands marked with
*   'optional' are not cogently required and should only be adapted if
*   the display controller supports these features.
*
* Parameter:
*   LayerIndex - Index of layer to be configured
*   Cmd        - Please refer to the details in the switch statement below
*   pData      - Pointer to a LCD_X_DATA structure
*
* Return Value:
*   < -1 - Error
*     -1 - Command not handled
*      0 - Ok
*/
int LCD_X_DisplayDriver(unsigned LayerIndex, unsigned Cmd, void * pData) {
  int r;
  (void) LayerIndex;
  (void) pData;
  
  switch (Cmd) {
  case LCD_X_INITCONTROLLER: {
    //
    // Called during the initialization process in order to set up the
    // display controller and put it into operation. If the display
    // controller is not initialized by any external routine this needs
    // to be adapted by the customer...
    //
    // ...
    NT35510_Init();//modify by fire
    
    return 0;
  }
  default:
    r = -1;
  }
  return r;
}


/*************************** End of file ****************************/
