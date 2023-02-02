#include <stdio.h>
#include <stdlib.h>

struct playlistNode
{
    char song_name[10];
    char artist_name[20];
    long int duration;
    struct playlistNode *next1;
}*start1 = NULL;

struct libraryNode
{
    char song_name[10];
    char artist_name[20];
    long int duration;
    struct libraryNode *next2;
}*start2 = NULL;

void insert_end(char[], char[], long int);
void traverse_library();
void search_by_title_in_library();
void insert_into_playlist();
void traverse_playlist();
void show_duration_of_the_playlist();
void search_by_title_in_playlist();
void swap_using_songname_in_a_playlist();
void shuffle(int);
void remove_a_song_from_the_playlist(int);
void repeat_song();

int main()
{
    int choice, x = 1, choices, m = 1, position, q = 1, choice1,l=0;
    long int duration1;
    char songname[10], artistname[20];
        	printf("\n");
	printf("\n                          O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *                   WELCOME TO                    *     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *             |      I MUSIC     |                *     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O     ");
	printf("\n\n");

    C:

    printf("\n\t\t\t** MAIN MENU **\n\tPRESS 1: Go to Music Library\n\tPRESS 2: Go to your playlist\n\tPRESS 3: Exit from App\n\n");

    while(q)
    {
        printf("Enter the choice: ");
        scanf("%d", &choice1);

        switch(choice1)
        {
            case 1:
            {
                goto A;
                break;
            }

            case 2:
            {
                goto B;
                break;
            }

            case 3:
            {
                	printf("\n                          O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O     ");
	                printf("\n                          *                                                 *     ");
                    printf("\n                          *         THANK YOU FOR USING OUR APP             *     ");
                    printf("\n                          *                                                 *     ");
                	printf("\n                          O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O*X*O     ");
                return 0;
                break;
            }

            default:
            {
                printf("\t\t\tInvalid Choice\n");
                printf("\t\tPlease choose again\n\n\n");
                goto C;
                break;
            }
        }
    }
    A:
    printf("\n\n\n\t\t\t*Menue for MUSIC LIBRARY*\n\tPress 1: Insert songs into the Main Library\n\tPress 2: Display all songs in Main Library\n\tPress 3: Search by Title\n\tPress 4: Insert song in Playlist\n\tPress 5: Enter to put song on Repeat\n\tPress 6: Go to the Playlist Menu\n\tPress 7: Return to Main Menu\n\n");

    while(x)
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                l++;
                printf("Fill the following columns:\n    Sr No.\tSong Name\tArtist Name\tDuration(in seconds)\n");
                printf("\t %d \t\t", l);
                scanf("%s %s %ld", &songname, &artistname, &duration1);
                insert_end(songname, artistname, duration1);
                goto A;
                break;
            }

            case 2:
            {
                traverse_library();
                goto A;
                break;
            }

            case 3:
            {
                search_by_title_in_library();
                goto A;
                break;
            }

            case 4:
            {
                insert_into_playlist();
                goto A;
                break;
            }
             case 5:
            {
                repeat_song();
                goto A;
                break;
            }

            case 6:
            {
                B:
                printf("\n\t\t\t**FOR PLAYLIST**\n");
                printf("\n\n\n\t\t\t * Menue for PLAYLIST *\n\tPress 1: Insert a song into playlist\n\tPress 2: Display the playlist\n\tPress 3: Display total duration\n\tPress 4: Search by Title\n\tPress 5: Shuffle playlist\n\tPress 6: Swap\n\tPress 7: Delete a song from playlist\n\tPress 8: Return to Music Library\n\tPress 9: Return to Main Menu\n\n");
                while(m)
                {
                    printf("\nEnter choice: ");
                    scanf("%d", &choices);

                    switch(choices)
                    {
                        case 1:
                        {
                            insert_into_playlist();
                            goto B;
                            break;
                        }
                        case 2:
                        {
                            traverse_playlist();
                            goto B;
                            break;
                        }

                        case 3:
                        {
                            show_duration_of_the_playlist();
                            goto B;
                            break;
                        }

                        case 4:
                        {
                            search_by_title_in_playlist();
                            goto B;
                            break;
                        }

                        case 5:
                        {
                            shuffle(l);
                            goto B;
                            break;
                        }
                        case 6:
                        {
                            swap_using_songname_in_a_playlist();
                            goto B;
                            break;
                        }

                        case 7:
                        {
                            printf("Enter the Sr No. of the song to be delete:\n");
                            scanf("%d", &position);
                            remove_a_song_from_the_playlist(position);
                            goto B;
                            break;
                        }

                        case 8:
                        {
                            goto A;
                            break;
                        }

                        case 9:
                        {
                            goto C;
                            break;
                        }

                        default:
                        {
                            printf("\t\tInvalid Choice\n");
                            printf("\t\tPlease choose again\n\n\n");
                            goto B;
                            break;
                        }
                    }
                }
            }

            case 7:
            {
                goto C;
                break;
            }

            default:
            {
                printf("\t\tInvalid Choice.\n");
                printf("\t\tPlease choose again\n\n\n");
                goto A;
                break;
            }
        }
    }
}


