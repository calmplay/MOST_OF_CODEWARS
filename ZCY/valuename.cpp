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


#include <string.h>
#include "common.h"




//EC json2cmd(char * jsonStr, FILE * hSaveFile, char * eName);
//void errorReporter(EC e, const char * json);


class ValueName{
public:
	char key[4096];

	ValueName(){
		stk = _stk;
		*stk = 0;
		memset(key, 0, sizeof(key));
	}

	ValueName push(const char * str){
		int t = 0;
		tail = key + *stk;
		for (; *str != '\0'; t++)
			*tail++ = *str++;
		*tail = '\0';
		stk[1] = *stk + t;
		stk++;
		return *this;
	}

	ValueName pop(){
		stk--;
		key[*stk] = '\0';
		return *this;
	}

private:
	int _stk[4096];
	int *stk;
	char *tail;
};


const char * _ErrorType[] = {
	"Success.",
	"Unexpected charater or data type.",
	"There should not be a '%c'.",
	"There are no '%c' before to match the '%c'.",
	"The json string is not complete."
};


void errorReporter(EC e, const char * json){
	if (e.et == SUCCESS){
		puts(_ErrorType[e.et]);
		return;
	}
	const char *tmp = "}]";
	char * part = (char*)malloc(sizeof(char)* 50);
	char * p = (char*)(json>e.pos - 20 ? json : e.pos - 20);
	int i;
	for (i = 0; p[i] != '\0'&&i<40; i++){
		part[i] = p[i];
	}
	part[i] = '\0';
	puts("ERROR:");
	printf("%s%s%s\n", p == json ? "" : "...", part, i<40 ? "" : "...");
	printf("%*s\n", (p == json ? e.pos - json : 23) + 1, "^");
	switch (e.et){
	case BAD_CONTENT_TYPE:      /* fallthrough */
	case INCOMPLETE:
		puts(_ErrorType[e.et]);
		break;
	case WRONG_CHARACTER:
		printf(_ErrorType[e.et], *e.pos);
		puts("");
		break;
	case NO_MATCH:
		printf(_ErrorType[e.et],
			"{["[strchr(tmp, *e.pos) - tmp],
			*e.pos);
		puts("");
		break;
	default:
		puts("Unexcepted Error!");
		break;
	}
	free(part);
}
/*
json2cmd
jsont to cmd main loop
*/
EC json2cmd(char * strJson, FILE * fhSave, char * _objectName) {

	const char * p;
	ErrorType et = SUCCESS;

	char _stk[4096];            /* record "" {} [] : */
	char *stk = _stk;

	ValueName objectName;             /* record element name */
	objectName.push(_objectName);

	int _inx[4096] = { 0 };       /* record list index */
	int *inx = _inx;

	p = strJson;
	char * tmp;

	for (; *p; p++) {
		switch (*p){
		case '{':
			if (*stk == '{') return EC(WRONG_CHARACTER, p);
			*++stk = *p;
			break;
		case '[':
			if (*stk == '{') return EC(WRONG_CHARACTER, p);
			*++stk = *p;
			*++inx = 0;
			tmp = getIndex(*inx);
			objectName.push(tmp);
			free(tmp);
			break;
		case '}':
			if (*stk == '{') stk--;
			else if (*stk == ':'){
				stk--, p--;
				objectName.pop();
				objectName.pop();
			}
			else return EC(NO_MATCH, p);
			break;
		case ']':
			if (*stk == '[') stk--;
			else return EC(NO_MATCH, p);
			inx--;
			objectName.pop();
			break;
		case ':':
			*++stk = *p;
			break;
		case ',':
			if (*stk == '['){
				++*inx;
				tmp = getIndex(*inx);
				objectName.pop();
				objectName.push(tmp);
				free(tmp);
			}
			if (*stk == ':'){
				stk--;
				objectName.pop();
				objectName.pop();
			}
			break;
		default:
			int ctSize = -1;
			tmp = getContent(p, ctSize, et);
			if (tmp == NULL) return EC(et, p);
			if (*stk == '{'){
				/* left value */
				objectName.push(".");
				objectName.push(tmp);
			}
			else{
				/* right value */
				fprintf(fhSave, "set \"%s=%s\"\n", objectName.key, tmp);
			}
			free(tmp);
			p += ctSize;
			break;
		}
	}
	if (stk != _stk) return EC(INCOMPLETE, p);
	return EC(SUCCESS, p);
}





