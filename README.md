
      `      Developing and Testing a MCT Device Simulator

Revised Algorithm Design Document

Submitted to:
Vojislav D Radonjic
COMP 3004 Object-Oriented Software Engineering
School Of Computer Science
Carleton University


Team 10
Funa Anommeze
Naol Gushu
Mohammed Camara
Kareem Arab

Table of Content

Introduction
UseCase
Implementation
Program Class
Frequency
Battery

Table of Figures

Figure 1 Activity diagram
Figure 2 a simple sequence diagram that how how the system work
Figure 3 a sequence diagram demonstrates that how to read the messages



Deliverables no: 1
Projected Grade:    /50
Actual Grade:    /50


Introduction


	The objective of this assignment is to record the evaluation and detail of an inserted frameworks model utilized in microcurrent biofeedback frameworks comparable to the DENAS. Microcurrent Technology (MCT) is a major advance in persistent and intractable pain medications, and provides potential for a number of other treatments. Numerous have named this modern era of restorative items that utilize electrical streams, called electroceuticals, the restorative science presence. At a certain active point in the human body, electro-neuro-stimulation is based at the premise that electrical currents are impulses. Moreover, the program gives numerous other shapes of care for individuals enduring from other disorders. To associate outside helpful anodes the MCT framework has a coordinates cathode and attachment. This basic effective framework is effortless, convenient and reasonable for any pain-stricken individual.


Use Cases:
Electrode is attached
Electrode is not attached
Low Battery

Implementation:
Low Battery - When device is turned on, random number from (1-10) * 100 is generated as battery level.
Battery is drained depending on power level and therapy time
3 ranges:
If < 10% Lightning sign
If 10% < x < 30% Please charge battery
If 30% < x Proceed to the main menu.

From main menu,

From Program page:
Select desired treatment.
Select power level
Prompt: Is denas touching skin:
If Yes->frequency meter
If No->Please attach to desired treatment area

1. The interface: buttons, display and electrodes
2. Battery level: dependent on time and power level of therapy
3. Time of therapy: displayed and advanced only during skin on, paused during skin off 4. Power level: 0-100
5. Electrodes: output and input (skin on/off)
6. Therapies: frequency, programmed (3 of your choice)

Program Class
Select Treatment (Head, Hand, Throat)
Select Power level (1-10)
Select Time (1-5 min)
Inherits Session
Launches Session
Frequency Class
Select Frequency
Select Power Level
Session Class
Checks if electrode is attached
If attached:
Displays treatment, power level and times (and frequency??)
Drains power level every minute (ie. battery->drainLevel(int PowerLevel)
If detached:
Requests for electrodes to be attached
Stops mid treatment
Battery Class
Will be a global variable
Stores battery level
Drain level function
Drains depending on power level (1% for 1, 2% for 2… 10% for 10)
Adds 2 power levels and divides by 2. (PPL =1, FPL = 1-> 1%, PPL = 2, FPL = 1 -> 1.5%)
Battery display will be rounded

The Basic Use Case: Battery Enough and Attached to skin
User presses the  ON button.
Battery check and Indicates >30%.
Proceeds to the Main menu screen.
User navigates the Main menu with the help of pressing arrows(Up or Down).
User chooses between Program and Frequency.
User uses arrows (Up or down) to navigate the Program menu.
User uses (up or down) buttons to navigate the Frequency menu.
User presses ok to select the desired frequency level.
User uses arrows (back) to return to Main menu
User selects desired treatment and adjusts power level.
User attaches electrodes to the desired area for treatment.
Denas begins treatment until the treatment session terminates.
User presses the off button.

The 2nd Use Case: Battery Enough and Not attached to skin
User presses the  ON button.
Battery check and Indicates >30%.
Proceeds to the Main menu screen.
User navigates the Main menu with the help of pressing arrows(Up or Down).
User chooses between Program and Frequency.
User uses arrows (Up or down) to navigate the Program menu.
User uses (up or down) buttons to navigate the Frequency menu.
User presses ok to select the desired frequency level.
User uses arrows (back) to return to Main menu
User selects desired treatment and adjusts power level.
DENAS electrodes not attached to skin
DENAS prompts user to attach electrodes to skin
User attaches electrodes to the desired area for treatment.
Denas begins treatment until the treatment session terminates.
User presses the off button.

The 3rd Use Case: Low Battery
User presses the  ON button.
Battery check and Indicates <10%.
Low battery message prompts user: “Please Charge DENAS”.
User connects the DENAS with a cord to an outlet until the battery reaches 100%.
Patient presses the ON button.
Battery check and Indicates >30%.
