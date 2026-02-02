#include <LedControl.h> // LED Matris kontrol kütüphanesi / Library for LED Matrix control

// Pin tanımlamaları / Pin definitions
int CS = 10;  // Seçim pini / Chip Select pin
int DIN = 11; // Veri giriş pini / Data Input pin
int CLK = 13; // Saat sinyali pini / Clock pin

// LedControl nesnesi oluşturma / Create LedControl object
// (DIN, CLK, CS, Cihaz Sayısı / Number of devices)
LedControl gitdisplay = LedControl(DIN, CLK, CS, 0);

// Karakter ve şekil tanımlamaları (8x8 Byte dizileri) / Character and shape definitions (8x8 Byte arrays)
byte sol_ust[8] = {0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; // Sol üst nokta / Top-left dot
byte sag_alt[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01}; // Sağ alt nokta / Bottom-right dot
byte alt[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};     // Alt kenar / Bottom edge
byte sol[8] = {0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80};     // Sol kenar / Left edge
byte ust[8] = {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};     // Üst kenar / Top edge
byte sag[8] = {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01};     // Sağ kenar / Right edge

// Animasyon için ifade aşamaları / Expression frames for animation
byte ifade[8] = {0x00, 0x00, 0x66, 0x66, 0x00, 0x42, 0x24, 0x18};   // Gülen yüz / Smiley face
byte ifade_1[8] = {0x00, 0x00, 0x60, 0x66, 0x00, 0x24, 0x18, 0x00}; // Göz kırpma aşama 1 / Wink frame 1
byte ifade_2[8] = {0x00, 0x00, 0x60, 0x60, 0x00, 0x24, 0x18, 0x00}; // Göz kırpma aşama 2 / Wink frame 2

// Matrise karakter yazdırma fonksiyonu / Function to print character to matrix
void dot_yazdir(byte karakter [])
{
  int i = 0;
  for (i = 0; i < 8; i++) // 8 satırı tek tek döner / Loops through 8 rows
  {
    gitdisplay.setRow(0, i, karakter[i]); // İlgili satırı LED'de gösterir / Displays the row on LED
  }
}

void setup() {
  Serial.begin(9600);                  // Seri haberleşmeyi başlatır / Starts serial communication
  gitdisplay.shutdown(0, false);       // Uyku modunu kapatır / Wakes up the display
  gitdisplay.setIntensity(0, 5);       // Parlaklık seviyesini ayarlar (0-15) / Sets brightness level
  gitdisplay.clearDisplay(0);          // Ekranı temizler / Clears the display
}

void loop() {
  // Animasyon döngüsü / Animation loop
  
  dot_yazdir(ifade);    // İlk ifadeyi göster / Show first expression
  delay(1000);          // 1 saniye bekle / Wait 1 second
  
  dot_yazdir(ifade_1);  // İkinci ifadeyi göster / Show second expression
  delay(1000);          // 1 saniye bekle / Wait 1 second
  
  dot_yazdir(ifade_2);  // Üçüncü ifadeyi göster / Show third expression
  delay(100);           // 0.1 saniye bekle / Wait 0.1 second
}
