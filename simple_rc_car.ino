/*
 * Simple RC JCB operation using arduino
 *
 * Commands are receving from serial port to arduino.
 * based on the commands, motor operation will be done.
 *
 * This sketch will use buffer ic to interface with motor
 *
 */

char command;
int ledPin = 13;

void setup()
{
	Serial.begin(9600); // Initialize serial port to send and receive at 9600 baud
	pinMode(ledPin, OUTPUT); // set this pin as output
}

void loop()
{
	if( Serial.available())
	{
		char ch = Serial.read();
		if (isAlpha(ch))
		{
			if(isLowerCase(ch))
			{
				ch = ch - 'a' + 'A';
			}
			handlecommand(ch);
		}
	}
}


void handlecommand(char ch)
{
	switch(ch)
	{
		case 'F':
			Serial.write("Forward");
			command = ch;
			break;
		case 'B':
			Serial.write("Backward");
			command = ch;
			break;
		case 'L':
			Serial.write("Left");
			command = ch;
			break;
		case 'R':
			Serial.write("Right");
			command = ch;
			break;
		case 'C':
			Serial.write("Crane");
			command = ch;
			break;
		case 'S':
			Serial.write("Stop");
			command = ch;
			break;
		default:
			Serial.write("default case");
	}
}
