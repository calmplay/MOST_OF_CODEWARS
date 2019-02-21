#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#define MATCHED(c,s) (strchr(s,c)!=NULL)        /* judge if c is in s */
#define IS_WHITESPACE(c) (MATCHED(c," \t\n"))   /* judge if c is a whitespace */
#define IS_KEYCHAR(c) (MATCHED(c,"{}[],:\0"))   /* judge if c is a json key character */

enum ContentType { STRING_TYPE, NUMBER_TYPE, BOOL_TYPE, NULL_TYPE, BAD_TYPE };//
enum ErrorType{ SUCCESS = 0, BAD_CONTENT_TYPE, WRONG_CHARACTER, NO_MATCH, INCOMPLETE };


struct EC{
	ErrorType et;
	const char * pos;
	EC(ErrorType _et, const char * _pos) :et(_et), pos(_pos){}
};


bool isNumber(const char *str);
bool matchStr(const char *str1, const char *str2);
ContentType typeCheck(const char *str, ErrorType & et);

char * loadJsonFile(const char * filepath);
char * getContent(const char * str, int & ctSize, ErrorType & et);
char * getIndex(int inx);

void whitespaceCLR(char *str);
int itoa(int x, char *buffer);

EC json2cmd(char * jsonStr, FILE * hSaveFile, char * eName);
void errorReporter(EC e, const char * json);