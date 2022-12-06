#include <iostream>
#include <fstream>
#include "Decod.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


int main(int argc, char** argv) 
{
	// calling main parser
	decod &decod = decod::instance();
	decod.createfile();
	return 0;
}
