#include "displayapp/screens/settings/SettingSetDateTime.h"
#include <lvgl/lvgl.h>
#include <hal/nrf_rtc.h>
#include <nrf_log.h>
#include "displayapp/DisplayApp.h"
#include "displayapp/screens/Symbols.h"
#include "displayapp/screens/ScreenList.h"
#include "displayapp/screens/Label.h"
#include "components/settings/Settings.h"
#include "displayapp/InfiniTimeTheme.h"

using namespace Pinetime::Applications::Screens;

bool SettingSetDateTime::OnTouchEvent(Pinetime::Applications::TouchEvents event) {
  return screens.OnTouchEvent(event);
}

SettingSetDateTime::SettingSetDateTime(Pinetime::Applications::DisplayApp* app,
                                       Pinetime::Controllers::DateTime& dateTimeController,
                                       Pinetime::Controllers::Settings& settingsController)
  : Screen(app),
    dateTimeController {dateTimeController},
    settingsController {settingsController},
    screens {app,
             0,
             {[this]() -> std::unique_ptr<Screen> {
                return CreateScreen1();
              },
              [this]() -> std::unique_ptr<Screen> {
                return CreateScreen2();
              }},
             Screens::ScreenListModes::UpDown} {
}

std::unique_ptr<Screen> SettingSetDateTime::CreateScreen1() {

  
  return std::make_unique<Screens::SettingSetDate>(app, dateTimeController);
}

std::unique_ptr<Screen> SettingSetDateTime::CreateScreen2() {

  return std::make_unique<Screens::SettingSetTime>(app, dateTimeController, settingsController);
}

SettingSetDateTime::~SettingSetDateTime() {
  lv_obj_clean(lv_scr_act());
}
