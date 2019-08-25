// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       MyVoice.ino
    Created:	2019/8/10 13:16:38
    Author:     lynsucceed@gmail.com
*/

// Define User Types below here or use a .h file

#include <Arduino.h>
#include "MIdiNote.h"

#define durtion_base 4 //以1/4音符为1拍
#define Tempo 120 // 定义1min多少拍

// //MIDI开/关消息
#define velocity  100 // MIDI音符的速度必须在0到127之间,更高的速度通常会使MIDI乐器更响亮
#define noteON  144 //  144 = 10010000 in binary,note on 命令
#define noteOFF  128 // 128 = 10000000 in binary,note off命令
#define deltatime 10   // 定义音符触发结束的时间

// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//发送MIDI消息
void MIDImessage(int command,int MIDInote,int MIDIvelocity){
  Serial.write(command); //发送note on或note off命令 
  Serial.write(MIDInote); //发送音高数据  
  Serial.write(MIDIvelocity); //发送速度数据
}
//演奏MIDI
void playMidi(int note,int speed)
{
	MIDImessage(noteON,note,velocity); //演奏MIDI
    delay(speed-deltatime); //延时speed ms
	MIDImessage(noteOFF,note,velocity); 
    delay(deltatime);
}

void play_per_Midi(int note,int duration_type , bool isDot ,int tempo)
{
	
	int delta_duration = 60000/tempo;
	int duration = delta_duration * durtion_base/duration_type;
	
	if (isDot == false)
	{
	   playMidi(note,duration);

	}
	else
	{
		playMidi(note,duration +0.5* duration);
	}

}

void play_Reset_Midi(int duration_type , bool isDot ,int tempo)
{
	
	int delta_duration = 60000/tempo;
	int duration = delta_duration * durtion_base/duration_type;
	
	if (isDot == false)
	{
	   MIDImessage(noteOFF,C4,velocity); 
	   delay(duration);

	}
	else
	{
		MIDImessage(noteOFF,C4,velocity); 
	    delay(duration + 0.5 * duration);
	}

}



// The setup() function runs once each time the micro-controller starts
void setup()
{
 //设置MIDI通信波特率
  Serial.begin(31250);

}

