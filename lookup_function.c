/*

Name : Purushotham Puchakatla

Description  : Implement an optimised string lookup function using linear search for an ESP-IDF firmware project.
               The function should efficiently find a target string in an array of strings.

               Crucial point: Optimize the function for repeated lookups of the same string,
               ensuring that after the first lookup, subsequent lookups for the same string
               can be done in minimum number of steps.

               Assume the maximum array size to be 1000 strings.




-> This is a function named Lookup_Linear_Search which searches the Target String in array of size is fixed to 1000,
-> Next to optimise the search here we created a one more struct array called "search_list".
            1) first the Lookup_Linear_Search function searches the string in "search-list" .
            2) if it is present there then returns the index number in (main array[]) array of strings here.
            3)if it is not present in search_list , then it starts searching in main array[] and returns the index and
          * 4) Next it stores the searched string and index in search_list to optimise the search.

            5) search_list is pointer array which stores address of elements of previous searched elements of main array[].



            6)Here one more function is there "Increase_Search_List_Size " It increases the search_list size
             whenever we need add an previous searched element .

             */


int Lookup_Linear_Search(char *array[], const char *Target_String, int array_size, struct searches **search_list, int *search_list_size)
{
    //struct searches *search_list is pointer array which is created using malloc function
    //then we can resizes or reallocs the memory when every we needed.
    //The search_list stores the struct elements
    // To store the string and index , i created a structure calles searches having elements string and index.
    for(int i=0; i<(*search_list_size); i++)
    {
        if(strcmp((*search_list)[i].string , Target_String) == 0)
        {
            return (*search_list)[i].index;
        }

    }
    for(int i=0; i<array_size; i++)
    {
        if(strcmp(array[i] , Target_String) == 0)
        {
            Increase_Search_List_Size(search_list, search_list_size);
            //it is function which reallocs the memory when every element is need to added
            (*search_list)[*search_list_size - 1].index = i;
            strcpy((*search_list)[*search_list_size - 1].string , Target_String);
            return i;
        }
    }
    return -1;
}
