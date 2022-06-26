//<App !Start!>
// FILE: [guislice.ino]
// Created by GUIslice Builder version: [0.17.b11]
//
// GUIslice Builder Generated File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<App !End!>

// ------------------------------------------------
// Headers to include
// ------------------------------------------------
#include "guislice_GSLC.h"


// ------------------------------------------------
// Program Globals
// ------------------------------------------------

// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef* m_pElemBatteryStatus0= NULL;
gslc_tsElemRef* m_pElemCurrentStatus0= NULL;
gslc_tsElemRef* m_pElemCurrentStatus1= NULL;
gslc_tsElemRef* m_pElemPowerStatus0= NULL;
gslc_tsElemRef* m_pElemProgressBattery= NULL;
gslc_tsElemRef* m_pElemSeekbarPower0= NULL;
gslc_tsElemRef* m_pElemSelectUser = NULL;
gslc_tsElemRef* m_pElemTempratureStatus0= NULL;
gslc_tsElemRef* m_pElemTempratureStatus1= NULL;
gslc_tsElemRef* m_pElemToggleImgWIFI= NULL;
gslc_tsElemRef* m_pElemValMaxCurrent= NULL;
gslc_tsElemRef* m_pElemValMaxTemprature= NULL;
gslc_tsElemRef* m_pElemXRingGaugeCurrent0= NULL;
gslc_tsElemRef* m_pElemXRingGaugeCurrent1= NULL;
gslc_tsElemRef* m_pElemXRingGaugeTemprature0= NULL;
gslc_tsElemRef* m_pElemXRingGaugeTemprature1= NULL;
gslc_tsElemRef* m_pElemKeyPadNum  = NULL;
//<Save_References !End!>

// Define debug message function
static int16_t DebugOut(char ch) { if (ch == (char)'\n') Serial.println(""); else Serial.write(ch); return 0; }

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
// Common Button callback
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY)
{
  // Typecast the parameters to match the GUI and element types
  gslc_tsGui*     pGui     = (gslc_tsGui*)(pvGui);
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui,pElemRef);

  if ( eTouch == GSLC_TOUCH_UP_IN ) {
    // From the element's ID we can determine which button was pressed.
    switch (pElem->nId) {
//<Button Enums !Start!>
      case E_ELEM_IMAGEBTN_WIFI:
        break;
      case E_ELEM_IMAGEBTN_SYNC:
        break;
      case E_ELEM_BTN_POWER:
        gslc_SetPageCur(&m_gui, E_PG_POWER);
        break;
      case E_ELEM_BTN_SETTINGS:
        gslc_SetPageCur(&m_gui, E_PG_SETTINGS);
        break;
      case E_ELEM_BTN_BACK:
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        break;
      case E_ELEM_BTN_BACK_2:
        gslc_SetPageCur(&m_gui, E_PG_MAIN);
        break;
      case E_ELEM_NUMINPUT_MC:
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValMaxCurrent);
        break;
      case E_ELEM_NUMINPUT_MT:
        // Clicked on edit field, so show popup box and associate with this text field
        gslc_ElemXKeyPadInputAsk(&m_gui, m_pElemKeyPadNum, E_POP_KEYPAD_NUM, m_pElemValMaxTemprature);
        break;
      case E_ELEM_SELECT_USER:
        gslc_SetPageCur(&m_gui, E_PG_USER_SELECT);
        break;
      case E_ELEM_SELECT_AHMAD:
        gslc_SetPageCur(&m_gui, E_PG_SETTINGS);
        break;
      case E_ELEM_SELECT_JAMES:
        gslc_SetPageCur(&m_gui, E_PG_SETTINGS);
        break;
      case E_ELEM_SELECT_COLIN:
        gslc_SetPageCur(&m_gui, E_PG_SETTINGS);
        break;
      case E_ELEM_SELECT_SEBASTAIN:
        gslc_SetPageCur(&m_gui, E_PG_SETTINGS);
        break;
      case E_ELEM_SELECT_DEVAN:
        gslc_SetPageCur(&m_gui, E_PG_SETTINGS);
        break;
//<Button Enums !End!>
      default:
        break;
    }
  }
  return true;
}
//<Checkbox Callback !Start!>
//<Checkbox Callback !End!>
// KeyPad Input Ready callback
bool CbKeypad(void* pvGui, void *pvElemRef, int16_t nState, void* pvData)
{
  gslc_tsGui*     pGui     = (gslc_tsGui*)pvGui;
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui,pElemRef);

  // From the pvData we can get the ID element that is ready.
  int16_t nTargetElemId = gslc_ElemXKeyPadDataTargetIdGet(pGui, pvData);
  if (nState == XKEYPAD_CB_STATE_DONE) {
    // User clicked on Enter to leave popup
    // - If we have a popup active, pass the return value directly to
    //   the corresponding value field
    switch (nTargetElemId) {
//<Keypad Enums !Start!>
      case E_ELEM_NUMINPUT_MC:
        gslc_ElemXKeyPadInputGet(pGui, m_pElemValMaxCurrent, pvData);
	    gslc_PopupHide(&m_gui);
        break;
      case E_ELEM_NUMINPUT_MT:
        gslc_ElemXKeyPadInputGet(pGui, m_pElemValMaxTemprature, pvData);
	    gslc_PopupHide(&m_gui);
        break;

//<Keypad Enums !End!>
      default:
        break;
    }
  } else if (nState == XKEYPAD_CB_STATE_CANCEL) {
    // User escaped from popup, so don't update values
    gslc_PopupHide(&m_gui);
  }
  return true;
}
//<Spinner Callback !Start!>
//<Spinner Callback !End!>
//<Listbox Callback !Start!>
//<Listbox Callback !End!>
//<Draw Callback !Start!>
//<Draw Callback !End!>

// Callback function for when a slider's position has been updated
bool CbSlidePos(void* pvGui,void* pvElemRef,int16_t nPos)
{
  gslc_tsGui*     pGui     = (gslc_tsGui*)(pvGui);
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui,pElemRef);
  int16_t         nVal;

  // From the element's ID we can determine which slider was updated.
  switch (pElem->nId) {
//<Slider Enums !Start!>
    case E_ELEM_SEEKBAR_COIL_POWER:
      // Fetch the slider position
      nVal = gslc_ElemXSeekbarGetPos(pGui,m_pElemSeekbarPower0);
      break;

//<Slider Enums !End!>
    default:
      break;
  }

  return true;
}
//<Tick Callback !Start!>
//<Tick Callback !End!>

void setup()
{
  // ------------------------------------------------
  // Initialize
  // ------------------------------------------------
  Serial.begin(9600);
  // Wait for USB Serial 
  //delay(1000);  // NOTE: Some devices require a delay after Serial.begin() before serial port can be used

  gslc_InitDebug(&DebugOut);

  // ------------------------------------------------
  // Create graphic elements
  // ------------------------------------------------
  InitGUIslice_gen();

}

// -----------------------------------
// Main event loop
// -----------------------------------
void loop()
{

  // ------------------------------------------------
  // Update GUI Elements
  // ------------------------------------------------
  
  //TODO - Add update code for any text, gauges, or sliders
  
  // ------------------------------------------------
  // Periodically call GUIslice update function
  // ------------------------------------------------
  gslc_Update(&m_gui);
    
}

