/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.44                          *
*        Compiled Nov 10 2017, 08:53:57                              *
*        (c) 2017 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

#include "SliderDLG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0   (GUI_ID_USER + 0x00)
#define ID_SLIDER_0     (GUI_ID_USER + 0x01)
#define ID_SLIDER_1     (GUI_ID_USER + 0x02)
#define ID_SLIDER_2     (GUI_ID_USER + 0x03)
#define ID_EDIT_0       (GUI_ID_USER + 0x04)
#define ID_EDIT_1       (GUI_ID_USER + 0x05)

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 480, 854, 0, 0x0, 0 },
  { SLIDER_CreateIndirect, "Slider", ID_SLIDER_0, 100, 40, 340, 40, 0, 0x0, 0 },
  { SLIDER_CreateIndirect, "Slider", ID_SLIDER_1, 100, 210, 40, 500, 8, 0x0, 0 },
  { SLIDER_CreateIndirect, "Slider", ID_SLIDER_2, 100, 125, 340, 40, 0, 0x0, 0 },
  { EDIT_CreateIndirect, "Edit", ID_EDIT_0, 40, 40, 50, 40, 0, 0x4, 0 },
  { EDIT_CreateIndirect, "Edit", ID_EDIT_1, 40, 210, 50, 40, 0, 0x3, 0 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/**
  * @brief 对话框回调函数
  * @note 无
  * @param pMsg：消息指针
  * @retval 无
  */
static void _cbDialog(WM_MESSAGE* pMsg) {
	WM_HWIN hItem;
	WM_HWIN hSlider;
  WM_HWIN hEdit;
	int     NCode;
	int     Id;
	int     value;

	switch (pMsg->MsgId) {
	case WM_INIT_DIALOG:
			/* 初始化Framewin控件 */
			hItem = pMsg->hWin;
			FRAMEWIN_SetTitleHeight(hItem, 32);
			FRAMEWIN_SetText(hItem, "STemWIN@EmbedFire STM32H743");
			FRAMEWIN_SetFont(hItem, GUI_FONT_32_ASCII);
			/* 初始化Slider0 */
			hItem = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_0);
			SLIDER_SetRange(hItem, 0, 1000);
			/* 初始化Slider1 */
			hItem = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_1);
			SLIDER_SetRange(hItem, 0, 100);
			SLIDER_SetWidth(hItem, 20);
			/* 初始化Slider2 */
			hItem = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_2);
			SLIDER_SetSkinClassic(hItem);
			SLIDER_SetWidth(hItem, 30);
			/* 初始化Edit0 */
			hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
			EDIT_SetText(hItem, "0000");
			EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
			EDIT_SetFont(hItem, GUI_FONT_COMIC18B_ASCII);
			EDIT_SetDecMode(hItem, 0, 0, 1000, 0, GUI_EDIT_NORMAL);
			/* 初始化Edit1 */
			hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_1);
			EDIT_SetText(hItem, "000");
			EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
			EDIT_SetFont(hItem, GUI_FONT_COMIC18B_ASCII);
			EDIT_SetDecMode(hItem, 0, 0, 100, 0, GUI_EDIT_NORMAL);
			break;
	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch (Id) {
		case ID_SLIDER_0: // Notifications sent by 'Slider0'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				/* 滑块的值被改变，将改变后的值更新到EDIT控件中 */
				hSlider = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_0);
				hEdit = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
				value = SLIDER_GetValue(hSlider);
				EDIT_SetValue(hEdit, value);
				break;
			}
			break;
		case ID_SLIDER_1: // Notifications sent by 'Slider1'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				/* 滑块的值被改变，将改变后的值更新到EDIT控件中 */
				hSlider = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_1);
				hEdit = WM_GetDialogItem(pMsg->hWin, ID_EDIT_1);
				value = SLIDER_GetValue(hSlider);
				EDIT_SetValue(hEdit, value);
				break;
			}
			break;
		case ID_EDIT_0: // Notifications sent by 'EDIT0'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				break;
			}
			break;
		case ID_EDIT_1: // Notifications sent by 'EDIT1'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				break;
			}
			break;
		}
		break;
	default:
		WM_DefaultProc(pMsg);
		break;
	}
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
 /**
  * @brief 以对话框方式间接创建控件
  * @note 无
  * @param 无
  * @retval hWin：资源表中第一个控件的句柄
  */
WM_HWIN CreateFramewin(void);
WM_HWIN CreateFramewin(void) {
	WM_HWIN hWin;

	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

/**
  * @brief GUI主任务
  * @note 无
  * @param 无
  * @retval 无
  */
void MainTask(void)
{
	CreateFramewin();
	
	while(1)
	{
		GUI_Delay(10);
	}
}

/*************************** End of file ****************************/
