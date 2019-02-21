
#include "common.h"

//
//bool isNumber(const char *str);//kjk
//bool matchStr(const char *str1, const char *str2);
//ContentType typeCheck(const char *str, ErrorType & et);

/*
isNumber
judge if a string is a json number.
*/
bool isNumber(const char *str){
	/* -0.0e+003 */
	bool ef, df, ff, fnf, pzf, pnf;
	ef = false;     /* e flag */
	df = false;     /* dot flag */
	ff = true;      /* first position flag */
	fnf = true;     /* first number flag */
	pzf = false;    /* prefix zero flag */
	pnf = false;      /* prefix non-zero flag */
	for (const char *p = str; !IS_KEYCHAR(*p); p++){
		if (MATCHED(*p, "+-")){
			if (!ef && *p == '+') return false;
			if (!ff) return false;
			ff = false;
		}
		else if (MATCHED(*p, "eE")){
			if (ff || fnf || ef) return false;
			ff = fnf = ef = df = true;
			pnf = false;
		}
		else if (*p == '.'){
			if (df || ff || fnf || ef) return false;
			df = fnf = true;
		}
		else if (*p >= '0' && *p <= '9'){
			if (*p == '0' && !pnf &&!df){
				if (pzf) return false;
				pzf = true;
			}
			if (*p != '0')
				pnf = true;
			ff = fnf = false;
		}
		else{
			return false;
		}
	}
	return !fnf;
}


/*
matchStr
judge if str2 matched str1.
*/
bool matchStr(const char * str1, const char * str2){
	for (; *str2 != '\0'; str1++, str2++)
	if (*str1 != *str2)
		return false;
	return IS_KEYCHAR(*str1);
}


/*
typeCheck
get the type of content.
*/
ContentType typeCheck(const char * str, ErrorType & et){

	if (matchStr(str, "true") || matchStr(str, "false"))
		return BOOL_TYPE;

	if (matchStr(str, "null"))
		return NULL_TYPE;

	if (isNumber(str))
		return NUMBER_TYPE;

	if (*str == '"'){
		for (str++; *str != '"'; str++);
		if (IS_KEYCHAR(str[1]))
			return STRING_TYPE;
	}
	et = BAD_CONTENT_TYPE;
	return BAD_TYPE;
}