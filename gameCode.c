#include <stdio.h>

/*14 is the number of tiles, and each tile is represented by 3*3 matrix */
char tiles[14][9][9];

void readfromfile(char s1[], char s2[]){

int t;
	
        FILE *file1 = fopen( s1, "r" );
        FILE *file2 = fopen( s2, "w" );

        /* fopen returns 0, the NULL pointer, on failure */
        if ( file1 == 0 )
        {
            printf( "Could not open file\n" );
        }
        else 
        {
            char x[10];
            /* read one Line at a time from file1, stopping at EOF, which indicates the end of the file. */
			int i=0;
            while  (  !feof(file1) )
            {
		 

			fscanf( file1,"%s",x ) ;
			t=0;
			for (int j=0;j<3;j++){
				for (int k=0;k<3;k++){
					tiles[i][j][k]=x[t];
					t++;
					}
				}
				i++;
			
			
		
              /*  printf( "%c", x ); */
		fprintf(file2,"%s\n",x);
		
            }
            fclose( file1 );
	    fclose( file2 );
        }

}

int main ( int argc, char *argv[] )
{
    
	// We assume argv[1], argv[2] are a filenames to open
	readfromfile(argv[1],argv[2]);


		for (int i=0;i<14;i++){
			
			for (int j=0;j<3;j++){
				for (int k=0;k<3;k++){
					printf("%c",tiles[i][j][k]);
					
					}
					printf("\n");
				}
				printf("\n");
			}
      
}