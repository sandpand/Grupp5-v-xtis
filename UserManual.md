# Användarmanual: Smart Växtbevattningssystem

## 1. Introduktion
Detta system är utvecklat för att automatiskt övervaka och bevattna växter med hjälp av en Arduino-plattform. Systemet mäter jordens fuktighetsnivå och ljusnivå för att styra en vattenpump och UV-LED, vilket ger optimal bevattning och visuell feedback.

---

## 2. Systemets Komponenter
- **Arduino Uno** – Styrsystem
- **Fuktighetssensor** – Mäter jordens fuktnivå
- **Ljussensor (LDR)** – Känner av ljusnivån
- **Vattenpump** – Vattnar automatiskt vid behov
- **RGB-LED** – Visar växtstatus med färger
- **UV-LED** – Aktiveras vid låg ljusnivå
- **LCD-skärm** – Visar aktuella sensorvärden
- **Relämodul** – Styr vattenpumpens på/av-läge

---

## 3. Användning
### 3.1 Systemfunktioner
- **Startläge:** Systemet börjar läsa sensordata direkt.
- **LED-status:**
  - 🟢 **Grön:** Bra fuktighet
  - 🔵 **Blå:** Måttlig fuktighet
  - 🔴 **Röd:** Torr jord – pump aktiveras
- **UV-LED:**
  - **På:** Låg ljusnivå upptäckt
  - **Av:** Tillräcklig ljusnivå
- **LCD-skärm:** Visar aktuella fukt- och ljusvärden

---

## 4. Underhåll
- **Sensorer:** Rengör regelbundet för att säkerställa korrekta avläsningar.
- **Pump:** Kontrollera slangar och kopplingar för att undvika blockeringar.
- **Strömförsörjning:** Kontrollera kablar och strömadapter.

---

## 5. Felsökning
| **Problem**           | **Möjlig lösning**                          |
|-----------------------|--------------------------------------------|
| Pump startar inte     | Kontrollera kablar, relä och kod            |
| LED lyser fel färg    | Se till att RGB-kablarna är rätt kopplade   |
| Inget visas på LCD    | Kontrollera anslutningarna till LCD-pinnarna|
| UV-LED lyser inte     | Kontrollera anslutning och ljusvärden       |

