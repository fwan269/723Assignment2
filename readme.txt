Cruise Control system Esterel
============================
Authors: Iain Ross, Fang Ping, Tai Martinez Grant
Release Date 8/06/2025
version 1.0

Overview
========
This project implements a cruise control system using a synchronous programming language Esterel v5. It models a state behvaiour of a cruise control system in modern cars, allowing it to maintain a cruise speed and respond to the drivers input. The control logic is structured as an esterel (unit control) that interacts with the vehicles signals. A top level CruiseController runs the control unit and system interfaces. The system also contains some associated C code that supports the throttle regulation and signal type interpretation for the enums and helper functions for signaling the pedals.

Files included
===================
-UnitControl Model main esterel model in CruiseControl.strl implementing the control logic.
-CruiseControl Model used as a top level Esterel module for the CruiseControl.strl implementing the input/output signals from the vehicle.
-cruisecontrol.h header function for defining the enums, constants and helper functions
-crusiecontrol_data.c main code running the helper functions for initializing the Enum, pedal sensor and regulating the throttle.


Functionalities
=================
-Cruise States: The systems loops through different states OFF, ON.STDBY, and DISABLE states, this function is done using Esterel in the Unit Control Model.
-Throttle Regulation: Implements a pi controller in crusiecontrol_data.c to maintain the cruise speed.
-Pedal Monitoring: Tracks the pedal power through the accel signel and changes states depending on how high it is, this is done in crusiecontrol_data.c.
-Speed Constraints: These speed constrains limit the speed and acceleration of the vehicle by limiting how high it can accelerate and how fast it can move based on reasonable values.
-Quick Accel/Deccel: Special buttons that the driver triggers to rapidly increase the cars speed but still limit it two within the speed constrains.
-Resume and set buttons; This logic is used the resume the last cruise speed or setting a new speed based on current vehicle speed.

Constrants
=============
-Minimum Speed = 30.0 km/h (minimum speed of the cruise controller)
-Max Speed = 150.0 km/h (maximum speed of the cruise controller)
-speed incline = 2.5 km/h (step acceleration for the quick accel and decel)
-Pedel minimum = 3.0 (abstract value for the minimum pedal press to accelerate the car)
-throttle saturation maximum = 45 (maximum the throttle can accelerate the car)

Instructions for implementation
==================
To run the simulation you would need a Linux run server (this can be done on flexit) and the ctype/MakeFile provided in the zip to convert strl files into xes files so that it can be run on esterel. To run the code first open the zip file for the 723Assignment folder. Using terminal type in (cd assignment2), then (cd files), and now you can create the xes file by typing in first make clean and then make cruisecontrol.strl. After that open the file containing the xes file by typing in ./cruisecontrol.xes. Now the terminal is running and you can select different inputs and observe the outputs.

Notes
============
This code only emits throttle commands when in the off state will change to better suit the requirements.