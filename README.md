# Digital-Thermometer-using-Proteus
This is a software simulation of Digital Thermometer using LM35 ADC and 8051 microcontroller on Proteus<br/>
<br/>
![image](https://user-images.githubusercontent.com/68046238/118305027-0c414480-b505-11eb-8691-ef6f6c4bbb77.png)


## Installing Proteus

You may install the licensed version of proteus(paid) or can also get latest unlicensed [version](https://getintopc.com/?s=proteus) (not recommended but you can go with it if that is the only option left).
After installation, if the components list shows as empty, follow this [link](https://youtu.be/l4770kWKwRs).<br/>
Once the installation has completed, you can open the Project file (with extention .pdsprj) and modify it according to need.

## Installing Keil uVision

You can skip this step if you don't wish to change the code. <br/>
Download the Keil MDK-Arm and Keil c51 (both are free) from the [official Keil website](https://www.keil.com/download/product/). It would ask for a bunch of information before you can start installation.

## Debugging the code in Keil uVision

You can skip this step if you didn't change the code. <br/>
1. Create a project (.uvproj)
2. Import the code from the location where you have downloaded this repository.
3. Right click on the Target 1 and select 'Options for Target 1...'. <br/>
![image](https://user-images.githubusercontent.com/68046238/118304312-23336700-b504-11eb-8541-f6ba1ee92027.png)

4. Go to the 'Target' tab and check that the crystal frequency matches to that of the one set in the microcontroller in Proteus. Next, go to the 'Output' tab and select 'Create HEX File' check-box and hit 'OK'. <br/>
![image](https://user-images.githubusercontent.com/68046238/118304579-79080f00-b504-11eb-9281-e65e9185325e.png)
5. Here, you can edit the code according to your need (changing the delay time, message to be displayed, etc).
6. Now, Translate and Build the file in Keil. You will notice that a new HEX file has been generated.

## Loading the code in Proteus

You can skip this step if you didn't edit the code. <br/>
1. Right-click on the microcontroller in Proteus and select 'Edit Properties'.
2. In the 'Program File', make sure that the correct HEX file (the one you recently generated) has been selected.
3. Click 'OK'.

## Running the Simulation

1. Select the 'PLAY' button on the bottom-left corner. <br/>
 ![image](https://user-images.githubusercontent.com/68046238/118312755-74952380-b50f-11eb-96ea-6284b05a179a.png)

To obtain different value of temperature, toggle the voltage on the LM35 sensor and re-run the project to display on LCD display.  

<br/>
