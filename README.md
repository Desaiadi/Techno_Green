Abstract— The practise of farming has endured significant transformation as technology advances every day. The constraints of area and nonlinear nature of climatic conditions, polyhouse kind of concepts are increasing, which is helpful in production of flowers, vegetables and fruits. The proposed work discusses such an automated irrigation system that highlights the optimum solution for the efficient use of water and electricity for agricultural purposes. Field survey and literature shows that the existing systems are available with two solutions, one is timer-based and another one is moisture-based automization. Moreover, the timerbased system has demerits like being semi-automated i.e., timer needs to be changed manually according to climate. Similarly, in moisture-based systems, reliability is the issue. Therefore, the main objectives of the proposed work are to overcome the demerits of the present systems by integrating both the systems, to develop a fully automated irrigation system, to manage the use of water, electricity, and to add a remote controlling system. The report includes algorithm for the integration of moisture and timer-based system which provides the optimum efficiency on the water use and the use of solenoidal valve.
Index Terms—Automation, irrigation, microcontroller, farming

# I. INTRODUCTION

The process of farming has witnessed dramatic change as technology advances every day. The demands for offseason yields has dramatically increased, and when traditional methods were formerly deemed to be sufficient for crop production, they now have little application and appeal to consumers. India’s ground water levels are critically low and present irrigation systems are poor in efficient water and energy management. Moreover, the situation is similar all over the World. So there is definite need of developing the efficient system for irrigation of water.
Traditional farming practises in India have changed because of concepts like polyhouse [1], which also offers new chances to increase productivity while using fewer resources. The motivation behind this work is as follows:
•	It takes time for the farmers to visit their fields to check the moisture content. They turn on the motor and wait till there is enough water in the tank before watering the land. It takes a lot of time and is unpleasant.
•	Any unconsciousness could result in excessive watering. Over-irrigating refers to providing too much water to the soil. The productivity of crops is harmed by this.
•	Additionally, it is a waste of water. Power usage increases. Thus, the price of irrigation rises.
•	Smart irrigation systems [2]–[5] automatically adjust watering schedules and run times to suit unique landscape requirements.
•	Farmers will find it easy to steer the motor away from them. This will make their lives and work easier.
This article proposes an automated irrigation system that highlights the optimum solution for the efficient use of water and electricity for agricultural purposes. There are some existing systems who came up with two solutions, one is timer-based [6] and another one is moisture-based [7], [8] automation. The timer-based approach includes drawbacks such being semi-automated, or the necessity to manually modify the timing in accordance with the weather. Similar problems with reliability exist in moisture-based systems.
Therefore, the major contributions of the article are to construct a completely automated irrigation system, monitor the usage of water and electricity, and add a remote controlling system in order to eliminate the drawbacks of the existing systems by merging both systems. The employment of solenoidal valve and siphoned technology reduces the consumption of less water and power therefore increasing the overall system efficiency, while the integration of moisture and timer-based system produces better quality crops.
The rest of paper is arranged as follows. Section II briefs about the existing technologies used in automated irrigation system. In Section III, the overall block diagram and algorithm of the proposed system is discussed. The hardware and implementation part is discussed in Section IV. In Section V the analysis of results is carried out. Section VI lists the conclusions.

# II. RELATED WORK

A. Literature Survey
Despite being a more sustainable agricultural method than monoculture, polyculture involves more manual labour and is more difficult to automate. In this article, we suggest a quick, first-order simulator that models plant growth in a polyculture environment. However, it has not yet been tried in a real garden. Simulation trials imply that the simulator can be used to learn a planting, watering, and pruning strategy a robot can follow to produce the most yield from a variety of plants with minimal irrigation. In the future, we’ll do research to create a completely automated controller that will run planting, irrigation, and trimming equipment in a real garden during various plant growth cycles [1].
Automation is practised in various fields by different technologies [9]–[11]. An embedded controller PIC 16F877A, moisture sensor, and an induction valve have all been used in an attempt to create an automatic irrigation system. The sensors are utilised to gauge the soil’s moisture content and adjust the valve accordingly. [12]. Data pertaining the microcontroller-based automated irrigation system has been attempted to give (ATMEGA 328). With an automated irrigation control system based on an ATMEGA 328 and GSM module, an effort is made to give continuous readings of soil humidity and ambient temperature [13]. To control the temperature and relative humidity inside polyhouse using microcontroller is discussed in [14]. The tracking and recordkeeping of seedlings and other agricultural products during the germination and growth stages is illustrated using an internet of things (IoT)-based greenhouse traceability model [15]. A model for polyhouse using various sensors and IoT have been proposed by the researchers [16]–[20]. A closed loop irrigation system that completely automates the distribution of irrigation water and determines in real time the amount of water needed using satellite photos is exhibited in [21].
MATLAB/Simulink is used to build and model a structure for an automated control system of the soil’s moisture within the modular field using subterranean irrigation. [8].
B. Field Survey
For further understanding we have visited one automated irrigation system i.e. Suman Agro Industries, Itkare. The system is provided by Jain solutions; and it costs a huge amount. The firm have implemented the timer based irrigation system for open fields. The actual field on which dripper lines are laid is shown in Fig. 1.

