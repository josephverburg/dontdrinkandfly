#include <stdint.h>
#include <stdbool.h>


#ifndef PC_TERMINAL_H_
#define PC_TERMINAL_H_

#define PREAMPLE_B1 0x13
#define PREAMPLE_B2 0x37
#define PACKET_BODY_LENGTH 10
#define PACKET_LENGTH (PACKET_BODY_LENGTH + 5)

int fd_joystick;
// @Author: George Giannakaras
struct pcState{
	//KEYBOARD
	bool escPressed; //abort / exit

	uint8_t mode;
	bool n0Pressed;
	bool n1Pressed;
	bool n2Pressed;
	bool n3Pressed;
	bool n4Pressed;
	bool n5Pressed;
	bool n6Pressed;
	bool n7Pressed;
	bool n8Pressed;

	bool aPressed;	//lift up
	bool zPressed;	//lift down
	uint16_t liftValue;

	bool leftPressed;	//roll up
	bool rightPressed;	//roll down
	uint8_t rollValue;
	bool upPressed;		//pitch down
	bool downPressed;	//pitch up
	uint8_t pitchValue;

	bool qPressed;	//yaw down
	bool wPressed;	//yaw up
	uint8_t yawValue;

	bool uPressed;	//yaw control P up
	bool jPressed;	//yaw control P down
	uint16_t PValue;

	bool iPressed;	//roll/pitch control P1 up
	bool kkPressed;	//roll/pitch control P1 down
	uint16_t P1Value;

	bool oPressed;	//roll/pitch control P2 up
	bool lPressed;	//roll/pitch control P2 down
	uint16_t P2Value;

	//JOYSTICK
	bool jChanged;
	bool jThrottleUp;	//lift up
	bool jThrottleDown;	//lift down
	bool jLeft;		//roll up
	bool jRight;	//roll down
	bool jForward;	//pitch down
	bool jBackward;	//pitch up
	bool jTwistClockwise;			//yaw up
	bool jTwistCounterClockwise;	//yaw down
	bool jFire;	//abort / exit
	uint16_t jThrottleValue;
	uint8_t jRollValue;
	uint8_t jPitchValue;
	uint8_t jYawValue;

	//TOTAL
	uint16_t tLiftValue;
	uint8_t tRollValue;
	uint8_t tPitchValue;
	uint8_t tYawValue;
};


// @Author: Alex Lyrakis
typedef struct{
	uint16_t fcs;
	uint8_t payload[10];
	uint8_t crc;
} SRPacket;

FILE *Rfile;
FILE *Sfile;

SRPacket sPacketBuffer[65535];
bool receivedACK[65535];

void logReceivePacket(SRPacket *rPacket);

#endif
