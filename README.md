# OWI-535-control-QT
A OWI-535 control App with GUI using Qt.

This App is develop to use the keyboard to control the OWI-535 arm, given that the CD only provide tools for Windows.


Part of the code is from the blog **NOTBRAINSURGERY**, which was publised at https://notbrainsurgery.livejournal.com/38622.html
<br/>


<br/> <br/> <br/> 




# Usage
  
  Use the Qt Creator to open the .pro file, then compile it.
  
  * Remember to configure the libusb in the .pro file
  
  * An easy to get libusb on Mac is to run 
  ```
    brew install libusb 
  ```
  with the terminal.
 <br/><br/> <br/> 
  
  To make it work on Windows 10, I use Zadig to replace the driver that Windows installed automatically. Before this, I failed to open the device, where it return the error number -12 when calling libusb_open.





# Controll
Click the button to detect the USB interface kit. 
Note that when a key is released, the detection will also be executed. By this way, disconnection event will be detected earlier.


There are 5 motors and A LED on the OWI-535 on the machine.

   | code| name    | up(KEY) | down |
   | :---| ------: | :-----: | :--: |
   | M1  | grip    | 1       | Q    |
   | M2  | wrist   | 2       | W    |
   | M3  | elbow   | 3       | E    |
   | M4  | shoulder| 4       | R    |
   | M5  | roate   | 5       | T    |
   | L   | Light   | L       | .    |
   | P   | stop    | P       |      |
   | F   | flash   | F       |      |

Press the key and the machine will do the corresponding action, and will stop when the key is released.



