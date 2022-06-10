#include "Structs.h"
#ifndef LISTS_H_
#define LISTS_H_

void init_list(list *l);

void pushElement(list *l, data *value);

void deleteElement(list *l);

node* nextElement(list *l);

#endif /* LISTS_H_ */