// Add the main program code into the continuous loop() function
void loop()
{
	play_per_Midi(A04,2,false,Tempo);//playMidi(69,800);
	play_per_Midi(A04,4,false,Tempo);//playMidi(69,400);
	play_per_Midi(E5,4,false,Tempo);//playMidi(76,400);
	play_per_Midi(E5,4,false,Tempo);//playMidi(76,400);
	play_per_Midi(C5,4,false,Tempo);//playMidi(72,400);
	play_per_Midi(D5,4,false,Tempo);//playMidi(74,400);
	play_per_Midi(D5,4,false,Tempo);//playMidi(74,400);
	play_per_Midi(C5,4,false,Tempo);//playMidi(72,400);
	play_per_Midi(A04,2,false,Tempo);//playMidi(69,800);
	play_per_Midi(A04,4,false,Tempo);//playMidi(69,400);
    play_per_Midi(G4,2,false,Tempo);//playMidi(67,800);
	play_per_Midi(E4,4,false,Tempo);//playMidi(64,400);
	play_per_Midi(E4,4,false,Tempo);//playMidi(64,400);
	play_per_Midi(G4,4,false,Tempo);//playMidi(67,400);
	play_per_Midi(B4,4,false,Tempo);//playMidi(71,400);
	play_per_Midi(A04,2,true,Tempo);//playMidi(69,1200);
	play_per_Midi(A04,2,true,Tempo);//playMidi(69,1200);

	play_per_Midi(E5,2,false,Tempo);//playMidi(76,800);
	play_per_Midi(C5,4,false,Tempo);//playMidi(72,400);
	play_per_Midi(E5,4,false,Tempo);//playMidi(76,400);
	play_per_Midi(E5,4,false,Tempo);//playMidi(76,400);
	play_per_Midi(C5,4,false,Tempo);//playMidi(72,400);
	play_per_Midi(D5,4,false,Tempo);//playMidi(74,400);
	play_per_Midi(D5,4,false,Tempo);//playMidi(74,400);
	play_per_Midi(C5,4,false,Tempo);//playMidi(72,400);
    play_per_Midi(D5,2,false,Tempo);//playMidi(74,800);
	play_per_Midi(C5,4,false,Tempo);//playMidi(72,400);
	play_per_Midi(B4,2,false,Tempo);//playMidi(71,800);
	play_per_Midi(B4,4,false,Tempo);//playMidi(71,400);
	play_per_Midi(B4,4,false,Tempo);//playMidi(71,400);
	play_per_Midi(B4,4,false,Tempo);//playMidi(71,400);
	play_per_Midi(A04,4,false,Tempo);//playMidi(69,400);
	play_per_Midi(E5,2,true,Tempo);//playMidi(76,1200);
	play_Reset_Midi(4,false,Tempo);//delay(400);
    play_per_Midi(A04,4,false,Tempo);//playMidi(69,400);
	play_per_Midi(A04,4,false,Tempo);//playMidi(69,400);


	play_per_Midi(A05,2,false,Tempo);//playMidi(81,800);
	play_per_Midi(G5,4,false,Tempo);//playMidi(79,400);
	play_per_Midi(A05,4,false,Tempo);//playMidi(81,400);
	play_per_Midi(E5,4,false,Tempo);//playMidi(76,400);
	play_per_Midi(E5,4,false,Tempo);//playMidi(76,400);
	play_per_Midi(G5,4,false,Tempo);//playMidi(79,400);
    play_per_Midi(G5,4,false,Tempo);//playMidi(79,400);
	play_per_Midi(E5,4,false,Tempo);//playMidi(76,400);
	play_per_Midi(G5,4,false,Tempo);//playMidi(79,800);
	play_per_Midi(C5,4,false,Tempo);//playMidi(72,400);
	play_per_Midi(D5,4,false,Tempo);//playMidi(74,400);
	play_per_Midi(D5,4,false,Tempo);//playMidi(74,400);
	play_per_Midi(C5,4,false,Tempo);//playMidi(72,400);
	play_per_Midi(D5,4,false,Tempo);//playMidi(74,400);
	play_per_Midi(D5,4,false,Tempo);//playMidi(74,400);
	play_per_Midi(C5,4,false,Tempo);//playMidi(72,400);
	play_per_Midi(C5,4,false,Tempo);//playMidi(72,400);
	play_per_Midi(E5,2,false,Tempo);//playMidi(76,800);
	play_per_Midi(E5,2,true,Tempo);//playMidi(76,1200);

	play_per_Midi(A04,4,false,Tempo);//playMidi(69,400);
	play_per_Midi(A04,4,false,Tempo);//playMidi(69,400);
	play_per_Midi(A04,4,false,Tempo);//playMidi(69,400);
	play_per_Midi(E5,2,false,Tempo);//playMidi(76,800);
	play_per_Midi(C5,4,false,Tempo);//playMidi(72,400);
	play_per_Midi(D5,4,false,Tempo);//playMidi(74,400);
	play_per_Midi(D5,4,false,Tempo);//playMidi(74,400);
	play_per_Midi(C5,4,false,Tempo);//playMidi(72,400);
    play_per_Midi(D5,2,false,Tempo);//playMidi(74,800);
	play_per_Midi(C5,4,false,Tempo);//playMidi(72,400);
	play_per_Midi(B4,4,false,Tempo);//playMidi(71,400);
	play_per_Midi(B4,4,false,Tempo);//playMidi(71,400);
	play_per_Midi(B4,4,false,Tempo);//playMidi(71,400);
	play_per_Midi(B4,4,false,Tempo);//playMidi(71,400);
	play_per_Midi(G4,4,false,Tempo);//playMidi(67,400);
	play_per_Midi(B4,4,false,Tempo);//playMidi(71,400);
	play_per_Midi(A04,2,true,Tempo);//playMidi(69,1200);
	play_per_Midi(A04,2,true,Tempo);//playMidi(69,1200);

}
