#include<KRrtc.h>

void setup () {
  Serial.begin(9600u);
  rtcBegin();
  //  setComputer();
  //  setManual(2020, 4, 8, 16, 1, 0);
}

void loop () {
  rtcGet();
  Serial.print(String() + hari + ", " + tanggal + "-" + bulan + "-" + tahun);
  Serial.print("  ");
  Serial.println(String() + jam + ":" + menit + ":" + detik);
  delay(1000L);
}
