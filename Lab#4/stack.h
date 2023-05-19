#pragma once
#include <iostream>
#include <string>

void zadanie();
void pop();
void show();

typedef struct {
	std::string str;
} DATA;

typedef struct tag_object {
	DATA d;
	struct tag_object* next;
} OBJ;

OBJ* top = NULL;

OBJ* push(DATA d) {
	OBJ* ptr = new OBJ;
	ptr->d = d;
	ptr->next = top;
	top = ptr;
	return ptr;
}
