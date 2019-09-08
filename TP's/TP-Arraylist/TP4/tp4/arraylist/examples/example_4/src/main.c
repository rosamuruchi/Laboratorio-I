/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/ArrayList.h"
#include "../inc/Employee.h"



int main(void)
{
        startTesting(1); //al_newArrayList(void)
        startTesting(2); //al_add(ArrayList* this, void* pElement)
        startTesting(3); //al_deleteArrayList(ArrayList* this)
        startTesting(4); //al_len(ArrayList* this)
        startTesting(5); //al_get(ArrayList* this, int index)
        startTesting(6); //al_contains(ArrayList* this, void* pElement)
        startTesting(7);  //al_set(ArrayList* this, int index,void* pElement)
        startTesting(8); //al_remove(ArrayList* this,int index)
        startTesting(9); //al_clear(ArrayList* this)
        startTesting(10); //ArrayList* al_clone(ArrayList* this)
        startTesting(11); //al_push(ArrayList* this, int index, void* pElement)
        startTesting(12); //al_indexOf(ArrayList* this, void* pElement)
        startTesting(13); //al_isEmpty(ArrayList* this)
        startTesting(14); //al_pop(ArrayList* this,int index)
        startTesting(15); //al_subList(ArrayList* this,int from,int to)
        startTesting(16); //al_containsAll(ArrayList* this,ArrayList* this2)
        startTesting(17);//al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)

    return 0;
}





