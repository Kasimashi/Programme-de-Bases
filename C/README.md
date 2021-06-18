## Standard Predefined Macros
The standard predefined macros are specified by the relevant language standards, so they are available with all compilers that implement those standards. Older compilers may not provide all of them. Their names all start with double underscores.

__FILE__
This macro expands to the name of the current input file, in the form of a C string constant. This is the path by which the preprocessor opened the file, not the short name specified in ‘#include’ or as the input file name argument. For example, "/usr/local/include/myheader.h" is a possible expansion of this macro.

__LINE__
This macro expands to the current input line number, in the form of a decimal integer constant. While we call it a predefined macro, it’s a pretty strange macro, since its “definition” changes with each new line of source code.

__FILE__ and __LINE__ are useful in generating an error message to report an inconsistency detected by the program; the message can state the source line at which the inconsistency was detected. For example,

fprintf (stderr, "Internal error: "
                 "negative string length "
                 "%d at %s, line %d.",
         length, __FILE__, __LINE__);
An ‘#include’ directive changes the expansions of __FILE__ and __LINE__ to correspond to the included file. At the end of that file, when processing resumes on the input file that contained the ‘#include’ directive, the expansions of __FILE__ and __LINE__ revert to the values they had before the ‘#include’ (but __LINE__ is then incremented by one as processing moves to the line after the ‘#include’).

A ‘#line’ directive changes __LINE__, and may change __FILE__ as well. See Line Control.

C99 introduced __func__, and GCC has provided __FUNCTION__ for a long time. Both of these are strings containing the name of the current function (there are slight semantic differences; see the GCC manual). Neither of them is a macro; the preprocessor does not know the name of the current function. They tend to be useful in conjunction with __FILE__ and __LINE__, though.

__DATE__
This macro expands to a string constant that describes the date on which the preprocessor is being run. The string constant contains eleven characters and looks like "Feb 12 1996". If the day of the month is less than 10, it is padded with a space on the left.

If GCC cannot determine the current date, it will emit a warning message (once per compilation) and __DATE__ will expand to "??? ?? ????".

__TIME__
This macro expands to a string constant that describes the time at which the preprocessor is being run. The string constant contains eight characters and looks like "23:59:01".

If GCC cannot determine the current time, it will emit a warning message (once per compilation) and __TIME__ will expand to "??:??:??".

__STDC__
In normal operation, this macro expands to the constant 1, to signify that this compiler conforms to ISO Standard C. If GNU CPP is used with a compiler other than GCC, this is not necessarily true; however, the preprocessor always conforms to the standard unless the -traditional-cpp option is used.

This macro is not defined if the -traditional-cpp option is used.

On some hosts, the system compiler uses a different convention, where __STDC__ is normally 0, but is 1 if the user specifies strict conformance to the C Standard. CPP follows the host convention when processing system header files, but when processing user files __STDC__ is always 1. This has been reported to cause problems; for instance, some versions of Solaris provide X Windows headers that expect __STDC__ to be either undefined or 1. See Invocation.

__STDC_VERSION__
This macro expands to the C Standard’s version number, a long integer constant of the form yyyymmL where yyyy and mm are the year and month of the Standard version. This signifies which version of the C Standard the compiler conforms to. Like __STDC__, this is not necessarily accurate for the entire implementation, unless GNU CPP is being used with GCC.

The value 199409L signifies the 1989 C standard as amended in 1994, which is the current default; the value 199901L signifies the 1999 revision of the C standard; the value 201112L signifies the 2011 revision of the C standard; the value 201710L signifies the 2017 revision of the C standard (which is otherwise identical to the 2011 version apart from correction of defects). An unspecified value larger than 201710L is used for the experimental -std=c2x and -std=gnu2x modes.

This macro is not defined if the -traditional-cpp option is used, nor when compiling C++ or Objective-C.

__STDC_HOSTED__
This macro is defined, with value 1, if the compiler’s target is a hosted environment. A hosted environment has the complete facilities of the standard C library available.

__cplusplus
This macro is defined when the C++ compiler is in use. You can use __cplusplus to test whether a header is compiled by a C compiler or a C++ compiler. This macro is similar to __STDC_VERSION__, in that it expands to a version number. Depending on the language standard selected, the value of the macro is 199711L for the 1998 C++ standard, 201103L for the 2011 C++ standard, 201402L for the 2014 C++ standard, 201703L for the 2017 C++ standard, or an unspecified value strictly larger than 201703L for the experimental languages enabled by -std=c++2a and -std=gnu++2a.

__OBJC__
This macro is defined, with value 1, when the Objective-C compiler is in use. You can use __OBJC__ to test whether a header is compiled by a C compiler or an Objective-C compiler.

__ASSEMBLER__
 This macro is defined with value 1 when preprocessing assembly language.
