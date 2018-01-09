#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>/* timeval, gettimeofday() */
#include "profile.h"
#include "data.h"

struct timeval start, stop;

Data data_array[1000];

void profileInsert (Vector * vect,List * list)
{
   time_t start_time=0;
   time_t stop_time=0;
   float profile_time=0;
   gettimeofday(&start, NULL);

   int i=0;
	for( ; i < 1000 ; i++){
		data_array[i].value = (rand() % 1000);
		vect->insert(vect, i, data_array[i]);
	}
   gettimeofday(&stop, NULL);
    start_time = (start.tv_sec* 1000000) + start.tv_usec;
    stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
    profile_time = stop_time - start_time;
   fprintf(stderr,"\nTime to insert 1000 data objects in  a Vector is: %f\n",profile_time);

   gettimeofday(&start, NULL);
   int index = 0;
	//add elements to the list
	for( ; index < 1000 ; index++ ){
		list->insert(list , index, (Data){index+1});
	}
   gettimeofday(&stop, NULL);
    start_time = (start.tv_sec* 1000000) + start.tv_usec;
    stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
    profile_time = stop_time - start_time;
   printf("\nTime to insert 1000 data objects in a List is: %f\n",profile_time);
}

void profileRead (Vector * vect,List * list)
{
   time_t start_time;
   time_t stop_time;
   float profile_time;
   gettimeofday(&start, NULL);

   int i=0;
   for(; i < 100 ; i++){
        int j;
        j = (rand()%1000);
		Data * d = vect->read(vect, j);
		//fprintf(stderr, "%d %d\n",data_array[j].value, d->value );
		assert(data_array[j].value == d->value);
	}
   gettimeofday(&stop, NULL);
    start_time = (start.tv_sec* 1000000) + start.tv_usec;
    stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
    profile_time = stop_time - start_time;
   printf("\nTime to read random 100 data objects from a Vector is: %f\n",profile_time);

   gettimeofday(&start, NULL);
   int index = 0;
   for( ; index < 100 ; index++){
        int j;
        j = (rand()%1000) + 1;
		Data * d = list->read(list, j);
		assert(d->value == j + 1);
	}
   gettimeofday(&stop, NULL);
    start_time = (start.tv_sec* 1000000) + start.tv_usec;
    stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
    profile_time = stop_time - start_time;
   printf("\nTime to read random 100 data objects from a List is %f\n",profile_time);
}

void profileRemove (Vector * vect,List * list)
{
   time_t start_time;
   time_t stop_time;
   float profile_time;
   gettimeofday(&start, NULL);

   int i=0;
   for(; i < 100 ; i++){
		vect->remove(vect, ((rand()%1000)));
	}
   gettimeofday(&stop, NULL);
    start_time = (start.tv_sec* 1000000) + start.tv_usec;
    stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
    profile_time = stop_time - start_time;
   printf("\nTime to remove random 100 data objects from a Vector is %f\n",profile_time);

   gettimeofday(&start, NULL);
   int index = 0;
   i = 0;
   for(; index < list->head != NULL; index++){
                int j;
                j =  rand()%1000;
	       // index = index % 4;
         	list->remove(list ,j);
                i = i + 1;
                if (i ==100)
                break;
	}
   gettimeofday(&stop, NULL);
    start_time = (start.tv_sec* 1000000) + start.tv_usec;
    stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
    profile_time = stop_time - start_time;
    printf("\nTime to remove random 100 data objects from a List is %f\n",profile_time);
     index = 0;
     for (;list->head != NULL; index ++)
      {
     index = index % 1000;
     list->remove(list,index);
     }
}
