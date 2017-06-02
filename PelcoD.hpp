#pragma once
#include <stdint.h>




/**PelcoD protocol implementation for some cheap china pan/tilt head.
 * @noote the head behaves different than normal pelcoD. Do not use this for any other device */
class PelcoD
{
public:
	uint8_t data[7];

	void setAddr(uint8_t addr);

	void moveUp(uint8_t speed);
	void moveDown(uint8_t speed);
	void moveLeft(uint8_t speed);
	void moveRight(uint8_t speed);
	void setPreset(uint8_t preset);
	void calcChecksum();
	void clear();//does not clear address
};
