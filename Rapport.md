# **Beskrivning av arbetet med fokus på HUR vi arbetade agilt**  

Under projektet utvecklade vi ett automatiskt bevattningssystem för växter baserat på en Arduino-plattform. Systemet mäter jordens fuktighetsnivå och omgivande ljusnivåer och styr en vattenpump samt en LED-lampa utifrån dessa mätvärden för att säkerställa optimal bevattning. Vi inledde arbetet med att bygga och testa kretsarna i TinkerCAD för att skapa en virtuell prototyp och säkerställa att alla komponenter fungerade korrekt. Därefter utvecklade vi koden för att hantera sensorer, pump och LED-lampa. När vi var nöjda med funktionaliteten i den virtuella miljön, byggde vi systemet fysiskt och genomförde omfattande tester. Systemet implementerades även med en LCD-display för att visa sensoravläsningar och ge användaren tydlig feedback.  

För att arbeta agilt använde vi en **Developer's To-Do list** och en **SRS** (*Software Requirements Specification*) som levande dokument genom hela projektet. Vi arbetade tätt tillsammans och kommunicerade kontinuerligt för att hantera uppgifter effektivt. Genom att ge varandra löpande feedback kunde vi snabbt identifiera förbättringsområden och göra nödvändiga justeringar. Eftersom projektet endast pågick under två veckor valde vi att inte implementera en Kanban-tavla, då vi bedömde att det skulle vara tidskrävande att upprätthålla.  

### **Arbetsfaser**  
1. **Planering och kravställning** – Vi definierade **SRS** och **Developer's To-Do list** för att få en tydlig riktning.  
2. **Simulering och prototypframtagning** – Vi testade och validerade designen i TinkerCAD.  
3. **Fysisk implementering och testning** – Vi byggde systemet och utförde omfattande tester för att säkerställa att det fungerade enligt våra krav.  

---

# **Reflektion över vårt arbetssätt**  

### **Hur fungerade samarbetet i teamet?**  
Samarbetet fungerade mycket bra. Vi arbetade tätt tillsammans och hade en tydlig gemensam vision redan från start, vilket gjorde planeringen effektiv. Vi diskuterade eventuella ändringar och nya förslag öppet, vilket hjälpte oss att fatta snabba beslut. Kommunikationsflödet i gruppen var avgörande för att vi kunde genomföra projektet smidigt och effektivt.  

### **Vad tar vi med oss för lärdomar till nästa projekt?**  
En av de viktigaste lärdomarna är vikten av detaljerad planering. Vi stötte exempelvis på förseningar eftersom vi inte hade tänkt på att vissa komponenter krävde en skruvmejsel för montering. Dessutom insåg vi vikten av noggrannhet vid koppling av kretsarna, då en enda felkopplad kabel kunde leda till tidskrävande felsökning.  

### **Vad skulle vi vilja gjort annorlunda?**  
Projektets ramar och mål var något otydliga från början, vilket gjorde det svårt att planera effektivt. Att vi parallellt arbetade med ett annat projekt skapade även utmaningar i tidsplaneringen. Nästa gång skulle vi tydligare definiera projektets omfattning från start.  

En annan förbättring skulle vara att använda PlatformIO istället för Arduino IDE från början, istället för att byta IDE mitt i projektet. Vi fick vissa komponenter sent, vilket begränsade hur mycket vi kunde göra i ett tidigt skede av projektet.  

---

# **Beskrivning av resultatet**  

### **Hur långt kom vi med färdigställandet av uppgiften?**  
Vi lyckades utveckla ett fungerande bevattningssystem som mäter jordens fuktighetsnivå och styr vattenpumpen samt en LED-lampa utifrån dessa mätvärden. Dessutom implementerade vi en LCD-display som visar aktuella sensorvärden och ger användaren tydlig feedback om systemets status.  

### **Hur gick den gemensamma kompletterande instuderingen?**  
För att kunna använda en relämodul behövde vi fördjupa oss i hur reläer, transistorer och dioder fungerar samt hur de kopplas i kretsen. Vi behövde även läsa in oss på hur en LCD-display ansluts och programmeras för att korrekt visa sensorvärden. Denna instudering hjälpte oss att undvika misstag och säkerställde att systemet fungerade som förväntat.  

### **Vad finns kvar att göra?**  
Vi har uppnått de mål vi satte upp för projektet, men en viktig förbättring skulle vara att bygga en skyddande inkapsling för komponenterna. Detta skulle hjälpa till att skydda elektroniken från vatten och andra yttre faktorer.  

### **Eventuell vidareutveckling**  
För att göra systemet mer skalbart skulle vi kunna anpassa koden för att stödja olika typer av pumpar och växter med varierande bevattningsbehov. På så sätt skulle systemet kunna användas i fler miljöer och för olika typer av växtodlingar. En annan potentiell förbättring är att integrera en övervakningsfunktion via en mobilapp eller webbsida, vilket skulle ge användaren möjlighet att styra och övervaka bevattningen på distans.  

---

# **Reflektion över resultatet**  

### **Fungerar systemet som tänkt?**  
Ja, systemet fungerar som planerat och bevattnar växten automatiskt baserat på fuktighetsnivån i jorden. Sensordata visas korrekt på LCD-displayen och LED-lampan ger visuell feedback.  

### **Kodens kvalitet?**  
Koden är välstrukturerad och tydligt kommenterad, vilket gör den lätt att förstå och vidareutveckla. Dock finns det utrymme för optimering, särskilt vad gäller felhantering och energieffektivitet. Att strukturera om delar av koden för bättre modulär uppdelning skulle också kunna förbättra kodens läsbarhet och underhållbarhet.  
