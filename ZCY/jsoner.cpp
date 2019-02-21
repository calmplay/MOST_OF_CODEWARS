
/*
jsoner
Version     : 1.0
Auther      : blackkitty
Date        : 2017-3-14
Description : JSON parsing for batch

batch usage:
jsoner [-f JSONFile]|[-s JSONString] SaveFile elementName
call SaveFile
*/


#include "common.h"


int main(int argc, char *argv[]) {

	if (argc >= 5){
		char * json = NULL;
		FILE * fhSave;
		fhSave = fopen(argv[3], "w+");
		if (fhSave == NULL){
			return 1;
		}

		if (matchStr(argv[1], "-f")){
			json = loadJsonFile(argv[2]);
			if (json == NULL){
				fclose(fhSave);
				return 1;
			}
		}
		else if (matchStr(argv[1], "-s")){
			json = argv[2];
		}
		else
			goto help;

		errorReporter(json2cmd(json, fhSave, argv[4]), json);
		fclose(fhSave);

		return 0;
	}

help:;
	puts("    jsoner ver 1.0 By blackkitty");
	puts("    jsoner [-f JSONFile]|[-s JSONString] SaveFile ObjectName");
	puts("");
	return 0;
}
