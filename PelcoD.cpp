#include "PelcoD.hpp"

#define SET_BIT(p,n) ((p) |= (1 << (n)))
#define CLR_BIT(p,n) ((p) &= (~(1) << (n)))

void PelcoD::setAddr(uint8_t addr)
{
	data[0] = 0xFF;
	data[1] = addr;
}

void PelcoD::clear()
{
	data[2] = 0;
	data[3] = 0;
	data[4] = 0;
	data[5] = 0;
	data[6] = 0;
}

void PelcoD::moveUp(uint8_t speed)
{
	CLR_BIT(data[3], 4);
	SET_BIT(data[3], 3);
	if(speed > 0x3f) speed = 0x3f;
	data[5] = speed;
}

void PelcoD::moveDown(uint8_t speed)
{
	CLR_BIT(data[3], 3);
	SET_BIT(data[3], 4);
	if(speed > 0x3f) speed = 0x3f;
	data[5] = speed;
}

void PelcoD::moveLeft(uint8_t speed)
{
	CLR_BIT(data[3], 1);
	SET_BIT(data[3], 2);
	data[4] = speed;
}

void PelcoD::moveRight(uint8_t speed)
{
	CLR_BIT(data[3], 2);
	SET_BIT(data[3], 1);
	data[4] = speed;
}

void PelcoD::setPreset(uint8_t preset)
{
	data[2] = 0;
	data[3] = 3;
	data[4] = 0;
	if(preset > 20) preset = 20; //only 20 presets allowed according to doc
	data[5] = preset;

}

void PelcoD::calcChecksum()
{
	uint16_t sum = 0;
	for(int i = 1; i < 6; ++i)
	{
		sum += data[i];
	}
	sum = sum % 256;
	data[6] = (uint8_t)sum;
}
