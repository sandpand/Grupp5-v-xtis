# SRS - Automatic Plant Watering System

## 1. Introduction

### 1.1 Purpose

This document outlines the software requirements for an automatic plant watering system.

### 1.2 Scope

The system will monitor soil moisture and light levels and automatically control a water pump and UV LED.

### 1.3 Definitions, Acronyms, and Abbreviations

* LDR: Light Dependent Resistor
* UV: Ultraviolet
* RTC: Real-Time Clock

## 2. Overall Description

### 2.1 Product Perspective

The system is a standalone Arduino-based device.

### 2.2 Product Functions

* Monitor soil moisture.
* Monitor ambient light levels.
* Control a water pump based on soil moisture.
* Control a UV LED based on light levels.
* Provide an LED indicator for watering status.
* Display sensor readings on an LCD screen.
* (Optional) Monitor soil- and light status via an external application.

### 2.3 User Characteristics

* Users are plant owners who want to automate plant care.
* Users have basic knowledge of electronics and Arduino.

### 2.4 Operating Environment

* Indoor environment.
* Powered by a 5V power supply.

### 2.5 Design and Implementation Constraints

* Arduino Uno as the microcontroller.
* Use of readily available sensors and components.
* Power consumption should be minimized.

## 3. Specific Requirements

### 3.1 Functional Requirements

* **FR1:** The system shall measure soil moisture at regular intervals.
* **FR2:** The system shall activate the water pump when soil moisture falls below a predefined threshold.
* **FR3:** The system shall measure ambient light levels at regular intervals.
* **FR4:** The system shall activate the UV LED when ambient light falls below a predefined threshold.
* **FR5:** The system shall provide an LED indicator for water pump status.
* **FR6:** The system shall display soil moisture and light levels on an LCD screen.
* **FR7:** (Optional) The system shall use an RTC module to schedule watering and UV light.

### 3.2 Non-Functional Requirements

* **NFR1:** The system shall be reliable and operate continuously.
* **NFR2:** The system shall be easy to assemble and use.
* **NFR3:** The system shall be energy-efficient.
* **NFR4:** The sensor readings must be reasonably accurate.
