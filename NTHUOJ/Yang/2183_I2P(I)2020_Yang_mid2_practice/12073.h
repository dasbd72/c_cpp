#ifndef __FUNCTION_H__
#define __FUNCTION_H__

// Please implement this function in another C cource code
int changeCharacter(char *str, char a, char b){
    for(int i = 0; str[i] != '\0'; i++) if(str[i] == a) str[i] = b;
}

#endif