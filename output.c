#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char* a, const char* b) {
    size_t len = strlen(a) + strlen(b) + 1;
    char* res = malloc(len);
    strcpy(res, a);
    strcat(res, b);
    return res;
}

char* mid(const char* s, int start, int length) {
    char* res = malloc(length + 1);
    strncpy(res, s + start - 1, length);
    res[length] = '\0';
    return res;
}

int main() {
	char* inputString = "123 \"Hello, World!\" 456";
	char* currentChar;
	int index = 1;
	char* token;
	char* result;
	while (index <= strlen(inputString)) {
		currentChar = mid(inputString,index,1);
		if (strcmp(currentChar, " ") == 0 || strcmp(currentChar, "\n") == 0 || strcmp(currentChar, "\t") == 0) {
			index = index + 1;
		} else if (strcmp(currentChar, "\"") == 0) {
			token = "";
			index = index + 1;
			while (index <= strlen(inputString) && !(strcmp(mid(inputString,index,1), "\"") == 0)) {
				token = concat(token,mid(inputString,index,1));
				index = index + 1;
			}
			if (index <= strlen(inputString)) {
				index = index + 1;
				result = concat("String: ",token);
			}
		} else if (currentChar[0] >= "0"[0] && currentChar[0] <= "9"[0]) {
			token = "";
			while (index <= strlen(inputString) && mid(inputString,index,1)[0] >= "0"[0] && mid(inputString,index,1)[0] <= "9"[0]) {
				token = concat(token,mid(inputString,index,1));
				index = index + 1;
			}
			result = concat("Integer: ",token);
		} else {
			result = concat("Unknown character: ",currentChar);
			index = index + 1;
		}
		printf("%s\n", result);
		if (result != "") {
			result = "";
		}
	}
	return 0;
}

