#include <ctype.h>
#include <stdio.h>

void main(int argc, char *argv[]) {
  int charLen = 0;
  int wordLen = 0;
  int lineLen = 0;

  int input;

  do {
    input = getchar();
    if (input == EOF || input == '*') {
      lineLen += 1;
      break;
    }
    charLen = charLen + 1;
    if (isspace(input)) {
      // Word
      wordLen = wordLen + 1;
      if (input == '\n') {
        // Line
        lineLen = lineLen + 1;
      }
    }
  } while (input != EOF);

  printf("Count of char = %d\n", charLen);
  printf("Count of word = %d\n", wordLen);
  printf("Count of line = %d\n", lineLen);
  return;
}