void insert_end(char songname[], char artistname[], long int duration1)
{
    struct libraryNode *newnode,*temp;
    newnode = (struct libraryNode*)malloc(sizeof(struct libraryNode));
    strcpy(newnode->song_name, songname);
    strcpy(newnode->artist_name, artistname);
    newnode->duration = duration1;
    newnode->next2 = NULL;

     if(start2 == NULL)
     start2 = newnode;

     else
    {
        temp = start2;
        while(temp->next2 != NULL)
        {
            temp = temp->next2;
        }

     temp->next2 = newnode;
    }
      printf("\nInsertion of Song Successful\n\n");
}


void traverse_library()
{
    int f=0;
    struct libraryNode*temp;
    temp = start2;

    if(temp == NULL)
    {
        printf("Library is empty.\n");
        printf("Try again please\n\n\n");
    }

    else
    {
        printf("       Sr No.  \t   Song Name\t   Artist Name\t  Duration(in seconds)\n");
        while (temp!=NULL)
        {
            f++;
            printf("\t %d \t\t %s\t\t %s\t\t%ld\n" ,f, temp->song_name, temp->artist_name, temp->duration);
            temp = temp->next2;
        }
    }
}

void search_by_title_in_library()
{
    int c = 1,f=0;
    char n[20];
    printf("Enter the Song Name to be searched: ");
    scanf("%s", &n);
    struct libraryNode*temp;
    temp = start2;
    if(start2 == NULL)
    {
        printf("Library is empty.\n");
        printf("Please try again \n\n");
    }

    else
    {
        printf("       Sr No.  \t   Song Name\t   Artist Name\t  Duration(in seconds)\n");
        while(temp!= NULL)
        {
            c = strcmp(n, temp->song_name);
            if(c==0)
            {
                f++;
            printf("\t %d \t\t %s\t\t %s\t\t%ld\n" ,f, temp->song_name, temp->artist_name, temp->duration);
                break;
            }
                temp = temp->next2;
        }

        if(c!=0)
            {
                printf("-----------------------------------------------------------------\n");
                printf("Data not available.\n");
                printf("Please try again \n\n");
            }
    }

}

void insert_into_playlist()
{
    struct playlistNode*newnode, *temp1;
    newnode = (struct playlistNode*)malloc(sizeof(struct playlistNode));
    temp1 = start1;
    int c = 1, counter = 0;
    char n[20];
    printf("Enter the song title to be added to the playlist: ");
    scanf("%s", &n);

    while(temp1!=NULL)
    {
        if(!strcmp(temp1->song_name, n))
        {
            counter++;
        }

        temp1 = temp1->next1;
    }

    if(counter == 0)
    {
        struct libraryNode*temp;
        temp = start2;
        if(start2 == NULL)
        {
        printf("Library is empty.\n");
        printf("Please try again \n\n");
        return;
        }

    else
    {
        printf("  Song Name\t   Artist Name\t  Duration(in seconds)\n");
        while(temp!= NULL)
        {
            c = strcmp(n, temp->song_name);
            if(c==0)
            {
            printf("\t%s\t\t %s\t\t%ld\n" ,temp->song_name, temp->artist_name, temp->duration);
                break;
            }
            temp = temp->next2;
        }


            if(c!=0)
            {
                printf("Data not available.\n");
                printf("Please try again \n\n");
                return;
            }
    }

        strcpy(newnode->song_name, temp->song_name);
        strcpy(newnode->artist_name, temp->artist_name);
        newnode->duration = temp->duration;
        newnode->next1 = NULL;

        if(start1 == NULL)
        start1 = newnode;

        else
        {
            newnode->next1 = start1;
            start1 = newnode;
        }
        printf("\n Insertion of song successful\n\n");
    }

    else
    {
        printf("\nData is already in the playlist\n");
        return;
    }


}

void traverse_playlist()
{
    struct playlistNode*temp;
    temp = start1;
    int f=0;

    if(temp == NULL)
    {
        printf("Playlist is empty.\n");
                printf("Please try again \n\n");
    }

    else
    {
         printf("       Sr No.  \t   Song Name\t   Artist Name\t  Duration(in seconds)\n");
        while (temp!=NULL)
        {
            f++;
            printf("\t %d \t\t %s\t\t %s\t\t%ld\n" ,f, temp->song_name, temp->artist_name, temp->duration);
            temp = temp->next1;
        }
    }
}

void show_duration_of_the_playlist()
{
    struct playlistNode *temp;
    long int sum = 0, n;

    temp = start1;

    if(temp == NULL)
    {
        printf("Playlist is empty.\n");
        printf("Please try again \n\n");
    }

    else
    {
        while(temp!=NULL)
        {
            n = temp->duration;
            sum = sum + n;
            temp = temp->next1;
        }
    }

    printf("\nPlaylist Duration(in seconds): %ld sec\n", sum);
}

