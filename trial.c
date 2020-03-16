#include"functionheader.h"
void main()
{

	typedef void * histdata_t;

	typedef struct _hist_entry {
		char *line;
		char *timestamp;
		histdata_t data;
	} HIST_ENTRY;

	HIST_ENTRY ** the_history_list;

	typedef struct _hist_state {
		HIST_ENTRY **entries; /* Pointer to the entries themselves. */
		int offset;           /* The location pointer within this array. */
		int length;           /* Number of elements within this array. */
		int size;             /* Number of slots allocated to this array. */
		int flags;
	} HISTORY_STATE;

	char *s,**t;

	int i;
	s=readline("Enter Something!!!> ");
	t=tokenizer_for_all(s);
	if (*t[0]=='!')
	{
		i=history_search(t[1],-1);
	}
	HIST_ENTRY *w;
	w=history_get(i);
	printf("%s",w->line);


}
