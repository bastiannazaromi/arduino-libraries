#include "RTClib.h"
RTC_DS1307 rtc;
char dataHari[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
String hari, mnt;
int no_hari, tanggal, bulan, tahun, jam, menit, detik;

void setComputer()
{
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void setManual(int rtc_tahun, int rtc_bulan, int rtc_tanggal, int rtc_jam, int rtc_menit, int rtc_detik)
{
  rtc.adjust(DateTime(rtc_tahun, rtc_bulan, rtc_tanggal, rtc_jam, rtc_menit, rtc_detik));
}

void rtcBegin()
{
  if (!rtc.begin())
  {
    Serial.println("RTC Tidak Ditemukan, silakan periksa kembali rangkaian.");
    Serial.flush();
    abort();
  }
}

void rtcGet()
{
  DateTime now = rtc.now();
  
  hari = dataHari[now.dayOfTheWeek()];
  no_hari = now.dayOfTheWeek();
  tanggal = now.day(), DEC;
  bulan = now.month(), DEC;
  tahun = now.year(), DEC;
  jam = now.hour(), DEC;
  menit = now.minute(), DEC;
  detik = now.second(), DEC;
}
