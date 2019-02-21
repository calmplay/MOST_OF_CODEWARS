#include "common.h"

//char * loadJsonFile(const char * filepath);
//char * getContent(const char * str, int & ctSize, ErrorType & et);
//char * getIndex(int inx);

/*
getIndex
int to index string

Attention:
free the memory of index string.
*/
char * getIndex(int inx){
	if (inx < 0) return NULL;
	char * ret = (char *)malloc(sizeof(char)* 15);
	ret[0] = '[';
	int t = itoa(inx, ret + 1);
	ret[t + 1] = ']';
	ret[t + 2] = '\0';
	return ret;
}

/*
getContent
Return content and size of content.
Return NULL if content do not comply with grammar.

Attention:
free the memory of content
*/
char * getContent(const char * str, int & ctSize, ErrorType & et){
	char * buffer;      /*constent buffer*/
	char ctType;        /*content type*/
	const char * endFlag;

	switch (ctType = typeCheck(str, et)){
	case STRING_TYPE:     endFlag = "\""; str++; break;
	case BOOL_TYPE:       /* fallthrough... */
	case NULL_TYPE:       /* fallthrough... */
	case NUMBER_TYPE:     endFlag = " \t\n{}[],:\0"; break;
	case BAD_TYPE:        /* fallthrough... */
	default: return NULL;
	}

	/* copy content to buffer */
	for (ctSize = 0; !MATCHED(str[ctSize], endFlag); ctSize++);
	buffer = (char *)malloc(sizeof(char)*(ctSize + 1));
	memcpy(buffer, str, sizeof(char)*ctSize);
	buffer[ctSize] = '\0';
	if (ctType == STRING_TYPE)
		ctSize++;
	else
		ctSize--;

	return buffer;
}

/*
loadJsonFile
return file content.

Attention:
free the memory of return.
*/
char *loadJsonFile(const char * filepath){
	char * ret;
	FILE *fh;
	fh = fopen(filepath, "r");
	if (fh == NULL) return NULL;

	/* get file size */
	int fsize = 0;
	fseek(fh, 0, SEEK_SET);
	fsize = ftell(fh);
	fseek(fh, 0, SEEK_END);
	fsize = ftell(fh) - fsize;

	/* load file */
	ret = (char *)malloc(sizeof(char)*(fsize + 3));
	fseek(fh, 0, SEEK_SET);
	fsize = fread(ret, sizeof(char), fsize - 1, fh);
	ret[fsize] = '\0';
	whitespaceCLR(ret);
	fclose(fh);

	return ret;
}