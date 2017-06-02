#include <iostream>
#include <string>
#include <iomanip>
#include "PelcoD.hpp"

using namespace std;

void print(const string& text, const PelcoD& pelco)
{
	cout << text << ": ";
	for(int i = 0; i < 7; ++i)
	{
		cout << setfill('0') << setw(2) << hex << (int)pelco.data[i] << " ";
	}
	cout << endl;
}

int main()
{
	PelcoD pelco;

	pelco.clear();
	pelco.setAddr(1);
	pelco.moveLeft(0x3F);
	pelco.calcChecksum();
	print("move left, speed=3f", pelco);

	pelco.clear();
	pelco.setAddr(1);
	pelco.moveLeft(0x3F);
	pelco.moveUp(0x3F);
	pelco.calcChecksum();
	print("move left up, speed=3f", pelco);

	pelco.clear();
	pelco.setAddr(1);
	pelco.moveRight(0x20);
	pelco.calcChecksum();
	print("move right, speed=20", pelco);

	pelco.clear();
	pelco.setAddr(1);
	pelco.moveUp(0xAF);
	pelco.calcChecksum();
	print("move up, speed=3f", pelco); //speed is clamped

	pelco.clear();
	pelco.setAddr(1);
	pelco.moveDown(0x05);
	pelco.calcChecksum();
	print("move down, speed=04", pelco);

	pelco.clear();
	pelco.setAddr(1);
	pelco.setPreset(12);
	pelco.calcChecksum();
	print("set preset, no=12", pelco);




	return 0;

}
