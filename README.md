# Not-a-block
Note block from Minecraft but in real life.

![Note block isometric image](/images/iso_nb_main.png)

![Note block and instrument block stacked image](/images/both_stack.png)

## What it is:
I made a note block from Minecraft which functions close enough to the actual game. You can tap the top face of the note block to play it and hit the back side of it to change the pitch (like right-clicking in Minecraft).

You can change the sound of the note block by placing it on different types of blocks as well. This is possible as there is an RFID card reader underneath the note block and a RFID tag on top of the instrument block (like stone, glass, sand, etc.)

## How it works:
The note block contains an ESP-32-C3-SuperMini. It's the microcontroller which connects to different components. It also stores music files inside its flash memory. 
As the music files are under a second, we can store quite a lot of them inside the ESP32, so there is no need for a SD card module (which also saves pins). Sound is played by a MAX98357A I2S amp with a 4Ω 3W speaker (50mm diameter).

There are 2 piezoelectric sensors present inside the note block's top and back surface. When you hit the surface, the piezo sends voltage to the ESP32's data pin which tells it to play the sound.

![Note block piezo mount](/images/nb_inner.png)

There are 16 different instrument sounds which the note block can play, which depend on the block below it. When the top surface is hit, it only tells ESP32 to play a single sound each time. When the back surface is hit, which is for changing the pitch of the instrument, each hit changes the sound to a different pitch. We don't need to have different audio inside the ESP32 for each pitch, as it can directly change on its own. Only the instrument sounds are needed to be stored.

For detecting which block is present below the note block, a PN532 RFID card reader sits on the bottom surface, while a RFID tag sits on the top surface of the other blocks. 
The tag gets read every few seconds so that if the block changes, its sound changes as well without a lot of delay. 4 magnets are also present under the note block's surface as well as an instrument block's top surface, so that lining up the tags as well as the blocks is very easy. The magnets are also in different polarities (NN/SS) on the surfaces so you don't accidentally misplace back of the note block (where you hit to change pitch).

![Note block RFID mount](/images/nb_bottom.png)

![Note block pcb mount](/images/nb_bottom2.png)

The front surface of the note block contains holes so that the speaker can out put sound. I decided to only make holes in the black layer as it is thinner than the white one and would not show that many holes as well. 

![Note block speaker grill](/images/nb_f%2Bb.png)

## Dimensions:
1) Note block / Instrument block: 10 x 10 x 10 cm
  - Each face has 3 layers, overall 0.4cm thick.
2) Note block PCB: 5.75 x 4 cm
3) Piezoelectric sensor: 3.5cm diameter


