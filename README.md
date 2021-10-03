# R3-SoftwareTask1-CameronTuffnerLyons

This Project was created as part of Software training task 1 F2021 for Ryerson Rams Robotics.

This code is based on the following arduino schematic which can be found at [this link to tinkercad.](https://www.tinkercad.com/things/bjMUoGF4JN4)

![image](https://user-images.githubusercontent.com/83479899/135765015-6d18357b-0526-40c2-a522-f6e07a9f49fa.png)


This main objective of this project was to drive two 7-segment displays using two 7-segment decoders (CD4511), a potentiometer, and an arduino.

![image](https://user-images.githubusercontent.com/83479899/135762742-1cfcae3a-68fb-4625-b26c-f6684e1c9fe3.png)

The code initializes two byte arrays that contain the relevant pin numbers for operating the decoders.

Then, in order to facilitate easy operation of the decoders wrt the input value, a byte array was created which contains all possible 4-bit input values.

![image](https://user-images.githubusercontent.com/83479899/135762819-b21cf0af-be6e-4f2e-a542-10865148fda2.png)

This allows for each binary number to be associated with its respective row within the array. meaning row 0 contains the 4-bit value for 0, row 1 contains the 4-bit value for 1, etc.

Byte variables are created to operate the decoders, specifically Value_To_Display and Digit[2].

The function setDefaultOutput initiallizes the output value that the 7-segment display will show when no other input is given.

the function setPinOutputModes ensures that the pins required to operate the decoders are in output mode.

the function getMappedPOTInputValue obtains the input value from a predetermined anolog pin (A0) and maps said value to the desired range.

![image](https://user-images.githubusercontent.com/83479899/135763195-a294aee9-0102-4aac-b7b5-1e82a8f9dc8f.png)

the function setValueToDisplay sets the variable Value_To_Display to the value returned from getMappedPOTInputValue with a range of 0 to 99

![image](https://user-images.githubusercontent.com/83479899/135763274-fb3d822f-cff9-4882-b74c-c374ebe13318.png)

The function convertValueToDigits deparates a two digit number into its respective tens value and ones value using the code shown above.

the function generate7segOutput generates the required binary input to the decoders in order to produce its output on the relevant output on the displays. This is done by utilizing the Input pin arrays and the Binary input arrays to produce the correct binary input.

220 Ohm resistors are used to limit the current through the 7-segment displays and through the decoders.

Both ICs are powered by the onboard 5V from the arduino.

![image](https://user-images.githubusercontent.com/83479899/135765333-71762d0b-02af-42e6-a647-4755b6a64782.png)

The lamp test and blanking pins on the decoders are set to high and the latching pin to low for normal operation.

![image](https://user-images.githubusercontent.com/83479899/135765353-ec2ca856-04ad-4c30-bd62-4ffcb1f42ddf.png)

Using these functions and schematic the code operates as such:

![image](https://user-images.githubusercontent.com/83479899/135765579-f0c4cc3d-52a8-4962-a0b2-014a8019bad0.png)

The code runs the setup function which calls the functions setDefaultOutput and sePinOutputModes. the default output is set to 0 and the required pins are set to output mode.

The code calls the function setValueToDisplay with a min and max value of 0 and 99 respectively. This value stored in the variable Value_To_Display.

![image](https://user-images.githubusercontent.com/83479899/135765061-fc0e1873-4f39-499b-8b68-e43e6f2efcc6.png)

Next the code uses the function convertValueToDigits to obtain the tens and ones digit from the variable Value_To_Dsiplay and places them in the Digit array.

![image](https://user-images.githubusercontent.com/83479899/135765129-41a2df8b-e2fe-446f-a275-d3ef166c8a01.png)

These digits are then used to create the binary inputs required for the decoders to function.

![image](https://user-images.githubusercontent.com/83479899/135765191-91e269af-e6c9-4411-b391-89c3c4e9eddb.png)

This set of statements is looped in order to function continuously and allow the number displayed to be changed through the potentiometer.
