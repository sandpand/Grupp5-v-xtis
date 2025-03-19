# **Description of the Work with Focus on HOW We Worked Agile**

During the project, we developed an automatic watering system for plants based on an Arduino platform. The system measures soil moisture and ambient light levels and controls a water pump and an LED light based on these measurements to ensure optimal watering. We started by building and testing the circuits in TinkerCAD to create a virtual prototype and ensure all components functioned correctly. We then developed the code to manage sensors, pump, and LED light. Once we were satisfied with the functionality in the virtual environment, we built the system physically and conducted extensive testing. The system was also implemented with an LCD display to show sensor readings and provide clear feedback to the user.

To work agilely, we used a **Developer's To-Do list** and an **SRS** (Software Requirements Specification) as living documents throughout the project. We worked closely together and communicated continuously to manage tasks effectively. By providing each other with ongoing feedback, we could quickly identify areas for improvement and make necessary adjustments. Since the project only lasted for two weeks, we chose not to implement a Kanban board, as we assessed that it would be time-consuming to maintain.

### **Work Phases**
1. **Planning and Requirements Definition** – We defined the **SRS** and **Developer's To-Do list** to have a clear direction.
2. **Simulation and Prototyping** – We tested and validated the design in TinkerCAD.
3. **Physical Implementation and Testing** – We built the system and performed extensive tests to ensure it worked according to our requirements.

---

# **Reflection on Our Working Method**

### **How Did the Team Collaboration Work?**
The collaboration worked very well. We worked closely together and had a clear shared vision from the start, which made planning efficient. We discussed any changes and new suggestions openly, which helped us make quick decisions. The communication flow within the group was crucial for us to carry out the project smoothly and effectively.

### **What Lessons Do We Take to the Next Project?**
One of the most important lessons is the importance of detailed planning. For example, we encountered delays because we hadn't considered that some components required a screwdriver for assembly. We also realized the importance of accuracy when connecting the circuits, as a single incorrectly connected cable could lead to time-consuming troubleshooting.

### **What Would We Have Liked to Do Differently?**
The project's framework and goals were somewhat unclear from the beginning, which made it difficult to plan effectively. Additionally, we received some components late, which limited how much we could do in the early stages of the project. Working on another project in parallel also created challenges in time management. Next time, we would like a clearer definition of the project's scope from the start to more easily adapt our idea to the project's size.

Another improvement would be to use PlatformIO instead of the Arduino IDE from the beginning, instead of switching IDEs mid-project.

---

# **Description of the Result**

### **How Far Did We Get with the Completion of the Task?**
We managed to develop a functioning watering system that measures soil moisture and controls the water pump and an LED light based on these measurements. We also implemented an LCD display that shows current sensor values and provides the user with clear feedback on the system's status.

### **How Did the Joint Supplementary Study Go?**
To use a relay module, we needed to delve into how relays, transistors, and diodes work and how they are connected in the circuit. We also needed to study how an LCD display is connected and programmed to correctly display sensor values. This study helped us avoid mistakes and ensured the system worked as expected.

### **What Remains to Be Done?**
We have achieved the goals we set for the project, but an important improvement would be to build a protective enclosure for the components. This would help protect the electronics from water and other external factors.

### **Potential Further Development**
To make the system more scalable, we could adapt the code to support different types of pumps and plants with varying watering needs. This would allow the system to be used in more environments and for different types of plant cultivation. Another potential improvement is to integrate a monitoring function via a mobile app or website, which would give the user the ability to control and monitor watering remotely.

---

# **Reflection on the Result**

### **Does the System Work as Intended?**
Yes, the system works as planned and waters the plant automatically based on the moisture level in the soil. Sensor data is displayed correctly on the LCD display, and the LED light provides visual feedback.

### **Code Quality?**
The code is well-structured and clearly commented, making it easy to understand and further develop. However, there is room for optimization, particularly in terms of error handling and energy efficiency. Restructuring parts of the code for better modularization could also improve the code's readability and maintainability.
