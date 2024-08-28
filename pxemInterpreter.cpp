#include <iostream>
#include <fstream>
#include <string>
#include "pxem.h"

int main(int argc,char **argv){
	if ( argc < 2 ) {
		std::cerr << "Usage: " << argv[0] << " FILE" << std::endl;
		return 1;
	}

	std::string fileName = argv[1];
	std::string fileName2;
	std::ifstream fR(fileName.c_str());
	std::string fileContents;

	if ( !fR.is_open() ) {
		std::cerr << "FileOpenError: " << fileName << std::endl;
		goto GetBasename;
	}

	char c;
	while(fR.get(c))
		fileContents += c;
	fR.close();

GetBasename:
	if(fileName.rfind('/') == std::string::npos)
		if(fileName.rfind('\\') != std::string::npos)
			fileName2 = fileName.substr(1+(int)fileName.rfind('\\'));
		else
			fileName2 = fileName;
	else
		fileName2 = fileName.substr(1+(int)fileName.rfind('/'));

	Pxem pxemi((char*)fileName2.c_str(),(char*)fileContents.c_str());
	pxemi.run();
}
