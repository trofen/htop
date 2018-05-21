/*
htop - UptimeMeter.c
(C) 2004-2011 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#include "UptimeMeter.h"
#include "Platform.h"
#include "CRT.h"

/*{
#include "Meter.h"
}*/

int TempMeter_attributes[] = {
   UPTIME
};

static void TempMeter_updateValues(Meter* this, char* buffer, int len) {
   int temperature = Platform_getTemp();
   xSnprintf(buffer, len, "%02d C", temperature);
}

MeterClass TempMeter_class = {
   .super = {
      .extends = Class(Meter),
      .delete = Meter_delete
   },
   .updateValues = TempMeter_updateValues,
   .defaultMode = TEXT_METERMODE,
   .maxItems = 1,
   .total = 100.0,
   .attributes = TempMeter_attributes,
   .name = "Temp",
   .uiName = "Temperature",
   .caption = "CPU temp: "
};
