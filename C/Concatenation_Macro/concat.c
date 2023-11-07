#include "concat.h"
#include <stdbool.h> // For `true` (`1`) and `false` (`0`) macros in C
#include <stdint.h>  // For `uint8_t`, `int8_t`, etc.
#include <stdio.h>   // For `printf()`

#define ArgArg(x, y)          x##y
#define ArgText(x)            x##TEXT
#define TextArg(x)            TEXT##x
#define TextText              TEXT##text
#define Jitter                1
#define bug                   2
#define Jitterbug             3

/*
ArgArg(lady, bug)	"ladybug"
ArgText(con)	"conTEXT"
TextArg(book)	"TEXTbook"
TextText	"TEXTtext"
ArgArg(Jitter, bug)	3
*/
#define COMMAND(NAME)  { #NAME, NAME ## _command }

struct command
{
  char *name;
  void (*function) (void);
};

void quit_command(void)
{
}
void help_command(void)
{
}


struct command commands[] =
{
  COMMAND (quit),
  COMMAND (help),
  /*
  { "quit", quit_command },
  { "help", help_command },
  */
};

#define CONCAT_(prefix, suffix) prefix##suffix
/// Concatenate `prefix, suffix` into `prefixsuffix`
#define CONCAT(prefix, suffix) CONCAT_(prefix, suffix)
/// Make a unique variable name containing the line number at the end of the
/// name. Ex: `uint64_t MAKE_UNIQUE_VARIABLE_NAME(counter) = 0;` would
/// produce `uint64_t counter_7 = 0` if the call is on line 7!
#define MAKE_UNIQUE_VARIABLE_NAME(prefix) CONCAT(prefix##_, __LINE__)
int main(void)
{
	printf("Autogenerate unique variable names containing the line number "
           "in them.\n\n");

    uint64_t MAKE_UNIQUE_VARIABLE_NAME(counter) = 0; // `uint64_t counter_59 = 0;
    uint64_t MAKE_UNIQUE_VARIABLE_NAME(counter) = 0; // `uint64_t counter_60 = 0;
    uint64_t MAKE_UNIQUE_VARIABLE_NAME(counter) = 0; // `uint64_t counter_61 = 0;

    // Uncomment this to suppress the errors.
    (void)counter_59;
    (void)counter_60;
    (void)counter_61;
	
	printf("Date %s\r\n",__DATE__);

    return 0;
}
