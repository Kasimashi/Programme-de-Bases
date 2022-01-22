#include <stdio.h>


typedef void (*appender_cbk)(
		int a
		);
		
typedef struct logger {
	appender_cbk appender;	/**< Callback function to be used by the logger to log each message */
} logger_t;


int (*pf)(int);

static void platform1_affiche(int a)
{
    printf("Platform 1 : %d\n",a);
}

static void platform2_affiche(int a)
{
    printf("Platform 2 : %d\n",a);
}

int main(void)
{
    logger_t logger;
    
    logger.appender = platform1_affiche;  
    logger.appender(3);
    
    logger.appender = platform2_affiche;  
    logger.appender(3);
       
    return 0;
}