![image](https://github.com/Desaiadi/Techno_Green/assets/110556814/f8647fc4-eb33-476e-88e6-1656e081ac94)
Fig. 1. Automated irrigation system at Itkare

III. PROPOSED SYSTEM
The proposed system is elaborated in the following two subsections.

A. Block Diagram
The block diagram of the proposed system is shown in Fig.
2. The flow of water from water tank to field is controlled

![image](https://github.com/Desaiadi/Techno_Green/assets/110556814/9e2a800d-786c-4bf5-9688-8656c57c1a87)
 
Fig. 2. Block Diagram of Proposed System
by a solenoid valve and motor. The control signal is given to motor from controller. The controller is connected with real-time control (RTC) module which provides real time and date and with moisture sensor which are two major inputs for controlling. The overall controlling of water is done by following way. The water is stored in upper tank and supplied to each rack independently. Then each rack has its own 12 V motor for individual flow control. Motor is actuated by relay while signal for each really is given by a microcontroller.
B. Flowchart
The working of overall proposed work is illustrated through flowchart which is as given below. The proposed system

![image](https://github.com/Desaiadi/Techno_Green/assets/110556814/9fef2101-fabe-4476-bb52-f20c3873af2a)

 
Fig. 3. Flowchart for 1st week
consists of RTC module, so the date and time is set in the controller and accordingly the water is given to the crops. Furthermore, to make the system robus, sensors are employed in the soil. The Fig. 3 shows the 1st week operation logic where every alternate day watering to the crops is done or if moisture level goes down then based on the moisture sensor water is supplied, taking care of crops with desired water. Similarly for Fig. 4 and Fig. 5 demonstrate the operations of 2nd and 3rd week respectively.
Here, if input date and input time are matched with the set date and set time then the motor is turned ON. Then proper delay is applicable to keep motor turned on for certain pre-defined time, which is calulated based on the crop study, after that signal is provided so that motor turns OFF. The overall system is programmed using embedded C code and downloaded to microcontroller.

![image](https://github.com/Desaiadi/Techno_Green/assets/110556814/64c27ed9-26ab-4843-a9a9-9733ed302df8)

Fig. 4. Flowchart for 2nd week

![image](https://github.com/Desaiadi/Techno_Green/assets/110556814/2e194bef-a0ba-41d4-9272-9f9b4c684db2)

Fig. 5. Flowchart for 3rd week 

# IV. IMPLEMENTATION



# A. Plan of Installation
The test bench of the proposed work planned in rack structure and is planned as depicted in Fig. 6. The same is built at Tulip Farms Project location, as shown in Fig. 7. The test

![image](https://github.com/Desaiadi/Techno_Green/assets/110556814/65a41faa-d930-4306-9596-baacf0f07a01)

Fig. 6. Actual Plan of Installation

![image](https://github.com/Desaiadi/Techno_Green/assets/110556814/fef0f9cc-aaa3-4659-ab32-ebfd1e264980)

Fig. 7. Making of Test Bench
bench consists of four racks and each rack have dimensions as: height of approximately 7 feet, length of 11 feet and width of 2 feet. The rack is made of metal (iron) for robust structure. These structures are generally named as ‘Model – D’ which are used for balcony or terrace of the house. These movable racks can help to move the polyhouse structures from one place to other place very easily. The plan of installing of tank is such that, there are two tanks available in polyhouse. One tank contains water and other tank contains nutrition. Every rack has different pipeline of water and nutrition and whose flow will be controlled either by solenoidal valve or small 12V DC pumps according to requirement.
B. Actual Hardware
The proposed work is built at the project location. Fig. 8 is the model D of Tulip farms project where one rack is shown which is containing 3 layers each layer has different placed in it which has different need of need for independent irrigation control.

 ![image](https://github.com/Desaiadi/Techno_Green/assets/110556814/ca6ec316-01ef-4cfa-98b3-eb7a7115bb6f)

Fig. 8. Model D Structure of Test Bench
 
Fig. 9. Control Unit for the Test Bench
Each layer is provided with the different moisture sensors and different motors for controlling flow of water. Fig 9 is of the controlling unit which has controller LCD relay and RTC placed on it Each relay is connected to different motors of different layers while connections of moisture sensor is connected to different pins of controller.

# V. RESULTS AND DISCUSSIONS
The results acquired by proposed hardware model are compared with the conventional model. The first comparison is based on the power usage and second is on the water usage and the third comparison is based on the human efforts required for conventional system and proposed system.

A. Power Usage
Calculations are made considering the maximum running time of motor is 30 minutes. Comparison of power usage by proposed system and conventional system is given in Table I.
TABLE I
QUANTITATIVE ANALYSIS OF ELECTRICITY BY PROPOSED AND
CONVENTIONAL SYSTEMS
 
Electricity used by 1 microcontroller kit	1 Watt per hour
Electricity used by 12 Volt Motor	60 Watt per hour
Electricity used by Motor and Controller	61 Watt per hour
For 6 Racks	61x6 = 366 W per hour
Total electricity usage in a day	183 Watt
Total usage of the month	183x30 = 5490 W
Total Units consumed	5.490 Units
Total running cost of the month (Rs.)	5.36x5.490 = 29.42
 
Conventional System
Power consumption by motor per hour	746 W per hour
Power consumption by motor per day	373 W (30 min running)
Power consumption by motor per month	373x30 = 11190 W
Units consumed for a month	11.19 units
Total running cost of the month (Rs.)	5.36x11.19 = 59.98
The calculations shows that there is almost 50% saving on a particular crop by the use of proposed method.

B. Water Usage

Comparison of water usage by proposed system and conventional system is given in Table II. From the comparison, it is evident that there is saving of water in the proposed system.
C.	Human Efforts
In conventional system no matter what you have to put one person for monitoring and control of motor in our case these human are eliminated by incorporating automation for sake of convenience we have considered half hour of human efforts in entire month.
TABLE II
QUANTITATIVE ANALYSIS OF WATER USAGE BY PROPOSED AND CONVENTIONAL SYSTEMS
 
	12V, 110 psi motor	Average 200 litre per hour
	30 minutes of use per day	100 litre per day
	For 6 motors	100x6=600 litre per day
	For 30 days	600x30 = 18000 litre
 
Conventional System
For a half hp motor	1960 litre per hour
30 mins of use per day	1960/2 = 980 litre
For a month (30 days)	980x30 = 29400 litre

![image](https://github.com/Desaiadi/Techno_Green/assets/110556814/4660d9c7-fcda-4918-b2ce-f60a5f9f1f4e)
 
Fig. 10. Comparison of Proposed System with Conventional
The Fig. 10 shows graphical view of comparison of both systems in terms of electricity usage, water usage and human efforts. In all of these aspects the proposed system comes looks better choice. In case of electricity usage proposed system save around 50 percent of money spend on electricity. The graph also shows the total water usage of the system which is comparatively lot lower than conventional one. It can easily save 40 percent of water by implementing the automated system. Looking towards human efforts column we can easily say proposed system eliminates conventional one, in this case with saving around 90 percent of human efforts.
VI. CONCLUSION
The automated system is built independently for moisture sensor-based control and RTC-based control. Both systems are integrated together after satisfactory operation. A schedule programme is prepared for a few crops. System has been changed to provide maximum effectiveness. A microcontroller is used in the design and development of the automated irrigation system, which is constructed on a rack structure.
Results from the devised system are contrasted with those from the standard system. After comparing our system to the old one, we found that it offers superior efficiency in terms of water and electricity use, making it the optimal replacement for the existing system. Also, in comparison to a typical system, human efforts are insignificant.
This proposed automated irrigation system can be further incorporated with artificial intelligence (AI) and machine learning technologies for remote monitoring and control.
