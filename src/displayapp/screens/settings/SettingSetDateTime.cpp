/*#include "displayapp/screens/settings/SettingSetDateTime.h"
#include "displayapp/screens/settings/SettingSetDate.h"
#include "displayapp/screens/settings/SettingSetTime.h"
#include <lvgl/lvgl.h>
#include <hal/nrf_rtc.h>
#include <nrf_log.h>
#include "displayapp/DisplayApp.h"
#include "displayapp/screens/Symbols.h"
#include "displayapp/screens/ScreenList.h"
#include "displayapp/screens/DotLabel.h"
#include "components/settings/Settings.h"
#include "displayapp/InfiniTimeTheme.h"

using namespace Pinetime::Applications::Screens;

namespace {
  constexpr int16_t POS_X_DAY = -72;
  constexpr int16_t POS_X_MONTH = 0;
  constexpr int16_t POS_X_YEAR = 72;
  constexpr int16_t POS_Y_TEXT = -6;
  constexpr int16_t POS_Y_TEXTD = -7;

  void SetDateEventHandler(lv_obj_t* obj, lv_event_t event) {
    auto* screen = static_cast<SettingSetDateTime*>(obj->user_data);
    if (event == LV_EVENT_CLICKED) {
      screen->SetDate();
    }
  }

  void SetTimeEventHandler(lv_obj_t* obj, lv_event_t event) {
    auto* screen = static_cast<SettingSetDateTime*>(obj->user_data);
    if (event == LV_EVENT_CLICKED) {
      screen->SetTime();
    }
  }

  void DateValueChangedHandler(void* userData) {
    auto* screen = static_cast<SettingSetDateTime*>(userData);
    screen->UpdateDate();
  }

  void TimeValueChangedHandler(void* userData) {
    auto* screen = static_cast<SettingSetDateTime*>(userData);
    screen->UpdateTime();
  }

  int MaximumDayOfMonth(uint8_t month, uint16_t year) {
    switch (month) {
      case 2: {
        if ((((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0)) {
          return 29;
        }
        return 28;
      }
      case 4:
      case 6:
      case 9:
      case 11:
        return 30;
      default:
        return 31;
    }
  }
}

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

std::unique_ptr<Screen> SettingSetDate::CreateScreen1() {
  lv_obj_t* title = lv_label_create(lv_scr_act(), nullptr);
  lv_label_set_text_static(title, "Set current date");
  lv_label_set_align(title, LV_LABEL_ALIGN_CENTER);
  lv_obj_align(title, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 15, 15);
  return std::make_unique<Screens::SettingSetDate>(0, 1, app, title);
}

std::unique_ptr<Screen> SettingSetTime::CreateScreen2() {
  lv_obj_t* title = lv_label_create(lv_scr_act(), nullptr);
  lv_label_set_text_static(title, "Set current time");
  lv_label_set_align(title, LV_LABEL_ALIGN_CENTER);
  lv_obj_align(title, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 15, 15);
  return std::make_unique<Screens::SettingSetTime>(0, 1, app, title);
}

SettingSetDateTime::~SettingSetDateTime() {
  lv_obj_clean(lv_scr_act());
}

void SettingSetDateTime::SetDate() {
  const uint16_t yearValue = yearCounter.GetValue();
  const uint8_t monthValue = monthCounter.GetValue();
  const uint8_t dayValue = dayCounter.GetValue();
  NRF_LOG_INFO("Setting date (manually) to %04d-%02d-%02d", yearValue, monthValue, dayValue);
  dateTimeController.SetTime(yearValue,
                             monthValue,
                             dayValue,
                             0,
                             dateTimeController.Hours(),
                             dateTimeController.Minutes(),
                             dateTimeController.Seconds(),
                             nrf_rtc_counter_get(portNRF_RTC_REG));
  lv_btn_set_state(btnSetDate, LV_BTN_STATE_DISABLED);
  lv_obj_set_state(lblSetDate, LV_STATE_DISABLED);
  screens.OnTouchEvent(Pinetime::Applications::TouchEvents::SwipeUp);
}

void SettingSetDateTime::SetTime() {
  const int hoursValue = hourCounter.GetValue();
  const int minutesValue = minuteCounter.GetValue();
  NRF_LOG_INFO("Setting time (manually) to %02d:%02d:00", hoursValue, minutesValue);
  dateTimeController.SetTime(dateTimeController.Year(),
                             static_cast<uint8_t>(dateTimeController.Month()),
                             dateTimeController.Day(),
                             static_cast<uint8_t>(dateTimeController.DayOfWeek()),
                             static_cast<uint8_t>(hoursValue),
                             static_cast<uint8_t>(minutesValue),
                             0,
                             nrf_rtc_counter_get(portNRF_RTC_REG));
  lv_obj_set_state(btnSetTime, LV_STATE_DISABLED);
  lv_obj_set_state(lblSetTime, LV_STATE_DISABLED);
  running = false;
}

void SettingSetDateTime::UpdateDate() {
  const int maxDay = MaximumDayOfMonth(monthCounter.GetValue(), yearCounter.GetValue());
  dayCounter.SetMax(maxDay);
  lv_btn_set_state(btnSetDate, LV_BTN_STATE_RELEASED);
  lv_obj_set_state(lblSetDate, LV_STATE_DEFAULT);
}

void SettingSetDateTime::UpdateTime() {
  if (settingsController.GetClockType() == Controllers::Settings::ClockType::H12) {
    if (hourCounter.GetValue() >= 12) {
      lv_label_set_text_static(lblampm, "PM");
    } else {
      lv_label_set_text_static(lblampm, "AM");
    }
  }
  lv_obj_set_state(btnSetTime, LV_STATE_DEFAULT);
  lv_obj_set_state(lblSetTime, LV_STATE_DEFAULT);
}*/
