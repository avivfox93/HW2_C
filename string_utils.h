/*
 * string_utils.h
 *
 *  Created on: 27 Nov 2018
 *      Author: aviv
 */

#ifndef STRING_UTILS_H_
#define STRING_UTILS_H_

#define SPECIAL_LETTERS ":,?-"

void initString(char*,int);
void printString(const char*);
int countWords(const char*);
void longestInCaptital(char*);
void revertWords(char*);
void eraseCharsFromString(char*,const char*);
int isPalindrome(const char*);

int isLetter(char);
int isSpecial(char);
void swap(char*,char*);

#endif /* STRING_UTILS_H_ */
