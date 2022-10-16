#include <stdio.h>
#include <conio.h>


// making our own string methods

int length(char string[1000]) // finding the length of a string
{
    int counter = 0;
    while (string[counter] != '\0')
        counter++;
    return counter
}
void toUpperCase(char string[100])
{    
    // A-Z 65 to 91
    // a-z 97 to 123
    
    char uppercase[100];
    int counter = 0;
    
    while (string[counter] != '\0')
    {
        if (string[counter] >= 'a' && string[counter] <= 'z')
            uppercase[counter] =  string[counter] - 32;
        else
            uppercase[counter] = string[counter];
        counter++;
    }
    printf("Convrted To Upper Case: %s", uppercase);
}
void toLowerCase(char string[100])
{
 // A-Z 65 to 91
    // a-z 97 to 123
    char lowercase[100];
    int counter = 0;
    while (string[counter] != '\0')
    {
        if (string[counter] >= 'A' && string[counter] <= 'Z')
            lowercase[counter] =  string[counter] + 32;
        else
            lowercase[counter] = string[counter];
        counter++;
    }
    printf("Convrted To Lower Case: %s", lowercase);   
}
void append(char destination[100], char source[100]) // appending at the end
{
    int i,j = 0;

    while (destination[j] != '\0')
        j++;
    i = 0;
    while (source[i] != '\0')
    {
        destination[j] = source[i];
        j++;
        i++;
    }
    printf("\n [+] Appendid: %s", destination);
}

void strCompare(char first[100], char second[100])
{
    int first_length = 0, second_length = 0;
    while (first[first_length] != '\0')
        first_length++;
    while (second[second_length] != '\0')
        second_length++;
    if (second_length != first_length)
        printf("[-] Strings Are Not Equal.");
    int check = 0;
    int flag = 0;
    if (first_length == second_length)
    {
        while (check < first_length)
        {
            if (first[check] == second[check])
                check++;
            else
                break; 
        }
        if (check == first_length)
        {
            flag = 1;
            printf("\n Two Strings Are Equal.");
        }
    }
    if (flag == 0)
    {
        if (first[first_length] > second[second_length])
            printf("[+] String 1 is greater than string 2");
        else if (first[first_length] < second[second_length])
            printf("[+] String 2 is greater than string 1");
    }
}

void strReverse(char string[100])
{
    char temp;
    int i = 0, j = 0;
    while (string[j] != '\0')
        j++;
    j = j - 1;

    while (i < j)
    {
        temp = string[j];
        string[j] = string[i];
        string[i] = temp;
        i++;
        j--;
    }
    printf("\n Reversed: %s", string);
}
// extracting a substring from a string

void extract(char string[100], int start, int length) // extracting a string from a substring
{
    int i, j = 0;
    char substring[100];
    i = start;

    while (string[i] != '\0' && length > 0)
    {
        substring[j] = string[i];
        j++;
        i++;
        length--;
    }
    substring[j] = '\0';
    printf("[+] The Extracted SubString: %s", substring);
}

// inserting a text in a string with a given position
void insert(char main[100], char umain[100], int position)
{
    char inserted[100];
    int i = 0, j = 0, k = 0;
    while (main[i] != '\0')
    {
        if (i == position)
        {
            while (umain[k] != '\0')
            {
                inserted[j] = umain[k];
                j++;
                k++;
            }
        }
        else 
        {
            inserted[j] = main[i];
            j++;
        }
        i++;
    }
    inserted[j] = '\0';
    printf("The Inserted String:");
    puts(inserted);
}

// deleting a string from a substirng
void strDelete(char string[100], char delete[100]) // The Algo To Delete A SubString From A String
{
    int i = 0, j = 0, copy = 0, k, n = 0;
    char inserted[100];
    while (string[i] != '\0')
    {
        j = 0, k = i;
        while (string[k] == delete[j] && delete[j] != '\0')
        {
            k++;
            j++;
        }
        if(delete[j] == '\0')
            copy = k;
        inserted[n] = string[copy];
        i++;
        copy++;
        n++;
    }
    printf("The New String: ");
    puts(inserted);
}

int main()
{
    char string[100], deleteit[100];
    printf("Enter The Main String: ");
    gets(string);
    printf("Enter The String To Be Deleted: ");
    gets(deleteit);
    strDelete(string, deleteit);
   
    return 0;
}