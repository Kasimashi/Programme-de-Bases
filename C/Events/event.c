#include <stdio.h>

#define SET_BIT(val, bitIndex) val |= (1 << bitIndex)
#define BIT_IS_SET(val, bitIndex) (val & (1 << bitIndex))

/*
* this enum is a bit  field . One bit per event
*/
typedef enum
{
   EVENT_1 = 1,
   EVENT_2,
   EVENT_3,
   EVENT_4,
   EVENT_5,
   EVENT_LAST,
} EVENT;

typedef struct security_record
{
	unsigned int ui32event;
} security_record_t;


static void voSaveEvent ( security_record_t *pRecord, EVENT eSyslogEvent )
{
	if (eSyslogEvent >= EVENT_LAST){
		printf("[Warning] eSyslogEvent given in %s is too high\n",__FUNCTION__);
		return;
	}
	SET_BIT(pRecord->ui32event,eSyslogEvent);
}

static int processEvent (security_record_t *pRecord)
{
	int status = 0;

	if (pRecord->ui32event){
		if (BIT_IS_SET(pRecord->ui32event,EVENT_1)){
			printf("Event 1\n");
		}
		if (BIT_IS_SET(pRecord->ui32event,EVENT_2)){
			printf("Event 2\n");
		}
		if (BIT_IS_SET(pRecord->ui32event,EVENT_3)){
			printf("Event 3\n");
		}
		if (BIT_IS_SET(pRecord->ui32event,EVENT_4)){
			printf("Event 4\n");
		}
		if (BIT_IS_SET(pRecord->ui32event,EVENT_5)){
			printf("Event 5\n");
		}
	}
	return status;
}

int main(int argc, char **argv)
{
	security_record_t Record = {0};
	security_record_t *pRecord = &Record;

	voSaveEvent(pRecord,EVENT_5);
	voSaveEvent(pRecord,EVENT_1);
	voSaveEvent(pRecord,EVENT_3);
	voSaveEvent(pRecord,6);

	processEvent(pRecord);

	return 0;
}
