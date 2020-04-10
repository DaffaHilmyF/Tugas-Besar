#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include "relasi.h"
#include "child.h"
#include "parent.h"

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;



void showMenu(List_child &C, List_parent &P, List_relasi &R);
void subMenuDisplay(List_child C, List_parent P, List_relasi R);
void subMenuBuy (List_child &C, List_parent &P, List_relasi &R);
void subMenuInput(List_child &C, List_parent &P, List_relasi &R);
void subMenuDelete(List_child &C, List_parent &P, List_relasi &R);
void subMenuRelation(List_child C, List_parent P, List_relasi R);

void subMenuSearch(List_child C, List_parent P, List_relasi R);

#endif // INTERFACE_H_INCLUDED
