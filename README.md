# OWI-535-control-QT
A OWI-535 control App with GUI using Qt.

Part of the code is from the blog **NOTBRAINSURGERY**, which was publised at https://notbrainsurgery.livejournal.com/38622.html
<br/> <br/> 


To use this project, please star it.
<br/> <br/> 

Usage:
  
  Use the Qt Creator to open the .pro file, then compile it.
  
  * Remember to configure the libusb in the .pro file
  
  * An easy to get libusb on Mac is to run 
  ```
    brew install libusb 
  ```
  with the terminal.
  
 <br/><br/> 
  
There are 5 motors and A LED on the OWI-535 on the machine.

   | code| name    | up(KEY) | down |
   | :-----| ----: | :----: |  :----:|
   | M1  | grip    | 1       | Q    |
   | M2  | wrist   | 2       | W    |
   | M3  | elbow   | 3       | E    |
   | M4  | shoulder| 4       | R    |
   | M5  | roate   | 5       | T    |
   | L   | Light   | L       | .    |
   | P   | stop    | P       |      |

Press the key and the machine will do the corresponding action, and will stop when the key is released.