void search_by_title_in_playlist()
{
    int c = 1,f=0;
    char n[20];
    printf("Enter the song name to be searched: ");
    scanf("%s", &n);
    struct playlistNode*temp;
    temp = start1;
    if(start1 == NULL)
    {
        printf("Playlist is empty.\n");
        printf("Please try again \n\n");
    }

    else
    {
        printf("       Sr No.  \t   Song Name\t   Artist Name\t  Duration(in seconds)\n");
        while(temp!= NULL)
        {
            c = strcmp(n, temp->song_name);
            if(c==0)
            {
                f++;
            printf("\t %d \t\t %s\t\t %s\t\t%ld\n" ,f, temp->song_name, temp->artist_name, temp->duration);
                break;
            }
                temp = temp->next1;
        }

        if(c!=0)
            {
                printf("-----------------------------------------------------------------\n");
                printf("Data not available.\n");
                printf("Please try again \n\n");
            }
    }

}

void swap_using_songname_in_a_playlist()
{
    char n1[10], n2[10]; 

    printf("\nBefore Swapping:\n\n");
    traverse_playlist();
    
    struct playlistNode*temp1, *temp2, *temp3;
    temp1 = start1;
    temp2 = start1;
    temp3 = (struct playlistNode*)malloc(sizeof(struct playlistNode));

    printf("Enter the song names to be swapped:\n");
    scanf("%s %s", n1, n2);


    if(temp1 == NULL)
    {
        printf("Playlist is empty.\n");
        printf("Try again please\n\n\n");
    }

    else
    {
        while (temp1!=NULL)
        {
            if(!strcmp(temp1->song_name, n1))
            {
                while (temp2!=NULL)
                {
                    if(!strcmp(temp2->song_name, n2))
                    {
                    strcpy(temp3->song_name, temp2->song_name);
                    strcpy(temp3->artist_name, temp2->artist_name);
                    temp3->duration = temp2->duration;

                    strcpy(temp2->song_name, temp1->song_name);
                    strcpy(temp2->artist_name, temp1->artist_name);
                    temp2->duration = temp1->duration;

                    strcpy(temp1->song_name, temp3->song_name);
                    strcpy(temp1->artist_name, temp3->artist_name);
                    temp1->duration = temp3->duration;

                    }
                    
                    temp2 = temp2->next1;
                }
            }

            temp1 = temp1->next1;
        }
    }
    
    printf("\n\nAfter Swapping:\n\n");
    traverse_playlist();
}

void remove_a_song_from_the_playlist(int position)
{
    struct playlistNode *temp1, *temp2;
    int i;
    temp1 = start1;
    temp2 = start1;
    if(start1 == NULL)
    {
    printf("Playlist is empty.\n");
    printf("Please try again \n\n");
    }
    else
    {
        for(i = 1; i<position - 1; i++)
        {
            temp1 = temp1->next1;
            temp2 = temp2->next1;
        }

        temp2 = temp2->next1;
        temp1->next1 = temp2->next1;
        free(temp2);
    }
    printf("\nDeletion successful\n");
    printf("New playlist\n");
    traverse_playlist();

}

void repeat_song()
{
    int c = 1,i =1,k=1,f=0;
    char n[20];
    printf("Enter the song name to put on loop: ");
    scanf("%s", &n);
    printf("Number of times you want to loop a song : ");
    scanf("%d",&k);
    struct libraryNode*temp;
    temp = start2;
    if(start2 == NULL)
    {
        printf("Library is empty.\n");
        printf("Please try again \n\n");
    }

    else
    {
        printf("       Loop No.  \t   Song Name\t   Artist Name\t  Duration(in seconds)\n");
        while(temp!= NULL)
        {
            c = strcmp(n, temp->song_name);
            if(c==0)
            {
                for(i=1;i<=k;i++)
                {
                    f++;
                    printf("\t %d \t\t %s\t\t %s\t\t%ld\n" ,f, temp->song_name, temp->artist_name, temp->duration);
                }
                break;
            }
                temp = temp->next2;
        }

        if(c!=0)
            {
                printf("-----------------------------------------------------------------\n");
                printf("Data not available.\n");
                printf("Please try again \n\n");
            }
    }
}



void shuffle (int l)
{
    int c = 1,a=0,n,j=0,ch,i;
    struct playlistNode*temp;
    temp = start1;
    if(temp == NULL)
    {
        printf("playlist is empty.\n");
        printf("Try again please\n\n\n");
    }

    else
    {
      printf("  Song Name\t   Artist Name\t  Duration(in seconds)\n");
      for (c = 1; c <=10; c++)
       {
         ch = rand() %  l+ 1;
         temp = start1;
         j=0;
         while(temp!= NULL)
            {
             j++;
             if(j==ch)
               {
                 printf(" \t\t %s\t\t %s\t\t%ld\n" , temp->song_name, temp->artist_name, temp->duration);
                 break;
                }
             temp = temp->next1;
            }

        }
    }
}
