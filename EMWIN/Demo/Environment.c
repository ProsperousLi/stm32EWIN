/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.28                          *
*        Compiled Jan 30 2015, 16:41:06                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "Environment.h"
#include "dht11.h" 	
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0   (GUI_ID_USER + 0x01)
#define ID_TEXT_0   (GUI_ID_USER + 0x02)
#define ID_PROGBAR_0   (GUI_ID_USER + 0x05)
#define ID_TEXT_1   (GUI_ID_USER + 0x06)
#define ID_PROGBAR_1   (GUI_ID_USER + 0x07)
#define ID_TEXT_2   (GUI_ID_USER + 0x08)
#define ID_PROGBAR_2   (GUI_ID_USER + 0x09)
#define ID_BUTTON_0 (GUI_ID_USER + 0x15)
u8 temp,humi;
static WM_HWIN hWin_e;
// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 800, 480, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_0, 17, 56, 119, 34, 0, 0x64, 0 },
  { PROGBAR_CreateIndirect, "Progbar", ID_PROGBAR_0, 149, 60, 300, 30, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_1, 38, 190, 80, 20, 0, 0x64, 0 },
  { PROGBAR_CreateIndirect, "Progbar", ID_PROGBAR_1, 149, 185, 300, 30, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_2, 41, 318, 80, 20, 0, 0x64, 0 },
  { PROGBAR_CreateIndirect, "Progbar", ID_PROGBAR_2, 149, 313, 300, 30, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 600, 400, 100, 50, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
	int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetText(hItem, "Temperature");
	  
		TEXT_SetFont(hItem, GUI_FONT_13B_1);
    //
    // Initialization of 'Progbar'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_0);
    PROGBAR_SetFont(hItem, GUI_FONT_13B_1);
		//PROGBAR_SetMinMax();
	  PROGBAR_SetValue(hItem,50);
	  //DHT11_Read_Data(&temp,&humi);    //��ȡ�¶�
	  
		hItem = WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_1);
    PROGBAR_SetFont(hItem, GUI_FONT_13B_1);
	
	  hItem = WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_2);
    PROGBAR_SetFont(hItem, GUI_FONT_13B_1);
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetText(hItem, "Humidity");
		TEXT_SetFont(hItem, GUI_FONT_13B_1);
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetText(hItem, "Air quality");
		TEXT_SetFont(hItem, GUI_FONT_13B_1);
		//button0
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetText(hItem, "back");
		BUTTON_SetFont(hItem, GUI_FONT_13B_1);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
	case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by 'Edit'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
				FRAMEWIN_Delete(hWin_e);
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
			
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateFramewin
*/



WM_HWIN CreateFramewin_environment(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}


void environment_Window(void) {
  hWin_e = CreateFramewin_environment();
}
// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/